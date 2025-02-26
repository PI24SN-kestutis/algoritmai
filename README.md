# Vienmatis masyvas

Ši C++ programa atlieka įvairias operacijas su vienmačiu masyvu.

## Funkcionalumas

Programa leidžia:

* Nustatyti masyvo dydį.
* Įvesti masyvo elementus.
* Įvesti intervalą [a; b].
* Rasti didžiausią pagal absoliučią reikšmę elementą.
* Apskaičiuoti sumą elementų, esančių po pirmojo teigiamo elemento (pagal absoliutų dydį).
* Pertvarkyti masyvą taip, kad pirmiausia eitų elementai, priklausantys intervalui [a; b], o paskui likę elementai.
* Atspausdinti masyvo elementus.

## Naudojimas

1.  **Kompiliavimas**:

    ```bash
    g++ main.cpp -o array_program
    ```

2.  **Vykdymas**:

    ```bash
    ./array_program
    ```

3.  **Meniu**:

    Programa turi meniu, kuriame galite pasirinkti norimą veiksmą:

    * 1: Nustatyti masyvo dydį
    * 2: Įvesti/atnaujinti masyvo elementus
    * 3: Įvesti/atnaujinti intervalo reikšmes
    * 4: Rasti didžiausią pagal absoliutų dydį elementą
    * 5: Apskaičiuoti sumą po pirmojo teigiamo elemento
    * 6: Perkelti elementus pagal intervalą
    * 7: Spausdinti masyva
    * 0: Grįžti į pagrindinį meniu

## Pavyzdžiai

### Masyvo sukūrimas ir elementų įvedimas

1.  Pasirinkite 1, kad nustatytumėte masyvo dydį (pvz., 5).
2.  Pasirinkite 2, kad įvestumėte masyvo elementus (pvz., -2, 5, -1, 3, -4).

### Didžiausios absoliučios reikšmės radimas

1.  Įvedus elementus, pasirinkite 4.
2.  Programa parodys didžiausią absoliučios reikšmės elementą (pvz., 5).

### Sumos po pirmojo teigiamo elemento skaičiavimas

1.  Įvedus elementus, pasirinkite 5.
2.  Programa parodys sumą elementų, esančių po pirmojo teigiamo elemento (pvz., 3 + 4 = 7).

### Masyvo pertvarkymas pagal intervalą

1.  Įvedus elementus, pasirinkite 3, kad įvestumėte intervalą (pvz., [0; 4]).
2.  Pasirinkite 6.
3.  Programa pertvarkys masyvą (pvz., 3, 0, -2, 5, -4).

### Masyvo spausdinimas

1.  Įvedus elementus, pasirinkite 7.
2.  Programa atspausdins masyvą.

## Autorius

[Kęstutis Skrebė]

## Pastabos

* Programa naudoja dinaminį atminties paskirstymą, todėl svarbu atlaisvinti atmintį po naudojimo.
* Įvedant duomenis, programa tikrina, ar įvestis yra teisinga.
* Programa naudoja `iomanip` biblioteką, kad formatuotų išvestį.