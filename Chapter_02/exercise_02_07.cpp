// Exercise 2.7
// Write a program to count down from 10 to -5.

#include <iostream>

int main()
{
    for (int i = 10; i != -6; --i)
    {
        std::cout << i << '\n';
    }
    std::cout << std::flush;

    return 0;
}
