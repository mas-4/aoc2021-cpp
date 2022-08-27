//
// Created by Michael Sendker on 8/25/22.
//

#include "aoc08.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

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
        {
            std::sort(word.begin(), word.end());
            left_words.push_back(word);
        }

        // right word parsing
        while (std::getline(right_stream, word, ' '))
        {
            if (!word.empty())
            {
                std::sort(word.begin(), word.end());
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
    for (const auto &output: m_outputs)
    {
        for (const auto &segment: output)
        {
            size_t seg_size = segment.size();
            //          1                4                7                8
            if (seg_size == 2 || seg_size == 4 || seg_size == 3 || seg_size == 7)
            {
                count++;
            }
        }
    }
    std::cout << "AoC 08.1: " << count << std::endl;
}

size_t get_idx_of_size(const std::vector<std::string> &words, size_t size)
{
    for (size_t i = 0; i < words.size(); i++)
    {
        if (words[i].size() == size)
        {
            return i;
        }
    }
    std::cerr << "Error: no word of size " << size << " found" << std::endl;
    exit(1);
}

std::string get_contains(const std::vector<std::string> &words, const std::string &word)
{
    for (const auto & i : words)
    {
        bool contains = true;
        for (const auto & j : word)
        {
            if (i.find(j) == std::string::npos)
            {
                contains = false;
            }
        }
        if (contains)
        {
            return i;
        }
    }
    std::cerr << "error: no digits contain " << word << "." << std::endl;
    exit(1);
}

std::string get_not_contains(const std::vector<std::string> &words, const std::string &word)
{
    for (const auto &i : words)
    {
        bool contains = true;
        for (const auto &j : word)
        {
            if (i.find(j) == std::string::npos)
            {
                contains = false;
                break;
            }
        }
        if (!contains)
        {
            return i;
        }
    }
    std::cerr << "error: all digits contain " << word << "." << std::endl;
    exit(1);
}

char get_elements_not_contained(const std::string &superset, const std::string &subset)
{
    for (const auto & i : superset)
    {
        if (subset.find(i, 0) == std::string::npos)
        {
            return i;
        }
    }
    std::cerr << "error: no elements from " << superset << " not contained in " << subset << "." << std::endl;
    exit(1);
}

void aoc08::run_part2()
{
    size_t sum = 0;
    for (size_t i = 0; i < m_inputs.size(); i++)
    {
        const auto &input = m_inputs[i];
        std::string one = input[get_idx_of_size(input, 2)];
        std::string four = input[get_idx_of_size(input, 4)];
        std::string seven = input[get_idx_of_size(input, 3)];
        std::string eight = input[get_idx_of_size(input, 7)];
        // _, 1, _, _, 4, _, _, 7, 8, _

        // numbers with 5 segments: (2, 3, 5)
        std::vector<std::string> five_segs;
        std::copy_if(
                input.begin(),
                input.end(),
                std::back_inserter(five_segs),
                [](const std::string &seg)
                { return seg.size() == 5; });
        // of (2, 3, 5) only 3 contains 1
        std::string three = get_contains(five_segs, one);
        // _, 1, _, 3, 4, _, _, 7, 8, _
        // remove 3
        std::vector<std::string> five_segs_without_three;
        std::copy_if(
                five_segs.begin(),
                five_segs.end(),
                std::back_inserter(five_segs_without_three),
                [&three](const std::string &seg)
                { return seg != three; });

        // numbers with 6 segments: (0, 6, 9)
        std::vector<std::string> six_segs;
        std::copy_if(
                input.begin(),
                input.end(),
                std::back_inserter(six_segs),
                [](const std::string &seg)
                { return seg.size() == 6; });
        // among (0, 6, 9) only 6 does not contain 1
        std::string six = get_not_contains(six_segs, one);
        // _, 1, _, 3, 4, _, 6, 7, 8, _
        // remove 6
        std::vector<std::string> six_segs_without_six;
        std::copy_if(
                six_segs.begin(),
                six_segs.end(),
                std::back_inserter(six_segs_without_six),
                [&six](const std::string &seg)
                { return seg != six; });
        // segment c is the only segment contained by three but not six
        char c = get_elements_not_contained(three, six);
        // of (2, 5) only 2 contains c
        std::string two = get_contains(five_segs_without_three, std::string(1, c));
        std::string five = get_not_contains(five_segs_without_three, std::string(1, c));
        // _, 1, 2, 3, 4, 5, 6, 7, 8, _

        // segment e is the only segment contained by six but not five
        char e = get_elements_not_contained(six, five);
        // of (0, 9) only 0 contains e
        std::string zero = get_contains(six_segs_without_six, std::string(1, e));
        std::string nine = get_not_contains(six_segs_without_six, std::string(1, e));
        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

        std::vector<std::string> numbers = {zero, one, two, three, four, five, six, seven, eight, nine};
        uint64_t output_number = 0;
        const std::vector<std::string> *outputs = &m_outputs[i];
        for (size_t j = 0; j < outputs->size(); j++)
        {
            size_t magnitude = outputs->size() - j - 1;
            size_t digit = std::distance(numbers.begin(), std::find(numbers.begin(), numbers.end(), outputs->at(j)));
            output_number += digit * (uint64_t) std::pow(10, magnitude);
        }
        sum += output_number;
    }
    std::cout << "AoC 08.2: " << sum << std::endl;
}
