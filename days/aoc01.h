//
// Created by mas on 8/7/22.
//

#ifndef AOC21CPP_AOC01_H
#define AOC21CPP_AOC01_H

#include <vector>
#include <cstdint>
#include <iostream>


class aoc01
{
private:
    std::vector<uint32_t> m_input;
    void parseInput();
public:
    aoc01();
    uint32_t single_increases();
};

void aoc01_1();


#endif //AOC21CPP_AOC01_H
