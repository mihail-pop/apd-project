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

| Framework:  | OpenMP |  | OpenACC |  |
| :-------------: | :-------------: |  :-------------: |  :-------------: |  :-------------: |
| Tip numere:  | 32 bit | 64 bit | 32 bit | 64 bit |
| 100.000  | 0.816 s  | 2.239 s  |  -  |  -  |
| 1.000.000  | 9.249 s  |  21.224 s  |  -  |  -  |
| 10.000.000  | 104.515 s  |  16.6 s  |  -  |  -  |
| 100.000.000  | -  |  -  |  -  |  -  |


Link pentru document:
https://docs.google.com/document/d/1f8CewnwJrwE_vf9C7DZ5ugNi-rKK6FLYxiI83jioA1E/edit?usp=sharing
