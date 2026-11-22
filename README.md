# Enchanted Latin Cube Solver

A C++ implementation of a Latin Cube puzzle generator and solver using recursive backtracking. This project was developed for **Assignment II – Task 3: Enchanted Latin Cube** from the *Algorithm Design Pattern Zoo* coursework.

---

## Overview

A Latin cube of size **n³** is a three-dimensional extension of a Latin square.

Each symbol from **1..n** must appear exactly once in:

- Every row
- Every column
- Every depth line

The objective is to reconstruct a partially masked Latin cube using a recursive backtracking algorithm.

The project includes:

- Latin cube generation
- Puzzle randomization
- Recursive backtracking solver
- Runtime benchmarking
- Recursive call analysis
- Automated graph generation

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

## Usage

Run the benchmark executable (use `./benchmark` on Linux/macOS or `./benchmark.exe` on Windows):

```bash
./benchmark
```

The program:

1. Generates sample Latin cubes.
2. Creates masked puzzle instances.
3. Solves puzzles using recursive backtracking.
4. Runs performance benchmarks.
5. Saves benchmark results to `data/benchmark.csv`.

Generate graphs with:

```bash
py -3.13 report/graph.py
```

Generated graphs are saved in:

```text
report/
```

---

## Example Output

### Sample Puzzle

```text
Layer 0
2 0 4 0
3 4 0 2
4 1 2 3
0 2 3 4

Layer 1
3 4 0 2
4 1 0 3
1 2 0 4
2 0 4 1
```

### Solved Puzzle

```text
Layer 0
2 3 4 1
3 4 1 2
4 1 2 3
1 2 3 4

Layer 1
3 4 1 2
4 1 2 3
1 2 3 4
2 3 4 1
```

### Benchmark Output

```text
Size: 8 Ratio: 0.6 Runtime: 6.47 ms Calls: 1406
Size: 9 Ratio: 0.6 Runtime: 33.23 ms Calls: 6151
Size: 10 Ratio: 0.6 Runtime: 8217.13 ms Calls: 2499852

Benchmark complete.
```

---

## Benchmark Configuration

| Parameter | Values |
|------------|---------|
| Cube Sizes | 3, 4, 5, 6, 7, 8, 9, 10 |
| Mask Ratios | 10%, 20%, 30%, 40%, 50%, 60% |
| Repetitions | 20 runs |

---

## Algorithm

### Latin Cube Generation

A valid Latin cube is generated using:

```cpp
cube[layer][row][col] =
    (layer + row + col) % n + 1;
```

This construction guarantees that every symbol appears exactly once in every row, column, and depth line.

### Puzzle Generation

The generated cube is randomized through:

- Symbol renaming
- Layer permutation
- Random masking

These transformations preserve the Latin cube properties while producing different puzzle instances for benchmarking.

### Backtracking Solver

The solver reconstructs the puzzle using depth-first search with backtracking.

For each empty cell:

1. Locate the next empty position.
2. Try all values from `1` to `n`.
3. Check whether the candidate value already appears in:
   - the current row,
   - the current column,
   - the current depth line.
4. If the placement is valid, recursively continue solving.
5. If a contradiction is reached, undo the assignment and try the next candidate.
6. When all cells are filled, the puzzle is solved.

The number of recursive calls is recorded during benchmarking to measure the size of the explored search space.

---

## Complexity Analysis

Let:

- `n` = number of symbols
- `m` = number of masked cells

For each empty cell, the solver may attempt up to `n` candidate values.

Worst-case complexity:

```text
O(n^m)
```

where:

- `n` is the number of possible symbols.
- `m` is the number of masked cells.

In the worst case, every empty cell may require exploring up to `n` candidate values, producing an exponential search tree.

Therefore, we expect:

- Runtime to increase with cube size.
- Runtime to increase with masking ratio.
- Recursive calls to grow rapidly for difficult puzzle instances.

The benchmark graphs should reflect these trends if the implementation behaves as predicted by theory.

---

## Results

### Representative Results (60% Masking)

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

These values correspond to one representative benchmark run using a masking ratio of 60%. Because puzzle generation is randomized, exact runtimes and recursive call counts may vary between executions.

### Hardest Observed Instance

| Metric | Value |
|----------|-------:|
| Cube Size | 10 |
| Mask Ratio | 60% |
| Runtime | ≈ 8.2 s |
| Recursive Calls | ≈ 2.5 million |

---

## Findings

### Runtime Growth

Runtime increased with both cube size and masking ratio.

Small cubes were solved almost instantly, while larger heavily masked cubes required substantially more computation. The increase became particularly noticeable for cube sizes 9 and 10, where the solver had to explore a significantly larger search space.

### Recursive Search Growth

The number of recursive calls increased rapidly as problem difficulty increased.

At **60% masking**, recursive calls increased from:

```text
17
```

for a cube of size **3**

to approximately:

```text
2,500,000
```

for a cube of size **10**.

This demonstrates the rapid expansion of the search space typical of backtracking algorithms.

### Comparison with Theory

The observed behavior matches the theoretical complexity:

```text
O(n^m)
```

where:

- `n` is the number of symbols.
- `m` is the number of masked cells.

As cube size and masking ratio increase, the solver must explore a significantly larger search space, leading to substantial increases in runtime and recursion depth.

---

## Generated Graphs

### Runtime vs Cube Size (Log Scale)

`report/runtime_vs_size_log.png`

**Observation**

- Runtime increases with cube size.
- Higher masking ratios consistently produce longer runtimes.
- The logarithmic scale reveals growth trends that are difficult to observe on a linear scale.

---

### Recursive Calls vs Cube Size

`report/recursive_calls_vs_size.png`

**Observation**

- Recursive calls increase rapidly with cube size.
- Higher masking ratios require substantially more search effort.
- The growth pattern supports the expected exponential behavior of backtracking.

---

### Runtime vs Mask Ratio (Log Scale, Sizes 9 and 10)

`report/runtime_pair_9_10_log.png`

**Observation**

- Runtime increases as the masking ratio increases.
- The effect is especially pronounced for larger cube sizes.
- The size 10 curve grows much faster than the size 9 curve, demonstrating the sensitivity of backtracking to problem difficulty.

---

### Recursive Calls vs Cube Size (60% Masking)

`report/hard_recursive_calls.png`

**Observation**

- Recursive calls increase dramatically as cube size grows.
- The increase between sizes 9 and 10 is particularly significant.
- The largest benchmark instance required approximately **2.5 million recursive calls**.
- This graph provides the strongest empirical evidence of search-space explosion.

---

### Graph Summary

The generated graphs support the following conclusions:

- Runtime increases with cube size.
- Runtime increases with masking ratio.
- Recursive calls grow rapidly for difficult puzzle instances.
- Large heavily masked cubes create significantly larger search spaces.
- The empirical results are consistent with the theoretical worst-case complexity:

```text
O(n^m)
```

where:

- `n` is the number of symbols.
- `m` is the number of masked cells.

---

## Conclusions

The experimental results confirm that recursive backtracking efficiently solves small and moderately sized Latin cubes.

However, runtime and recursive calls grow rapidly as cube size and masking ratio increase. The largest benchmark instance required approximately **2.5 million recursive calls** and more than **8 seconds** of computation time, demonstrating the exponential growth of the search space predicted by the theoretical analysis.

Overall, the benchmark results are consistent with the expected behavior of a backtracking solver.

---

## Author

**Desire Roslin Dziele**

University of Lodz  
Algorithms and Data Structures