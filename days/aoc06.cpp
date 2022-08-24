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

void aoc06::part1()
{
    auto *fishes = new uint64_t[9];
    for (const auto &i : m_data)
    {
        fishes[i]++;
    }
    for (size_t i = 0; i < 80; i++) {
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
        for (size_t j = 0; j < 9; j++) {
            std::cout << fishes[j] << " ";
        }
        std::cout << std::endl;
    }
    uint64_t total = 0;
    for (size_t i = 0; i < 9; i++) {
        total += fishes[i];
    }
    std::cout << "AoC 6.1: " << total << std::endl;
}

aoc06::~aoc06() = default;

void aoc06_1()
{
    aoc06 a;
    a.part1();
}