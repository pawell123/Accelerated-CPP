// Exercise 3.5
// Write a program that will keep track of grades for several students at once.
// The program could keep two vectors in sync: The first should hold the student's names,
// and the second the final grades that can be computed as input is read. For now, you
// should assume a fixed number of homework grades.

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> names;
    std::vector<double> grades;

    while (std::cin)
    {
        std::cout << "\nStudent's name (or EOF): ";
        std::string name;
        if (std::cin >> name)
        {
            names.push_back(name);

            std::cout << "Enter midterm and final exam grades: ";
            double midterm, final;
            std::cin >> midterm >> final;

            constexpr int numberOfHomeworks = 5;
            std::cout << "Enter all your homework grades (" << numberOfHomeworks << "): ";

            std::vector<double> homeworkGrades;

            double homeworkGrade;
            for (int i = 0; i != numberOfHomeworks; ++i)
            {
                std::cin >> homeworkGrade;
                homeworkGrades.push_back(homeworkGrade);
            }

            if (homeworkGrades.empty())
            {
                std::cout << "\nYou must enter grades for " + name + ". Please try again!" << std::endl;
                return 1;
            }

            std::sort(homeworkGrades.begin(), homeworkGrades.end());

            std::vector<double>::size_type size = homeworkGrades.size();
            std::vector<double>::size_type mid = size / 2;
            double median = size % 2 == 0 ? (homeworkGrades[mid] + homeworkGrades[mid - 1]) / 2 : homeworkGrades[mid];

            const double grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
            grades.push_back(grade);
        }
    }
    std::cout << '\n';

    const std::streamsize prec = std::cout.precision(3);
    for (std::vector<std::string>::size_type i = 0; i != names.size(); ++i)
    {
        std::cout << '\n' << names[i] << ": " << grades[i];
    }
    std::cout << std::setprecision(prec) << std::endl;

    return 0;
}
