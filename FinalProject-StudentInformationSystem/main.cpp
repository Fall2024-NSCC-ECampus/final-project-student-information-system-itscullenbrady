#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits> // For input validation

// Class representing a student
class Student {
public:
    std::string lastName;
    std::string firstName;
    std::string studentNumber;
    double midterm1;
    double midterm2;
    double finalExam;

    // Constructor to initialize a student
    Student(std::string lName, std::string fName, std::string sNumber, double m1, double m2, double final)
        : lastName(lName), firstName(fName), studentNumber(sNumber), midterm1(m1), midterm2(m2), finalExam(final) {}

    // Calculate the average grade based on weights
    double calculateAverage(double midterm1Weight, double midterm2Weight, double finalWeight) const {
        return (midterm1 * midterm1Weight + midterm2 * midterm2Weight + finalExam * finalWeight) / 100.0;
    }

    // Calculate the letter grade based on the average
    char calculateLetterGrade(double midterm1Weight, double midterm2Weight, double finalWeight) const {
        double average = calculateAverage(midterm1Weight, midterm2Weight, finalWeight);
        if (average > 90) return 'A';
        else if (average >= 80) return 'B';
        else if (average >= 70) return 'C';
        else if (average >= 60) return 'D';
        else return 'F';
    }

    // Print student details
    void printStudent(double midterm1Weight, double midterm2Weight, double finalWeight) const {
        std::cout << "Name: " << firstName << " " << lastName
                  << ", Student Number: " << studentNumber
                  << ", Midterm 1: " << midterm1
                  << ", Midterm 2: " << midterm2
                  << ", Final: " << finalExam
                  << ", Average: " << std::fixed << std::setprecision(2)
                  << calculateAverage(midterm1Weight, midterm2Weight, finalWeight)
                  << ", Grade: " << calculateLetterGrade(midterm1Weight, midterm2Weight, finalWeight) << std::endl;
    }
};

// Class to manage a collection of students
class StudentManager {
private:
    std::vector<Student> students;
    double midterm1Weight = 25.0;
    double midterm2Weight = 25.0;
    double finalWeight = 50.0;

    // Validate that the weights add up to 100
    bool validateWeights(double m1Weight, double m2Weight, double finalWeight) {
        return (m1Weight + m2Weight + finalWeight == 100.0);
    }

public:
    // Add a student to the collection
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Print all students
    void printAllStudents() const {
        if (students.empty()) {
            std::cout << "No students to display.\n";
            return;
        }
        for (const auto& student : students) {
            student.printStudent(midterm1Weight, midterm2Weight, finalWeight);
        }
    }

    // Print students sorted by last name and first name
    void printStudentsSorted() const {
        if (students.empty()) {
            std::cout << "No students to sort.\n";
            return;
        }
        auto sortedStudents = students;
        std::sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
            if (a.lastName == b.lastName) {
                return a.firstName < b.firstName;
            }
            return a.lastName < b.lastName;
        });
        for (const auto& student : sortedStudents) {
            student.printStudent(midterm1Weight, midterm2Weight, finalWeight);
        }
    }

    // Print a specific student by student number
    void printStudentByNumber(const std::string& studentNumber) const {
        for (const auto& student : students) {
            if (student.studentNumber == studentNumber) {
                student.printStudent(midterm1Weight, midterm2Weight, finalWeight);
                return;
            }
        }
        std::cout << "Student not found!\n";
    }

    // Remove a student by student number
    void removeStudent(const std::string& studentNumber) {
        auto it = std::remove_if(students.begin(), students.end(),
                                 [&studentNumber](const Student& s) { return s.studentNumber == studentNumber; });
        if (it != students.end()) {
            students.erase(it, students.end());
            std::cout << "Student removed.\n";
        } else {
            std::cout << "Student not found!\n";
        }
    }

    // Delete all students
    void deleteAllStudents() {
        students.clear();
        std::cout << "All student data deleted.\n";
    }

    // Set the weights for the grades
    void setWeights(double m1Weight, double m2Weight, double finalWeight) {
        if (validateWeights(m1Weight, m2Weight, finalWeight)) {
            midterm1Weight = m1Weight;
            midterm2Weight = m2Weight;
            finalWeight = finalWeight;
            std::cout << "Weights updated successfully.\n";
        } else {
            std::cout << "Error: The weights must add up to 100.\n";
        }
    }
};

// Display the menu options
void displayMenu() {
    std::cout << "\nStudent Management System\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Print All Students\n";
    std::cout << "3. Print Students Sorted\n";
    std::cout << "4. Print Specific Student\n";
    std::cout << "5. Remove Student\n";
    std::cout << "6. Delete All Students\n";
    std::cout << "7. Set Weights for Grades\n";
    std::cout << "0. Exit\n";
}

// Clear the input buffer to handle invalid input
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    StudentManager manager;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            clearInputBuffer();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string lastName, firstName, studentNumber;
                double midterm1, midterm2, finalExam;
                std::cout << "Enter Last Name: ";
                std::cin >> lastName;
                std::cout << "Enter First Name: ";
                std::cin >> firstName;
                std::cout << "Enter Student Number: ";
                std::cin >> studentNumber;
                std::cout << "Enter Midterm #1 Grade: ";
                if (!(std::cin >> midterm1)) {
                    clearInputBuffer();
                    std::cout << "Invalid input. Aborting.\n";
                    break;
                }
                std::cout << "Enter Midterm #2 Grade: ";
                if (!(std::cin >> midterm2)) {
                    clearInputBuffer();
                    std::cout << "Invalid input. Aborting.\n";
                    break;
                }
                std::cout << "Enter Final Exam Grade: ";
                if (!(std::cin >> finalExam)) {
                    clearInputBuffer();
                    std::cout << "Invalid input. Aborting.\n";
                    break;
                }
                manager.addStudent(Student(lastName, firstName, studentNumber, midterm1, midterm2, finalExam));
                break;
            }
            case 2:
                manager.printAllStudents();
                break;
            case 3:
                manager.printStudentsSorted();
                break;
            case 4: {
                std::string studentNumber;
                std::cout << "Enter Student Number: ";
                std::cin >> studentNumber;
                manager.printStudentByNumber(studentNumber);
                break;
            }
            case 5: {
                std::string studentNumber;
                std::cout << "Enter Student Number to Remove: ";
                std::cin >> studentNumber;
                manager.removeStudent(studentNumber);
                break;
            }
            case 6:
                manager.deleteAllStudents();
                break;
            case 7: {
                double m1Weight, m2Weight, finalWeight;
                std::cout << "Enter Midterm #1 Weight: ";
                if (!(std::cin >> m1Weight)) {
                    clearInputBuffer();
                    std::cout << "Invalid input. Aborting.\n";
                    break;
                }
                std::cout << "Enter Midterm #2 Weight: ";
                if (!(std::cin >> m2Weight)) {
                    clearInputBuffer();
                    std::cout << "Invalid input. Aborting.\n";
                    break;
                }
                std::cout << "Enter Final Exam Weight: ";
                if (!(std::cin >> finalWeight)) {
                    clearInputBuffer();
                    std::cout << "Invalid input. Aborting.\n";
                    break;
                }
                manager.setWeights(m1Weight, m2Weight, finalWeight);
                break;
            }
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}