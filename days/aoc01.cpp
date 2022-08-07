//
// Created by mas on 8/7/22.
//

#include <fstream>
#include "aoc01.h"

void aoc01::parseInput()
{
    std::ifstream inputFile("input/aoc01.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        exit(-1);
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        m_input.push_back(std::stoi(line));
    }
}

aoc01::aoc01()
{
    parseInput();
}

uint32_t aoc01::single_increases()
{
    uint32_t increases = 0;
    uint32_t last = m_input.at(0);
    for (size_t i = 1; i < m_input.size(); i++)
    {
        if (m_input.at(i) > last)
        {
            increases++;
        }
        last = m_input.at(i);
    }
    return increases;
}

uint32_t aoc01::window_increases()
{
    uint32_t increases = 0;
    uint32_t first = m_input.at(0);
    uint32_t middle = m_input.at(1);
    uint32_t last = m_input.at(2);
    uint32_t last_window = first + middle + last;
    for (size_t i = 3; i < m_input.size(); i++)
    {
        uint32_t window = m_input.at(i) + middle + last;
        if (window > last_window)
        {
            increases++;
        }
        first = middle;
        middle = last;
        last = m_input.at(i);
        last_window = first + middle + last;
    }
    return increases;
}

void aoc01_1(){
    aoc01 a;
    std::cout << "AoC 1.1: " << a.single_increases() << std::endl;
}

void aoc01_2()
{
    aoc01 a;
    std::cout << "AoC 1.2: " << a.window_increases() << std::endl;
}
