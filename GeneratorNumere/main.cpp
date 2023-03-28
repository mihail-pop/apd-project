#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937_64 generator(rd());
    uniform_int_distribution<long long> distribution(0, 4294967295);

    ofstream file32("32_numbers.txt");
    ofstream file64("64_numbers.txt");

    for (int i = 0; i < 1000000; ++i) {
        file32 << distribution(generator) << '\n';
    }

    for (int i = 0; i < 1000000; ++i) {
        file64 << ((long long)distribution(generator) << 32) << distribution(generator) << '\n';
    }

    file32.close();
    file64.close();

    return 0;
}
