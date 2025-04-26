#include <iostream>

using namespace std;

struct Information{
    string name;
    string id;
    int age;
    string position;
    Information *next;
};

struct List{
    int n;
    Information *head;
    Information *tail;
};

void 