#include <iostream>

using namespace std;

struct Employee{
    string id;
    string firstName;
    string lastName;
    char gender;
    string position;
    string department;
    double salary;
    double bonus;
    string newPassword;
    string performance;
    Employee *next;
};

struct EmployeeList{
    Employee *head;
    Employee *tail;
    int size;
};

EmployeeList *initEmployeeList() {
    EmployeeList *list = new EmployeeList;
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
    return list;
}
    
struct login{
    string id;
    string password;
};

