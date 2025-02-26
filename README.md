# Vienkryptis sąrašas

Ši C++ programa atlieka įvairias operacijas su vienkrypčiu sąrašu.

## Funkcionalumas

Programa leidžia:

* Nustatyti sąrašo dydį.
* Įvesti sąrašo elementus.
* Įvesti intervalą [a; b] elementų šalinimui.
* Ištrinti elementus, kurie patenka į intervalą [a; b].
* Rasti mažiausio pagal absoliučią reikšmę elemento vietą sąraše.
* Apskaičiuoti sumą elementų, esančių po pirmojo neigiamo elemento (pagal absoliutų dydį).
* Atspausdinti sąrašo elementus.

## Naudojimas

1.  **Kompiliavimas**:

    ```bash
    g++ main.cpp -o linked_list_program
    ```

2.  **Vykdymas**:

    ```bash
    ./linked_list_program
    ```

3.  **Meniu**:

    Programa turi meniu, kuriame galite pasirinkti norimą veiksmą:

    * 1: Nustatyti sąrašo dydį
    * 2: Įvesti/atnaujinti sąrašo elementus
    * 3: Įvesti/atnaujinti intervalo reikšmes
    * 4: Ištrinti elementus pagal intervalą
    * 5: Rasti mažiausio pagal absoliutų dydį elemento vietą sąraše
    * 6: Apskaičiuoti sumą po pirmojo neigiamo elemento
    * 7: Atspausdinti sąrašą
    * 0: Palikti

## Pavyzdžiai

### Sąrašo sukūrimas ir elementų įvedimas

1.  Pasirinkite 1, kad nustatytumėte sąrašo dydį (pvz., 5).
2.  Pasirinkite 2, kad įvestumėte sąrašo elementus (pvz., -2, 5, -1, 3, -4).

### Elementų šalinimas pagal intervalą

1.  Įvedus elementus, pasirinkite 3, kad įvestumėte intervalą (pvz., [0; 3]).
2.  Pasirinkite 4.
3.  Programa ištrins elementus, kurie patenka į intervalą (pvz., -2, -1, 3).

### Mažiausios absoliučios reikšmės radimas

1.  Įvedus elementus, pasirinkite 5.
2.  Programa parodys mažiausios absoliučios reikšmės elemento vietą sąraše (pvz., vieta 2, jei elementas -1).

### Sumos po pirmojo neigiamo elemento skaičiavimas

1.  Įvedus elementus, pasirinkite 6.
2.  Programa parodys sumą elementų, esančių po pirmojo neigiamo elemento (pvz., 5 + 3 + 4 = 12).

### Sąrašo spausdinimas

1.  Įvedus elementus, pasirinkite 7.
2.  Programa atspausdins sąrašą.

## Autorius

[Kęstutis Skrebė]

## Pastabos

* Programa naudoja vienkryptį sąrašą, kuris yra dinamiška duomenų struktūra.
* Įvedant duomenis, programa tikrina, ar įvestis yra teisinga.
* Programa atlaisvina atmintį po naudojimo.