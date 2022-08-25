//
// Created by mas on 8/21/22.
//

#include "aoc05.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Grid::mark(Line line, bool use_diagonal = false)
{
    if (!use_diagonal && line.x1 != line.x2 && line.y1 != line.y2)
    {
        // not marking diagonals
        return;
    }
    size_t x = line.x1;
    size_t y = line.y1;
    while (true)
    {
        // 1. Resize
        if (y >= m_grid.size())
        {
            m_grid.resize(y + 1);
        }
        if (x >= m_grid[y].size())
        {
            m_grid[y].resize(x + 1);
        }

        // 2. Mark
        m_grid[y][x]++;
        if (x == line.x2 && y == line.y2)
        { break; }

        // 3. Increment
        if (x < line.x2)
        {
            x++;
        } else if (x > line.x2)
        {
            x--;
        }
        if (y < line.y2)
        {
            y++;
        } else if (y > line.y2)
        {
            y--;
        }
    }
//    std::cout << "Marked restricted line: " << line.x1 << "," << line.y1 << " -> " << line.x2 << "," << line.y2 << std::endl;
//    print();
}

[[maybe_unused]]
void Grid::print()
{
    for (auto &i: m_grid)
    {
        for (unsigned long j: i)
        {
            if (j == 0)
            {
                std::cout << ".";
            } else
            {
                std::cout << j;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "\n" << std::endl;
    std::cout << "\n" << std::endl;

}

void aoc05::readInput()
{
    std::ifstream input("input/aoc05.txt");
    if (!input.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string x1, y1, x2, y2, _;
        std::getline(ss, x1, ',');
        std::getline(ss, y1, ' ');
        std::getline(ss, _, ' ');  // skip through ' -> '
        std::getline(ss, x2, ',');
        std::getline(ss, y2, '\n');
        m_lines.push_back({std::stoull(x1), std::stoull(y1), std::stoull(x2), std::stoull(y2)});
    }
}

aoc05::aoc05()
{
    readInput();
}

void aoc05::part1()
{
    Grid grid;
    for (auto line: m_lines)
    {
        grid.mark(line);
    }
    size_t count = 0;
    for (const auto &row: grid.m_grid)
    {
        for (auto cell: row)
        {
            if (cell > 1)
            {
                count++;
            }
        }
    }
    std::cout << "AoC 05.1: " << count << std::endl;

}

void aoc05::part2()
{
    Grid grid;
    for (auto line: m_lines)
    {
        grid.mark(line, true);
    }
    size_t count = 0;
    for (const auto &row: grid.m_grid)
    {
        for (auto cell: row)
        {
            if (cell > 1)
            {
                count++;
            }
        }
    }
    std::cout << "AoC 05.2: " << count << std::endl;


}

void aoc05_1()
{
    aoc05 a;
    a.part1();
}

void aoc05_2()
{
    aoc05 a;
    a.part2();
}