# Dvikryptis simbolių sąrašas (C++) 🧵

## 📋 Aprašymas

Ši C++ programa:

- Įveda vartotojo tekstą.
- Įrašo visus simbolius (raides, tarpus, skyrybos ženklus ir t. t.) į **dvikryptį sąrašą**.
- Nenaudoja masyvų.
- Suskaičiuoja, **koks simbolis pasikartojo dažniausiai** (iš mažųjų raidžių arba tarpas).
- Išveda simbolį ir jo **pasikartojimo kiekį**.

Jei dažniausiai pasikartoja **tarpas**, jis atvaizduojamas kaip `|_|`.

---

## 📦 Paleidimas

1. Atidarykite projektą bet kurioje C++ aplinkoje (pvz., Code::Blocks, Visual Studio, Visual Studio Code, CLion ar kt.).
2. Įsitikinkite, kad palaikomas C++11 (ar naujesnis) standartas.
3. Paleiskite `main()` funkciją.

> Pastaba: Jei naudojate Windows OS, programa automatiškai nustato UTF-8 konsolės išvestį (`SetConsoleOutputCP(CP_UTF8)`).

---

## 💡 Pavyzdys

**Įvestis:**
Labas vakaras!


**Išvestis:**
Dažniausiai pasikartojanti mažoji raidė: 'a' (pasikartojo 5 kartus)


---

## 🛠 Struktūra

Programa naudoja:

- `struct Dvikryptis` – sąrašo mazgas su `char` duomenimis.
- `class DvikryptisLinkedList` – dvikrypčio sąrašo klasė su metodais:
    - `append(char ch)` – prideda simbolį į galą.
    - `countSkaiciuokle(char ch)` – suskaičiuoja konkretaus simbolio pasikartojimus.
    - `mostDazniausiaiLowercase()` – grąžina dažniausiai pasikartojantį mažąjį simbolį arba tarpą.

---

## 📎 Reikalavimai

- C++ kompiliatorius (pvz., g++, MSVC)
- Palaikomas UTF-8 simbolių rinkinys (Windows naudotojams – `SetConsoleOutputCP` iš `windows.h`)

---

## 📚 Kiti pasiūlymai

✅ Galima išplėsti programą taip, kad:
- būtų skaičiuojami visi simboliai (ne tik mažosios raidės ir tarpas),
- būtų išvedama visa simbolių pasikartojimų statistika,
- simboliai būtų rūšiuojami pagal dažnumą.

---

© 2025 Kęstutis Skrebė  
Užduotis mokymosi tikslais 🎓
