#include "grade.hpp"
#include <stdexcept>
#include "median.hpp"
#include "Student.hpp"

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, std::vector<double> homeworks)
{
    if (homeworks.empty())
    {
        throw std::domain_error("Student has not done any homework!");
    }
    return grade(midterm, final, median(homeworks));
}

double grade(const Student& student)
{
    return grade(student.midterm, student.final, student.homeworks);
}