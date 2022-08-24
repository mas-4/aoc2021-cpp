//
// Created by mas on 8/21/22.
//

#ifndef AOC21CPP_AOC05_H
#define AOC21CPP_AOC05_H

#include <vector>
#include <cstdint>
#include <cstddef>

struct Line {
    size_t x1;
    size_t y1;
    size_t x2;
    size_t y2;
};

class Grid
{
public:
    Grid(): m_grid(10, std::vector<uint64_t>(10, 0)) {}
    void mark_restricted(Line line);
    std::vector<std::vector<uint64_t>> m_grid;
    void print();
};

class aoc05
{
private:
    std::vector<Line> m_lines;
    void readInput();
public:
    aoc05();
    ~aoc05() = default;
    void part1();
    void part2();
};

void aoc05_1();
void aoc05_2();

#endif //AOC21CPP_AOC05_H
