#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <openacc.h>


using namespace std;

template<typename T>
int partition(vector<T>& vec, int low, int high) {
    T pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

template<typename T>
void quickSort(vector<T>& vec, long long low, long long high) {
    if (low < high) {
        long long pi = partition(vec, low, high);

        #pragma acc task
        quickSort(vec, low, pi - 1);

        #pragma acc task
        quickSort(vec, pi + 1, high);

        #pragma acc taskwait
    }
}


int main() {
    ifstream input_file("numere.txt", ios::binary);
    vector<int32_t> numere32;
    vector<int64_t> numere64;
    int32_t num32;
    int64_t num64;

    input_file.seekg(0, ios::end);
    size_t file_size = input_file.tellg();
    input_file.seekg(0, ios::beg);

    if (file_size <= sizeof(int32_t)) {
        while (input_file.read((char*)&num32, sizeof(int32_t))) {
            numere32.push_back(num32);
        }
    }
    else {
        while (input_file.read((char*)&num64, sizeof(int64_t))) {
            numere64.push_back(num64);
        }
    }

    input_file.close();

    if (numere32.size() > 0) {

        #pragma acc data copy(numere32)
        {
            quickSort(numere32, 0, numere32.size() - 1);
        }

    }
    else if (numere64.size() > 0) {

        #pragma acc data copy(numere64)
        {
            quickSort(numere64, 0, numere64.size() - 1);
        }


    }

    return 0;
}
