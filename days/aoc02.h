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
    uint64_t part1();
    uint64_t part2();
};

void aoc02_1();
void aoc02_2();


#endif //AOC21CPP_AOC02_H
