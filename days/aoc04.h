//
// Created by mas on 8/20/22.
//

#ifndef AOC21CPP_AOC04_H
#define AOC21CPP_AOC04_H
#include <vector>
#include <cstdint>
#include <string>
#define BLOCK_SIZE 5

class Board {
private:
    std::vector<uint16_t> m_data;
    std::vector<bool> m_marked;
    bool m_won = false;
public:
    explicit Board(const std::string &input);
    ~Board();
    void print();
    void mark(uint16_t number);
    [[nodiscard]] bool won() const { return m_won; };
    uint64_t score();
};

class aoc04
{
private:
    std::vector<Board> m_boards;
    std::vector<uint16_t> m_numbers;
    void readInput();
public:
    aoc04();
    uint64_t part1();
    uint64_t part2();
};

void aoc04_1();
void aoc04_2();


#endif //AOC21CPP_AOC04_H
