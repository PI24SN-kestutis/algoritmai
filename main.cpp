#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <windows.h>

// Rikiavimo algoritmai
void bubbleSort(std::vector<int>& arr, long long& swapCount) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapCount++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Quick Sort su sukeitimų skaičiumi
int partition(std::vector<int>& arr, int low, int high, long long& swapCount) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    swapCount++;
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, long long& swapCount) {
    while (low < high) {
        int pi = partition(arr, low, high, swapCount);
        // Rikiuoti mažesnę dalį rekursyviai
        if (pi - low < high - pi) {
            quickSort(arr, low, pi - 1, swapCount);
            low = pi + 1;
        } else {
            quickSort(arr, pi + 1, high, swapCount);
            high = pi - 1;
        }
    }
}


// Duomenų generavimas
std::vector<int> generateRandomData(size_t size) {
    std::vector<int> data(size);
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(1, size * 10);
    for (auto& x : data) x = dis(gen);
    return data;
}

// Spartos matavimo funkcija
template<typename Func>
void measureSort(std::vector<int> arr, Func sortFunction, const std::string& label, const std::string& dataType, size_t size) {
    long long swapCount = 0;
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr, swapCount);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << label << " | " << dataType << " | " << size << " | Laikas: " << elapsed.count() << " ms | Sukeitimai: " << swapCount << "\n";
}


// Testavimas skirtingiems masyvams
void testAllSizes() {
    std::vector<size_t> sizes = {5000, 10000, 50000, 100000};
    for (auto size : sizes) {
        auto randomData = generateRandomData(size);
        auto sortedData = randomData;
        std::sort(sortedData.begin(), sortedData.end());
        auto reversedData = sortedData;
        std::reverse(reversedData.begin(), reversedData.end());

        std::cout << "\n===== " << size << " elementų =====\n";

        // Random
        measureSort(randomData, [](auto& a, auto& s){ bubbleSort(a, s); }, "Bubble Sort", "Random", size);
        measureSort(randomData, [](auto& a, auto& s){ quickSort(a, 0, a.size()-1, s); }, "Quick Sort", "Random", size);

        // Sorted
        measureSort(sortedData, [](auto& a, auto& s){ bubbleSort(a, s); }, "Bubble Sort", "Sorted", size);
        measureSort(sortedData, [](auto& a, auto& s){ quickSort(a, 0, a.size()-1, s); }, "Quick Sort", "Sorted", size);

        // Reversed
        measureSort(reversedData, [](auto& a, auto& s){ bubbleSort(a, s); }, "Bubble Sort", "Reversed", size);
        measureSort(reversedData, [](auto& a, auto& s){ quickSort(a, 0, a.size()-1, s); }, "Quick Sort", "Reversed", size);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    testAllSizes();
    return 0;
}

