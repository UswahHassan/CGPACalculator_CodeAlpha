#pragma once
#include <vector>
#include "Student.h"
#include "Course.h"

class Semester {
private:
    Student student;
    std::vector<Course> courses;
    bool previousRecordAdded;
    double previousCreditHours;
    double previousCGPA;

public:
    Semester(const Student& student);

    void addCourse(const Course& course);
    void setPreviousRecord(double creditHours, double cgpa);

    const Student& getStudent() const;
    const std::vector<Course>& getCourses() const;
    bool hasPreviousRecord() const;

    double getTotalCreditHours() const;
    double getTotalGradePoints() const;
    double calculateGPA() const;
    double calculateCGPA() const;
};
