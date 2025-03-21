#include <iostream>
#include <windows.h>
using namespace std;
/*
Šioje užduotyje negalima naudoti STL bibliotekų.
Sukurti ciklinį vienkryptį sąrašą, realizuojant duomenų įvedimą, įterpimą prieš ir po nurodyto elemento, norimo elemento pašalinimą bei didžiausio elemento radimą. Realizuoti funkcijas, kurios:
a. Pirmus 6 neigiamus skaičius perkelia į dvikryptį ciklinį sąrašą.
b. Apskaičiuoja kiek dvikrypčiame cikliniame sąraše esančių lyginių elementų pagal absoliučią reikšmę suma yra didesnė už vienkrypčio ciklinio sąrašo visų nelyginių elementų sumą.
c. Panaikina ciklinio sąrašo pirmąjį, vidurinį ir paskutinį elementą, ir atspausdina juos ekrane

*/


struct Vienkryptis {
    int data;
    Vienkryptis* next;
};

struct Dvikryptis {
    int data;
    Dvikryptis* next;
    Dvikryptis* prev;
};


void insertEnd(Vienkryptis*& head, int value) {
    Vienkryptis* newVienkryptis = new Vienkryptis{value, nullptr};
    if (!head) {
        head = newVienkryptis;
        head->next = head;
    } else {
        Vienkryptis* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newVienkryptis;
        newVienkryptis->next = head;
    }
}

