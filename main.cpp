#include <iostream>
#include <windows.h>
#include <utility> // dėl std::pair

/**
 *Simbolius (raides, skyrybos simbolius bei tarpus) įrašykite į dvikryptį sąrašą.
 *Suskaičiuoti kokia mažoji raidė pasikartoja dažniausia.
 */


using namespace std;

struct Dvikryptis {
    char data;
    Dvikryptis* kitas;
    Dvikryptis* ankstesnis;
};

class DvikryptisLinkedList {
public:
    Dvikryptis* head;
    Dvikryptis* tail;

    DvikryptisLinkedList() : head(nullptr), tail(nullptr) {}

    void append(char ch) {
        Dvikryptis* newNode = new Dvikryptis{ch, nullptr, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->ankstesnis = tail;
            tail->kitas = newNode;
            tail = newNode;
        }
    }

    int countSkaiciuokle(char ch) {
        int count = 0;
        Dvikryptis* curr = head;
        while (curr) {
            if (curr->data == ch)
                count++;
            curr = curr->kitas;
        }
        return count;
    }

    pair<char, int> mostDazniausiaiLowercase() {
        Dvikryptis* curr = head;
        char mostFreqChar = '\0'; // tuščias simbolis
        int maxCount = 0;

        while (curr) {
            char ch = curr->data;
            if ((ch >= 'a' && ch <= 'z') || ch == ' ') {
                int count = countSkaiciuokle(ch);
                if (count > maxCount) {
                    maxCount = count;
                    mostFreqChar = ch;
                }
            }
            curr = curr->kitas;
        }

        return {mostFreqChar, maxCount};
    }


    ~DvikryptisLinkedList() {
        Dvikryptis* curr = head;
        while (curr) {
            Dvikryptis* kitas = curr->kitas;
            delete curr;
            curr = kitas;
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    DvikryptisLinkedList list;
    string input;
    cout << "Įveskite tekstą: ";
    getline(cin, input);

    for (char ch : input) {
        list.append(ch);
    }

    pair<char, int> result = list.mostDazniausiaiLowercase();
    if (result.second > 0) {
        if (result.first == ' ')
            cout << "Dažniausiai pasikartojęs simbolis yra tarpas: |_| (pasikartojo " << result.second << " kartus)" << endl;
        else
            cout << "Dažniausiai pasikartojanti mažoji raidė: '" << result.first
                 << "' (pasikartojo " << result.second << " kartus)" << endl;
    } else {
        cout << "Mažųjų raidžių ir tarpo simbolių nerasta." << endl;
    }

    return 0;
}

