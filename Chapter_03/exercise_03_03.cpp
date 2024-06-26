// Exercise 3.3
// Write a program to count how many times each distinct word appears in its input.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> readWords(std::istream& in)
{
    std::vector<std::string> ret;

    std::string word;
    while (in >> word)
    {
        ret.push_back(word);
    }
    return ret;
}

// Version 1
std::vector<std::pair<std::string, int>> countWords1(std::istream& in)
{
    std::vector<std::pair<std::string, int>> ret;

    std::vector<std::string> words = readWords(in);
    if (words.empty())
    {
        return ret;
    }

    std::sort(words.begin(), words.end());

    std::string previousWord;
    unsigned counter = 0;

    for (std::string::size_type i = 0; i != words.size(); ++i)
    {
        const auto& currentWord = words[i];

        if (i == 0 || currentWord == previousWord)
        {
            ++counter;
        }
        else
        {
            ret.emplace_back(std::make_pair(previousWord, counter));
            counter = 1;
        }
        previousWord = currentWord;
    }
    ret.emplace_back(std::make_pair(words.back(), counter));
    return ret;
}

// Version 2 (using std::map)
std::map<std::string, int> countWords2(std::istream& in)
{
    std::map<std::string, int> ret;

    std::string word;
    while (in >> word)
    {
        ++ret[word];
    }
    return ret;
}

int main()
{
    std::cout << "Write words: ";

    const auto wordsCounters = countWords1(std::cin); // countWords2(std::cin)

    for (const auto& item : wordsCounters)
    {
        std::cout << '\n' << item.first << ": " << item.second;
    }
    std::cout << std::endl;

    return 0;
}
