// Exercise 7.2
// Extend the program in §4.2.3/64 to assign letter grades by ranges:
// A 90-100
// B 80-89.99...
// C 70-79.99...
// D 60-69.99...
// F < 60
// The output should list how many students fall into each category.

#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include "grade.hpp"
#include "Student.hpp"

enum class LetterGrade
{
    A,
    B,
    C,
    D,
    F
};

char toChar(LetterGrade letterGrade)
{
    switch(letterGrade)
    {
        case LetterGrade::A : return 'A';
        case LetterGrade::B : return 'B';
        case LetterGrade::C : return 'C';
        case LetterGrade::D : return 'D';
        case LetterGrade::F : return 'F';
    }
    throw std::runtime_error("Unexpected flow");
}

LetterGrade calculateLetterGrade(double grade)
{
    if (grade >= 90)
    {
        return LetterGrade::A;
    }
    if (grade >= 80)
    {
        return LetterGrade::B;
    }
    if (grade >= 70)
    {
        return LetterGrade::C;
    }
    if (grade >= 60)
    {
        return LetterGrade::D;
    }
    return LetterGrade::F;
}

int main()
{
    std::vector<Student> students;

    Student student;
    std::string::size_type nameMaxLength = 0;
    while (read(std::cin, student))
    {
        nameMaxLength = std::max(nameMaxLength, student.name.size());
        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), compare);

    std::cout << std::endl;

    std::map<LetterGrade, unsigned> letterGradeCounters{{LetterGrade::A, 0}, {LetterGrade::B, 0}, {LetterGrade::C, 0}, {LetterGrade::D, 0}, {LetterGrade::F, 0}};
    for (const auto& student: students)
    {
        std::cout << student.name << std::string(nameMaxLength - student.name.size() + 1, ' ');

        try
        {
            const double studentGrade = grade(student);
            ++letterGradeCounters[calculateLetterGrade(studentGrade)];
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << studentGrade << std::setprecision(prec);

        } catch (const std::domain_error& error)
        {
            std::cout << error.what();
        }
        std::cout << std::endl;
    }

    for (const auto& letterGradeCounter : letterGradeCounters)
    {
        std::cout << std::endl << "Grade " << toChar(letterGradeCounter.first) << ": " << letterGradeCounter.second << " student(s)";
    }
    std::cout << std::endl;

    return 0;
}
