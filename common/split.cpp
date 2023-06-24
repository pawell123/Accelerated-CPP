#include "split.hpp"
#include <algorithm>
#include <cctype>

std::vector<std::string> split(const std::string& str)
{
    std::vector<std::string> ret;

    constexpr auto isSpace = [](char c) { return std::isspace(c); };

    auto iter1 = str.cbegin();
    while (iter1 != str.cend())
    {
        iter1 = std::find_if_not(iter1, str.cend(), isSpace);
        const auto iter2 = std::find_if(iter1, str.cend(), isSpace);

        if (iter1 != iter2)
        {
            ret.push_back(std::string(iter1, iter2));
            iter1 = iter2;
        }
    }
    return ret;
}
