#include <iostream>
using namespace std;

#include "employee.h"


void addEmployee(EmployeeList *list, int id, string name, string department, double salary) {
    Employee *newEmployee = new Employee;
    newEmployee->id = id;
    newEmployee->name = name;
    newEmployee->department = department;
    newEmployee->salary = salary;
    newEmployee->next = nullptr;

    if (list->head == nullptr) {
        list->head = newEmployee;
        list->tail = newEmployee;
    } else {
        list->tail->next = newEmployee;
        list->tail = newEmployee;
    }
    list->size++;
    writeEmployeeTofile(list);
    cout << "Employee added successfully!" << endl;
}

void deleteEmployee(EmployeeList *list, int id) {
    Employee *current = list->head;
    Employee *previous = nullptr;

    while (current != nullptr && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Employee with ID " << id << " not found." << endl;
        return;
    }

    if (previous == nullptr) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == list->tail) {
        list->tail = previous;
    }

    delete current;
    list->size--;
    writeEmployeeTofile(list);
    cout << "Employee with ID " << id << " deleted successfully!" << endl;
}

void displayEmployees(EmployeeList *list) {
    Employee *current = list->head;
    while (current != nullptr) {
        cout << "ID: " << current->id << ", Name: " << current->name
             << ", Department: " << current->department
             << ", Salary: " << current->salary << endl;
        current = current->next;
    }
}

void updateEmployeeDetails(EmployeeList *list, int id, string name, string department, double salary) {
    Employee *current = list->head;
    while (current != nullptr) {
        if (current->id == id) {
            current->name = name;
            current->department = department;
            current->salary = salary;
            writeEmployeeTofile(list);
            cout << "Employee details updated successfully!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee with ID " << id << " not found." << endl;
}

void viewEmployeeDetails(EmployeeList *list) {
    Employee *current = list->head;
    while (current != nullptr) {
        cout << "ID: " << current->id << ", Name: " << current->name
             << ", Department: " << current->department
             << ", Salary: " << current->salary << endl;
        current = current->next;
    }
}
