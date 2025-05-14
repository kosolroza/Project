#include <iostream>
#include <fstream>
#include<string>
#include<iomanip>
//include this to give space for each culomn (i guess)

using namespace std;

void displayEmployees() {
    fstream file("Employees_list.csv", ios::in);
    if (!file) {
        cout << "Error: couldn't open file" << endl;
        return;
    }

    string line;
    string id ,first, last, sex, pos, per, dep, sal, hir, bonus;
    int location =0;
    while (getline(file, line)) {
        //To give each string their value xD
        location = line.find(',');
        id = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        first = line.substr(0, location);
        line = line.substr(location + 1, line.length());
        
        location = line.find(',');
        last = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        sex = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        pos = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        per = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        dep = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        sal = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        hir = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        bonus = line.substr(0, location);
        line = line.substr(location + 1, line.length());
        //Now we will display ts
        cout << left << setw(10) << id
             << setw(15) << first
             << setw(15) << last
             << setw(10) << sex
             << setw(25) << pos
             << setw(15) << dep
             << setw(12) << hir
             << endl;

    }
    

    file.close();
}
