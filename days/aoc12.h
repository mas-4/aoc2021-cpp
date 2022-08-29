//
// Created by mas on 8/29/22.
//

#ifndef AOC21CPP_AOC12_H
#define AOC21CPP_AOC12_H
#include <vector>
#include <string>
#include <unordered_map>


class aoc12
{
private:
    void read_input();
    std::unordered_map<std::string, std::vector<std::string>> m_graph;

public:
    aoc12();
    void part1();
    void part2();

};


#endif //AOC21CPP_AOC12_H
