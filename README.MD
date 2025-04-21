# Dvikryptis simbolių sąrašas (C++) 🧵

## 📋 Aprašymas

Ši C++ programa:

- Įveda vartotojo tekstą.
- Įrašo visus simbolius (raides, tarpus, skyrybos ženklus ir t. t.) į **dvikryptį sąrašą**.
- Nenaudoja **masyvų** ir **STL** (standartinių bibliotekų struktūrų kaip `vector`, `list`, `pair`).
- Suskaičiuoja, **koks simbolis pasikartojo dažniausiai**, iš **mažųjų raidžių** arba **tarpas**.
- Išveda simbolį ir jo **pasikartojimo kiekį**.

Jei dažniausiai pasikartoja **tarpas**, jis atvaizduojamas kaip `|_|`.

---

## 📦 Paleidimas

1. Atidarykite projektą bet kurioje C++ aplinkoje (pvz., Code::Blocks, Visual Studio, Visual Studio Code, CLion ar kt.).
2. Įsitikinkite, kad palaikomas C++11 (ar naujesnis) standartas.
3. Paleiskite `main()` funkciją.

> 💡 **Pastaba**: Jei naudojate Windows OS, programa automatiškai nustato UTF-8 konsolės išvestį su `SetConsoleOutputCP(CP_UTF8)`.

---

## 💡 Pavyzdys

**Įvestis:**

Labas vakaras!

**Išvestis:**

Dažniausiai pasikartojanti mažoji raidė: 'a' (pasikartojo 5 kartus)

---

## 🛠 Struktūra

Programa naudoja:

- `struct Dvikryptis` – sąrašo mazgas su simboliu (`char`) bei rodyklėmis į kitą ir ankstesnį mazgą.
- `struct Rezultatas` – paprasta struktūra dažniausiai pasikartojančiam simboliui ir kiekiui saugoti.
- `class DvikryptisLinkedList` – dvikrypčio sąrašo klasė su metodais:
  - `append(char ch)` – prideda simbolį į sąrašo galą.
  - `countSkaiciuokle(char ch)` – suskaičiuoja kiek kartų simbolis pasitaiko sąraše.
  - `mostDazniausiaiLowercase()` – randa dažniausiai pasikartojusią mažąją raidę arba tarpą.
  - Destruktorius atlaisvina atmintį.

---

## 📎 Reikalavimai

- C++ kompiliatorius (`g++`, MSVC ar kitas)
- Palaikomas UTF-8 simbolių rinkinys (Windows naudotojams – `SetConsoleOutputCP` iš `windows.h`)

---

## 📚 Kiti pasiūlymai

Galima išplėsti programą taip, kad:

- būtų skaičiuojami visi simboliai (ne tik mažosios raidės ir tarpas),
- būtų išvedama visa simbolių pasikartojimų statistika,
- simboliai būtų rūšiuojami pagal dažnumą.

---

© 2025 Kęstutis Skrebė  
Užduotis mokymosi tikslais 🎓
