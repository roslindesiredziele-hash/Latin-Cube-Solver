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

--*

## Running

Execute:

```bash
./*enchmark.exe
```

The program:

1.*Generates randomized Latin cubes.
*. Produces masked puzzle instances*
3. Solves puzzles using recursive*backtracking.
4. Benchmarks solver*performance.
5. Exports benchmark *esults to CSV.
6. Generates perfor*ance graphs using Python.

Generat* graphs with:

```bash
py -3.13 re*ort/graph.py
```

---

## Benchmar* Configuration

### Cube Sizes

``*text
3, 4, 5, 6, 7, 8, 9, 10
```

*## Mask Ratios

```text
10%, 20%, *0%, 40%, 50%, 60%
```

### Repetit*ons

Each benchmark configuration *s averaged over:

```text
20 runs
*``

---

## Algorithm

### Latin C*be Generation

A valid Latin cube *s generated using:

```cpp
cube[layer][row][col] =
    (layer + row +*col) % n + 1;
```

This guarantees*that every symbol appears exactly *nce in every row, column, and dept* line.

### Puzzle Generation

The*generated cube is randomized throu*h:

- Symbol renaming
- Layer perm*tation
- Random masking

### Backt*acking Solver

The solver repeated*y:

1. Finds the next empty cell.
*. Tries all candidate values.
3. C*ecks row, column, and depth constr*ints.
4. Recursively continues sol*ing.
5. Backtracks whenever a conf*ict is detected.

---

## Complexi*y Analysis

Let:

- `n` = cube siz*
- `m` = number of masked cells

F*r each empty position, the solver *ay attempt up to `n` candidate val*es.

Worst-case complexity:

```te*t
O(n^m)
```

which is exponential*in the number of missing cells.

T*is behavior is characteristic of r*cursive backtracking algorithms.

*--

## Performance Metrics

The fo*lowing metrics are collected durin* benchmarking:

- Runtime (millise*onds)
- Recursive calls

Results a*e stored in:

```text
data/benchma*k.csv
```

---

## Results

Benchm*rking shows that:

- Runtime incre*ses with cube size.
- Runtime incr*ases with masking ratio.
- Recursi*e calls increase significantly for*difficult instances.
- Certain puz*le configurations trigger exponent*al search-space growth.

### Repre*entative Benchmark Results (60% Ma*king)

| Cube Size | Runtime (ms) * Recursive Calls |
|-----------|--*----------:|----------------:|
| 3*| 0.016 | 17 |
| 4 | 0.049 | 40 |
* 5 | 0.315 | 96 |
| 6 | 0.926 | 19* |
| 7 | 1.917 | 366 |
| 8 | 6.467*| 1,406 |
| 9 | 33.234 | 6,151 |
|*10 | 8217.130 | 2,499,852 |

### K*y Observations

- Small cubes (`n * 6`) are solved almost instantly.
* Medium cubes (`n = 7–9`) show ste*dily increasing search effort.
- L*rger and heavily masked cubes requ*re dramatically more recursion.
- *he jump from size 9 to size 10 dem*nstrates the exponential behavior *f backtracking.

### Hardest Obser*ed Instance

```text
Cube Size:   *    10
Mask Ratio:       60%
Runti*e:          8217 ms
Recursive Call*:  2,499,852
```

This benchmark h*ghlights the rapid growth of the s*arch space as puzzle difficulty in*reases.

---

## Findings

The ben*hmark results show that the diffic*lty of solving a Latin cube depend* heavily on both the cube size and*the masking ratio.

### Effect of *ube Size

For a fixed masking rati*, runtime increased as the cube si*e increased.

For example, with a *asking ratio of **60%**:

| Cube S*ze | Runtime (ms) | Recursive Call* |
|-----------|-------------:|---*------------:|
| 3 | 0.016 | 17 |
* 4 | 0.049 | 40 |
| 5 | 0.315 | 96*|
| 6 | 0.926 | 196 |
| 7 | 1.917 * 366 |
| 8 | 6.467 | 1,406 |
| 9 |*33.234 | 6,151 |
| 10 | 8217.130 |*2,499,852 |

The Runtime vs Cube Size and Recursive Calls vs Cube Size graphs clearly show this growth.

### Effect of Masking Ratio

For a fixed cube size, increasing the masking ratio increased both runtime and recursive calls.

For example, for a cube of size **10**:

| Mask Ratio | Runtime (ms) |
|-----------:|-------------:|
| 10% | 1.583 |
| 20% | 2.937 |
| 30% | 5.178 |
| 40% | 5.717 |
| 50% | 8.629 |
| 60% | 8217.130 |

As more cells were hidden, fewer constraints were known in advance and the solver was forced to explore a much larger search space.

This behavior is visible in the Runtime vs Mask Ratio graphs.

### Search Space Explosion

The most difficult benchmark instance was:

```text
Cube Size:        10
Mask Ratio:       60%
Runtime:          8217 ms
Recursive Calls:  2,499,852
```

This instance required over **2.5 million recursive calls** and took more than **8 seconds** to solve, while most smaller instances were solved in milliseconds.

The dramatic increase between sizes 9 and 10 demonstrates the exponential growth characteristic of backtracking algorithms.

### Comparison with Theoretical Complexity

The solver uses recursive backtracking.

Let:

- `n` = number of symbols
- `m` = number of masked cells

In the worst case, the algorithm may explore up to `n` candidate values for each empty cell, giving a theoretical complexity of:

```text
O(n^m)
```

The benchmark results support this theoretical expectation:

- Runtime increases with cube size.
- Runtime increases with masking ratio.
- Recursive calls grow rapidly for difficult instances.
- Large, heavily masked cubes can trigger exponential growth of the search space.

Therefore, the experimental results are consistent with the expected behavior of a backtracking solver.

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