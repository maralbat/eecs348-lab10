#include "calculator.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

// validates if a string is a valid double number
bool is_valid_double(const std::string& s) {
    size_t i = 0, n = s.size(); // initializes the index and string size
    if (n == 0) return false; // returns false if the string is empty

    if (s[i] == '+' || s[i] == '-') i++; // handles optional leading sign

    bool has_digits = false; // flag to check if digits are present
    while (i < n && std::isdigit(s[i])) { // checks for digits in the integer part
        has_digits = true; // marks that we have found digits
        i++; // move to the next character
    }

    if (i < n && s[i] == '.') { // checks if there's a decimal point
        i++; // skips the decimal point
        bool frac_digits = false; // flag for fractional digits
        while (i < n && std::isdigit(s[i])) { // checks for digits after the decimal point
            frac_digits = true; // marks fractional digits
            i++; // move on to the next character
        }
        if (!frac_digits) return false; // returns false if no fractional digits found
        return i == n; // returns true if no more characters are left after the fraction
    }

    return i == n && has_digits; // returns true if we reached the end and have digits
}

// loads string-formatted numbers from a file, one per line
std::vector<std::string> load_numbers_from_file(const std::string& filename) {
    std::vector<std::string> numbers; // vector to store the numbers
    std::ifstream infile(filename); // opens the file for reading
    std::string line; // variable to hold each line
    while (std::getline(infile, line)) { // reads each line of the file
        if (!line.empty()) { // checks if the line is not empty
            numbers.push_back(line); // adds the valid line to the numbers vector
        }
    }
    return numbers; // returns the vector of numbers
}

// parses a validated number string and returns its double value
double parse_number(const std::string &expression) {
    int i = 0, n = expression.size(); // initializes index and string size
    int sign = 1; // sets the default sign to positive
    if (expression[i] == '+' || expression[i] == '-') { // checks for optional sign
        if (expression[i] == '-') sign = -1; // sets the sign to negative if necessary
        i++; // moves past the sign
    }

    double integer_part = 0.0; // initializes the integer part
    while (i < n && std::isdigit(expression[i])) { // loops through the integer part of the string
        integer_part = integer_part * 10 + (expression[i] - '0'); // converts character to digit and adds to integer part
        i++; // move on to the next character
    }

    double fractional_part = 0.0; // initialize the fractional part
    if (i < n && expression[i] == '.') { // check if a decimal point is present
        i++; // skip the decimal point
        double divisor = 10.0; // divisor for fractional digits
        while (i < n && std::isdigit(expression[i])) { // loops through the fractional part of the string
            fractional_part += (expression[i] - '0') / divisor; // converts character to digit and adds to fractional part
            divisor *= 10.0; // increases the divisor by a factor of 10 for each digit
            i++; // move on to the next character
        }
    }

    return sign * (integer_part + fractional_part); // returns the final calculated number, applying the sign
}

