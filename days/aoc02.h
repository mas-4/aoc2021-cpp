//
// Created by mas on 8/7/22.
//

#ifndef AOC21CPP_AOC02_H
#define AOC21CPP_AOC02_H
#include <vector>
#include <cstdint>

enum Direction {
    UP,
    DOWN,
    FORWARD,
};

struct instruction {
    Direction dir;
    int steps;
};

class aoc02
{
private:
    std::vector<instruction> instructions;
    void parseInput();
public:
    aoc02();
    void part1();
    void part2();
};


#endif //AOC21CPP_AOC02_H
