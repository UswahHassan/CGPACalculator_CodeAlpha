#pragma once
#include <string>
#include "Semester.h"

class RecordManager {
private:
    std::string fileName;

public:
    RecordManager(const std::string& fileName = "records.txt");

    void save(const Semester& semester) const;
    void displayAll() const;
};
