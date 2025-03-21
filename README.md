# sąrašų užduotis (K2.2) naudojant STL

## 📝 Užduotis

Naudojant STL bibliotekas, sukurti programą, kuri:

1. Leidžia naudotojui įvesti nurodytą kiekį skaičių į **dvikryptį sąrašą (`std::list<int>`)**.
    - Leidžiama įvesti skaičių `0` kelis kartus (jis nėra pabaigos žymeklis).
2. Įgyvendina šias funkcijas:
    - Įterpimas **prieš** nurodytą elementą.
    - Įterpimas **po** nurodyto elemento.
    - Nurodyto elemento šalinimas.
    - Didžiausio elemento paieška.

3. Realizuoja papildomas užduotis:
   a. Visus skaičius **nuo paskutiniojo 0** perkelia į **ciklinį vienkryptį sąrašą** (naudojamas `std::list`, tačiau cikliškumas simuliuojamas logika).  
   b. Suskaičiuoja, **kiek cikliniame sąraše esančių skaičių** yra **didesni už dvikrypčio sąrašo vidurkį**.  
   c. Pašalina visus ciklinio sąrašo elementus esančius **tarp trečiojo ir priešpaskutiniojo** (jei jų pakanka), ir juos atspausdina.

---

## 🖥️ Naudojimas

## 📌 Meniu funkcijos
1. Įvesti elementus į dvikryptį sąrašą
2. Įterpti elementą PRIEŠ kitą
3. Įterpti elementą PO kito
4. Pašalinti nurodytą elementą
5. Rasti didžiausią elementą
6. Sukurti ciklinį sąrašą nuo paskutinio 0
7. Kiek elementų cikliniame > už dvikrypčio vidurkį
8. Pašalinti tarp 3-io ir priešpaskutinio (ciklinis)
9. Spausdinti abu sąrašus
0. Išeiti

### Paleidimas per terminalą (Linux / macOS / Windows + MinGW)

1. **Kompiliavimas**:

```bash
g++ main.cpp -o sarasu_uzduotis 



