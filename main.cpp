#include <iostream>
#include <limits>
#include <iomanip> // Pridėta spausdinimui su formatavimu

using namespace std;

int* arr = nullptr;
int n = 0;
int a = 0, b = 0;
bool elementsEntered = false, intervalEntered = false;

void inputArraySize() {
    cout << "Iveskite masyvo dydi: ";
    cin >> n;

    if (arr) {
        delete[] arr;
    }

    arr = new int[n];
    elementsEntered = false;
    intervalEntered = false;
    cout << "Masyvas turi " << n << " elementus.\n";
}

void inputArrayElements() {
    if (n == 0) {
        cout << "Pirmiausia nustatykite masyvo dydi!\n";
        return;
    }
    cout << "Iveskite " << n << " masyvo elementus: " << endl;
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Elementas " << i + 1 << ": ";
            cin >> arr[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Neteisinga ivestis, bandykite dar karta.\n";
            } else {
                break;
            }
        }
    }
    elementsEntered = true;
}

void inputInterval() {
    if (!elementsEntered) {
        cout << "Pirmiausia iveskite masyvo elementus!\n";
        return;
    }
    cout << "Iveskite intervalo reiksmes [a; b]: \n";
    cout << "nuo: ";
    cin >> a;
    cout << "iki: ";
    cin >> b;
    intervalEntered = true;
}

void findMaxAbs() {
    if (!elementsEntered) {
        cout << "Pirmiausia iveskite masyvo elementus!\n";
        return;
    }

    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) > abs(maxVal)) {
            maxVal = arr[i];
        }
    }
    cout << "Didziausias pagal absoliucia reiksme: " << maxVal << endl;
}

void sumAfterFirstPositive() {
    if (!elementsEntered) {
        cout << "Pirmiausia iveskite masyvo elementus!\n";
        return;
    }

    int sum = 0;
    bool foundFirstPositive = false;
    int firstPositiveIndex = -1;
    string tekstas = "";

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            foundFirstPositive = true;
            firstPositiveIndex = i;
            break; // Randame pirmą teigiamą ir nutraukiame ciklą
        }
    }

    if (foundFirstPositive) {
        for (int i = firstPositiveIndex +1; i < n; i++) {
                    sum += abs(arr[i]);
                    tekstas += to_string(arr[i]) + "(+)";

        }
    }

    if (tekstas.empty()) {
        cout << "Nera neigiamu elementu po pirmojo teigiamo skaiciaus.\n";
    } else {
        cout << tekstas << " => ";
        cout << "Suma po pirmojo teigiamo elemento (pagal absoliucia reiksme): " << sum << endl;
    }
}

void rearrangeArray() {
    if (!intervalEntered) {
        cout << "Pirmiausia įveskite intervalą!\n";
        return;
    }

    int* temp = new int[n];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < a || arr[i] > b) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
    cout << "Pakeistas masyvas: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Nuo |" << a << "| iki |" << b << endl;
}

void printArray() {
    if (!elementsEntered) {
        cout << "Pirmiausia iveskite masyvo elementus!\n";
        return;
    }

    cout << "Masyvo elementai: ";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << arr[i]; // setw naudojamas formatavimui
    }
    cout << endl;
}

void arrayMenu() {
    int choice;
    do {
        cout << "\nVienmacio masyvo meniu (dydis: " << n << "):\n";
        cout << "1. Nustatyti masyvo dydi\n";
        cout << (elementsEntered ? "2. Atnaujinti masyva\n" : "2. Ivesti masyvo elementus\n");
        cout << (intervalEntered ? "3. Atnaujinti intervala\n" : "3. Ivesti intervalo reiksmes\n");
        cout << "4. Rasti didziausia pagal absoliucia reiksme elementa\n";
        cout << "5. Apskaiciuoti suma po pirmojo teigiamo elemento\n";
        cout << "6. Perkelti elementus pagal intervala\n";
        cout << "7. Spausdinti masyva\n"; // Naujas meniu punktas
        cout << "0. Grizti i pagrindini meniu\n";
        cout << "Pasirinkite veiksma: ";
        cin >> choice;

        switch (choice) {
            case 1: inputArraySize(); break;
            case 2: inputArrayElements(); break;
            case 3: inputInterval(); break;
            case 4: findMaxAbs(); break;
            case 5: sumAfterFirstPositive(); break;
            case 6: rearrangeArray(); break;
            case 7: printArray(); break; // Naujas case
            case 0: cout << "Griztama i pagrindini meniu.\n"; break;
            default: cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
        }
    } while (choice != 0);
}

int main() {
    cout << "Programa 1: Vienmatis masyvas\n";
    arrayMenu();

    if (arr) {
        delete[] arr;
    }

    return 0;
}