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

Run the benchmark executable:

```bash
./benchmark.exe
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
2 0 4 *
```

### Solved Puzzle

```text
L*yer 0*2 3 4 1
3 4 1 *
4 1 2 3
1 2 3*4

Layer 1
3 4 1 2
* 1 2 3
1 2 3 4*2 3 4 1
```

### Benchmark Output
**``text
Size: 8 Ratio: 0.6 Runtime:*6.47 ms Calls: 1406
Size: 9*Ratio: 0.6 Runtime: 33.23 ms Calls* 6151
Size: 10 Ratio: 0.6 Runtime* 8217.13 ms Calls: 2499852

Benchm*rk complete.
```

---

## Benchmar* Configuration

| Parameter | Valu*s |
|------------|---------|
| Cub* Sizes | 3, 4, 5, 6, 7, 8, 9, 10 |*| Mask Ratios | 10%, 20%, 30%, 40%* 50%, 60% |
| Repetitions | 20 run* |

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

The solver:

1. Fin*s the next empty cell.
2. Tries ca*didate values from `1` to `n`.
3. *hecks row, column, and depth const*aints.
4. Recursively continues so*ving.
5. Backtracks when a conflic* is encountered.

---

## Complexi*y Analysis

Let:

- `n` = number o* symbols
- `m` = number of masked *ells

For each empty cell, the sol*er may attempt up to `n` candidate*values.

Worst-case complexity:

`*`text
O(n^m)
```

This exponential*complexity suggests:

- Increasing*runtime for larger cubes.
- Increa*ing runtime for higher masking rat*os.
- Rapid growth of recursive ca*ls for difficult puzzle instances.*
---

## Results

### Representati*e Results (60% Masking)

| Cube Si*e | Runtime (ms) | Recursive Calls*|
|-----------|-------------:|----*-----------:|
| 3 | 0.016 | 17 |
|*4 | 0.049 | 40 |
| 5 | 0.315 | 96 *
| 6 | 0.926 | 196 |
| 7 | 1.917 |*366 |
| 8 | 6.467 | 1,406 |
| 9 | *3.234 | 6,151 |
| 10 | 8217.130 | *,499,852 |

### Hardest Observed I*stance

| Metric | Value |
|------*---|-------:|
| Cube Size | 10 |
|*Mask Ratio | 60% |
| Runtime | 821* ms |
| Recursive Calls | 2,499,85* |

---

## Findings

### Runtime *rowth

Runtime increased with both*cube size and masking ratio.

Smal* cubes were solved almost instantl*, while larger heavily masked cube* required substantially more compu*ation. The most difficult benchmar* instance (**size 10**, **60% mask*ng**) required more than **8 secon*s** to solve*

### Recursive Search Growth

The*number of recursive calls increase* rapidly as problem difficulty inc*eased.

At **60% masking**, recurs*ve calls increased from:

```text
*7
```

for a cube of size **3**

t*

```text
2,499,852
```

for a cub* of size **10**.

This demonstrate* the rapid expansion of the search*space typical of*backtracking algorithms.

### Comp*rison with Theory*
The observed behavior matches*the theoretical complexity:

```te*t
O(n^m)
```

where:

- `n` is the*number of symbols.
- `m` is the nu*ber of masked cells.

As cube size*and masking ratio increase, the so*ver must explore a significantly l*rger search space, leading to subs*antial increases in runtime and re*ursion depth.

---

## Generated G*aphs

### Runtime vs Cube Size (Lo* Scale)

![Runtime vs Cube Size](r*port/runtime_vs_size_log.png)

**O*servation**

- Runtime increases w*th cube size.
- Higher masking rat*os consistently produce longer run*imes.
- The logarithmic scale reve*ls growth*trends that are difficult to see o* a linear scale.

---

### Recursi*e Calls vs Cube Size

![Recursive *alls vs Cube Size](report/recursiv*_calls_vs_size.png)

**Observation**

- Recursive calls increase rapi*ly with cube size.
- Higher maskin* ratios require substantially more*search effort.
- The growth patter* supports the expected exponential*behavior of backtracking.

---

##*/runtime_pair_9_10_log.png

**Observation**

- Runtime increases as the masking ratio increases.
- The effect is especially pronounced for larger cube sizes.
- The size 10 curve grows much faster than the size 9 curve, demonstrating the sensitivity of backtracking to problem difficulty.

---

### Recursive Calls vs Cube Size (60% Masking)

report/hard_recursive_calls.png

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