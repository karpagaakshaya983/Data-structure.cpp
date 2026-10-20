
#include <iostream>
using namespace std;

struct Coach {
    int data;
    Coach* next;
};

Coach* head = NULL;

void addBeginning(int x) {
    Coach* n = new Coach{x, head};
    head = n;
}

void addEnd(int x) {
    Coach* n = new Coach{x, NULL};
    if (head == NULL) {
        head = n;
        return;
    }
    Coach* t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = n;
}

void removeCoach(int x) {
    Coach* t = head;
    Coach* prev = NULL;

    while (t != NULL && t->data != x) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        cout << "Coach not found\n";
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    delete t;
    cout << "Coach removed\n";
}

void display() {
    Coach* t = head;
    while (t != NULL) {
        cout << "Coach" << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

int main() {
    addEnd(1);
    addEnd(2);
    addEnd(3);
    addEnd(4);

    cout << "Original Train:\n";
    display();

    addBeginning(0);
    cout << "After adding at beginning:\n";
    display();

    addEnd(5);
    cout << "After adding at end:\n";
    display();

    removeCoach(3);
    cout << "After removing Coach3:\n";
    display();

    return 0;
}
