#include "Course.h"
using namespace std;

static double lookupGradePoints(const string& grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A")  return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B")  return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C")  return 2.00;
    if (grade == "D")  return 1.00;
    if (grade == "F")  return 0.00;
    return -1;
}

Course::Course(const string& title, const string& grade, double creditHours)
    : title(title), grade(grade), creditHours(creditHours) {
}

string Course::getTitle() const {
    return title;
}

string Course::getGrade() const {
    return grade;
}

double Course::getCreditHours() const {
    return creditHours;
}

double Course::getGradePoints() const {
    return lookupGradePoints(grade);
}

double Course::getTotalPoints() const {
    return getGradePoints() * creditHours;
}

bool Course::isValidGrade(const string& grade) {
    return lookupGradePoints(grade) >= 0;
}