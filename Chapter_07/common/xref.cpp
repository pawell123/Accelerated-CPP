#include "xref.hpp"
#include <iostream>

std::map<std::string, std::vector<unsigned>> xref(std::istream& in, std::vector<std::string> findWords(const std::string&))
{
    std::map<std::string, std::vector<unsigned>> ret;

    unsigned lineNumber = 0;
    std::string line;
    while (std::getline(in, line))
    {
        const auto& splitted = findWords(line);
        for (const auto& word : splitted)
        {
            ret[word].push_back(lineNumber);
        }
        ++lineNumber;
    }
    return ret;
}
