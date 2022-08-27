//
// Created by mas on 8/27/22.
//

#include "aoc11.h"

#include <string>
#include <iostream>

#define SIDE 10

const char *const input = R""""(
6227618536
2368158384
5385414113
4556757523
6746486724
4881323884
4648263744
4871332872
4724128228
4316512167
)"""";

void print_grid(const std::vector<unsigned int> &grid, const std::vector<bool> &flashed)
{
    for (size_t y = 0; y < SIDE; ++y)
    {
        for (size_t x = 0; x < SIDE; ++x)
        {
            size_t idx = y * SIDE + x;
            if (flashed[idx]) {
                // change console color to red
                std::cout << "\033[1;31m";
            }
            size_t val = grid[idx];
            if (val < 10)
            {
                std::cout << " ";
            }
            std::cout << " " << val;
            // change console color to default
            std::cout << "\033[0m";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void aoc11::parseInput()
{
    std::string tmp(input);
    m_data.reserve(SIDE * SIDE);
    for (const char &c : tmp)
    {
        if (c == '\n')
            continue;
        size_t val = c - '0';
        m_data.push_back(val);
    }
}

aoc11::aoc11()
{
    parseInput();
}

size_t flash(std::vector<unsigned int> &grid, std::vector<bool> &flashed)
{
    size_t flashes = 0;
    for (size_t y = 0; y < SIDE; y++) {
        for (size_t x = 0; x < SIDE; x++) {
            size_t idx = y * SIDE + x;
            if (grid[idx] > 9 && !flashed[idx]) {
                flashes++;
                flashed[idx] = true;
                for (int radd = -1; radd < 2; radd++) {
                    for (int cadd = -1; cadd < 2; cadd++) {
                        if (radd == 0 && cadd == 0)
                            continue;
                        int r = (int)y + radd;
                        int c = (int)x + cadd;
                        if (r >= 0 && r < SIDE && c >= 0 && c < SIDE) {
                            size_t i = r * SIDE + c;
                            grid[i] ++;
                        }
                    }
                }
            }
        }
    }
    return flashes;
}

void aoc11::part1()
{
    std::vector<unsigned int> grid;
    grid.resize(m_data.size());
    for (size_t i = 0; i < m_data.size(); i++)
    {
        grid[i] = m_data[i];
    }
    size_t flashes = 0;
    for (size_t _ = 0; _ < 100; _++)
    {
        for (unsigned int & j : grid) j++;
        std::vector<bool> flashed(grid.size(), false);
        while (true)
        {
            size_t flashes_this_step = flash(grid, flashed);
            flashes += flashes_this_step;
            if (flashes_this_step == 0)
                break;
        }
        for (size_t j = 0; j < flashed.size(); j++)
        {
            if (flashed[j])
                grid[j] = 0;
        }
    }
    std::cout << "AoC 11.1: " << flashes << std::endl;
}

void aoc11::part2()
{

}