#include <iostream>
#include <vector>
#include <string>
#include "calculator.hpp"

int main(int argc, char *argv[]) { // defines the main function
    if (argc < 2) { // checks if there are enough command-line arguments
        std::cerr << "Usage: " << argv[0] << " <filename>\n"; // prints usage message if no filename is provided
        return 1; //exit program with error
    }

    std::string filename = argv[1]; // store filename
    auto numbers = load_numbers_from_file(filename); // load numbers from file into a vector.

    for (const auto& num : numbers) { // iterate for each number in vector
        if (is_valid_double(num)) { // if current number is valid double
            double value = parse_number(num); // parse the valid number string into a double
            double result = value + (-123.456); // add -123.456 to the parsed value

            // prints the original number, parsed value, and the result after addition
            std::cout << "Original: " << num << " | Parsed: " << value << " | After adding -123.456: " << result << "\n";
        } else { // if the number is not valid
            std::cout << "Invalid number: " << num << "\n"; // prints that the number is invalid
        }
    }

    return 0; // exit program successfully
}
