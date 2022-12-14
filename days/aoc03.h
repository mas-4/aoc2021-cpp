//
// Created by mas on 8/7/22.
//

#ifndef AOC21CPP_AOC03_H
#define AOC21CPP_AOC03_H

#include <vector>
#include <bitset>


// Credit to https://zachgiaco.com/2021-advent-of-code-day-3/
// for the idea of using a bitset to represent a 12-bit number.
// And other ideas.
class aoc03
{
private:
    std::vector<std::bitset<12>> data;
    void readInput();
public:
    aoc03();
    void part1();
    void part2();
};

#endif //AOC21CPP_AOC03_H
