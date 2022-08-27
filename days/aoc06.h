//
// Created by Michael Sendker on 8/24/22.
//

#ifndef AOC21CPP_AOC06_H
#define AOC21CPP_AOC06_H

#include <vector>
#include <cstdint>


class aoc06
{
private:
    void read_input();
    std::vector<uint8_t> m_data;
public:
    aoc06();
    ~aoc06();
    void part1();
    void part2();
};


#endif //AOC21CPP_AOC06_H