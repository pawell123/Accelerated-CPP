#ifndef GUARD_STUDENT_HPP
#define GUARD_STUDENT_HPP

#include <iosfwd>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homeworks;
};

bool compare(const Student&, const Student&);
std::istream& read(std::istream&, Student&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
