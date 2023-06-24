// Exercise 7.0b
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../common/split.hpp"
#include "common/xref.hpp"     // it contains `xref` function

int main()
{
    const auto ref = xref(std::cin);

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
