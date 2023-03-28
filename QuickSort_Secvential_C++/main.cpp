#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

// Functia partition este utilizata in quickSort pentru a partitiona vectorul in doua jumatati,
// astfel incat elementele mai mici decat pivotul sa fie in partea stanga, iar cele mai mari
// decat pivotul sa fie in partea dreapta. Returneaza pozitia pivotului.
template<typename T>
int partition(vector<T>& vec, int low, int high) {
    T pivot = vec[high]; // alegem pivotul ca fiind ultimul element din vector
    int i = low - 1;     // indexul elementului mai mic decat pivotul

    for (int j = low; j <= high - 1; j++) { // parcurgem vectorul de la low la high-1
        if (vec[j] < pivot) {              // daca gasim un element mai mic decat pivotul
            i++;                           // incrementam indexul elementului mai mic decat pivotul
            swap(vec[i], vec[j]);          // interschimbam elementele de pe pozitiile i si j
        }
    }
    swap(vec[i + 1], vec[high]); // plasam pivotul pe pozitia corecta
    return i + 1;                // returnam pozitia pivotului
}

// Functia quickSort sorteaza un vector prin aplicarea algoritmului quicksort.
// low si high reprezinta indicele de inceput si sfarsit al portiunii de vector care trebuie sortata.
template<typename T>
void quickSort(vector<T>& vec, long long low, long long high) {
    if (low < high) {                   // daca mai sunt cel putin doua elemente de sortat
        long long pi = partition(vec, low, high); // partitionam vectorul si obtinem pozitia pivotului
        quickSort(vec, low, pi - 1);    // sortam partea stanga a vectorului
        quickSort(vec, pi + 1, high);   // sortam partea dreapta a vectorului
    }
}

int main() {
    ifstream input_file("numere.txt", ios::binary); // deschidem fisierul de intrare numere.txt in modul binar
    vector<int32_t> numere32;
    vector<int64_t> numere64;
    int32_t num32;            // variabila pentru citirea unui numar de tip int32_t
    int64_t num64;            // variabila pentru citirea unui numar de tip int64_t

    // Determinam marimea fisierului pentru a determina tipul de date al numerelor
    input_file.seekg(0, ios::end); // ne deplasam la sfarsitul fisierului pentru a determina marimea acestuia
    size_t file_size = input_file.tellg(); // tellg() ne da pozitia curenta a cursorului in fisier, care la sfarsit este chiar dimensiunea fisierului
    input_file.seekg(0, ios::beg); // ne deplasam la inceputul fisierului pentru a incepe sa citim numerele

    if (file_size <= sizeof(int32_t)) { // daca dimensiunea fisierului este mai mica sau egala cu dimensiunea unui int32_t (4 bytes), citim numere intregi de 32 de biti
        while (input_file.read((char*)&num32, sizeof(int32_t))) { // citim numerele intregi de 32 de biti din fisier
            numere32.push_back(num32); // adaugam numarul citit in vectorul numere32
        }
    }
    else { // altfel, citim numere intregi de 64 de biti
        while (input_file.read((char*)&num64, sizeof(int64_t))) { // citim numerele intregi de 64 de biti din fisier
            numere64.push_back(num64); // adaugam numarul citit in vectorul numere64
        }
    }

    input_file.close();

    if (numere32.size() > 0) { // daca exista numere intregi de 32 de biti citite din fisier
        quickSort(numere32, 0, numere32.size() - 1); // sortam vectorul
        for (auto num : numere32) { // iteram prin fiecare element din vectorul sortat
            cout << num << " ";
        }
    }
    else if (numere64.size() > 0) { // daca exista numere intregi de 64 de biti citite din fisier
        quickSort(numere64, 0, numere64.size() - 1); // sortam vectorul
        for (auto num : numere64) { // iteram prin fiecare element din vectorul sortat
            cout << num << " ";
        }
    }

    cout << endl;
    return 0;
}
