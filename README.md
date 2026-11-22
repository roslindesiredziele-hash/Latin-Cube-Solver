# Enchanted Latin Cube Solver

A C++ implementation of a Latin Cube puzzle generator and solver using recursive backtracking. This project was developed for **Assignment II – Task 3: Enchanted Latin Cube** from the *Algorithm Design Pattern Zoo* coursework.

---

## Problem Description

A Latin cube of size **n³** is a three-dimensional extension of a Latin square.

Each symbol from **1..n** must appear exactly once along:

- Every row
- Every column
- Every depth line

The objective is to reconstruct a partially masked Latin cube using a backtracking algorithm.

---

## Features

- Latin cube generation using:

```cpp
(layer + row + col) % n + 1
```

- Symbol renaming
- Random layer permutation
- Random cell masking
- Recursive backtracking solver
- Runtime benchmarking
- Recursive call counting
- CSV dataset generation
- Automated graph generation

---

## Project Structure

```text
task3_Enchanted_Latin_cube/
│
├── data/
│   ├── benchmark.csv
│   ├── generated_cube.csv
│   ├── masked_cube.csv
│   └── solved_cube.csv
│
├── report/
│   ├── graph.py
│   ├── runtime_vs_size_log.png
│   ├── recursive_calls_vs_size.png
│   ├── runtime_pair_9_10.png
│   ├── runtime_pair_9_10_log.png
│   └── hard_recursive_calls.png
│
├── src/
│   ├── Cube.h
│   ├── Cube.cpp
│   ├── Solver.h
│   ├── Solver.cpp
│   └── main.cpp
│
└── README.md
```

---

## Building

Compile the project using:

```bash
g++ src/*.cpp -o benchmark
```

---

## Run*ing

Execute:

```bash
./benchmark*exe
```

The program:

1. Generate* randomized Latin cubes.
2. Produc*s masked puzzle instances.
3. Solv*s puzzles using recursive backtrac*ing.
4. Benchmarks solver performa*ce.
5. Exports benchmark results t* CSV.
6. Generates performance gra*hs using Python.

Generate graphs *ith:

```bash
py -3.13 report/grap*.py
```

---

## Benchmark Configu*ation

### Cube Sizes

```text
3, *, 5, 6, 7, 8, 9, 10
```

### Mask *atios

```text
10%, 20%, 30%, 40%,*50%, 60%
```

### Repetitions

Eac* benchmark configuration is averag*d over:

```text
20 runs
```

---

## Algorithm

### Latin Cube Generation

A valid Latin cube is generated using:

```cpp
cube[layer][row][col]
=
(layer + row + col) % n + 1;
```

This guarantees that every symbol appears exactly once in every row, column, and depth line.

### Puzzle Generation

The generated cube is randomized through:

- Symbol renaming
- Layer permutation
- Random masking

### Backtracking Solver

The solver repeatedly:

1. Finds the next empty cell.
2. Tries all candidate values.
3. Checks row, column, and depth constraints.
4. Recursively continues solving.
5. Backtracks when a conflict is detected.

---

## Complexity Analysis

Let:

- `n` = cube size
- `m` = number of masked cells

For each empty position the solver may attempt up to `n` candidate values.

Worst-case complexity:

```text
O(n^m)
```

which is exponential in the number of missing cells.

This behavior is characteristic of recursive backtracking algorithms.

---

## Performance Metrics

The following metrics are collected during benchmarking:

- Runtime (milliseconds)
- Recursive calls

Results are stored in:

```text
data/benchmark.csv
```

---

## Results

Benchmarking shows that:

- Runtime increases with cube size.
- Runtime increases with masking ratio.
- Recursive calls increase significantly for difficult instances.
- Certain puzzle configurations trigger exponential search-space growth.

### Representative Benchmark Results (60% Masking)

| Cube Size | Runtime (ms) | Recursive Calls |
|-----------|-------------:|----------------:|
| 3 | 0.016 | 17 |
| 4 | 0.049 | 40 |
| 5 | 0.315 | 96 |
| 6 | 0.926 | 196 |
| 7 | 1.917 | 366 |
| 8 | 6.467 | 1,406 |
| 9 | 33.234 | 6,151 |
| 10 | 8217.130 | 2,499,852 |

### Key Observations

- Small cubes (`n ≤ 6`) are solved almost instantly.
- Medium cubes (`n = 7–9`) show steadily increasing search effort.
- Larger and heavily masked cubes require dramatically more recursion.
- The jump from size 9 to size 10 demonstrates the exponential behavior of backtracking.

### Hardest Observed Instance

```text
Cube Size:        10
Mask Ratio:       60%
Runtime:          8217 ms
Recursive Calls:  2,499,852
```

This benchmark highlights the rapid growth of the search space as puzzle difficulty increases.

---

## Generated Graphs

The project automatically generates the following graphs:

### Runtime Analysis

- Runtime vs Cube Size (Log Scale)
- Runtime vs Mask Ratio (Sizes 9 and 10)
- Runtime vs Mask Ratio (Log Scale)

### Search-Space Analysis

- Recursive Calls vs Cube Size
- Recursive Calls vs Cube Size (60% Masking)

These graphs provide empirical evidence supporting the theoretical complexity analysis.

---

## Conclusions

The experimental results confirm that the backtracking solver performs efficiently on small and moderately sized Latin cubes. However, runtime and recursive calls grow rapidly as cube size and masking ratio increase.

The most difficult benchmark instance required approximately **2.5 million recursive calls** and more than **8 seconds** of computation time, demonstrating the exponential growth of the search space typical of backtracking algorithms.

Despite this growth, the solver successfully reconstructed all tested Latin cube instances.

---

## Author

**Desire Roslin Dziele**

University of Lodz  
Algorithms and Data Structures