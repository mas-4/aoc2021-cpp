//
// Created by Michael Sendker on 8/24/22.
//

#ifndef AOC21CPP_AOC07_H
#define AOC21CPP_AOC07_H

#include <vector>
#include <cstdint>


class aoc07
{
private:
    void read_input();
    std::vector<uint32_t> m_data;
public:
    aoc07();
    ~aoc07();
    void part1();
    void part2();
};

#endif //AOC21CPP_AOC07_H
