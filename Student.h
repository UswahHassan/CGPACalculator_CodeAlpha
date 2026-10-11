#pragma once
#include <string>

class Student {
private:
    std::string name;
    std::string rollNumber;

public:
    Student(const std::string& name, const std::string& rollNumber)
        : name(name), rollNumber(rollNumber) {
    }

    std::string getName() const { return name; }
    std::string getRollNumber() const { return rollNumber; }
};
