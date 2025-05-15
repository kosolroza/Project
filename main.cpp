#include<iostream>
#include<string>
#include"Employee.h"
int main() {
    List employeeList;
    readFile(&employeeList);

    displayEmployee(&employeeList);

    string searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;
    searchByID(&employeeList, searchID);

    return 0;
}

