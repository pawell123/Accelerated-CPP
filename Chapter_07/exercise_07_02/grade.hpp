#ifndef GUARD_GRADE_HPP
#define GUARD_GRADE_HPP

#include <vector>

struct Student;

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, std::vector<double> homeworks);
double grade(const Student&);

#endif