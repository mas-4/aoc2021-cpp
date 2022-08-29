//
// Created by mas on 8/29/22.
//

#include "aoc12.h"
#include <sstream>

const char *const input = R""""(
start-kc
pd-NV
start-zw
UI-pd
HK-end
UI-kc
pd-ih
ih-end
start-UI
kc-zw
end-ks
MF-mq
HK-zw
LF-ks
HK-kc
ih-HK
kc-pd
ks-pd
MF-pd
UI-zw
ih-NV
ks-HK
MF-kc
zw-NV
NV-ks
)"""";

void aoc12::read_input()
{
    std::string tmp(input);
    // iterate over lines
    std::string line;
    std::stringstream ss(tmp);
    while (std::getline(ss, line))
    {
        std::stringstream ss2(line);
        std::string from;
        std::string to;
        std::getline(ss2, from, '-');
        std::getline(ss2, to, '\n');
        m_graph[from].push_back(to);
        m_graph[to].push_back(from);
    }

}

aoc12::aoc12()
{
    read_input();
}

void aoc12::part1()
{


}

void aoc12::part2()
{

}
