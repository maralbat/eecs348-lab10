#include <iostream>
#include <vector>
#include <string>
#include "calculator.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::string filename = argv[1];
    auto numbers = load_numbers_from_file(filename);

    for (const auto& num : numbers) {
        if (is_valid_double(num)) {
            double value = parse_number(num);
            double result = value + (-123.456);
            std::cout << "Original: " << num << " | Parsed: " << value << " | After adding -123.456: " << result << "\n";
        } else {
            std::cout << "Invalid number: " << num << "\n";
        }
    }

    return 0;
}
