// Exercise 7.4
// The output produced by the cross-reference program will be ungainly if the input file is large.
// Rewrite the program to break up the output if the lines get too long.

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

        std::cout << iter->first << " occurs on line(s): " << std::endl;

        const auto& lines = iter->second;
        std::cout << lines.front();

        for (std::vector<unsigned>::size_type i = 1; i != lines.size(); ++i)
        {
            constexpr auto maxLineSize = 10;
            std::cout << ", ";
            if (i % maxLineSize == 0)
            {
                std::cout << std::endl;
            }
            std::cout << lines[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
