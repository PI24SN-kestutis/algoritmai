# Dinaminiai sąrašai C++

Ši C++ programėlė įgyvendina:

1. **Vienkryptį sąrašą** su funkcijomis:
    - Elemento įterpimas į pabaigą
    - Pašalinimas pagal reikšmę
    - Paieška
    - Spausdinimas

2. **Dvikryptį sąrašą**, į kurį perkeliami vienkrypčio sąrašo elementai, ir kuris gali būti atspausdintas.

---

## 🔧 Pagrindinės struktūros

- `struct Vienkryptis` – vienkrypčio sąrašo mazgas
- `struct Dvikryptis` – dvikrypčio sąrašo mazgas

---

## 📂 Failai

- `main.cpp` – pagrindinis programos failas
- (neprivaloma) `README.md` – šis dokumentas

---

## 💻 Kaip paleisti

1. Įkelk šį projektą į savo aplanką:
    ```bash
    git clone https://github.com/tavo-vardas/vienkryptis-dvikryptis.git
    cd vienkryptis-dvikryptis
    ```

2. Kompiliuok ir paleisk:
    ```bash
    g++ main.cpp -o programa
    ./programa
    ```

   Arba naudojant „Windows“:
    ```bash
    g++ main.cpp -o programa.exe
    programa.exe
    ```

---

## 🧪 Pavyzdys

Programos metu:
- Įterpiami elementai: `10, 20, 30, 40`
- Pašalinamas elementas `20`
- Tikrinama, ar yra `30`
- Perkeliami likę elementai į dvikryptį sąrašą

### Išvestis:
    Vienkryptis sąrašas: 10 20 30 40
    Ar yra 30? Taip
    Vienkryptis sąrašas: 10 30 40
    Dvikryptis sąrašas: 10 30 40



---

## 🧹 Atminties valdymas

Programa atlaisvina visą dinaminę atmintį, kuri buvo paskirta per `new` operatorių, naudodama `clear()` funkcijas abiems sąrašams.

---

## 📘 Reikalavimai

- C++11 arba naujesnė
- `g++`, `clang++`, arba „MSVC“
- Jei naudojama `windows.h` – tik Windows OS

---

## 📄 Licencija

Šis projektas pateikiamas kaip mokymosi pavyzdys. Galite naudoti, keisti ir platinti be jokių apribojimų.