void insertBefore(Vienkryptis*& head, int target, int value) {
    if (!head) return;
    Vienkryptis* newVienkryptis = new Vienkryptis{value, nullptr};
    if (head->data == target) {
        Vienkryptis* last = head;
        while (last->next != head) last = last->next;
        newVienkryptis->next = head;
        last->next = newVienkryptis;
        head = newVienkryptis;
        return;
    }

    Vienkryptis* prev = head, *curr = head->next;
    while (curr != head) {
        if (curr->data == target) {
            newVienkryptis->next = curr;
            prev->next = newVienkryptis;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    delete newVienkryptis;
}

void insertAfter(Vienkryptis* head, int target, int value) {
    if (!head) return;
    Vienkryptis* curr = head;
    do {
        if (curr->data == target) {
            Vienkryptis* newVienkryptis = new Vienkryptis{value, curr->next};
            curr->next = newVienkryptis;
            return;
        }
        curr = curr->next;
    } while (curr != head);
}

void deleteElement(Vienkryptis*& head, int value) {
    if (!head) return;
    Vienkryptis* curr = head, *prev = nullptr;
    do {
        if (curr->data == value) {
            if (curr == head) {
                Vienkryptis* last = head;
                while (last->next != head) last = last->next;
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                    return;
                }
                head = head->next;
                last->next = head;
                delete curr;
                return;
            } else {
                prev->next = curr->next;
                delete curr;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

int findMax(Vienkryptis* head) {
    if (!head) return -999999;
    int maxVal = head->data;
    Vienkryptis* temp = head->next;
    while (temp != head) {
        if (temp->data > maxVal) maxVal = temp->data;
        temp = temp->next;
    }
    return maxVal;
}

// a. Perkelti 6 neigiamus į dvikryptį sąrašą
void transferNegatives(Vienkryptis*& head, Dvikryptis*& dHead) {
    if (!head) return;
    int count = 0;
    Vienkryptis* curr = head;
    Vienkryptis* prev = nullptr;

    // Jei sąrašas tuščias arba elementų nėra – išeinam
    bool done = false;
    while (head && count < 6 && !done) {
        curr = head;
        prev = nullptr;
        int traversed = 0;

        do {
            Vienkryptis* next = curr->next;
            traversed++;

            if (curr->data < 0) {
                // 1. Įterpiame į dvikryptį sąrašą
                Dvikryptis* newDvikryptis = new Dvikryptis{curr->data, nullptr, nullptr};
                if (!dHead) {
                    dHead = newDvikryptis;
                    dHead->next = dHead;
                    dHead->prev = dHead;
                } else {
                    Dvikryptis* last = dHead->prev;
                    last->next = newDvikryptis;
                    newDvikryptis->prev = last;
                    newDvikryptis->next = dHead;
                    dHead->prev = newDvikryptis;
                }

                // 2. Pašaliname iš vienkrypčio
                if (curr == head) {
                    // Jei pašalinamas galva
                    if (head->next == head) {
                        delete head;
                        head = nullptr;
                        done = true;
                        break;
                    } else {
                        Vienkryptis* last = head;
                        while (last->next != head) last = last->next;
                        head = head->next;
                        last->next = head;
                        delete curr;
                    }
                } else {
                    prev->next = curr->next;
                    delete curr;
                }

                count++;
                break; // Pradėti ciklą iš naujo
            }

            prev = curr;
            curr = next;

        } while (curr != head && traversed <= 100); // apsauga nuo begalybės
    }
}


// b. Apskaičiuoti lyginių (|reikšmė|) sumą dvikryptiame sąraše ir palyginti su nelyginių vienkryptiame
int compareSums(Vienkryptis* sHead, Dvikryptis* dHead) {
    int evenSum = 0, oddSum = 0;
    Dvikryptis* dCurr = dHead;
    if (dCurr) {
        do {
            if (abs(dCurr->data) % 2 == 0)
                evenSum += abs(dCurr->data);
            dCurr = dCurr->next;
        } while (dCurr != dHead);
    }

    Vienkryptis* sCurr = sHead;
    if (sCurr) {
        do {
            if (sCurr->data % 2 != 0)
                oddSum += sCurr->data;
            sCurr = sCurr->next;
        } while (sCurr != sHead);
    }

    return evenSum > oddSum;
}

// c. Panaikinti pirmą, vidurinį ir paskutinį elementą
void deleteSpecial(Vienkryptis*& head) {
    if (!head) return;

    int count = 0;
    Vienkryptis* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    if (count < 3) return;

    // Pirmas
    cout << "Pirmas: " << head->data << endl;
    deleteElement(head, head->data);

    // Vidurinis
    int midIndex = count / 2;
    temp = head;
    for (int i = 0; i < midIndex - 1; i++) temp = temp->next;
    cout << "Vidurinis: " << temp->next->data << endl;
    deleteElement(head, temp->next->data);

    // Paskutinis
    temp = head;
    while (temp->next->next != head) temp = temp->next;
    cout << "Paskutinis: " << temp->next->data << endl;
    deleteElement(head, temp->next->data);
}

// Spausdinimas
void printList(Vienkryptis* head) {
    if (!head) {
        cout << "Tuščias\n";
        return;
    }
    Vienkryptis* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

void printDList(Dvikryptis* head) {
    if (!head) {
        cout << "Tuščias\n";
        return;
    }
    Dvikryptis* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

bool getValidInt(int &num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear();               // Išvalom klaidos vėliavėlę
        cin.ignore(10000, '\n');   // Pašalinam netinkamą įvestį iš buferio
        return false;
    }
    return true;
}







// --- Meniu ---
int main() {
    SetConsoleOutputCP(CP_UTF8); //terminalas priima lietuviškus simbolius
    Vienkryptis* list = nullptr;
    Dvikryptis* dlist = nullptr;
    int choice, val, ref;

    do {
        cout << "\n--- MENIU ---\n";
        cout << "1. Pridėti elementą į vienkryptį sąrašą\n";
        cout << "2. Įterpti prieš\n";
        cout << "3. Įterpti po\n";
        cout << "4. Pašalinti elementą\n";
        cout << "5. Rasti didžiausią\n";
        cout << "6. Perkelti 6 neigiamus į dvikryptį sąrašą\n";
        cout << "7. Palyginti sumas\n";
        cout << "8. Panaikinti pirmą, vidurinį ir paskutinį\n";
        cout << "9. Spausdinti sąrašus\n";
        cout << "0. Išeiti\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int kiek;
                while (true) {
                    cout << "Kiek elementų norite pridėti? ";
                    if (getValidInt(kiek) && kiek > 0) break;
                    cout << "Įveskite teigiamą sveiką skaičių.\n";
                }
                for (int i = 0; i < kiek; i++) {
                    int val;
                    while (true) {
                        cout << "Reikšmė #" << (i + 1) << ": ";
                        if (getValidInt(val)) break;
                        cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                    }
                    insertEnd(list, val);
                }
                break;
            }


            case 2: {
                int kiek;
                while (true) {
                    cout << "Kiek elementų norite įterpti ? ";
                    if (getValidInt(kiek) && kiek > 0) break;
                    cout << "Įveskite teigiamą sveiką skaičių.\n";
                }
                for (int i = 0; i < kiek; i++) {
                    int val, ref;
                    while (true) {
                        cout << "Reikšmė #" << (i + 1) << ": ";
                        if (getValidInt(val)) break;
                        cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                    }
                    while (true) {
                        cout << "Įterpti prieš: ";
                        if (getValidInt(ref)) break;
                        cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                    }
                    insertBefore(list, ref, val);
                }
                break;
            }


            case 3: {
                int kiek;
                while (true) {
                    cout << "Kiek elementų norite įterpti ? ";
                    if (getValidInt(kiek) && kiek > 0) break;
                    cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                }
                for (int i = 0; i < kiek; i++) {
                    int val, ref;

                    while (true) {
                        cout << "Reikšmė #" << (i + 1) << ": ";
                        if (getValidInt(val)) break;
                        cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                    }

                    while (true) {
                        cout << "Įterpti po: ";
                        if (getValidInt(ref)) break;
                        cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                    }

                    insertAfter(list, ref, val);
                }
                break;
            }


            case 4: {
                while (true) {
                    cout << "Kurį šalinti: ";
                    if (getValidInt(val)) break;
                    cout << "Neteisinga įvestis. Bandykite dar kartą.\n";
                }
                deleteElement(list, val);
                break;
            }

            case 5:
                cout << "Didžiausias: " << findMax(list) << endl;
                break;
            case 6:
                transferNegatives(list, dlist);
                break;
            case 7: {
                int evenSum = 0, oddSum = 0;

                // Suskaičiuojam dvikrypčio sąrašo lyginių absoliučių reikšmių sumą
                Dvikryptis* dCurr = dlist;
                if (dCurr) {
                    do {
                        if (abs(dCurr->data) % 2 == 0)
                            evenSum += abs(dCurr->data);
                        dCurr = dCurr->next;
                    } while (dCurr != dlist);
                }

                // Suskaičiuojam vienkrypčio sąrašo nelyginių reikšmių sumą
                Vienkryptis* sCurr = list;
                if (sCurr) {
                    do {
                        if (sCurr->data % 2 != 0)
                            oddSum += sCurr->data;
                        sCurr = sCurr->next;
                    } while (sCurr != list);
                }

                // Parodome abi sumas
                cout << "Dvikrypčio sąrašo lyginių (pagal absoliutą) suma: " << evenSum << endl;
                cout << "Vienkrypčio sąrašo nelyginių suma: " << oddSum << endl;

                if (evenSum > oddSum)
                    cout << "➡️ Dvikrypčio sąrašo suma yra didesnė.\n";
                else if (evenSum < oddSum)
                    cout << "➡️ Vienkrypčio sąrašo suma yra didesnė.\n";
                else
                    cout << "➡️ Abiejų sumos yra lygios.\n";

                break;
            }

            case 8:
                deleteSpecial(list);
                break;
            case 9:
                cout << "Vienkryptis: "; printList(list);
                cout << "Dvikryptis: "; printDList(dlist);
                break;
        }
    } while (choice != 0);

    return 0;
}