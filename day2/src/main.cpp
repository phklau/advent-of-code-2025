#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>

uint64_t findDoublePatterns(uint64_t &i)
{
    std::string number = std::to_string(i);
    bool digitsOdd = !bool(number.length() % 2);
    if (digitsOdd)
    {
        uint64_t firstHalf = std::stoull(number.substr(0, number.length()/2));
        uint64_t secondHalf = std::stoull(number.substr(number.length()/2, number.length()/2));
        if (firstHalf == secondHalf)
        {
            std::cout << number << std::endl;
            return std::stoull(number);
        }
    }
    return 0;
};

uint64_t findAllPatterns(uint64_t &i)
{
    return 0;
}


struct IDrange
{
    uint64_t begin;
    uint64_t end;
};

int main(int argc, char** argv) 
{
    if (argc != 2)
    {
        std::cout << "No or wrong input provided" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open())
    {
        std::cout << "File " << argv[1] << "couldn't be opened" << std::endl;
        return 1;
    }

    std::string input;
    getline(file, input);

    std::vector<IDrange> ranges;
    std::string range;
    std::stringstream ss(input);
    while(getline(ss, range, ','))
    {
        std::stringstream ss(range);
        std::string number;
        IDrange parsedRange;
        getline(ss, number, '-');
        parsedRange.begin = std::stoull(number);
        getline(ss, number, '-');
        parsedRange.end = std::stoull(number);
        ranges.push_back(parsedRange);
    }

    uint64_t passwort = 0;
    for(auto range=ranges.begin(); range!=ranges.end(); ++range)
    {
        std::cout << range->begin << "-" << range->end << std::endl;
        for (uint64_t i=range->begin; i<=range->end; i++)
        {
                passwort += findDoublePatterns(i);
        }
    }
    std::cout << "Part1: " << passwort << std::endl;

    return 0;
}
