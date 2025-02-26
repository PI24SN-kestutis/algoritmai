#include <iostream>
#include <limits>

using namespace std;

// Vienkrypčio sąrašo struktūra
struct Node {
    int data;
    Node* next;
};

// Globalūs kintamieji vienkrypčiam sąrašui
Node* head = nullptr;
int listSize = 0;
int listA = 0, listB = 0;
bool listElementsEntered = false, listIntervalEntered = false;

// Funkcijos vienkrypčiam sąrašui
void inputListSize() {
    cout << "Iveskite saraso elementu skaiciu: ";
    cin >> listSize;

    // Išvalome seną sąrašą, jei jis egzistuoja
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    listElementsEntered = false;
    listIntervalEntered = false;
    cout << "Sarasas turi " << listSize << " elementus.\n";
}

void inputListElements() {
    if (listSize == 0) {
        cout << "Pirmiausia nustatykite saraso dydi!\n";
        return;
    }

    cout << "Iveskite " << listSize << " saraso elementus: " << endl;
    for (int i = 0; i < listSize; i++) {
        int value;
        while (true) {
            cout << "Elementas " << i + 1 << ": ";
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Neteisinga ivestis, bandykite dar karta.\n";
            } else {
                break;
            }
        }

        // Įterpiame elementą į sąrašą
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    listElementsEntered = true;
}

void inputListInterval() {
    if (!listElementsEntered) {
        cout << "Pirmiausia iveskite saraso elementus!\n";
        return;
    }

    cout << "Iveskite intervalo reiksmes [a; b] elementu trinimui: \n";
    cout << "nuo: ";
    cin >> listA;
    cout << "iki: ";
    cin >> listB;
    listIntervalEntered = true;
}

void deleteElementsInInterval() {
    if (!listIntervalEntered) {
        cout << "Pirmiausia iveskite intervala!\n";
        return;
    }

    // Triname elementus, kurie patenka į intervalą [a; b]
    int deletedCount = 0; // Skaičiuojame, kiek elementų buvo ištrinta
    while (head && head->data >= listA && head->data <= listB) {
        Node* temp = head;
        head = head->next;
        delete temp;
        deletedCount++;
    }

    if (!head) {
        cout << "Visi elementai buvo istrinti.\n";
        listSize = 0; // Atnaujiname dydį
        return;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr) {
        if (curr->data >= listA && curr->data <= listB) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            deletedCount++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    // Atnaujiname sąrašo dydį
    listSize -= deletedCount;
    cout << "Elementai intervale [" << listA << "; " << listB << "] buvo istrinti.\n";
    cout << "Likusiu elementu skaicius: " << listSize << endl;
}

void findMinAbsPos() {
    if (!listElementsEntered) {
        cout << "Pirmiausia iveskite saraso elementus!\n";
        return;
    }

    int minPos = 0, minAbs = abs(head->data), pos = 0;
    Node* temp = head;

    while (temp) {
        if (abs(temp->data) < minAbs) {
            minAbs = abs(temp->data);
            minPos = pos;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Maziausio pagal absoliucia reiksme elemento vieta sarase: " << minPos << endl;
}

void sumAfterFirstNegative() {
    if (!listElementsEntered) {
        cout << "Pirmiausia iveskite saraso elementus!\n";
        return;
    }

    int sum = 0;
    bool foundFirstNegative = false;
    Node* temp = head;
    string tekstas = "";

    while (temp) {
        if (temp->data < 0 && !foundFirstNegative) {
            foundFirstNegative = true;
        } else if (foundFirstNegative) {
            sum += abs(temp->data);
            tekstas += to_string(temp->data) + "(+)";
        }
        temp = temp->next;
    }

    if (tekstas.empty()) {
        cout << "Nera elementu po pirmojo neigiamo skaiciaus.\n";
    } else {
        cout << tekstas << " => ";
        cout << "Suma po pirmojo neigiamo elemento (pagal absoliucia reiksme): " << sum << endl;
    }
}

void printList() {
    if (!head) {
        cout << "Sarasas yra tuscias.\n";
        return;
    }

    cout << "Elementai sarase: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void listMenu() {
    int choice;
    do {
        cout << "\nVienkrypcio saraso meniu (dydis: " << listSize << "):\n";
        cout << "1. Nustatyti saraso dydi\n";
        cout << (listElementsEntered ? "2. Atnaujinti saraso elementus\n" : "2. Ivesti saraso elementus\n");
        cout << (listIntervalEntered ? "3. Atnaujinti intervala\n" : "3. Ivesti intervalo reiksmes\n");
        cout << "4. Istrinti elementus pagal intervala\n";
        cout << "5. Rasti maziausio pagal absoliucia reiksme elemento vieta sarase\n";
        cout << "6. Rasti suma po pirmojo neigiamo elemento (pagal absoliucia reiksme)\n";
        cout << "7. Atspausdinti sarasa\n";
        cout << "0. palikti\n";
        cout << "Pasirinkite veiksma: ";
        cin >> choice;

        switch (choice) {
            case 1: inputListSize(); break;
            case 2: inputListElements(); break;
            case 3: inputListInterval(); break;
            case 4: deleteElementsInInterval(); break;
            case 5: findMinAbsPos(); break;
            case 6: sumAfterFirstNegative(); break;
            case 7: printList(); break;
            case 0: cout << "exit.\n"; break;
            default: cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
        }
    } while (choice != 0);
}

int main() {
    cout << "Programa 2: Vienkryptis sarasas\n";
    listMenu();

    // Atlaisviname atmintį
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}