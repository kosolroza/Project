#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

struct Employee{
    string ID, First, Last, Sex, Pos, Per, Dep, Sal, Hir, Bonus;
    Employee *next;
};

struct List{
    int n;
    Employee *head;
    Employee *tail;
     List(){
        n = 0;
        head = nullptr;
        tail = nullptr;
     }
};

void addTheEnd(List *ls, string id, string first, string last, string sex, string pos, string per, string dep, string sal, string hir, string bonus){
    Employee *e = new Employee;
    e -> ID = id;
    e -> First = first;
    e ->  Last = last;;
    e -> Sex = sex;
    e -> Pos = pos;
    e -> Per = per;
    e -> Dep = dep;
    e -> Sal = sal;
    e -> Hir = hir;
    e -> Bonus = bonus;
    e -> next = nullptr;
    if(ls -> n == 0 ){
        ls -> head = e;
        ls -> tail = e;
    }else{
        ls -> tail -> next = e ;
        ls -> tail = e ;
    }
    ls -> n++;
}

void searchByID(List *l,string id ){
    Employee *t = l -> head;
    while (t!= nullptr){
        if(id == t->ID){
            cout << left << setw(10) << "ID"
             << setw(15) << "First Name"
             << setw(15) << "Last Name"
             << setw(10) << "Sex"
             << setw(25) << "Position"
             << setw(15) << "Departement"
             << setw(12) << "Hire Date"
             << endl
             << left << setw(10) << id
             << setw(15) << t -> First
             << setw(15) << t -> Last
             << setw(10) << t -> Sex
             << setw(25) << t -> Pos
             << setw(15) << t -> Dep
             << setw(12) << t -> Hir
             << endl;
             return;
        }
        t = t -> next;
    }
    cout << "\n\t Employee is not found. "<< endl;
}

void displayEmployee(List *ls){
    Employee *t = ls -> head;
    if(t == nullptr){
        cout << "No Employee found."; 
    }
    while(t != nullptr){
        cout << left << setw(10) << t-> ID
             << setw(15) << t -> First
             << setw(15) << t -> Last
             << setw(10) << t -> Sex
             << setw(25) << t -> Pos
             << setw(15) << t -> Dep
             << setw(12) << t -> Hir
             << endl;
             t = t -> next;
    }
}

void readFile(List* ls){
    ifstream fin("Employees_list.csv");
    if(!fin){
        cout << "Error: could not open the file." << endl;
        return;
    }

    string line;
    getline(fin, line);

    while(getline(fin, line)){
        stringstream ss(line);
        string id, first, last, sex, pos, per, dep, sal, hir, bonus;

        getline(ss, id, ',');
        getline(ss, first, ',');
        getline(ss, last, ',');
        getline(ss, sex, ',');
        getline(ss, pos, ',');
        getline(ss, per, ',');
        getline(ss, dep, ',');
        getline(ss, sal, ',');
        getline(ss, hir, ',');
        getline(ss, bonus, ',');

        addTheEnd(ls, id, first, last, sex, pos, per, dep, sal, hir, bonus);
    }

    fin.close();
}
