
# Student Management System

## Overview

This program is a **Student Management System** implemented in C++. It allows users to store, manage, and manipulate information about students in a class. The system is designed to be interactive, providing various features such as adding students, sorting, searching, and calculating grades.

## Features

### Core Features:
1. **Student Attributes**:
    - Last Name
    - First Name
    - Student Number
    - Grade for Midterm #1
    - Grade for Midterm #2
    - Grade for Final Exam

2. **Functionalities**:
    - **Add Students**: Add a new student with all required attributes.
    - **Print All Students**: Display all student data in the system.
    - **Sort Students**: Print students sorted alphabetically by last name, then by first name if the last names are the same.
    - **Search for a Student**: Print the data of a specific student using their student number.
    - **Remove a Student**: Delete a specific student's data by their student number.
    - **Delete All Students**: Clear all student data.
    - **Grade Calculation**: Calculate letter grades based on user-defined weights for midterm and final exams:
        - **A**: Average higher than 90%
        - **B**: Average between 80% - 90%
        - **C**: Average between 70% - 80%
        - **D**: Average between 60% - 70%
        - **F**: Average below 60%
    - **Set Grade Weights**: Configure the percentage contribution of each midterm and final exam to the overall grade.

### Additional Enhancements:
- **Input Validation**: Ensures that numeric inputs like grades and weights are valid.
- **Weight Validation**: Ensures the sum of weights for grade calculation equals 100%.
- **Error Handling**: Handles invalid inputs gracefully with clear error messages.
- **Interactive Menu**: User-friendly menu for accessing program features.

## Usage Instructions

### Requirements
- **C++ Compiler**: Any standard C++ compiler supporting C++11 or later.

### Compilation
To compile the program, use the following command in your terminal:
```bash
g++ -o student_management student_management.cpp
```

### Execution
Run the compiled program using:
```bash
./student_management
```

### Menu Options
1. **Add Student**: Follow the prompts to input student details (Last Name, First Name, Student Number, Midterm #1, Midterm #2, Final Exam).
2. **Print All Students**: Display all stored students with calculated averages and letter grades.
3. **Print Students Sorted**: View students sorted alphabetically.
4. **Print Specific Student**: Search for and display a student using their student number.
5. **Remove Student**: Delete a student's data using their student number.
6. **Delete All Students**: Clear all stored student data.
7. **Set Weights for Grades**: Define new weights for midterms and finals (must add up to 100%).
8. **Exit**: Terminate the program.

### Example Session
1. **Adding Students**:
    ```
    Enter Last Name: Smith
    Enter First Name: John
    Enter Student Number: S12345
    Enter Midterm #1 Grade: 85
    Enter Midterm #2 Grade: 90
    Enter Final Exam Grade: 88
    ```
2. **Setting Grade Weights**:
    ```
    Enter Midterm #1 Weight: 30
    Enter Midterm #2 Weight: 30
    Enter Final Exam Weight: 40
    ```
3. **Viewing Sorted Students**:
    ```
    Name: John Smith, Student Number: S12345, Midterm 1: 85, Midterm 2: 90, Final: 88, Average: 87.20, Grade: B
    ```

## Code Structure

### Key Classes
- `Student`: Represents an individual student with attributes and methods for calculating averages and letter grades.
- `StudentManager`: Manages a collection of students and provides functionalities such as sorting, searching, and deletion.

### Modular Functions
- `displayMenu`: Displays the main menu.
- `clearInputBuffer`: Handles invalid input by clearing the input stream.

## Limitations
- The program is limited to console-based interaction.
- No persistence; data is lost when the program terminates.

## Future Improvements
- Add file handling for saving and loading student data.
- Implement a graphical user interface (GUI).

## License
This project is released under the MIT License.

---
**Author**: Cullen Murphy-Brady
