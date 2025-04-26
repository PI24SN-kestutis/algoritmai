# Projektas: C++ dinaminiai sąrašai ir dekas

## Aprašymas
Ši C++ programa leidžia naudoti dvikryptį ciklinį sąrašą ir vienkryptį deką be STL bibliotekų.

Pagrindinės galimybės:
- Kurti dvikryptį ciklinį sąrašą;
- Įterpti, šalinti, ieškoti ir spausdinti sąrašo elementus;
- Perkelti sąrašo elementus į deką (po perkėlimo sąrašas ištuštinamas);
- Dirbti su deku: įterpti ir šalinti elementus iš pradžios ir pabaigos;
- Apsauga nuo neteisingų įvesčių (spalvotas klaidos pranešimas ir garsinis signalas);
- Išeinant iš programos automatiškai atlaisvinama visa užimta atmintis (ištrinami sąrašo ir deko elementai).

## Naudojimas
1. Paleiskite programą.
2. Pasirinkite veiksmą iš pateikto meniu:
    - **Sąrašo funkcijos**:
        - Įterpti reikšmes į sąrašą;
        - Pašalinti reikšmę iš sąrašo;
        - Spausdinti sąrašą;
        - Ieškoti reikšmės sąraše;
        - Perkelti sąrašą į deką.
    - **Deko funkcijos**:
        - Spausdinti deką;
        - Įterpti į pradžią arba pabaigą;
        - Pašalinti iš pradžios arba pabaigos.
3. Jeigu padaroma netinkama įvestis, programa leis bandyti įvesti iš naujo.

## Techninės detalės
- **Programavimo kalba**: C++
- **Naudojamos bibliotekos**: `<iostream>`, `<windows.h>`
- **Pastabos**:
    - Dirbama be STL konteinerių;
    - UTF-8 simbolių palaikymas (`SetConsoleOutputCP(65001);`).

## Paleidimo instrukcijos
1. Kompiliuokite programą su C++ palaikančiu kompiliatoriumi (pvz., MinGW arba Visual Studio).
2. Paleiskite vykdomąjį failą.

## Reikalavimai
- Windows operacinė sistema (naudojamas `windows.h`);
- Konsolė su UTF-8 palaikymu.

## Autorius
- Programos kūrėjas: **(Kęstutis Skrebė)**

---

