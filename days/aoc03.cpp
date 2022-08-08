//
// Created by mas on 8/7/22.
//

#include "aoc03.h"
#include <fstream>
#include <iostream>

void aoc03::readInput()
{
    std::ifstream input("input/aoc03.txt");
    if (!input.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(input, line))
    {
        std::bitset<12> bs(line);
        data.push_back(bs);
    }
}

aoc03::aoc03()
{
    readInput();
}

uint64_t aoc03::part1()
{
    std::bitset<12> gamma_rate, epsilon_rate;
    for (size_t i = 0; i < 12; i++)
    {
        int zeros = 0;
        int ones = 0;
        for (auto &bs: data)
        {
            if (bs[i])
            {
                ones++;
            } else
            {
                zeros++;
            }
        }
        gamma_rate[i] = (ones > zeros);
    }
    epsilon_rate = std::bitset<12>(gamma_rate).flip();
    return epsilon_rate.to_ulong() * gamma_rate.to_ulong();
}

uint64_t aoc03::part2()
{
    std::vector<std::bitset<12>> o2set(data);
    std::vector<std::bitset<12>> co2set(data);
    // no idea why we have to reverse the iteration of bits here, but it
    // works and forward does not. Presumably because of endianness?
    for (size_t i = 11; i >= 0 && o2set.size() > 1; i--)
    {
        std::vector<std::bitset<12>> filtered[2];
        for (auto &bs: o2set)
        {
            filtered[bs[i]].push_back(bs);
        }
        o2set = filtered[0].size() > filtered[1].size() ? filtered[0] : filtered[1];
    }
    for (size_t i = 11; i >= 0 && co2set.size() > 1; i--)
    {
        std::vector<std::bitset<12>> filtered[2];
        for (auto &bs: co2set)
        {
            filtered[bs[i]].push_back(bs);
        }
        co2set = filtered[0].size() > filtered[1].size() ? filtered[1] : filtered[0];
    }
    ulong o2 = o2set[0].to_ulong();
    ulong co2 = co2set[0].to_ulong();

    return o2 * co2;
}

void aoc03_1()
{
    aoc03 a;
    std::cout << "AoC 3.1: " << a.part1() << std::endl;
}

void aoc03_2()
{
    aoc03 a;
    std::cout << "AoC 3.2: " << a.part2() << std::endl;
}
