#include<iostream>
#include<fstream>
using namespace std;

void displayEmployees() {
    fstream file;
    string line;
    file.open("Employees_list.csv", ios::in);
    if(!file){
        cout << "Error couldn't open file" << endl ;
    }
    while(getline(file,line)){
        cout << line << endl;
    }
    file.close();
}
