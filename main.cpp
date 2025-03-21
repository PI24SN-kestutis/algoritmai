#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <windows.h>

using namespace std;

/*
 *
Sukurti sąrašą, realizuojant duomenų įvedimą, įterpimą prieš ir po nurodyto elemento, norimo elemento pašalinimą bei didžiausio elemento radimą. Realizuoti funkcijas, kurios:
a. Visus skaičius nuo paskutiniojo 0 perkelia į vienkryptį ciklinį sąrašą.
b. Apskaičiuoja kiek cikliniame sąraše esančių elementų kurie yra didesnį už dvikrypčio sąrašo visų elementų vidurkį.
c. Panaikina ciklinio sąrašo visus elementus esančios tarp trečiojo ir priešpaskutinio elemento bei atspausdina juos ekrane.
 */

int safeInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear(); // išvalyti klaidos vėliavėlę
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // pašalinti netinkamą įvestį
            cout << "Netinkama įvestis. Bandykite dar kartą.\n";
        } else {
            return value;
        }
    }
}

void inputList(list<int>& lst) {
    int n = safeInput("Kiek elementų norite įvesti? ");
    for (int i = 0; i < n; ++i) {
        int x = safeInput("Įveskite elementą: ");
        lst.push_back(x);
    }
}



void insertBefore(list<int>& lst, int value, int target) {
    auto it = find(lst.begin(), lst.end(), target);
    if (it != lst.end()) {
        lst.insert(it, value);
    }
}

void insertAfter(list<int>& lst, int value, int target) {
    auto it = find(lst.begin(), lst.end(), target);
    if (it != lst.end()) {
        ++it;
        lst.insert(it, value);
    }
}

void removeElement(list<int>& lst, int value) {
    lst.remove(value);
}

int findMax(const list<int>& lst) {
    return *max_element(lst.begin(), lst.end());
}

//Perkelti skaičius po paskutiniojo 0 į ciklinį sąrašą
list<int> extractFromLastZero(const list<int>& original) {
    list<int> cyclicList;
    auto rit = find(original.rbegin(), original.rend(), 0);
    if (rit == original.rend()) return cyclicList;

    auto it = rit.base(); // base() grąžina iteratorių į elementą PO paskutiniojo 0
    while (it != original.end()) {
        cyclicList.push_back(*it++);
    }
    return cyclicList;
}


//Kiek elementų cikliniame sąraše > vidurkio
pair<int, double> countGreaterThanAverage(const list<int>& cyclic, const list<int>& original) {
    if (original.empty()) return {0, 0.0};

    double avg = accumulate(original.begin(), original.end(), 0.0) / original.size();

    int count = count_if(cyclic.begin(), cyclic.end(), [avg](int x) {
        return x > avg;
    });

    return {count, avg};
}


//Panaikinti tarp trečiojo ir priešpaskutinio ciklinio sąrašo elementus
void removeBetweenThirdAndPenultimate(list<int>& cyclic) {
    if (cyclic.empty()) {
        cout << "Ciklinis sąrašas tuščias!\n";
        return;
    }

    if (cyclic.size() < 4) {
        cout << "Cikliniame sąraše per mažai elementų (reikia bent 4).\n";
        return;
    }

    auto third = cyclic.begin();
    advance(third, 2); // trečias elementas

    auto penultimate = cyclic.end();
    advance(penultimate, -2); // priešpaskutinis

    list<int> removedElements(third, penultimate);
    cyclic.erase(third, penultimate);

    cout << "Pašalinti elementai: ";
    for (int x : removedElements) {
        cout << x << " ";
    }
    cout << endl;
}










int main() {
    SetConsoleOutputCP(CP_UTF8); //terminalas priima lietuviškus simbolius
    list<int> original;
    list<int> cyclic;
    int choice;

    do {
        cout << "\n====== MENIU ======\n";
        cout << "1. Įvesti elementus į dvikryptį sąrašą\n";
        cout << "2. Įterpti elementą PRIEŠ kitą\n";
        cout << "3. Įterpti elementą PO kito\n";
        cout << "4. Pašalinti nurodytą elementą\n";
        cout << "5. Rasti didžiausią elementą\n";
        cout << "6. Sukurti ciklinį sąrašą nuo paskutinio 0\n";
        cout << "7. Kiek elementų cikliniame > už dvikrypčio vidurkį\n";
        cout << "8. Pašalinti tarp 3-io ir priešpaskutinio (ciklinis)\n";
        cout << "9. Spausdinti abu sąrašus\n";
        cout << "0. Išeiti\n";
        cout << "Pasirinkite: ";
        cin >> choice;

        switch (choice) {
            case 1:
                original.clear();
            inputList(original);
            break;

            case 2: {
                int value = safeInput("Kokį elementą įterpti? ");
                int target = safeInput("Prieš kurį elementą? ");
                insertBefore(original, value, target);
                break;
            }

            case 3: {
                int value = safeInput("Kokį elementą įterpti? ");
                int target = safeInput("Po kurio elemento? ");
                insertAfter(original, value, target);
                break;
            }

            case 4: {
                int value = safeInput("Kokį elementą pašalinti? ");
                removeElement(original, value);
                break;
            }

            case 5:
                if (!original.empty())
                    cout << "Didžiausias elementas: " << findMax(original) << endl;
                else
                    cout << "Dvikryptis sąrašas tuščias!\n";
            break;

            case 6:
                cyclic = extractFromLastZero(original);
            if (!cyclic.empty())
                cout << "Ciklinis sąrašas sukurtas.\n";
            else
                cout << "Po paskutiniojo 0 nėra elementų. Ciklinis sąrašas tuščias.\n";
            break;

            case 7:
                if (cyclic.empty()) {
                    cout << "Ciklinis sąrašas tuščias!\n";
                } else if (original.empty()) {
                    cout << "Dvikryptis sąrašas tuščias – negalima apskaičiuoti vidurkio.\n";
                } else {
                    auto [count, avg] = countGreaterThanAverage(cyclic, original);
                    cout << "Dvikrypčio sąrašo vidurkis: " << avg << endl;
                    cout << "Cikliniame sąraše " << count
                         << " elementų yra didesni už šį vidurkį.\n";
                }
            break;


            case 8:
                removeBetweenThirdAndPenultimate(cyclic);
            break;

            case 9:
                cout << "Dvikryptis sąrašas: ";
            for (int x : original) cout << x << " ";
            cout << "\nCiklinis sąrašas: ";
            if (cyclic.empty()) cout << "(tuščias)";
            else for (int x : cyclic) cout << x << " ";
            cout << endl;
            break;

            case 0:
                cout << "Programa baigta.\n";
            break;

            default:
                cout << "Neteisingas pasirinkimas!\n";
        }


    } while (choice != 0);

    return 0;
}

