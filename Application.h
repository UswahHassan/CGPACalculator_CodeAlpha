#pragma once
#include <string>
#include "Student.h"
#include "Course.h"
#include "Semester.h"
#include "RecordManager.h"

class Application {
private:
    RecordManager recordManager;

    int readMenuChoice() const;
    int readPositiveInteger(const std::string& message) const;
    double readNumber(const std::string& message, bool zeroAllowed) const;
    std::string readText(const std::string& message) const;
    std::string readGrade() const;
    bool readYesNo(const std::string& message) const;

    Student readStudent() const;
    Course readCourse(int number) const;

    void calculateNewResult();
    void displayResult(const Semester& semester) const;

public:
    void run();
};
