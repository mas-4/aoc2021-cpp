//
// Created by Michael Sendker on 8/24/22.
//

#include "aoc07.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

void aoc07::read_input()
{
    std::ifstream input("input/aoc07.txt");
    if (!input.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(input, line))
    {
        // split on commas
        std::stringstream ss(line);
        std::string token;
        while (std::getline(ss, token, ','))
        {
            m_data.push_back(std::stoi(token));
        }
    }

}

aoc07::aoc07()
{
    read_input();
}

aoc07::~aoc07() = default;

void aoc07::part1()
{
    std::sort(m_data.begin(), m_data.end());
    size_t mid = m_data.size() / 2;
    uint64_t median = m_data[mid];
    uint64_t total = 0;
    for (unsigned int i: m_data)
    {
        total += abs((int)i - (int)median);
    }
    std::cout << "AoC 07.1: " << total << std::endl;
}

uint64_t fuel_expenditure(std::vector<uint32_t> *crabs, size_t k) {
    uint64_t sum = 0;
    for (auto &i : *crabs)
    {
        int diff = static_cast<int>(i) - static_cast<int>(k);
        uint64_t sqr = diff * diff;
        sum += (sqr + abs(diff)) / 2;
    }
    return sum;
}

void aoc07::part2()
{
    uint64_t total = 0;
    for (unsigned int i: m_data)
    {
        total += i;
    }
    double mean = (double)total / (double)m_data.size();
    uint64_t left = floor(mean);
    uint64_t right = ceil(mean);
    left = fuel_expenditure(&m_data, left);
    right = fuel_expenditure(&m_data, right);
    uint64_t ans = left < right ? left : right;
    std::cout << "AoC 07.2: " << ans << std::endl;
}

void aoc07_1()
{
    aoc07 a;
    a.part1();
}


void aoc07_2()
{
    aoc07 a;
    a.part2();
}
