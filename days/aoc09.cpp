//
// Created by Michael Sendker on 8/25/22.
//

#include "aoc09.h"
#include <fstream>
#include <iostream>
#include <algorithm>

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

[[maybe_unused]]
void print_point(const std::vector<std::vector<uint8_t>> &grid, size_t y, size_t x)
{
    // above
    if (y > 0)
    {
        std::cout << "_" << (int) grid[y - 1][x] << "_" << std::endl;
    } else
    {
        std::cout << "___" << std::endl;
    }
    if (x > 0)
    {
        std::cout << (int) grid[y][x - 1];
    } else
    {
        std::cout << "_";
    }
    std::cout << (int) grid[y][x];
    if (x < grid[y].size() - 1)
    {
        std::cout << (int) grid[y][x + 1] << std::endl;
    } else
    {
        std::cout << "_" << std::endl;
    }
    // below
    if (y < grid.size() - 1)
    {
        std::cout << "_" << (int) grid[y + 1][x] << "_" << std::endl;
    } else
    {
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

bool is_lowpoint(const std::vector<std::vector<uint8_t>> &grid, size_t y, size_t x)
{
    // above
    if (y > 0 && grid[y - 1][x] <= grid[y][x])
    {
        return false;
    }
    // down
    if (y < grid.size() - 1 && grid[y + 1][x] <= grid[y][x])
    {
        return false;
    }
    // left
    if (x > 0 && grid[y][x - 1] <= grid[y][x])
    {
        return false;
    }
    // right
    if (x < grid[y].size() - 1 && grid[y][x + 1] <= grid[y][x])
    {
        return false;
    }
    return true;
}

void aoc09::part2()
{
    const size_t max_level = 9;
    std::vector<std::pair<size_t, size_t>> stack;
    std::vector<std::pair<size_t, size_t>> seen;
    std::vector<size_t> sizes;
    for (size_t y = 0; y < m_grid.size(); y++)
    {
        for (size_t x = 0; x < m_grid[y].size(); x++)
        {
            auto current_pair = std::pair<size_t, size_t>(x, y);
            if (std::find(seen.begin(), seen.end(), current_pair) != seen.end())
            {
                continue;
            }
            if (m_grid[y][x] == 9)
            {
                seen.push_back(current_pair);
                continue;
            }
            if (!is_lowpoint(m_grid, y, x))
            {
                continue;
            }
            stack.push_back(current_pair);
            size_t current_size = 0;
            while (!stack.empty())
            {
                auto point = stack.back();
                stack.pop_back();
                if (std::find(seen.begin(), seen.end(), point) != seen.end())
                {
                    continue;
                }
                seen.push_back(point);
                auto [x1, y1] = point;
                current_size++;
                uint8_t depth = m_grid[y1][x1];
                // up
                auto up = std::pair<size_t, size_t>(x1, y1 - 1);
                auto down = std::pair<size_t, size_t>(x1, y1 + 1);
                auto left = std::pair<size_t, size_t>(x1 - 1, y1);
                auto right = std::pair<size_t, size_t>(x1 + 1, y1);
                if (
                        y1 > 0
                        && m_grid[y1 - 1][x1] < max_level
                        && m_grid[y1 - 1][x1] > depth)
                {
                    stack.emplace_back(up);
                }
                // down
                if (
                        y1 < m_grid.size() - 1
                        && m_grid[y1 + 1][x1] < max_level
                        && m_grid[y1 + 1][x1] > depth)
                {
                    stack.emplace_back(down);
                }
                // left
                if (
                        x1 > 0
                        && m_grid[y1][x1 - 1] < max_level
                        && m_grid[y1][x1 - 1] > depth)
                {
                    stack.emplace_back(std::pair<size_t, size_t>(left));
                }
                // right
                if (
                        x1 < m_grid[y1].size() - 1
                        && m_grid[y1][x1 + 1] < max_level
                        && m_grid[y1][x1 + 1] > depth)
                {
                    stack.emplace_back(right);
                }
            }
            sizes.push_back(current_size);
        }
    }
    std::sort(sizes.rbegin(), sizes.rend());
    std::cout << "AoC 09.2: " << sizes[0] * sizes[1] * sizes[2] << std::endl;
}
