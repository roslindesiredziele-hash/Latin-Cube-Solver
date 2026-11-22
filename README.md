# Enchanted Latin Cube Solver

A C++ implementation of a Latin Cube puzzle generator and solver using recursive backtracking. This project was developed for **Assignment II – Task 3: Enchanted Latin Cube** from the *Algorithm Design Pattern Zoo* coursework.

---

## Overview

A Latin cube of size **n³** is a three-dimensional extension of a Latin square.

Each symbol from **1..n** must appear exactly once along:

- Every row
- Every column
- Every depth line

The objective is to reconstruct a partially masked Latin cube using a backtracking algorithm.

The project includes:

- Latin cube generation
- Puzzle randomization
- Recursive backtracking solver
- Runtime benchmarking
- Recursive call analysis
- Automated graph generation

---

## Features

### Latin Cube Generation

Creates valid Latin cubes using:

```cpp
(layer + row + col) % n + 1
```

### Puzzle Randomization

The generated cube is randomized through:

- Symbol renaming
- Layer permutation
- Random masking

### Backtracking Solver

The solver:

1. Finds the next empty cell.
2. Tries all candidate values.
3. Validates row, column, and depth constraints.
4. Recursively continues solving.
5. Backtracks whenever a conflict occurs.

### Benchmarking

Measures:

- Runtime (milliseconds)
- Recursive calls

for multiple cube sizes and masking ratios.

### Reporting

Automatically generates:

- CSV benchmark dataset
- Sample puzzle files
- Performance graphs

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

Compile using:

```bash
g++ src/*.cpp -o benchmark
```

---

## Usage

Run the benchmark executable:

```bash
./benchmark.exe
```

The program will:

1. Generate a randomized Latin cube.
2. Create a masked puzzle.
3. Solve the puzzle using backtracking.
4. Export sample CSV files.
5. Execute benchmark experiments.
6. Save benchmark results to `data/benchmark.csv`.

Generate graphs with:

```bash
py -3.13 report/graph.py
```

Generated graphs are written to:

```text
report/
```

---

## Example Output

### Console Output

```text
Size: 3 Ratio: 0.1 Runtime: 0.001775 ms Calls: 3
Size: 3 Ratio: 0.2 Runtime: 0.004215 ms Calls: 6
Size: 3 Ratio: 0.3 Runtime: 0.008885 ms Calls: 9

...

Size: 10 Ratio: 0.4 Runtime: 5.71711 ms Calls: 463
Size: 10 Ratio: 0.5 Runtime: 8.62934 ms Calls: 964
Size: 10 Ratio: 0.6 Runtime: 8217.13 ms Calls: 2499852

Benchmark complete.
```

### Sample Generated Puzzle

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

---

## Benchmark Configuration

### Cube Sizes

```text
3, 4, 5, 6, 7, 8, 9, 10
```

### Mask Ratios

```text
10%, 20%, 30%, 40%, 50%, 60%
```

### Repetitions

Each benchmark configuration is averaged over:

```text
20 runs
```

---

## Algorithm

### Latin Cube Generation

A valid Latin cube is generated using:

```cpp
cube[layer][row][col] =
    (layer + row + col) % n + 1;
```

This guarantees that every symbol appears exactly once in every row, column, and depth line.

### Puzzle Generation

The generated cube is randomized through:

- Symbol renaming
- Layer permutation
- Random masking

### Backtracking Solver

For every empty cell:

1. Select the next empty position.
2. Try each value `1..n`.
3. Verify constraints.
4. Recurse.
5. Undo choices that lead to dead ends.

---

## Complexity Analysis

Let:

- `n` = cube size
- `m` = number of masked cells

The backtracking solver may explore up to `n` candidate values for each empty cell.

Worst-case complexity:

```text
O(n^m)
```

which is exponential in the number of missing cells.

### Expected Behavior

Theoretical expectations:

- Larger cubes require more work.
- Higher masking ratios create larger search spaces.
- Recursive calls should grow rapidly for difficult instances.
- Runtime should increase correspondingly.

The benchmark results confirm these expectations.

---

## Performance Metrics

The following metrics are collected:

- Runtime (milliseconds)
- Recursive calls

All benchmark data is exported to:

```text
data/benchmark.csv
```

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

### Hardest Observed Instance

| Metric | Value |
|----------|----------:|
| Cube Size | 10 |
| Mask Ratio | 60% |
| Runtime | 8217 ms |
| Recursive Calls | 2,499,852 |

---

## Findings

### Effect of Cube Size

For a fixed masking ratio, runtime increased as cube size increased.

At 60% masking:

| Cube Size | Runtime (ms) |
|-----------|-------------:|
| 3 | 0.016 |
| 5 | 0.315 |
| 7 | 1.917 |
| 9 | 33.234 |
| 10 | 8217.130 |

The Runtime vs Cube Size graph shows a clear upward trend.

### Effect of Masking Ratio

For a fixed cube size, increasing the masking ratio increased runtime and recursive calls.

For a cube of size 10:

| Mask Ratio | Runtime (ms) |
|-----------:|-------------:|
| 10% | 1.583 |
| 20% | 2.937 |
| 30% | 5.178 |
| 40% | 5.717 |
| 50% | 8.629 |
| 60% | 8217.130 |

More masked cells lead to a significantly larger search space.

### Search-Space Explosion

The most difficult benchmark required:

```text
Runtime:          8217 ms
Recursive Calls:  2,499,852
```

while smaller instances were solved in milliseconds.

This demonstrates the exponential nature of backtracking search.

### Comparison with Theory

The benchmark results are consistent with the expected complexity:

```text
O(n^m)
```

where:

- `n` = number of symbols
- `m` = number of masked cells

Runtime and recursive calls both increase as problem size increases, matching theoretical expectations.

---

## Generated Graphs

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

The experimental results confirm that the backtracking solver performs efficiently on small and moderately sized Latin cubes.

However, runtime and recursive calls increase rapidly as cube size and masking ratio grow. The hardest benchmark instance required approximately **2.5 million recursive calls** and over **8 seconds** of computation time, demonstrating the exponential growth of the search space typical of backtracking algorithms.

Despite this growth, the solver successfully reconstructed all tested puzzle instances.

---

## Author

**Desire Roslin Dziele**

University of Lodz  
Algorithms and Data Structures