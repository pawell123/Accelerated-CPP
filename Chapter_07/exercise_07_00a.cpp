// Exercise 7.0a
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, unsigned> counters;

    std::string word;
    while (std::cin >> word)
    {
        ++counters[word];
    }

    for (const auto& item : counters)
    {
        std::cout << item.first << '\t' << item.second << std::endl;
    }

    return 0;
}
