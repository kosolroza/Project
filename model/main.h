#include <iostream>

using namespace std;

struct Employee{
    int id;
    string name;
    string department;
    double salary;
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
    string username;
    string password;
};

