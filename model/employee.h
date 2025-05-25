#include <iostream>

using namespace std;
#include "fileio.h"


void searchEmployeeById(EmployeeList *list, int id) {
    Employee *current = list->head;
    while (current != nullptr) {
        if (current->id == id) {
            cout << "Employee found: " << current->name << ", " << current->department << ", " << current->salary << endl;
            return;
        }
        current = current->next;
    }
    cout << "Employee not found." << endl;
}



