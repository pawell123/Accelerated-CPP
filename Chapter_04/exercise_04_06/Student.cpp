#include "Student.hpp"
#include <iostream>
#include <stdexcept>
#include "../grade.hpp"

bool compare(const Student& lhs, const Student& rhs)
{
    return lhs.name < rhs.name;
}

std::istream& readHomeworks(std::istream& in, std::vector<double>& homeworks)
{
    if (in)
    {
        homeworks.clear();

        double homework;
        while (in >> homework)
        {
            homeworks.push_back(homework);
        }
        in.clear();
    }
    return in;
}

std::istream& read(std::istream& in, Student& student)
{
    double midterm{};
    double final{};
    in >> student.name >> midterm >> final;

    std::vector<double> homeworks;
    readHomeworks(in, homeworks);

    try
    {
        student.finalGrade = grade(midterm, final, homeworks);
    }
    catch (const std::domain_error& exception)
    {
        student.finalGrade = grade(midterm, final, 0.0);
    }
    return in;
}
