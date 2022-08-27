//
// Created by Michael Sendker on 8/25/22.
//

#include "aoc09.h"
#include <fstream>
#include <iostream>

void aoc09::readInput()
{
    std::ifstream input("input/aoc09.txt");
    std::string line;
    int len = -1;
    while (std::getline(input, line))
    {
        std::vector<uint8_t> row;
        if (len > 0)
        { row.reserve(len); }
        for (char c: line)
        {
            row.push_back(std::stoi(std::string(1, c)));
        }
        len = (int) row.size();
        m_grid.push_back(row);
    }
}

aoc09::aoc09()
{
    readInput();
}

void print_point(const std::vector<std::vector<uint8_t>> &grid , size_t y, size_t x)
{
    // above
    if (y > 0) {
        std::cout << "_" << (int) grid[y - 1][x] << "_" << std::endl;
    } else {
        std::cout << "___" << std::endl;
    }
    if (x > 0) {
        std::cout << (int) grid[y][x - 1];
    } else {
        std::cout << "_";
    }
    std::cout << (int) grid[y][x];
    if (x < grid[y].size() - 1) {
        std::cout << (int) grid[y][x + 1] << std::endl;
    } else {
        std::cout << "_" << std::endl;
    }
    // below
    if (y < grid.size() - 1) {
        std::cout << "_" << (int) grid[y + 1][x] << "_" << std::endl;
    } else {
        std::cout << "___" << std::endl;
    }
    std::cout << std::endl;
}

void aoc09::part1()
{
    size_t total_risk = 0;
    for (size_t y = 0; y < m_grid.size(); y++)
    {
        for (size_t x = 0; x < m_grid[y].size(); x++)
        {
            bool is_lowpoint = true;
            size_t level = m_grid[y][x];
            // up
            if (y > 0 && m_grid[y - 1][x] <= level)
            {
                is_lowpoint = false;
            }
            // down
            if ((y < m_grid.size() - 1) && m_grid[y + 1][x] <= level)
            {
                is_lowpoint = false;
            }
            // left
            if (x > 0 && m_grid[y][x - 1] <= level)
            {
                is_lowpoint = false;
            }
            // right
            if ((x < m_grid[y].size() - 1) && m_grid[y][x + 1] <= level)
            {
                is_lowpoint = false;
            }
            if (is_lowpoint)
            {
                total_risk += level + 1;
            }
        }
    }
    std::cout << "AoC 09.1: " << total_risk << std::endl;
}

void aoc09::part2()
{
    std::vector<std::tuple<size_t, size_t>> stack;
    std::vector<std::tuple<size_t, size_t>> seen;
    for (size_t y = 0; y < m_grid.size(); y++)
    {
        for (size_t x = 0; x < m_grid[y].size(); x++)
        {
            if (std::find(seen.begin(), seen.end(), std::tuple<size_t, size_t>(y, x)) == seen.end())
            {
                continue;
            }
            stack.emplace_back(std::tuple<size_t, size_t>(y, x));
            while (!stack.empty()) {
                auto point = stack.back();
                stack.pop_back();
                seen.emplace_back(point);
                size_t y1 = std::get<0>(point);
                size_t x1 = std::get<1>(point);
                // up
                if (y1 > 0 && m_grid[y1 - 1][x1] < m_grid[y1][x1] && std::find(seen.begin(), seen.end(), std::tuple<size_t, size_t>(y1 - 1, x1)) == seen.end())
                {
                    stack.emplace_back(std::tuple<size_t, size_t>(y1 - 1, x1));
                }
                // down
                if ((y1 < m_grid.size() - 1) && m_grid[y1 + 1][x1] < m_grid[y1][x1] && std::find(seen.begin(), seen.end(), std::tuple<size_t, size_t>(y1 + 1, x1)) == seen.end())
                {
                    stack.emplace_back(std::tuple<size_t, size_t>(y1 + 1, x1));
                }
                // left
                if (x1 > 0 && m_grid[y1][x1 - 1] < m_grid[y1][x1] && std::find(seen.begin(), seen.end(), std::tuple<size_t, size_t>(y1, x1 - 1)) == seen.end())
                {
                    stack.emplace_back(std::tuple<size_t, size_t>(y1, x1 - 1));
                }
                // right
                if ((x1 < m_grid[y1].size() - 1) && m_grid[y1][x1 + 1] < m_grid[y1][x1] && std::find(seen.begin(), seen.end(), std::tuple<size_t, size_t>(y1, x1 + 1)) == seen.end())
                {
                    stack.emplace_back(std::tuple<size_t, size_t>(y1, x1 + 1));
                }
            }
        }
    }



}
