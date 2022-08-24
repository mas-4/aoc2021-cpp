//
// Created by Michael Sendker on 8/24/22.
//

#include "aoc06.h"
#include <fstream>
#include <iostream>
#include <sstream>

void aoc06::read_input()
{
    std::ifstream input("input/aoc06.txt");
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

aoc06::aoc06()
{
    read_input();

}

uint64_t how_many_fish(uint64_t *fishes, size_t days) {
    for (size_t i = 0; i < days; i++) {
        uint64_t day0fish = fishes[0];
        fishes[0] = fishes[1];
        fishes[1] = fishes[2];
        fishes[2] = fishes[3];
        fishes[3] = fishes[4];
        fishes[4] = fishes[5];
        fishes[5] = fishes[6];
        fishes[6] = fishes[7] + day0fish;
        fishes[7] = fishes[8];
        fishes[8] = day0fish;
    }
    uint64_t total = 0;
    for (size_t i = 0; i < 9; i++) {
        total += fishes[i];
    }
    return total;
}

void aoc06::part1()
{
    uint64_t fishes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (const auto &i : m_data)
    {
        fishes[i]++;
    }
    std::cout << "AoC 6.1: " << how_many_fish(fishes, 80) << std::endl;
}

void aoc06::part2()
{
    uint64_t fishes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (const auto &i : m_data)
    {
        fishes[i]++;
    }
    std::cout << "AoC 6.1: " << how_many_fish(fishes, 256) << std::endl;
}

aoc06::~aoc06() = default;

void aoc06_1()
{
    aoc06 a;
    a.part1();
}

void aoc06_2()
{
    aoc06 a;
    a.part2();
}
