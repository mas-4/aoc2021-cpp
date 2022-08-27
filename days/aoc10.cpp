//
// Created by mas on 8/27/22.
//

#include "aoc10.h"
#include <fstream>
#include <iostream>
#include <algorithm>


void aoc10::readInput()
{
    std::ifstream input("input/aoc10.txt");
    if (!input.is_open())
    {
        std::cerr << "Could not open input file" << std::endl;
        exit(1);
    }
    while (!input.eof())
    {
        std::string line;
        std::getline(input, line);
        m_data.push_back(line);
    }
}

aoc10::aoc10()
{
    readInput();
}

char get_matching(const char &c)
{
    switch (c)
    {
        case '{':
            return '}';
        case '(':
            return ')';
        case '[':
            return ']';
        case '<':
            return '>';
        default:
        {
            std::cerr << "Invalid character: " << c << std::endl;
            exit(1);
        }
    }
}

void aoc10::part1()
{
    size_t score = 0;
    for (const auto &line: m_data)
    {
        std::vector<char> stack;
        for (const auto &c: line)
        {
            switch (c)
            {
                case '{':
                case '(':
                case '[':
                case '<':
                    stack.push_back(c);
                    break;
                case '}':
                case ')':
                case ']':
                case '>':
                    if (get_matching(stack.back()) != c)
                    {
                        switch (c)
                        {
                            case '}':
                                score += 1197;
                                break;
                            case ')':
                                score += 3;
                                break;
                            case ']':
                                score += 57;
                                break;
                            case '>':
                                score += 25137;
                                break;
                            default:
                                std::cerr << "Invalid character: " << c << std::endl;
                                exit(1);
                        }
                    }
                    stack.pop_back();
                    break;
                default:
                    std::cerr << "Invalid character: " << c << std::endl;
                    exit(1);
            }
        }
    }
    std::cout << "AoC 10.1: " << score << std::endl;

}

void aoc10::part2()
{
    std::vector<size_t> scores;
    size_t score = 0;
    for (const auto &line: m_data)
    {
        std::vector<char> stack;
        for (const auto &c: line)
        {
            switch (c)
            {
                case '{':
                case '(':
                case '[':
                case '<':
                    stack.push_back(c);
                    break;
                case '}':
                case ')':
                case ']':
                case '>':
                    if (get_matching(stack.back()) != c)
                    {
                        goto cnt; // skip this line
                    }
                    stack.pop_back();
                    break;
                default:
                    std::cerr << "Invalid character: " << c << std::endl;
                    exit(1);
            }
        }
        score = 0;
        while (!stack.empty())
        {
            score *= 5;
            switch (get_matching(stack.back()))
            {
                case ')':
                    score += 1;
                    break;
                case ']':
                    score += 2;
                    break;
                case '}':
                    score += 3;
                    break;
                case '>':
                    score += 4;
                    break;
            }
            stack.pop_back();
        }
        scores.push_back(score);
        cnt:;
    }
    std::sort(scores.begin(), scores.end());
    size_t middle = scores.size() / 2;
    std::cout << "AoC 10.2: " << scores[middle] << std::endl;
}