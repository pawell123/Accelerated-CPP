// Exercise 6.0a
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <string>
#include <vector>
#include "../common/split.hpp" // contains implementation of `split` function

int main()
{
    const std::string str{"This is example sentence"};

    const auto splitted = split(str);

    for (const auto& word : splitted)
    {
        std::cout << word << std::endl;
    }
    return 0;
}
