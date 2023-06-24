// Exercise 7.8
// Change the cross-reference program to find all the URLs in a file, and write all the lines on which each distinct URL occurs.

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../common/findUrls.hpp"
#include "../common/split.hpp"
#include "common/xref.hpp"

int main()
{
    const auto ref = xref(std::cin, findUrls);

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
