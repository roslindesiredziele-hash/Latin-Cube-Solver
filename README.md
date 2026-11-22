# Enchanted Latin Cube Solver

A C++ implementation of a Latin Cube puzzle generator and solver using recursive backtracking. This project was developed for **Assignment II – Task 3: Enchanted Latin Cube** from the *Algorithm Design Pattern Zoo* coursework.

---

## Overview

A Latin cube of size **n³** is a three-dimensional extension of a Latin square.

Each symbol from **1..n** must appear exactly once in:

- Every row
- Every column
- Every depth line

The goal is to reconstruct a partially masked Latin cube using a recursive backtracking algorithm.

The project includes:

- Latin cube generation
- Puzzle randomization
- Recursive backtracking solving
- Runtime benchmarking
- Recursive call analysis
- Automated graph generation

---

## Features

- Latin cube generation using

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
│   ├── hard_instances.png
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

## Usage

Run the benchmark exec*table:

```bash
./benchmark.exe
``*

The program:

1. Generates sampl* Latin cubes.
2. Creates masked pu*zle instances.
3. Solves puzzles u*ing recursive backtracking.
4. Run* performance benchmarks.
5. Saves *enchmark results to `data/benchmar*.csv`.

Generate graphs with:

```*ash
py -3.13 report/graph.py
```

*enerated graphs are saved in:

```*ext
report/
```

---

## Example O*tput

### Sample Puzzle

```text
L*yer 0
2 0 4 0
3 4 0 2
4 1 2 3
0 2 * 4

Layer 1
3 4 0 2
4 1 0 3
1 2 0 *
2 0 4 1
```

### Solved Puzzle

`*`text
Layer 0
2 3 4 1
3 4 1 2
4 1 * 3
1 2 3 4

Layer 1
3 4 1 2
4 1 2 *
1 2 3 4
2 3 4 1
```

### Benchmar* Output

```text
Size: 8 Ratio: 0.* Runtime: 6.47 ms Calls: 1406
Size* 9 Ratio: 0.6 Runtime: 33.23 ms Ca*ls: 6151
Size: 10 Ratio: 0.6 Runti*e: 8217.13 ms Calls: 2499852

Benc*mark complete.
```

---

## Benchm*rk Configuration

| Parameter | Va*ues |
|------------|---------|
| C*be Sizes | 3, 4, 5, 6, 7, 8, 9, 10*|
| Mask Ratios | 10%, 20%, 30%, 4*%, 50%, 60% |
| Repetitions | 20 r*ns |

---

## Algorithm

### Latin*Cube Generation

A valid Latin cub* is generated using:

```cpp
cube[*ayer][row][col] =
    (layer + row*+ col) % n + 1;
```

This guarante*s that every symbol appears exactl* once in every row, column, and de*th line.

### Puzzle Generation

T*e generated cube is randomized thr*ugh:

- Symbol renaming
- Layer pe*mutation*- Random masking*
### Backtracking Solver

The solv*r:

1. Finds the next empty cell.
*. Tries candidate values from `1` *o `n`.
3. Checks row, column, and *epth constraints.
4. Recursively c*ntinues solving.
5. Backtracks whe* a conflict is encountered.

---

*# Complexity Analysis

Let:

- `n`*= number of symbols
- `m` = number*of masked cells

For each empty ce*l, the solver may attempt up to `n* candidate values.

Worst-case com*lexity:

```text
O(n^m)
```

The e*ponential nature of this complexit* should result in:

- Increasing r*ntime for larger cubes.
- Increasi*g runtime for higher masking ratio*.
- Rapid growth of recursive call* for difficult puzzle instances.

*--

## Results

### Representative*Results (60% Masking)

| Cube Size*| Runtime (ms) | Recursive Calls |*|-----------|-------------:|------*---------:|
| 3 | 0.016 | 17 |
| 4*| 0.049 | 40 |
| 5 | 0.315 | 96 |
* 6 | 0.926 | 196 |
| 7 | 1.917 | 3*6 |
| 8 | 6.467 | 1,406 |
| 9 | 33*234 | 6,151 |
| 10 | 8217.130 | 2,*99,852 |

### Hardest Observed Ins*ance

| Metric | Value |
|--------*-|-------:|
| Cube Size | 10 |
| M*sk Ratio | 60% |
| Runtime | 8217 *s |
| Recursive Calls | 2,499,852 *

---

## Findings

### Runtime Gr*wth

The runtime increased with bo*h cube size and masking ratio.

Sm*ll cubes were solved almost instan*ly, while larger heavily masked cu*es required substantially more com*utation. The most difficult benchm*rk (**size 10**, **60% masking**) *equired over **8 seconds** to solv*.

### Recursive Search Growth

Th* number of recursive calls increas*d rapidly as problem difficulty in*reased.

At **60% masking**, recur*ive calls increased from:

```text*17
```

for a cube of size **3**

*o

```text
2,499,852
```

for a cu*e of size **10**.

This demonstrat*s the rapid expansion of the searc* space typical of backtracking alg*rithms.

### Comparison with Theor*

The observed behavior matches th* theoretical complexity:

```text
*(n^m)
```

where:

- `n` is the nu*ber of symbols.
- `m` is the numbe* of masked cells.

As cube size an* masking ratio increase, the solve* must explore a significantly larg*r search space, leading to substan*ial increases in runtime and recur*ion depth.

---

## Generated Grap*s

### Runtime vs Cube Size (Log S*ale)

![Runtime vs Cube Size](repo*t/runtime_vs_size_log.png)

**Obse*vation**

- Runtime increases with*cube size.
- Higher masking ratios*consistently produce longer runtim*s.
- The logarithmic scale reveals*growth trends that are difficult t* see on a linear scale.

---

### *ecursive Calls vs Cube Size

![Rec*rsive Calls vs Cube Size](report/r*cursive_calls_vs_size.png)

**Obse*vation**

- Recursive calls increa*e rapidly with cube size.
- Higher*masking ratios require substantial*y more search effort.
- The growth*pattern supports the expected expo*ential behavior of backtracking.

*--

### Runtime vs Cube Size (60% *asking)

![Runtime vs Cube Size 60*Percent Masking](report/hard_insta*ces.png)

**Observation**

- Runti*e remains relatively low for small*r cubes.
- Runtime increases drama*ically for larger cubes.
- The jum* between sizes 9 and 10 clearly il*ustrates the increasing difficulty*of heavily masked puzzle instances*

---

### Recursive Calls vs Cube*Size (60% Masking)

![Recursive Ca*ls vs Cube Size 60 Percent Masking*(report/hard_recursive_calls.png)
***Observation**

- Recursive calls*graph provides the strongest empirical evidence of search-space explosion.

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