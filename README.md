# Rikiavimo algoritmų lyginamoji analizė

Šis projektas skirtas **Bubble Sort** ir **Quick Sort** algoritmų veikimo greičiui ir efektyvumui palyginti naudojant skirtingo tipo duomenų masyvus.

## 🔍 Tikslas

Palyginti dviejų rikiavimo algoritmų veikimo laiką ir sukeitimų skaičių su:

- Atsitiktiniais duomenimis
- Jau surikiuotais duomenimis
- Atvirkščiai surikiuotais duomenimis

Kiekvienu atveju analizuojami šie masyvų dydžiai:
- 5 000
- 10 000
- 50 000
- 100 000 elementų

## 📌 Naudoti algoritmai

### 🟢 Bubble Sort
Paprastas, bet neefektyvus rikiavimo algoritmas, tinkamas tik mažiems arba beveik surikiuotiems duomenims. Sudėtingumas: **O(n²)**

### 🔵 Quick Sort
Vienas iš greičiausių praktikoje naudojamų algoritmų. Sudėtingumas: **vidutiniškai O(n log n)**, blogiausiu atveju – O(n²). Naudojama optimizuota rekursijos versija.

## 🧪 Kas matuojama

Kiekvienam algoritmui ir kiekvienam duomenų tipui matuojama:

- ⏱️ **Rikiavimo trukmė** (milisekundėmis)
- 🔁 **Sukeitimų skaičius**

Pavyzdinė išvestis:
===== 5000 elementų =====
 - Bubble Sort | Random | 5000 | Laikas: 136.397 ms | Sukeitimai: 6325272 Quick Sort | Random | 5000 | Laikas: 0.7709 ms | Sukeitimai: 38956


## 🛠️ Kaip paleisti

1. Atsidarykite projektą bet kuriame C++ palaikančiame IDE (pvz., **Visual Studio**, **CLion** ar kt.).
2. Įsitikinkite, kad naudojama **C++17** ar naujesnė versija.
3. Paleiskite `main()` funkciją.

### 🧑‍💻 Naudojamos bibliotekos:
- `<vector>` – darbui su dinaminiais masyvais
- `<chrono>` – laikui matuoti
- `<random>` – atsitiktinių duomenų generavimui
- `<windows.h>` – UTF-8 palaikymui Windows konsolėje

> Jei naudojate ne-Windows sistemą, pašalinkite `#include <windows.h>` ir `SetConsoleOutputCP(CP_UTF8);`

## 📈 Rezultatų apdorojimas

Visi rezultatai išvedami į konsolę. Jie gali būti nukopijuoti į CSV/Excel analizavimui ar grafinių ataskaitų sudarymui.

## ❗ Apie STL bibliotekų nenaudojimą

Šiame projekte naudojamos STL (Standard Template Library) struktūros ir funkcijos, tokios kaip:

- `std::vector` – dinaminis masyvas
- `std::sort` – pradinių duomenų rikiavimui
- `std::reverse` – atvirkštinei kopijai sukurti
- `std::swap` – saugiam elementų sukeitimui

### ➕ Privalumai naudojant STL:
- Optimizuotos, labai greitos funkcijos.
- Užtikrintas saugumas ir stabilumas.
- Trumpesnis ir aiškesnis kodas.

### ➖ Jei nenaudotume STL:
- Reikėtų patiems realizuoti dinaminį masyvą, rikiavimo ir sukeitimo funkcijas.
- Gali sumažėti veikimo greitis dėl mažiau efektyvaus kodo.
- Žymiai padidėja **klaidų tikimybė** (pvz., neteisingas atminties valdymas, „segmentation fault“).
- Palyginimas gali būti ne toks sąžiningas, nes klaidos gali daryti įtaką rezultatams, o optimizavimas – užtrunka.

> **Svarbu**: STL naudojimas šiame projekte užtikrina, kad algoritmų lyginimas būtų pagrįstas jų veikimo principais, o ne techninėmis implementacijos detalėmis.

Jei norite gilesnio iššūkio ar dirbate aplinkoje, kurioje STL naudoti negalima – galima perrašyti šį projektą nenaudojant standartinės bibliotekos. Tokiu atveju rekomenduojama naudoti papildomą testavimą, siekiant užtikrinti teisingą rezultatų palyginimą.


## 📚 Teorinė dalis

Šis projektas buvo naudojamas rašto darbe, kuriame lyginami algoritmai pagal:

- Laiko sudėtingumą (Big-O analizė)
- Veikimo laiką skirtingoms įvestims
- Sukeitimų skaičių
- Stabilumą ir praktinį taikymą

## 📄 Licencija

Šis projektas skirtas edukaciniam tikslui ir gali būti laisvai naudojamas, keičiamas ir platinamas studijų ar mokymosi tikslais.

---
