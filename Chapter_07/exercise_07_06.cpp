// Exercise 7.6
// Reimplement the gen_sentence program using two vectors:
// One will hold the fully unwound, generated sentence, and the other will hold the rules and will be used as a stack.
// Do not use any recursive calls.

#include <fstream>
#include <iostream>
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

void generate(const Grammar& grammar, const std::string& token, std::vector<std::string>& tokens, std::vector<std::string>& sentence)
{
    if (not isBracketed(token))
    {
        sentence.push_back(token);
    }
    else
    {
        const auto& iter = grammar.find(token);
        if (iter == grammar.cend())
        {
            throw std::logic_error("empty_rule");
        }
        const auto& rules = iter->second;
        const auto& rule = rules[nrand(rules.size())];
        for (Rule::const_reverse_iterator iter = rule.crbegin(); iter != rule.crend(); ++iter)
        {
            tokens.push_back(*iter);
        }
    }
}

std::vector<std::string> generateSentence(const Grammar& Grammar)
{
    std::vector<std::string> sentence;
    std::vector<std::string> tokens{"<sentence>"};
    while (not tokens.empty())
    {
        const auto token = tokens.back();
        tokens.pop_back();
        generate(Grammar, token, tokens, sentence);
    }
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

    const std::vector<std::string> sentence = generateSentence(Grammar);

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
