// Exercise 7.1
// Extend the program from §7.2/124 to produce its output sorted by occurrence count.
// That is, the output should group all the words that occur once, followed by those that occur twice, and so on.

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, unsigned> counters;

    std::string word;
    while (std::cin >> word)
    {
        ++counters[word];
    }

    std::map<unsigned, std::vector<std::string>> sortedCounters;
    for (const auto& counter : counters)
    {
        sortedCounters[counter.second].push_back(counter.first);
    }

    for (const auto& item : sortedCounters)
    {
        std::cout << "Occurance " << item.first << ':';
        for (const auto& word : item.second)
        {
            std::cout << ' ' << word;
        }
        std::cout << std::endl;
    }

    return 0;
}
