// Exercise 7.7
// Change the driver for the cross-reference program so that it writes line if there is only one line and lines otherwise.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../common/split.hpp"
#include "common/xref.hpp"

int main()
{
    const auto ref = xref(std::cin);

    for (std::map<std::string, std::vector<unsigned>>::const_iterator iter = ref.cbegin(); iter != ref.cend(); ++iter)
    {
        if (iter->second.size() == 1)
        {
            std::cout << iter->first << " occurs on line: ";
        }
        else
        {
            std::cout << iter->first << " occurs on lines: ";
        }

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
