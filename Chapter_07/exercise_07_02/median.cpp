#include "median.hpp"
#include <algorithm>
#include <stdexcept>

double median(std::vector<double> vec)
{
    if (vec.empty())
    {
        throw std::domain_error("Median of the empty set!");
    }

    std::sort(vec.begin(), vec.end());

    std::vector<double>::size_type mid = vec.size() / 2;
    return (vec.size() % 2) ? (vec[mid-1] + vec[mid]) / 2 : vec[mid];
}