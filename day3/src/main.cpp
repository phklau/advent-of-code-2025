#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdint>

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

    std::vector<std::vector<uint>> batteries;
    std::string line;
    while(getline(file, line))
    {
        std::vector<uint> bank;
        for (auto c=line.begin(); c!=line.end(); ++c)
        {
            int num = (*c)-'0';
            // std::cout << num << std::endl;
            bank.push_back(num);
        }
        batteries.push_back(bank);
    }

    uint64_t max_joltage = 0;

    for(auto bat=batteries.begin(); bat!=batteries.end(); ++bat)
    {
        auto max1 = std::max_element((*bat).begin(),(*bat).end()-1);
        auto max2 = std::max_element(max1+1, (*bat).end());
        int batJoltage = (*max1)*10+(*max2);
        // std::cout << batJoltage << std::endl;
        max_joltage += batJoltage;
    }

    std::cout << "Part1: " << max_joltage << std::endl;

    max_joltage = 0;

    for(auto bat=batteries.begin(); bat!=batteries.end(); ++bat)
    {
        uint64_t batJoltage = 0;
        auto max = bat->begin();
        max = std::max_element(max ,bat->end()-(11));
        batJoltage += *max*std::pow(10, 11);
        for(int i=11; i>0; i--)
        {
            max = std::max_element(max+1 ,bat->end()-(i-1));
            // std::cout << *max << std::endl;
            batJoltage += *max*std::pow(10, i-1);
        }
        // std::cout << batJoltage << std::endl;
        max_joltage += batJoltage;
    }
    std::cout << "Part2: " << max_joltage << std::endl;
    return 0;
}