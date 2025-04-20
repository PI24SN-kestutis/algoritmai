# Teigiamų ir neteigiamų skaičių atskyrimas C++ (be masyvų)

Ši programėlė C++ kalba realizuoja uždavinį:
> Duotas sveikasis skaičius `n` ir `n` sveikųjų skaičių sąrašas. Reikia pakeisti sąrašą taip, kad pradžioje eitų **visi teigiami**, o po jų – **neteigiami** skaičiai. Svarbu: **išlaikoma pradinė tvarka** kiekvienoje grupėje.  
**Sąlyga: nenaudoti masyvų.**

---

## 🔧 Naudojamos priemonės

- `std::list<int>` (C++ STL)
- Paprastas sąrašo perėjimas ir atskyrimas į 2 sąrašus
- Sąrašų sujungimas su `splice`

---

## 📁 Failai

- `main.cpp` – pagrindinis programos failas
- `README.md` – šis dokumentas

---

## 📌 Funkcionalumas

1. Vartotojas įveda skaičių kiekį `n`
2. Įveda `n` skaičių (gali būti neigiami, teigiami arba nuliai)
3. Programa išskiria:
    - visus **teigiamus** (tvarką išlaikant)
    - visus **neteigiamus** (taip pat tvarką išlaikant)
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
Įveskite skaičių kiekį: 7 Įveskite 7 skaičius: 3 -1 5 0 -2 4 1

### Išvestis
Pakeistas sąrašas: 3 5 4 1 -1 0 -2


---

## 🧠 Ką naudinga žinoti

- `std::list` **nėra masyvas**, tai **dvipusis sąrašas**, leidžiantis naudoti efektyvų `splice()`
- Sprendime **nėra naudojami indeksai ar masyvinės struktūros**
- Panaudoti du papildomi sąrašai: vienas teigiamiems, kitas neteigiamiems

---

## 📄 Licencija

Projektas skirtas mokymuisi. Galima naudoti, kopijuoti ar adaptuoti be apribojimų.

---

## 📘 Reikalavimai

- C++11 arba naujesnė
- g++ arba kita C++ kompiliavimo priemonė
