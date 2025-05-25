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
    string id, password;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> password;

    if (id == l->id && password == l->password) {
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
        
        string id;
        char gender;
        string fName, lName, posi, department, perform;
        double salary, bonus;
        switch (choice) {
            case 1:{
                // Add employee logic
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee First Name: ";
                cin >> fName;
                cout << "Enter Employee Last Name: ";
                cin >> lName;
                cout << "Enter Employee gender (M/F): ";
                cin>>gender;
                cout << "Enter Employee Position: ";
                cin >> posi;
                cout << "Enter Employee Performance: ";
                cin >> perform;
                cout << "Enter Employee Department: ";
                cin >> department;
                cout << "Enter Employee Salary: ";
                cin >> salary;
                cout << "Enter Employee Bonus: ";
                cin >> bonus;

                addEmployee(list, id, fName, lName, gender, posi, department, salary, bonus, perform);
                cout << "Employee added successfully!" << endl;
                break;
            }
            case 2:{
                // Delete employee logic
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee(list, id);
                cout << "Employee deleted successfully!" << endl;
                break;
            }
            case 3:{
                // Update employee logic
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter new Employee First Name: ";
                cin >> fName;
                cout << "Enter new Employee Last Name: ";
                cin>>lName;
                cout << "Enter new Employee gender (M/F): ";
                cin>>gender;
                cout << "Enter new Employee Position: ";
                cin >> posi;
                cout << "Enter new Employee Performance: ";
                cin >> perform;
                cout << "Enter new Employee Department: ";
                cin >> department;
                cout << "Enter new Employee Salary: ";
                cin >> salary;
                cout << "Enter new Employee Bonus: ";
                cin >> bonus;
                updateEmployeeDetails(list, id, fName, lName, gender, posi, department, salary, bonus, perform);
                cout << "Employee updated successfully!" << endl;
            }
            case 4:{
                // View employees logic
                cout << "Employee List:" << endl;
                displayEmployee(list);
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
        cout << "1. Search Employee" << endl;
        cout<<"2. View your Profile"<<endl;
        cout << "3. Update Profile" << endl;
        cout << "4. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
       
        string id;
        char gender;
        string fName, lName, posi, department, perform;
        double salary, bonus;

        switch (choice) {
            case 1:{
                // View profile logic

                cout << "Enter Employee ID to view: ";
                cin >> id;
                searchByID(list, id);
                cout << "Employee details displayed successfully!" << endl;
                break;
            }
            case 2:{
                // View profile logic
                cout << "Enter Employee ID to view: ";
                cin >> id;
                viewPersonalDetail(list, id);
                cout << "Employee details displayed successfully!" << endl;
                break;
            }
            case 3:{
                // Update profile logic

                // cout << "Enter Employee ID to update: ";
                // cin >> id;
                // cout << "Enter new Employee Name: ";
                // cin >> name;
                // cout << "Enter new Employee Department: ";
                // cin >> department;
                // cout << "Enter new Employee Salary: ";
                // cin >> salary;
                // updateEmployeeDetails(list, id, name, department, salary);
                // cout << "Employee updated successfully!" << endl;
                // break;
            }
            case 4:
                firstboard();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                employeeboard();
        }
    }
}


