#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "StringCalculator.h"

std::string FindDelimeter(const std::string& input)
{
    // Determine delimiter and numbers part
    std::string delimiter = ",";
    std::string numbersStr = input;

    // Check if there's a custom delimiter specified
    if (input.substr(0, 2) == "//") {
        size_t delimiterPos = input.find("\n");
        if (delimiterPos != std::string::npos) {
            delimiter = input.substr(2, delimiterPos - 2);
            numbersStr = input.substr(delimiterPos + 1);
        }
    }
    return delimiter;

}

std::string ReplaceWithCommas(const std::string& input, const std::string& delimiter)
{
    std::string numbersStr = input;
    // Replace delimiter and newlines with commas for easy splitting
    for (char& c : numbersStr) {
        if (c == '\n' || c == delimiter[0]) {
            c = ',';
        }
    }
    return numbersStr;
}


int FindSum(const std::string& updatedinput){
    // Creating a stringstream
    std::stringstream strstream(updatedinput);
    std::string segment;
    int sum = 0;
    std::vector<int> negatives;

    while (std::getline(strstream, segment, ',')) {
        int number = std::stoi(segment);
        if (number < 0) {
            throw std::runtime_error("negatives not allowed");
        } else if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}

// bool FindNegatives(int num){
//         // If there are negative numbers, throw an exception
//         if (number < 0) {
//             throw std::runtime_error("negatives not allowed");
//         }
//         ss << "negatives not allowed:";
//         throw std::invalid_argument(ss.str());
//     }
// }

int StringCalculator::add(const std::string& input) 
{
  if (input.empty()) {
        return 0;
    }
    std::string delimiter = FindDelimeter(input);

    // Replace delimiter and newlines with commas for easy splitting
    std::string updatedinput = ReplaceWithCommas(input,delimiter);

    int sum = FindSum(updatedinput);
    
    //FindNegatives(negatives);

    return sum;
}

