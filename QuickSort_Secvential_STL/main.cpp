#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

// Comparator personalizat, nu face o diferenta
template<typename T>
bool cmp(T a, T b)
{
    return a < b;
}

// Implementarea QuickSort folosind sort din STL
template<typename T>
void quickSort(vector<T>& arr)
{
    sort(arr.begin(), arr.end(), cmp<T>); // Apelarea functiei sort din STL, care sorteaza vectorul 'arr' in intervalul [begin(), end()) folosind comparatorul 'cmp' definit mai sus.
}

int main()
{
    ifstream input_file("numere.txt", ios::binary);
    vector<int32_t> numere32; // Declararea unui vector pentru numere de 32 de biti.
    vector<int64_t> numere64; // Declararea unui vector pentru numere de 64 de biti.

    int32_t num32; // Declararea unei variabile de tip intreg cu latime fixa de 32 de biti.
    int64_t num64; // Declararea unei variabile de tip intreg cu latime fixa de 64 de biti.
    while (input_file.read((char*)&num32, sizeof(int32_t)))
    {
        numere32.push_back(num32);
    }
    while (input_file.read((char*)&num64, sizeof(int64_t)))
    {
        numere64.push_back(num64);
    }
    input_file.close();

    quickSort(numere32);

    for (auto num : numere32)   // parcurgem fiecare element
    {
        cout << num << " ";
    }
    cout << endl;

    quickSort(numere64);

    for (auto num : numere64)   // parcurgem fiecare element
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

