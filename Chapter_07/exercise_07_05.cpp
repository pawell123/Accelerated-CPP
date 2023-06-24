// Exercise 7.5
// Reimplement the grammar program using a list as the data structure in which we build the sentence.

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include "../common/split.hpp"

using Category = std::string;
using Rule = std::vector<std::string>;
using Grammar = std::map<std::string, std::vector<Rule>>;

int nrand(int n)
{
    if (n < 0 or n> RAND_MAX)
    {
        throw std::domain_error("Arguemnt to nrand is out of range");
    }

    const int bucketSize = RAND_MAX / n;
    int ret;
    do
    {
        ret = std::rand() / bucketSize;
    }
    while (ret >= n);

    return ret;
}

Grammar readGrammar(std::istream& in)
{
    Grammar Grammar;

    std::string line;
    while (std::getline(in, line))
    {
        const auto splittedLine = split(line);
        if (not splittedLine.empty())
        {
            Grammar[splittedLine.front()].push_back(Rule(splittedLine.cbegin()+1, splittedLine.cend()));
        }
    }
    return Grammar;
}

bool isBracketed(const std::string& word)
{
    return word.size() > 1 and word.front() == '<' and word.back() == '>';
}

void generate(const Grammar& grammar, const std::string& word, std::list<std::string>& sentence)
{
    if (not isBracketed(word))
    {
        sentence.push_back(word);
    }
    else
    {
        const auto& iter = grammar.find(word);
        if (iter == grammar.cend())
        {
            throw std::logic_error("empty_rule");
        }
        const auto& rules = iter->second;
        for (const auto& item : rules[nrand(rules.size())])
        {
            generate(grammar, item, sentence);
        }
    }
}

std::list<std::string> generateSentence(const Grammar& Grammar)
{

    std::list<std::string> sentence;
    generate(Grammar, "<sentence>", sentence);
    return sentence;
}

int main()
{
    std::ifstream file("Grammar.txt");

    if (not file)
    {
        std::cerr << "Cannot open the file" << std::endl;
        return 1;
    }
    const Grammar Grammar = readGrammar(file);

    const std::list<std::string> sentence = generateSentence(Grammar);

    if (not sentence.empty())
    {
        auto it = sentence.cbegin();
        std::cout << *it++;

        while (it != sentence.cend())
        {
            std::cout << ' ' << *it++;
        }
        std::cout << std::endl;
    }

    return 0;
}
