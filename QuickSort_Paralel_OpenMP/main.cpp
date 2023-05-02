#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <omp.h>

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

        // Sectiunile de cod care vor fi rulate in paralel
        #pragma omp parallel sections
        {
            #pragma omp section // sectiune pentru sortarea partii stangi a vectorului
            {
                quickSort(vec, low, pi - 1);
            }
            #pragma omp section // sectiune pentru sortarea partii drepti a vectorului
            {
                quickSort(vec, pi + 1, high);
            }
        }
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
        // Numarul de thread-uri
        int num_threads = 4;
        omp_set_num_threads(num_threads);

        // measure the time for parallel quicksort
        double start_time = omp_get_wtime();
        quickSort(numere32, 0, numere32.size() - 1);
        double end_time = omp_get_wtime();

        for (auto num : numere32) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Time taken for parallel quicksort with " << num_threads << " threads: "
             << end_time - start_time << " seconds" << endl;
    }
    else if (numere64.size() > 0) {
        // Numarul de thread-uri
        int num_threads = 16;
        omp_set_num_threads(num_threads);

        // measure the time for parallel quicksort
        double start_time = omp_get_wtime();
        quickSort(numere64, 0, numere64.size() - 1);
        double end_time = omp_get_wtime();


        cout << endl;

        cout << "Time taken for parallel quicksort with " << num_threads << " threads: "
             << end_time - start_time << " seconds" << endl;
    }

    return 0;
}
