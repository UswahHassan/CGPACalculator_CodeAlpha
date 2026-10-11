#include "Application.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

static string toUpperCase(string text) {
    for (char& letter : text) {
        letter = toupper(static_cast<unsigned char>(letter));
    }
    return text;
}

int Application::readMenuChoice() const {
    int choice;
    cout << "\n===== CGPA Calculator =====\n";
    cout << "1. Calculate new GPA\n";
    cout << "2. View previous calculations\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Enter 1, 2 or 3: ";
    }
    return choice;
}

int Application::readPositiveInteger(const string& message) const {
    int number;
    cout << message;
    while (!(cin >> number) || number <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. " << message;
    }
    return number;
}

double Application::readNumber(const string& message, bool zeroAllowed) const {
    double number;
    cout << message;
    while (!(cin >> number) || number < 0 || (!zeroAllowed && number == 0)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. " << message;
    }
    return number;
}

string Application::readText(const string& message) const {
    string text;
    cout << message;
    cin >> ws;
    getline(cin, text);
    return text;
}

string Application::readGrade() const {
    string grade;
    cout << "  Grade (A+, A, B+, B, C+, C, D, F): ";
    cin >> grade;
    grade = toUpperCase(grade);

    while (!Course::isValidGrade(grade)) {
        cout << "  Invalid grade. Try again: ";
        cin >> grade;
        grade = toUpperCase(grade);
    }
    return grade;
}

bool Application::readYesNo(const string& message) const {
    char answer;
    cout << message;
    cin >> answer;
    cin.ignore(1000, '\n');
    answer = toupper(static_cast<unsigned char>(answer));

    while (answer != 'Y' && answer != 'N') {
        cout << "Please type Y or N: ";
        cin >> answer;
        cin.ignore(1000, '\n');
        answer = toupper(static_cast<unsigned char>(answer));
    }
    return answer == 'Y';
}

Student Application::readStudent() const {
    string name = readText("Student name: ");
    string rollNumber = readText("Roll number: ");
    return Student(name, rollNumber);
}

Course Application::readCourse(int number) const {
    cout << "\nCourse " << number << endl;
    string title = readText("  Course title: ");
    string grade = readGrade();
    double creditHours = readNumber("  Credit hours: ", false);
    return Course(title, grade, creditHours);
}

void Application::displayResult(const Semester& semester) const {
    const vector<Course>& courses = semester.getCourses();

    cout << fixed << setprecision(2);
    cout << "\n=== Result ===\n";

    for (size_t i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i].getTitle()
            << " | Grade: " << courses[i].getGrade()
            << " | Credit hours: " << courses[i].getCreditHours() << endl;
    }

    cout << "\nTotal credit hours: " << semester.getTotalCreditHours() << endl;
    cout << "Total grade points: " << semester.getTotalGradePoints() << endl;
    cout << "Semester GPA: " << semester.calculateGPA() << endl;

    if (semester.hasPreviousRecord()) {
        cout << "Overall CGPA: " << semester.calculateCGPA() << endl;
    }
}

void Application::calculateNewResult() {
    Semester semester(readStudent());

    int courseCount = readPositiveInteger("Enter number of courses: ");
    for (int number = 1; number <= courseCount; number++) {
        semester.addCourse(readCourse(number));
    }

    if (readYesNo("\nInclude previous semesters to get overall CGPA? (Y/N): ")) {
        double oldCreditHours = readNumber("Credit hours completed in previous semesters: ", true);
        double oldCGPA = readNumber("Previous CGPA: ", true);
        semester.setPreviousRecord(oldCreditHours, oldCGPA);
    }

    displayResult(semester);
    recordManager.save(semester);
}

void Application::run() {
    int choice;

    do {
        choice = readMenuChoice();

        if (choice == 1) {
            cout << endl;
            calculateNewResult();
        }
        else if (choice == 2) {
            recordManager.displayAll();
        }
    } while (choice != 3);

    cout << "\nGoodbye!\n";
}