# Library Management System in C++

## Problem Statement:
This project implements a **Library Management System** using **C++** and **Object-Oriented Programming** concepts. The system is designed to work on the **Command Line Interface (CLI)** and manages library operations for three types of users: **Professors, Students,** and **Librarians**. Each user type has distinct roles and permissions as described below.

## Functionalities:

### 1. User Roles:
- **Professor**:
  - Can view all books in the library.
  - Can check if a book is available for issue.
  - Can issue an unlimited number of books for a duration of 60 days.
  - Late returns incur a fine of 5 rupees/day after the due date.

- **Student**:
  - Can view all books in the library.
  - Can check if a book is available for issue.
  - Can issue up to 5 books for a maximum of 30 days.
  - Late returns incur a fine of 2 rupees/day after the due date.

- **Librarian**:
  - Can add, update, and delete book records.
  - Can add, update, and delete user records.
  - Can view a list of all books and users.
  - Can track which books are issued to which users.

### 2. Login/Logout System:
- The system allows users to log in using credentials stored in a CSV file. Upon login, users can access functionalities specific to their role.

## Implementation Details:

### CSV Files:
- **=users_data.csv**: Stores details of users in the format `[name, id, password, type of user]`, where:
  - `type of user = 1` for Students.
  - `type of user = 2` for Professors.
  - `type of user = 3` for Librarians.
  
- **books_data.csv**: Stores details of books in the library in the format `[name of book, author, publisher, ISBN code, is_issued]`, where `is_issued` is `1` if the book is issued and `0` otherwise.

- **issued_books_data.csv**: Stores records of issued books in the format `[user id, name of book, ISBN code, timestamp]`. The timestamp helps in calculating fines for overdue books.

### Running the System:
1. Compile the program using:
   ```bash
   g++ main.cpp -o main
