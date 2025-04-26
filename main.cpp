#include <iostream>
#include <windows.h>
using namespace std;

/**
 * Sukurti dinaminį dvikryptį ciklinį sąrašą,
 * realizuojant elemento įterpimo, pašalinimo, spausdinimo bei paieškos funkcijas.
 * Perkelti to sąrašo visus elementus į vienkryptį sąrašą, kuris turi būti realizuotas kaip dekas
 * (įterpimas į priekį ar į galą, pašalinimas iš pradžios ar iš galo).
 */

// Dvikrypcio ciklinio saraso elemento struktura
struct DvikryptisMazgas {
    int duomenys;
    DvikryptisMazgas* kitas;
    DvikryptisMazgas* ankstesnis;
};

// Vienkrypcio deko elemento struktura
struct DekasMazgas {
    int duomenys;
    DekasMazgas* kitas;
};

// Pagrindiniai sarasu rodykles
DvikryptisMazgas* pradzia = nullptr;
DekasMazgas* dekPradzia = nullptr;
DekasMazgas* dekPabaiga = nullptr;

// Funkciju deklaracijos
void iterptiMazga(int reiksme);
void salintiMazga(int reiksme);
void spausdintiSarasa();
DvikryptisMazgas* ieskotiMazgo(int reiksme);
void perkeltiIDeka();
void iterptiIPradziaDekas(int reiksme);
void iterptiIPabaigaDekas(int reiksme);
void salintiIsPradziosDekas();
void salintiIsPabaigosDekas();
void spausdintiDeka();
void istrintiDeka();
void istrintiSarasa();
void meniu();

void klaida() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Raudona spalva
    cout << "Neteisinga įvestis. Bandykite dar kartą: ";
    Beep(750, 300);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Grąžinti baltą spalvą
    cin.clear();
    cin.ignore(10000, '\n');
}


int main() {
    SetConsoleOutputCP(65001);
    meniu();
    return 0;
}

// Funkciju implementacijos
void iterptiMazga(int reiksme) {
    DvikryptisMazgas* naujas = new DvikryptisMazgas{reiksme, nullptr, nullptr};

    if (!pradzia) {
        pradzia = naujas;
        pradzia->kitas = pradzia;
        pradzia->ankstesnis = pradzia;
    } else {
        DvikryptisMazgas* pabaiga = pradzia->ankstesnis;
        pabaiga->kitas = naujas;
        naujas->ankstesnis = pabaiga;
        naujas->kitas = pradzia;
        pradzia->ankstesnis = naujas;
    }
}

void salintiMazga(int reiksme) {
    if (!pradzia) {
        cout << "Sarasas tuscias.\n";
        return;
    }

    DvikryptisMazgas* dabartinis = pradzia;
    do {
        if (dabartinis->duomenys == reiksme) {
            if (dabartinis->kitas == dabartinis) {
                delete dabartinis;
                pradzia = nullptr;
            } else {
                dabartinis->ankstesnis->kitas = dabartinis->kitas;
                dabartinis->kitas->ankstesnis = dabartinis->ankstesnis;
                if (dabartinis == pradzia)
                    pradzia = dabartinis->kitas;
                delete dabartinis;
            }
            cout << "Elementas pasalintas.\n";
            return;
        }
        dabartinis = dabartinis->kitas;
    } while (dabartinis != pradzia);

    cout << "Elementas nerastas.\n";
}

void spausdintiSarasa() {
    if (!pradzia) {
        cout << "Sarasas tuscias.\n";
        return;
    }
    DvikryptisMazgas* dabartinis = pradzia;
    cout << "Sarasas: ";
    do {
        cout << dabartinis->duomenys << " ";
        dabartinis = dabartinis->kitas;
    } while (dabartinis != pradzia);
    cout << endl;
}

DvikryptisMazgas* ieskotiMazgo(int reiksme) {
    if (!pradzia) return nullptr;

    DvikryptisMazgas* dabartinis = pradzia;
    do {
        if (dabartinis->duomenys == reiksme)
            return dabartinis;
        dabartinis = dabartinis->kitas;
    } while (dabartinis != pradzia);

    return nullptr;
}

void perkeltiIDeka() {
    if (!pradzia) {
        cout << "Sąrašas tuščias.\n";
        return;
    }
    DvikryptisMazgas* dabartinis = pradzia;
    do {
        iterptiIPabaigaDekas(dabartinis->duomenys);
        dabartinis = dabartinis->kitas;
    } while (dabartinis != pradzia);

    istrintiSarasa();

    cout << "Elementai perkelti į deką.\n";
}

void istrintiSarasa() {
    if (!pradzia) return;

    DvikryptisMazgas* dabartinis = pradzia;
    do {
        DvikryptisMazgas* sekantis = dabartinis->kitas;
        delete dabartinis;
        dabartinis = sekantis;
    } while (dabartinis != pradzia);

    pradzia = nullptr;
}
void istrintiDeka() {
    while (dekPradzia) {
        DekasMazgas* laikinas = dekPradzia;
        dekPradzia = dekPradzia->kitas;
        delete laikinas;
    }
    dekPabaiga = nullptr;
}


