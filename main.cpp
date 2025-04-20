#include <iostream>
#include <list>
#include <windows.h>

/**
 *
 * Duotas sveikas skaičius n. Skaičiai a1, a2, … , an surašyti į sąrašą.
 * Pakeisti sąrašą taip, kad pradžioje eitų tik teigiami, o po jų neteigiami.
 * Teigiamų ir neteigiamų skaičių tvarka išlieka tokia pati.
 */
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    std::cout << "Įveskite skaičių kiekį: ";
    std::cin >> n;

    std::list<int> original;
    std::cout << "Įveskite " << n << " skaičius:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        original.push_back(x);
    }

    std::list<int> positive;
    std::list<int> nonPositive;

    for (int x : original) {
        if (x > 0) {
            positive.push_back(x);
        } else {
            nonPositive.push_back(x);
        }
    }

    // Sujungiame sąrašus
    positive.splice(positive.end(), nonPositive);

    std::cout << "Pakeistas sąrašas:\n";
    for (int x : positive) {
        std::cout << x << " ";
    }

    return 0;
}
