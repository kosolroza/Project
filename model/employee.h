#include <iostream>
#include <iomanip>
using namespace std;
#include "fileio.h"


void searchByID(EmployeeList*l,string id ){
    Employee *t = l -> head;
    while (t!= nullptr){
        if(id == t->id){
            cout << left << setw(10) << "ID"
             << setw(15) << "First Name"
             << setw(15) << "Last Name"
             << setw(10) << "Sex"
             << setw(25) << "Position"
             << setw(15) << "Departement"
             << endl
             << left << setw(10) << id
             << setw(15) << t ->firstName
             << setw(15) << t ->lastName
             << setw(10) << t ->gender
             << setw(25) << t ->position
             << setw(15) << t ->department
             << endl;
            readEmployeeFromfile(l);
            cout << "\n\t Employee is found. "<< endl;
             return;
        }
        t = t -> next;
    }
    cout << "\n\t Employee is not found. "<< endl;
}

void displayEmployee(EmployeeList *ls){
    Employee *t = ls -> head;
    if(t == nullptr){
        cout << "No Employee found."; 
    }
    while(t != nullptr){
        cout << left << setw(10) << t->id
             << setw(15) << t ->firstName
             << setw(15) << t ->lastName
             << setw(10) << t ->gender
             << setw(25) << t ->position
             << setw(15) << t ->department
             << endl;
             t = t -> next;
    }
}

void viewPersonalDetail(EmployeeList*l ,string id){
     Employee *t = l -> head;
    while (t!= nullptr){
        if(id == t->id){
            cout << left << setw(10) << "ID"
             << setw(15) << "First Name"
             << setw(15) << "Last Name"
             << setw(10) << "Sex"
             << setw(25) << "Position"
             << setw(15) << "Perfromance"
             << setw(15) << "Departement"
             << setw(15) << "Salary"
             << setw(15) << "Bonus"
             << setw(15) << "Password"
             << endl
             << left << setw(10) << id
             << setw(15) << t ->firstName
             << setw(15) << t ->lastName
             << setw(10) << t ->gender
             << setw(25) << t ->position
             << setw(15) << t -> performance
             << setw(15) << t ->department
             << setw(15) << t ->salary
             << setw(15) << t ->bonus
             << setw(15) << t ->newPassword
             << endl;
             return;
        }
        t = t -> next;
    }
}