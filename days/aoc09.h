//
// Created by Michael Sendker on 8/25/22.
//

#ifndef AOC21CPP_AOC09_H
#define AOC21CPP_AOC09_H

#include <vector>
#include <cstdint>


class aoc09
{
private:
    std::vector<std::vector<uint8_t>> m_grid;
    void readInput();
public:
    aoc09();
    void part1();
    void part2();
};


#endif //AOC21CPP_AOC09_H
