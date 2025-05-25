#include <iostream>
using namespace std;

#include "employee.h"

void sortEmployeesByName(EmployeeList *list);

void addEmployee(EmployeeList *list, string id, string fName, string lName, char gender, string pos,string department, double salary, double bonus, string perform){
    Employee *newEmployee = new Employee;
    newEmployee->id = id;
    newEmployee->firstName = fName;
    newEmployee->lastName = lName;
    newEmployee->gender = gender;
    newEmployee->position = pos;
    newEmployee->department = department;
    newEmployee->salary = salary;
    newEmployee->bonus = bonus;
    newEmployee->performance = perform;
    newEmployee->next = nullptr;
    if (list->head == nullptr) {
        list->head = newEmployee;
        list->tail = newEmployee;
    } else {
        list->tail->next = newEmployee;
        list->tail = newEmployee;
    }
    list->size++;
    sortEmployeesByName(list); // Sort after adding a new employee
    cout << "Employee added successfully!" << endl;
}

void deleteEmployee(EmployeeList *list, string id) {
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
        cout << "ID: " << current->id << ", Name: " << current->firstName << " " << current->lastName
        <<" "<<current->gender<<" "<<current->position<<" "<<current->department<<" "<<current->salary<<" "
        <<current->bonus<<" "<<current->performance<<endl;
        current = current->next;
    }
}

//update employee but need to ask first which one manager want to update
void updateEmployeeDetails(EmployeeList *list, string id, string fName, string lName, char gender, string pos, string department, double salary, double bonus, string perform) {
    Employee *current = list->head;

    while (current != nullptr) {
        if (current->id == id) {
            current->firstName = fName;
            current->lastName = lName;
            current->gender = gender;
            current->position = pos;
            current->department = department;
            current->salary = salary;
            current->bonus = bonus;
            current->performance = perform;
            writeEmployeeTofile(list);
            cout << "Employee details updated successfully!" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee with ID " << id << " not found." << endl;
}


//make bubble sort funtion that can store employee base on their name start with A-Z

void sortEmployeesByName(EmployeeList *list) {
    if (list->head == nullptr || list->head->next == nullptr) {
        return; // List is empty or has only one employee
    }

    bool swapped;
    do {
        swapped = false;
        Employee *current = list->head;
        while (current->next != nullptr) {
            if (current->firstName > current->next->firstName) {
                // Swap names
                swap(current->firstName, current->next->firstName);
                swap(current->lastName, current->next->lastName);
                swap(current->id, current->next->id);
                swap(current->gender, current->next->gender);
                swap(current->position, current->next->position);
                swap(current->department, current->next->department);
                swap(current->salary, current->next->salary);
                swap(current->bonus, current->next->bonus);
                swap(current->performance, current->next->performance);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    writeEmployeeTofile(list);
    // cout << "Employees sorted by name successfully!" << endl;
}

