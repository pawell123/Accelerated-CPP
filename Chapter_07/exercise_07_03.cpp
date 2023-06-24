// Exercise 7.3
// The cross-reference program from §7.3/126 could be improved: As it stands, if a word occurs more than once on the same input line,
// the program will report that line multiple times.
// Change the code so that it detects multiple occurrences of the same line number and inserts the line number only once.

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../common/split.hpp"

std::map<std::string, std::vector<unsigned>> xref1(std::istream& in, std::vector<std::string> findWords(const std::string&) = split)
{
    std::map<std::string, std::vector<unsigned>> ret;

    unsigned lineNumber = 0;
    std::string line;
    while (std::getline(in, line))
    {
        const auto& splitted = findWords(line);
        for (const auto& word : splitted)
        {
            if (ret.find(word) == ret.cend() || ret[word].back() != lineNumber)
            {
                ret[word].push_back(lineNumber);
            }
        }
        ++lineNumber;
    }
    return ret;
}

std::map<std::string, std::set<unsigned>> xref2(std::istream& in, std::vector<std::string> findWords(const std::string&) = split)
{
    std::map<std::string, std::set<unsigned>> ret;

    unsigned lineNumber = 0;
    std::string line;
    while (std::getline(in, line))
    {
        const auto& splitted = findWords(line);
        for (const auto& word : splitted)
        {
            ret[word].insert(lineNumber);
        }
        ++lineNumber;
    }
    return ret;
}

int main()
{
    const auto ref = xref1(std::cin);
    //const auto ref = xref2(std::cin);

    for (std::map<std::string, std::vector<unsigned>>::const_iterator iter = ref.cbegin(); iter != ref.cend(); ++iter)
    {

        std::cout << iter->first << " occurs on line(s): ";

        std::vector<unsigned>::const_iterator lineIter = iter->second.cbegin();
        std::cout << *lineIter;
        ++lineIter;

        while (lineIter != iter->second.cend())
        {
            std::cout << ", " << *lineIter;
            ++lineIter;
        }
        std::cout << std::endl;
    }
    return 0;
}
