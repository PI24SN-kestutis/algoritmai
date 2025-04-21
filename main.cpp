#include <iostream>
#include <windows.h>


/**
 * Sukurti dinaminį vienkryptį sąrašą, realizuojant elemento įterpimo, pašalinimo, spausdinimo bei paieškos funkcijas.
 * Perkelti to sąrašo visus elementus į dvikryptį. Atspausdinti visus dvikrypčio sąrašo elementus.
 */

using namespace std;

struct Vienkryptis {
    int data;
    Vienkryptis* next;
};

struct Dvikryptis {
    int data;
    Dvikryptis* next;
    Dvikryptis* prev;
};

void insert(Vienkryptis*& head, int data) {
    Vienkryptis* naujas_vienkryptis = new Vienkryptis{ data, nullptr};
    if (!head) {
        head = naujas_vienkryptis;
        return;
    }
    Vienkryptis* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = naujas_vienkryptis;
}

void remove(Vienkryptis*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        Vienkryptis* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Vienkryptis* temp = head;
    while (temp->next && temp->next->data != value)
        temp = temp->next;
    if (temp->next) {
        Vienkryptis* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void print(Vienkryptis* head) {
    cout << "Vienkryptis sąrašas: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
bool search(Vienkryptis* head, int value) {
    while (head) {
        if (head->data == value)
            return true;
        head = head->next;
    }
    return false;
}

void transferToDoubleList(Vienkryptis* singleHead, Dvikryptis*& doubleHead, Dvikryptis*& doubleTail) {
    while (singleHead) {
        Dvikryptis* newNode = new Dvikryptis{singleHead->data, nullptr, nullptr};
        if (!doubleHead) {
            doubleHead = doubleTail = newNode;
        } else {
            doubleTail->next = newNode;
            newNode->prev = doubleTail;
            doubleTail = newNode;
        }
        singleHead = singleHead->next;
    }
}

void printDoubleList(Dvikryptis* head) {
    cout << "Dvikryptis sąrašas: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void clear(Vienkryptis*& head) {
    while (head) {
        Vienkryptis* temp = head;
        head = head->next;
        delete temp;
    }
}
void clear(Dvikryptis*& head) {
    while (head) {
        Dvikryptis* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    Vienkryptis* singleList = nullptr;

    insert(singleList, 10);
    insert(singleList, 20);
    insert(singleList, 30);
    insert(singleList, 40);

    print(singleList); // 10 20 30 40

    cout << "Ar yra 30? " << (search(singleList, 30) ? "Taip" : "Ne") << endl;

    remove(singleList, 20);
    print(singleList); // 10 30 40

    // Perkėlimas į dvikryptį
    Dvikryptis* doubleList = nullptr;
    Dvikryptis* tail = nullptr;
    transferToDoubleList(singleList, doubleList, tail);

    printDoubleList(doubleList); // 10 30 40

    clear(singleList);
    clear(doubleList);


    return 0;
}
