# Teigiamų ir neteigiamų skaičių atskyrimas C++ (be masyvų ir STL)

Ši C++ programėlė realizuoja uždavinį:

> Duotas sveikasis skaičius `n` ir `n` sveikųjų skaičių sąrašas. Reikia pakeisti sąrašą taip, kad pradžioje eitų **visi teigiami**, o po jų – **neteigiami** skaičiai.  
> Svarbu: **išlaikoma pradinė tvarka** kiekvienoje grupėje.  
> **Sąlyga: nenaudoti masyvų ir STL konteinerių.**

---

## 🔧 Naudojamos priemonės

- Rankiniu būdu sukurtas vienkryptis sąrašas (`struct Node`)
- Paprasta sąrašo perėjimo logika
- Sąrašų sujungimas naudojant žymeklius (pointerius)

---

## 📁 Failai

- `main.cpp` – pagrindinis programos failas
- `README.md` – šis dokumentas

---

## 📌 Funkcionalumas

1. Vartotojas įveda skaičių kiekį `n`
2. Įveda `n` skaičių (gali būti neigiami, teigiami arba nuliai)
3. Programa išskiria:
   - visus **teigiamus** (išlaikant tvarką)
   - visus **neteigiamus** (taip pat išlaikant tvarką)
4. Abu sąrašai sujungiami – teigiami eina pirmi

---

## 💻 Kaip paleisti

1. Kompiliuok ir paleisk:
    ```bash
    g++ main.cpp -o skaiciu-rikiavimas
    ./skaiciu-rikiavimas
    ```

2. Įvesk pavyzdinius duomenis.

---

## 🧪 Pavyzdys

### Įvestis:
Įveskite skaičių kiekį: 7
Įveskite 7 skaičius: 3 -1 5 0 -2 4 1


### Išvestis:
3 5 4 1 -1 0 -2


---

## 🧠 Ką naudinga žinoti

- Programoje **nėra naudojami nei masyvai, nei STL** (`vector`, `list`, ir pan.)
- Viskas realizuota naudojant rankinį vienkryptį sąrašą (`struct Node`)
- Naudojami `append()` ir `reorderList()` metodai sąrašų tvarkymui

---

## 📄 Licencija

Projektas skirtas mokymuisi. Galima naudoti, kopijuoti ar adaptuoti be apribojimų.

---

## 📘 Reikalavimai

- C++11 arba naujesnė
- `g++` arba kita C++ kompiliavimo priemonė
