#include "calculator.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

bool is_valid_double(const std::string& s) {
    size_t i = 0, n = s.size();
    if (n == 0) return false;

    if (s[i] == '+' || s[i] == '-') i++;

    bool has_digits = false;
    while (i < n && std::isdigit(s[i])) {
        has_digits = true;
        i++;
    }

    if (i < n && s[i] == '.') {
        i++;
        bool frac_digits = false;
        while (i < n && std::isdigit(s[i])) {
            frac_digits = true;
            i++;
        }
        if (!frac_digits) return false;
        return i == n;
    }

    return i == n && has_digits;
}

std::vector<std::string> load_numbers_from_file(const std::string& filename) {
    std::vector<std::string> numbers;
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line)) {
        if (!line.empty()) {
            numbers.push_back(line);
        }
    }
    return numbers;
}

double parse_number(const std::string &expression) {
    int i = 0, n = expression.size();
    int sign = 1;
    if (expression[i] == '+' || expression[i] == '-') {
        if (expression[i] == '-') sign = -1;
        i++;
    }

    double integer_part = 0.0;
    while (i < n && std::isdigit(expression[i])) {
        integer_part = integer_part * 10 + (expression[i] - '0');
        i++;
    }

    double fractional_part = 0.0;
    if (i < n && expression[i] == '.') {
        i++;
        double divisor = 10.0;
        while (i < n && std::isdigit(expression[i])) {
            fractional_part += (expression[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
    }

    return sign * (integer_part + fractional_part);
}

