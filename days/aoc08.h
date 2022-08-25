//
// Created by Michael Sendker on 8/25/22.
//

#ifndef AOC21CPP_AOC08_H
#define AOC21CPP_AOC08_H

#include <vector>
#include <string>


class aoc08
{
private:
    void readInput();
    std::vector<std::vector<std::string>> m_inputs;
    std::vector<std::vector<std::string>> m_outputs;
public:
    aoc08();
    void run_part1();
    void run_part2();
};


#endif //AOC21CPP_AOC08_H
