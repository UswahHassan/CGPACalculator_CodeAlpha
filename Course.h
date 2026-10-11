#pragma once
#include <string>

class Course {
private:
    std::string title;
    std::string grade;
    double creditHours;

public:
    Course(const std::string& title, const std::string& grade, double creditHours);

    std::string getTitle() const;
    std::string getGrade() const;
    double getCreditHours() const;
    double getGradePoints() const;
    double getTotalPoints() const;

    static bool isValidGrade(const std::string& grade);
};
