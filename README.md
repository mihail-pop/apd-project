# About

This project was developed for the **"Algoritmi Paraleli și Distribuiți"** (Parallel and Distributed Algorithms) course. It compares the performance of sequential and parallel implementations of the **QuickSort** algorithm using **C++** and **STL**, with parallelization frameworks like **OpenMP** and **OpenACC**. The goal was to analyze how parallelization improves sorting performance for large datasets.

## Key Features
- **QuickSort Algorithm**: Implemented in C++ for sequential execution and parallelized using OpenMP and OpenACC.
- **Performance Comparison**: Benchmarks for sorting datasets of varying sizes (100,000 to 100,000,000 elements) with 32-bit and 64-bit numbers.
- **Frameworks**:
  - **OpenMP**: Used for CPU-based parallelization.
  - **OpenACC**: Used for GPU-based parallelization.
- **Dataset Generation**: The datasets of 32-bit and 64-bit numbers used for testing were generated using the included **GeneratorNumere** program.
- **Experimental Results**: Detailed timing results for both sequential and parallel implementations.

## Requirements
- **Compiler**: A C++ compiler with support for OpenMP and OpenACC (e.g., GCC with Code::Blocks).
- **Used Hardware**:
  - **CPU**: Intel(R) Core(TM) i7-6700 CPU @ 3.40GHz.
  - **GPU**: NVIDIA GTX 970.
  - **RAM**: 16.0 GB.
- **Libraries**: STL for C++.

## Experimental Results

### Sequential QuickSort Performance
| Language | C++ (32-bit) | C++ (64-bit) | STL (32-bit) | STL (64-bit) |
| :------: | :----------: | :----------: | :----------: | :----------: |
| 100,000  | 0.104 s      | 0.164 s      | 0.158 s      | 0.432 s      |
| 1,000,000 | 0.559 s     | 1.531 s      | 1.277 s      | 3.545 s      |
| 10,000,000 | 6.033 s    | 16.6 s       | 13.933 s     | 38.776 s     |
| 100,000,000 | 62.760 s  | 72.306 s     | 155.905 s    | 178.571 s    |

### Parallel QuickSort Performance (4 Threads)
| Framework | OpenMP (32-bit) | OpenMP (64-bit) | OpenACC (32-bit) | OpenACC (64-bit) |
| :-------: | :-------------: | :-------------: | :--------------: | :--------------: |
| 100,000   | 0.019 s         | 0.046 s         | 0.087 s          | 0.159 s          |
| 1,000,000 | 0.174 s         | 0.484 s         | 0.577 s          | 1.682 s          |
| 10,000,000 | 2.476 s        | 5.587 s         | 6.710 s          | 17.397 s         |
| 100,000,000 | 22.038 s      | 29.004 s        | 68.185 s         | 75.779 s         |

## Observations
- **OpenMP** consistently outperformed **OpenACC** for smaller datasets, likely due to the overhead of GPU memory transfers.
- For larger datasets, **OpenACC** showed significant speedups, leveraging the GPU's parallel processing capabilities.
- The **STL implementation** was slower than the custom C++ implementation, highlighting the benefits of low-level optimizations.
