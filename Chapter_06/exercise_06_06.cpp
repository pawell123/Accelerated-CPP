// Exercise 6.6
// Note that the function from the previous exercise and the functions from §6.2.2/113 and §6.2.3/115 do the same task.
// Merge these three analysis functions into a single function.

#include <algorithm>
#include <iterator>
#include <vector>
#include "Student.hpp"
#include "median.hpp"

double analysis(const std::vector<Student>& students, double analysisMethod(const Student&))
{
    std::vector<double> grades;
    std::transform(students.cbegin(), students.cend(), std::back_inserter(grades), analysisMethod);
    return median(grades);
}
