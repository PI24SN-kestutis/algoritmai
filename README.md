# 🌲 Dvejetainio Medžio Valdymo Programa

Ši C++ kalba parašyta programa leidžia kurti ir valdyti **dvejetainį paieškos medį**, į kurį galima įterpti, iš jo ieškoti, šalinti sveikus skaičius, bei atlikti specialias **intervalų operacijas** su **eile** ir **deku**, realizuotais kaip sąrašai.

## ✅ Funkcionalumas

- Įterpimas į dvejetainį medį
- Spausdinimas „piramidės“ forma (pasukta 90°)
- Paieška su keliu (matomas maršrutas iki reikšmės)
- Šalinimas su logika (mazgas su 0, 1 arba 2 vaikais)
- Intervalų operacijos:

### 5. Intervalų operacijos:

#### 5.1
Sukurti eilę (Queue), į kurią įrašomi visi medžio elementai iš intervalo **[a; b]**
#### 5.2
Iš medžio pašalinti visus elementus iš intervalo **[a; c]**, juos įrašant į **deko pradžią (front)**
#### 5.3
Iš medžio pašalinti visus elementus iš intervalo **[c; b]**, juos įrašant į **deko pabaigą (back)**
#### 5.4
Spausdinti tiek **eilę**, tiek **deką**

## 🛠️ Technologijos

- C++ (be STL)
- Komandinė eilutė / Konsolė (Windows)
- UTF-8 simbolių palaikymas (naudojamas `SetConsoleOutputCP(CP_UTF8)`)

## 📂 Struktūra

- `TreeNode` – dvejetainio medžio mazgas
- `Queue` – eilė, realizuota kaip sąrašas
- `Deque` – dekas, realizuotas kaip sąrašas
- Visi duomenys laikomi dinamiškai ir atmintis atlaisvinama

## 🖥️ Paleidimas

1. Atsidarykite projektą C++ aplinkoje (pvz., **Visual Studio**, **Code::Blocks**, **Dev-C++**, **CLion** arba **g++** per terminalą)
2. Įsitikinkite, kad kompiliatorius palaiko C++11 ar naujesnį
3. Kompiliuokite ir paleiskite

🧪 Pavyzdinis testas

    Įterpkite skaičius: 10, 5, 15, 3, 7, 12, 18

    Pasirinkite intervalus: a = 5, c = 10, b = 15

    Stebėkite:

        Eilėje bus: 5 7 10 12 15

        Dekas bus: 10 5 7 12 15 (pradžioje – nuo [a; c], gale – nuo [c; b])

⚠️ Reikalavimai

    Naudojama tik standartinė C++ kalba, be STL (vector, queue, deque ir pan.)

    Tinka naudoti mokomaisiais tikslais ar algoritmų analizėje

📄 Licencija

Šis projektas skirtas mokymuisi ir švietimui. Naudokite laisvai.

💡 Autorius: Kęstutis Skrebė / GitHub PI24SN-kestutis

### Terminale (naudojant `g++`):
```bash
g++ main.cpp -o medis
./medis
