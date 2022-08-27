//
// Created by mas on 8/20/22.
//

#include "aoc04.h"
#include <fstream>
#include <iostream>
#include <sstream>

void aoc04::readInput()
{
    std::ifstream input("input/aoc04.txt");
    if (!input.is_open())
    {
        std::cout << "Could not open input file" << std::endl;
        exit(1);
    }
    std::stringstream buffer;
    buffer << input.rdbuf();
    input.close();
    std::string content = buffer.str();
    std::string numbers_to_call = content.substr(0, content.find("\n\n"));
    std::string boards = content.substr(numbers_to_call.size() + 2); // 2 for double new line
    size_t start = 0;
    size_t end;
    while ((end = numbers_to_call.find(',', start)) != std::string::npos)
    {
        m_numbers.push_back(std::stoi(numbers_to_call.substr(start, end - start)));
        start = end + 1;
    }
    m_numbers.push_back(std::stoi(numbers_to_call.substr(start)));
    start = 0;
    while ((end = boards.find("\n\n", start)) != std::string::npos)
    {
        Board board(boards.substr(start, end - start));
        m_boards.push_back(board);
        start = end + 2;
    }
    m_boards.emplace_back(Board(boards.substr(start)));
}

aoc04::aoc04()
{ readInput(); }

Board::Board(const std::string &input)
{
    // line length = 14 = nn nn nn nn nn
    m_data.resize(5 * 5);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            size_t str_start = ((i * BLOCK_SIZE) + j) * 3;
            m_data[(i * BLOCK_SIZE) + j] = std::stoi(input.substr(str_start, 3));
        }
    }
    m_marked.resize(m_data.size(), false);
}

[[maybe_unused]]
void Board::print()
{
    // prints the board for debug, red means marked
    for (size_t i = 0; i < BLOCK_SIZE; i++)
    {
        for (size_t j = 0; j < BLOCK_SIZE; j++)
        {
            size_t idx = (i * BLOCK_SIZE) + j;
            if (m_data[idx] < 10)
            { std::cout << " "; }
            if (m_marked[idx])
            { std::cout << "\033[31m"; }
            else
            { std::cout << "\033[0m"; }
            std::cout << m_data[idx] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void Board::mark(uint16_t number)
{
    int marked = -1;
    for (size_t i = 0; i < m_data.size(); i++)
    {
        if (m_data[i] == number)
        {
            m_marked[i] = true;
            marked = (int) i;
        }
    }
    if (marked >= 0)
    {
        size_t row = marked / BLOCK_SIZE;
        size_t col = marked % BLOCK_SIZE;
        // check row all marked
        m_won = true;
        for (size_t i = 0; i < BLOCK_SIZE; i++)
        {
            if (!m_marked[(row * BLOCK_SIZE) + i])
            {
                m_won = false;
                break;
            }
        }
        if (m_won)
        { return; }
        // check col all marked
        m_won = true;
        for (size_t i = 0; i < BLOCK_SIZE; i++)
        {
            if (!m_marked[(i * BLOCK_SIZE) + col])
            {
                m_won = false;
                break;
            }
        }
        if (m_won)
        { return; }
        // check diag all marked
        if (row == col)
        {
            m_won = true;
            for (size_t i = 0; i < BLOCK_SIZE; i++)
            {
                if (!m_marked[(i * BLOCK_SIZE) + i])
                {
                    m_won = false;
                    break;
                }
            }
        }
    }
}

uint64_t Board::score()
{
    uint64_t score = 0;
    for (size_t i = 0; i < m_data.size(); i++)
    {
        if (!m_marked[i])
        {
            score += m_data[i];
        }
    }
    return score;
}

Board::~Board()
= default;


void aoc04::part1()
{
    size_t winner = 0;
    uint16_t winning_number = 0;
    for (unsigned short number: m_numbers)
    {
        for (size_t j = 0; j < m_boards.size(); j++)
        {
            m_boards[j].mark(number);
            if (m_boards[j].won())
            {
                winner = j;
                winning_number = number;
                goto outer;
            }
        }
    }
    outer:
    std::cout << "AoC 04.1: " << winning_number * m_boards[winner].score() << std::endl;
}

void aoc04::part2()
{
    uint16_t winning_number = 0;
    size_t last_winner = 0;
    for (unsigned short number: m_numbers)
    {
        for (size_t i = 0; i < m_boards.size(); i++)
        {
            if (!m_boards[i].won())
            {

                m_boards[i].mark(number);
                if (m_boards[i].won())
                {
                    last_winner = i;
                    winning_number = number;
                }
            }
        }
    }
    std::cout << "AoC 04.2: " << winning_number * m_boards.at(last_winner).score() << std::endl;
}