// Exercise 6.0c
// Compile, execute, and test the programs in this chapter.

#include <iostream>
#include <string>
#include <vector>
#include "../common/findUrls.hpp" // it contains `findUrls` function

int main()
{
    const std::string text = " http://www.onet.pl invalid ssh://192.168.0.1:8080 :// @://invalid invalid:// invalid://*";

    const auto urls = findUrls(text);

    std::cout << "URLs: " << std::endl;
    for (const auto& url : urls)
    {
        std::cout << url << std::endl;
    }

    return 0;
}
