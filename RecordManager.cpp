#include "RecordManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

RecordManager::RecordManager(const string& fileName) : fileName(fileName) {}

void RecordManager::save(const Semester& semester) const {
    ofstream file(fileName, ios::app);

    if (!file) {
        cout << "\nCould not save the result to the file.\n";
        return;
    }

    const vector<Course>& courses = semester.getCourses();

    file << fixed << setprecision(2);
    file << "----------------------------------------\n";
    file << "Student Name: " << semester.getStudent().getName() << "\n";
    file << "Roll Number: " << semester.getStudent().getRollNumber() << "\n";
    file << "Courses:\n";

    for (size_t i = 0; i < courses.size(); i++) {
        file << "  " << i + 1 << ". " << courses[i].getTitle()
            << " | Grade: " << courses[i].getGrade()
            << " | Credit hours: " << courses[i].getCreditHours() << "\n";
    }

    file << "Total credit hours: " << semester.getTotalCreditHours() << "\n";
    file << "Total grade points: " << semester.getTotalGradePoints() << "\n";
    file << "Semester GPA: " << semester.calculateGPA() << "\n";

    if (semester.hasPreviousRecord()) {
        file << "Overall CGPA: " << semester.calculateCGPA() << "\n";
    }

    file << "----------------------------------------\n\n";
    file.close();

    cout << "\nResult saved to " << fileName << "\n";
}

void RecordManager::displayAll() const {
    ifstream file(fileName);

    if (!file) {
        cout << "\nNo saved calculations yet.\n";
        return;
    }

    string line;
    bool foundRecords = false;

    while (getline(file, line)) {
        if (!foundRecords) {
            cout << "\n=== Previous Calculations ===\n";
            foundRecords = true;
        }
        cout << line << endl;
    }

    if (!foundRecords) {
        cout << "\nNo saved calculations yet.\n";
    }
}