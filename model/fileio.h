#include <iostream>
#include <fstream>

using namespace std;
#include "main.h"


void writeEmployeeTofile(EmployeeList *list){
    fstream f1;
    f1.open("employee.txt", ios::out);
    if (!f1) {
        cout << "Error opening file!" << endl;
        return;
    }
    Employee *current = list->head;
    while (current != nullptr) {
        f1 << current->id << " " << current->name << " " << current->department << " " << current->salary << endl;
        current = current->next;
    }
    f1.close();
    cout << "Data written to file successfully!" << endl;
}

void readEmployeeFromfile(EmployeeList *list){
    fstream f1;
    f1.open("employee.txt", ios::in);
    if (!f1) {
        cout << "Error opening file!" << endl;
        return;
    }
    Employee *current = list->head;
    while (current != nullptr) {
        f1 >> current->id >> current->name >> current->department >> current->salary;
        current = current->next;
    }
    f1.close();
    cout << "Data read from file successfully!" << endl;
}

void readloginFromfile(login *l){
    fstream f1;
    f1.open("login.txt", ios::in);
    if (!f1) {
        cout << "Error opening file!" << endl;
        return;
    }
    f1 >> l->username >> l->password;
    f1.close();
    cout << "Data read from file successfully!" << endl;
}

