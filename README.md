# Proiect-APD

 Specificatii Proiect


Algoritmul folosit: QuickSort
Limbaj de programare folosit: C++, STL 
Framework-uri folosite: OpenMP, OpenACC

Informatii masina: 
Processor - Intel(R) Core(TM) i7-6700 CPU @ 3.40GHz   3.40 GHz
Installed RAM - 16.0 GB
System type - 64-bit operating system, x64-based processor
Graphics card - GTX 970

Rezultate experimentale pentru variantele secvențiale:

| Limbaj:  | C++ |  | STL |  |
| :-------------: | :-------------: |  :-------------: |  :-------------: |  :-------------: |
| Tip numere:  | 32 bit | 64 bit | 32 bit | 64 bit |
| 100.000  | 0.104 s  | 0.164 s  |  0.158 s  |  0.432 s  |
| 1.000.000  | 0.559 s  |  1.531 s  |  1.277 s  |  3.545 s  |
| 10.000.000  | 6.033 s  |  16.6 s  |  13.933 s  |  38.776 s  |
| 100.000.000  | 62.760 s  |  72.306 s  |  155.905 s  |  178.571 s  |

Rezultate experimentale pentru variantele paralele:

| Framework:  | OpenMP | 4 threads | OpenACC | 4 threads |
| :-------------: | :-------------: |  :-------------: |  :-------------: |  :-------------: |
| Tip numere:  | 32 bit | 64 bit | 32 bit | 64 bit |
| 100.000  | 0.019 s | 0.046 s |  0.087 s |  0.159 s |
| 1.000.000  |  0.174 s |  0.484 s |  0.577 s  |  1.682 s  |
| 10.000.000  | 2.476 s |  5.587 s |  6.710 s |  17.397 s  |
| 100.000.000  | 22.038 s |  29.004 s | 68.185 s |  75.779 s  |


Link pentru document:
https://docs.google.com/document/d/1f8CewnwJrwE_vf9C7DZ5ugNi-rKK6FLYxiI83jioA1E/edit?usp=sharing
