#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

/**
 * Duotas dvikryptis sąrašas, kuriame skaičiai gali kartotis.
 * Sukurti vienkryptį sąrašą į kurį pakliūna tik pasikartojantys skaičiai.
 */
struct BiNode {
    int data;
    BiNode* next;
    BiNode* prev;
};

struct OneNode {
    int data;
    OneNode* next;
};

BiNode* createBiNode(int value) {
    BiNode* newNode = new BiNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

OneNode* createOneNode(int value) {
    OneNode* newNode = new OneNode;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(BiNode*& head, int value) {
    BiNode* newNode = createBiNode(value);
    if (!head) {
        head = newNode;
    } else {
        BiNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printDoublyList(BiNode* head) {
    cout << "Dvikryptis sąrašas: ";
    BiNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printSingleList(OneNode* head) {
    cout << "Vienkryptis pasikartojančių skaičių sąrašas:" << endl;
    OneNode* temp = head;
    int count = 0;
    int index = 1;
    while (temp) {
        cout << index << ". " << temp->data << endl;
        temp = temp->next;
        count++;
        index++;
    }
    cout << "Pasikartojančių elementų skaičius: " << count << endl;
}

bool isInList(OneNode* head, int value) {
    OneNode* temp = head;
    while (temp) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

OneNode* findDuplicates(BiNode* head) {
    OneNode* duplicates = nullptr;
    BiNode* current = head;
    while (current) {
        BiNode* checker = current->next;
        while (checker) {
            if (current->data == checker->data) {
                if (!isInList(duplicates, current->data)) {
                    OneNode* newNode = createOneNode(current->data);
                    newNode->next = duplicates;
                    duplicates = newNode;
                }
                break;
            }
            checker = checker->next;
        }
        current = current->next;
    }
    return duplicates;
}

void deleteDoublyList(BiNode*& head) {
    while (head) {
        BiNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteSingleList(OneNode*& head) {
    while (head) {
        OneNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void generateRandomList(BiNode*& head, int count) {
    srand(time(0));
    for (int i = 0; i < count; ++i) {
        int value = rand() % 20;
        insertEnd(head, value);
    }
}

void clearScreen() {
    system("cls");
}

void menu() {
    SetConsoleOutputCP(65001);
    BiNode* doublyList = nullptr;
    OneNode* duplicatesList = nullptr;
    int choice;
    do {
        clearScreen();
        cout << "\n+------------------------------+" << endl;
        cout << "|            Meniu             |" << endl;
        cout << "+------------------------------+" << endl;
        cout << "| 1. Pridėti skaičius ranka    |" << endl;
        cout << "| 2. Generuoti random sąrašą   |" << endl;
        cout << "| 3. Atspausdinti sąrašą       |" << endl;
        cout << "| 4. Sukurti pasikartojančių   |" << endl;
        cout << "| 5. Atspausdinti pakartojimus |" << endl;
        cout << "| 6. Išeiti                    |" << endl;
        cout << "+------------------------------+" << endl;
        cout << "Pasirinkite: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n, value;
                cout << "Kiek skaičių norite įvesti? ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    cout << "Įveskite skaičių " << i + 1 << ": ";
                    cin >> value;
                    insertEnd(doublyList, value);
                }
                break;
            }
            case 2: {
                int n;
                cout << "Kiek atsitiktinių skaičių sugeneruoti? ";
                cin >> n;
                generateRandomList(doublyList, n);
                cout << "Sugeneruotas sąrašas." << endl;
                break;
            }
            case 3:
                printDoublyList(doublyList);
                break;
            case 4:
                deleteSingleList(duplicatesList);
                duplicatesList = nullptr;
                duplicatesList = findDuplicates(doublyList);
                cout << "Pasikartojantys skaičiai sukurti." << endl;
                break;
            case 5:
                printSingleList(duplicatesList);
                break;
            case 6:
                cout << "Baigiama programa." << endl;
                break;
            default:
                cout << "Neteisingas pasirinkimas!" << endl;
        }
        if (choice != 6) {
            system("pause");
        }
    } while (choice != 6);

    deleteDoublyList(doublyList);
    deleteSingleList(duplicatesList);
}

int main() {
    menu();
    return 0;
}
