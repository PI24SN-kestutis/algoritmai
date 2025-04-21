#include <iostream>
#include <windows.h>

struct Node {
    int value;
    Node* next;
};

// Funkcija, pridedanti elementą į sąrašo galą
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Spausdinimo funkcija
void printList(Node* head) {
    while (head) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Atlaisviname atmintį
void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Pertvarkymo funkcija
void reorderList(Node*& head) {
    Node* positive = nullptr;
    Node* nonPositive = nullptr;

    Node* current = head;
    while (current) {
        if (current->value > 0)
            append(positive, current->value);
        else
            append(nonPositive, current->value);
        current = current->next;
    }

    // Sujungiame sąrašus
    if (!positive) {
        head = nonPositive;
    } else {
        head = positive;
        Node* temp = positive;
        while (temp->next)
            temp = temp->next;
        temp->next = nonPositive;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n;
    std::cout << "Įveskite skaičių kiekį: ";
    std::cin >> n;

    Node* list = nullptr;

    std::cout << "Įveskite " << n << " skaičius:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        append(list, x);
    }

    std::cout << "Pradinis sąrašas:\n";
    printList(list);

    reorderList(list);

    std::cout << "Pakeistas sąrašas:\n";
    printList(list);

    freeList(list);

    return 0;
}
