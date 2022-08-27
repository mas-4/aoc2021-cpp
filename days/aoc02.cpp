//
// Created by mas on 8/7/22.
//

#include "aoc02.h"
#include <fstream>
#include <iostream>

void aoc02::parseInput()
{
    // open file
    std::ifstream file("input/aoc02.txt");
    if (!file.is_open())
    {
        std::cout << "Could not open file" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t space = line.find(' ');
        std::string direction = line.substr(0, space);
        std::string steps = line.substr(space + 1);
        instruction inst{};
        if (direction == "up")
        {
            inst.dir = UP;
        } else if (direction == "down")
        {
            inst.dir = DOWN;
        } else if (direction == "forward")
        {
            inst.dir = FORWARD;
        }
        inst.steps = std::stoi(steps);
        instructions.push_back(inst);
    }
}

aoc02::aoc02()
{
    parseInput();
}

void aoc02::part1()
{
    uint64_t pos = 0;
    uint64_t depth = 0;
    for (auto &inst: instructions)
    {
        switch (inst.dir)
        {
            case UP:
                depth -= inst.steps;
                break;
            case DOWN:
                depth += inst.steps;
                break;
            case FORWARD:
                pos += inst.steps;
                break;
        }
    }

    std::cout << "AoC 02.1: " << pos * depth << std::endl;
}

void aoc02::part2()
{
    uint64_t pos = 0;
    uint64_t depth = 0;
    uint64_t aim = 0;
    for (auto &inst: instructions)
    {
        switch (inst.dir)
        {
            case UP:
            {
                aim -= inst.steps;
                break;
            }
            case DOWN:
            {
                aim += inst.steps;
                break;
            }
            case FORWARD:
            {
                pos += inst.steps;
                depth += inst.steps * aim;
                break;
            }
        }
    }
    std::cout << "AoC 02.2: " << depth * pos << std::endl;
}