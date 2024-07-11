#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
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
    // Replace delimiter characters and newlines with commas
    std::replace_if(numbersStr.begin(), numbersStr.end(), [&](char c) {
        return c == '\n' || delimiter.find(c) != std::string::npos;
    }, ',');
    return numbersStr;
}

void FindNegatives(const std::string& updatedinput)
{
    std::stringstream strstream(updatedinput);
    std::string segment;

    while (std::getline(strstream, segment, ',')) {
        //int number = std::stoi(segment);
        if (std::stoi(segment) < 0) 
        {
        throw std::runtime_error("negatives not allowed");
        }
    }
}

int FindSum(const std::string& updatedinput)
{
    // Creating a stringstream
    std::stringstream strstream(updatedinput);
    std::string segment;
    int sum = 0;

    while (std::getline(strstream, segment, ',')) {
        int number = std::stoi(segment);
        if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}

int StringCalculator::add(const std::string& input) 
{
  if (input.empty()) {
        return 0;
    }
    std::string delimiter = FindDelimeter(input);

    // Replace delimiter and newlines with commas for easy splitting
    std::string updatedinput = ReplaceWithCommas(input,delimiter);

    int sum = FindSum(updatedinput);
    
    FindNegatives(updatedinput);

    return sum;
}

