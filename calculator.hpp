#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>
#include <vector>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);

// validates if a string is a valid double number
bool is_valid_double(const std::string& s);

// reads string-formatted numbers from file
std::vector<std::string> load_numbers_from_file(const std::string& filename);

#endif // __CALCULATOR_HPP