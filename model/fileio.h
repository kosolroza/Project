#include <iostream>
#include <fstream>

using namespace std;
#include "main.h"

void writeEmployeeTofile(EmployeeList *l){
    fstream f1;
    f1.open("employee.csv", ios::out);
    if (!f1) {
        cout << "Error opening file!" << endl;
        return;
    }
    Employee *current = l->head;
    while (current != nullptr) {
        f1 << current->id << "," << current->firstName << "," << current->lastName <<","<< current->gender 
        <<","<<current->position<<","<<current->performance<<","<<current->department<<","<<current->salary<<","
        <<current->bonus<< endl;
        current = current->next;
    }
    f1.close();
    cout << "Data written to file successfully!" << endl;
}

void readEmployeeFromfile(EmployeeList *l){
    fstream f1;
    f1.open("employee.csv", ios::in);
    if (!f1) {
        cout << "Error opening file!" << endl;
        return;
    }
    Employee *current = l->head;
    while (current != nullptr) {
        f1 >> current->id >> current->firstName >> current->lastName >>current->gender >>current->position >>
        current->performance >>current->department >>current->salary >> current->bonus;
        current = current->next;
    }
    f1.close();
    cout << "Data read from file successfully!" << endl;
}



void readloginFromfile(login *l){
    fstream f1;
    f1.open("login.csv", ios::in);
    if (!f1) {
        cout << "Error opening file!" << endl;
        return;
    }
    f1 >> l->username >> l->password;
    f1.close();
    cout << "Data read from file successfully!" << endl;
}

