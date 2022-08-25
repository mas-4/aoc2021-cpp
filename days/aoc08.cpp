//
// Created by Michael Sendker on 8/25/22.
//

#include "aoc08.h"
#include <fstream>
#include <iostream>
#include <sstream>

void aoc08::readInput()
{
    std::ifstream input("input/aoc08.txt");
    std::string line;
    while (std::getline(input, line))
    {
        // separate on |, left words go to m_inputs, right words go to m_outputs
        std::stringstream ss(line);
        std::string left;
        std::string right;
        std::getline(ss, left, '|');
        std::getline(ss, right);
        std::stringstream left_stream(left);
        std::stringstream right_stream(right);
        std::string word;
        std::vector<std::string> left_words;
        std::vector<std::string> right_words;

        // left word parsing
        while (std::getline(left_stream, word, ' '))
            left_words.push_back(word);

        // right word parsing
        while (std::getline(right_stream, word, ' '))
        {
            if (!word.empty())
            {
                right_words.push_back(word);
            }
        }

        m_inputs.push_back(left_words);
        m_outputs.push_back(right_words);
    }
}

aoc08::aoc08()
{
    readInput();
}

// Known digits: 1: 2, 4: 4, 7: 3, 8: 7

void aoc08::run_part1()
{
    size_t count = 0;
    for (const auto &output : m_outputs) {
        for (const auto &segment : output) {
            size_t seg_size = segment.size();
                //          1                4                7                8
            if (seg_size == 2 || seg_size == 4 || seg_size == 3 || seg_size == 7)
                count++;
        }
    }
    std::cout << "AoC 08.1: " << count << std::endl;
}

void aoc08::run_part2()
{

}