void iterptiIPradziaDekas(int reiksme) {
    DekasMazgas* naujas = new DekasMazgas{reiksme, dekPradzia};
    dekPradzia = naujas;
    if (!dekPabaiga) dekPabaiga = dekPradzia;
}

void iterptiIPabaigaDekas(int reiksme) {
    DekasMazgas* naujas = new DekasMazgas{reiksme, nullptr};
    if (!dekPabaiga) {
        dekPradzia = dekPabaiga = naujas;
    } else {
        dekPabaiga->kitas = naujas;
        dekPabaiga = naujas;
    }
}

void salintiIsPradziosDekas() {
    if (!dekPradzia) {
        cout << "Dekas tuscias.\n";
        return;
    }
    DekasMazgas* laikinas = dekPradzia;
    dekPradzia = dekPradzia->kitas;
    if (!dekPradzia) dekPabaiga = nullptr;
    delete laikinas;
    cout << "Elementas pasalintas is pradzios.\n";
}

void salintiIsPabaigosDekas() {
    if (!dekPabaiga) {
        cout << "Dekas tuscias.\n";
        return;
    }
    if (dekPradzia == dekPabaiga) {
        delete dekPradzia;
        dekPradzia = dekPabaiga = nullptr;
    } else {
        DekasMazgas* dabartinis = dekPradzia;
        while (dabartinis->kitas != dekPabaiga) {
            dabartinis = dabartinis->kitas;
        }
        delete dekPabaiga;
        dekPabaiga = dabartinis;
        dekPabaiga->kitas = nullptr;
    }
    cout << "Elementas pasalintas is pabaigos.\n";
}

void spausdintiDeka() {
    if (!dekPradzia) {
        cout << "Dekas tuscias.\n";
        return;
    }
    DekasMazgas* dabartinis = dekPradzia;
    cout << "Dekas: ";
    while (dabartinis) {
        cout << dabartinis->duomenys << " ";
        dabartinis = dabartinis->kitas;
    }
    cout << endl;
}

void meniu() {
    int pasirinkimas, reiksme;
    do {
        cout << "\n╔═════════════════════════╗" << endl;
        cout << "║        Sąrašo meniu     ║" << endl;
        cout << "╠═════════════════════════╣" << endl;
        cout << "║  1. Įterpti į sąrašą    ║" << endl;
        cout << "║  2. Pašalinti iš sąrašo ║" << endl;
        cout << "║  3. Spausdinti sąrašą   ║" << endl;
        cout << "║  4. Surasti elementą    ║" << endl;
        cout << "║  5. Perkelti į deką     ║" << endl;
        cout << "╠═════════════════════════╣" << endl;
        cout << "║        Deko meniu       ║" << endl;
        cout << "╠═════════════════════════╣" << endl;
        cout << "║  6. Spausdinti deką     ║" << endl;
        cout << "║  7. Įterpti į pradžią   ║" << endl;
        cout << "║  8. Įterpti į pabaigą   ║" << endl;
        cout << "║  9. Pašalinti iš pradž. ║" << endl;
        cout << "║ 10. Pašalinti iš pabaig.║" << endl;
        cout << "╠═════════════════════════╣" << endl;
        cout << "║  0. Baigti              ║" << endl;
        cout << "╚═════════════════════════╝" << endl;
        cout << "Pasirinkimas: ";
        while (!(cin >> pasirinkimas) || pasirinkimas < 0 || pasirinkimas > 10) {
            klaida();
        }

        switch (pasirinkimas) {
            case 1: {
                int kiekis;
                cout << "Kiek skaičių norite įterpti: ";
                while (!(cin >> kiekis) || kiekis <= 0) {
                    klaida();
                }
                for (int i = 0; i < kiekis; i++) {
                    cout << "Įveskite reikšmę: ";
                    while (!(cin >> reiksme)) {
                        klaida();
                    }
                    iterptiMazga(reiksme);
                }
                break;
            }
            case 2:
                cout << "Įveskite reikšmę: ";
                while (!(cin >> reiksme)) {
                    klaida();
                }
                salintiMazga(reiksme);
                break;
            case 3:
                spausdintiSarasa();
                break;
            case 4:
                cout << "Įveskite ieškomą reikšmę: ";
                while (!(cin >> reiksme)) {
                    klaida();
                }
                if (ieskotiMazgo(reiksme))
                    cout << "Elementas rastas.\n";
                else
                    cout << "Elementas nerastas.\n";
                break;
            case 5:
                perkeltiIDeka();
                break;
            case 6:
                spausdintiDeka();
                break;
            case 7:
                cout << "Įveskite reikšmę: ";
                while (!(cin >> reiksme)) {
                    klaida();
                }
                iterptiIPradziaDekas(reiksme);
                break;
            case 8:
                cout << "Įveskite reikšmę: ";
                while (!(cin >> reiksme)) {
                    klaida();
                }
                iterptiIPabaigaDekas(reiksme);
                break;
            case 9:
                salintiIsPradziosDekas();
                break;
            case 10:
                salintiIsPabaigosDekas();
                break;
            case 0:

                istrintiSarasa();
                istrintiDeka();
                cout << "Programa baigta.\n";
                break;
        }
    } while (pasirinkimas != 0);
}
