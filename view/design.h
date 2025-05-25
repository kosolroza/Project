#pragma once
#include <iostream>
using namespace std;
// #include "employee.h"
#include "../model/manager.h"

EmployeeList *list = initEmployeeList();
void firstboard();
void managerboard();
void employeeboard();


void loginManager(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "admin") {
        cout << "Login successful!" << endl;
        managerboard();
    } else {
        cout << "Invalid username or password." << endl;
        loginManager();
    }
}

//login Employee need to be read username and password from file "login.txt"

void loginEmployee(){
    login *l = new login;
    readloginFromfile(l);
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == l->username && password == l->password) {
        cout << "Login successful!" << endl;
        employeeboard();
    } else {
        cout << "Invalid username or password." << endl;
        loginEmployee();
    }
}


void firstboard(){
    while(1){
        cout << "Welcome to the Employee Management System" << endl;
        cout << "1. Login as Manager" << endl;
        cout << "2. Login as Employee" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:
                loginManager();
                break;
            case 2:
                loginEmployee();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
                firstboard();
        }
    }
}

void managerboard(){
    while(1){
        cout << "Welcome to the Manager Board" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. View Employees" << endl;
        cout << "5. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:{
                // Add employee logic
                int id;
                string name, department;
                double salary;
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin >> name;
                cout << "Enter Employee Department: ";
                cin >> department;
                cout << "Enter Employee Salary: ";
                cin >> salary;
                addEmployee(list, id, name, department, salary);
                break;
            }
            case 2:{
                // Delete employee logic
                int id;
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee(list, id);
                cout << "Employee deleted successfully!" << endl;
                break;
            }
            case 3:{
                // Update employee logic
                int id;
                string name, department;
                double salary;
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter new Employee Name: ";
                cin >> name;
                cout << "Enter new Employee Department: ";
                cin >> department;
                cout << "Enter new Employee Salary: ";
                cin >> salary;
                updateEmployeeDetails(list, id, name, department, salary);
                cout << "Employee updated successfully!" << endl;
            }
            case 4:{
                // View employees logic
                cout << "Employee List:" << endl;
                viewEmployeeDetails(list);
                break;
            }
            case 5:
                firstboard();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                managerboard();
        }
    }
}

void employeeboard(){
    while(1){
        cout << "Welcome to the Employee Board" << endl;
        cout << "1. View Profile" << endl;
        cout << "2. Update Profile" << endl;
        cout << "3. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1:{
                // View profile logic
                int id;
                cout << "Enter Employee ID to view: ";
                cin >> id;
                searchEmployeeById(list, id);
                cout << "Employee details displayed successfully!" << endl;
                break;
            }
            case 2:{
                // Update profile logic
                int id;
                string name, department;
                double salary;
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter new Employee Name: ";
                cin >> name;
                cout << "Enter new Employee Department: ";
                cin >> department;
                cout << "Enter new Employee Salary: ";
                cin >> salary;
                updateEmployeeDetails(list, id, name, department, salary);
                cout << "Employee updated successfully!" << endl;
                break;
            }
            case 3:
                firstboard();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                employeeboard();
        }
    }
}


