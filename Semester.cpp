#include "Semester.h"
using namespace std;

Semester::Semester(const Student& student)
    : student(student), previousRecordAdded(false),
    previousCreditHours(0), previousCGPA(0) {
}

void Semester::addCourse(const Course& course) {
    courses.push_back(course);
}

void Semester::setPreviousRecord(double creditHours, double cgpa) {
    previousCreditHours = creditHours;
    previousCGPA = cgpa;
    previousRecordAdded = true;
}

const Student& Semester::getStudent() const {
    return student;
}

const vector<Course>& Semester::getCourses() const {
    return courses;
}

bool Semester::hasPreviousRecord() const {
    return previousRecordAdded;
}

double Semester::getTotalCreditHours() const {
    double total = 0;
    for (const Course& course : courses) {
        total += course.getCreditHours();
    }
    return total;
}

double Semester::getTotalGradePoints() const {
    double total = 0;
    for (const Course& course : courses) {
        total += course.getTotalPoints();
    }
    return total;
}

double Semester::calculateGPA() const {
    double creditHours = getTotalCreditHours();
    if (creditHours == 0) {
        return 0;
    }
    return getTotalGradePoints() / creditHours;
}

double Semester::calculateCGPA() const {
    if (!previousRecordAdded) {
        return calculateGPA();
    }
    double allGradePoints = previousCGPA * previousCreditHours + getTotalGradePoints();
    double allCreditHours = previousCreditHours + getTotalCreditHours();
    return allGradePoints / allCreditHours;
}