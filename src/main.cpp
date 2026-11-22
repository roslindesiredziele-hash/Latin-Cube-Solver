#include "Cube.h"
#include "Solver.h"

#include <windows.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq);

double BenchmarkSolve(int size, double ratio, long long& calls);

double AverageBenchmark(int size, double ratio, int runs);

void RunBenchmarks(const std::vector<int>& sizes, const std::vector<double>& ratios, int runs);

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    return 0;
}

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq)
{
    return static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
}

double BenchmarkSolve(int size, double ratio, long long& calls)
{
    Cube cube(size);

    cube.generateLatinCube();
    cube.renameSymbols();
    cube.permuteLayers();
    cube.maskCells(ratio);

    Solver solver;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    solver.solve(cube);

    QueryPerformanceCounter(&end);

    calls = solver.calls;

    return MeasureMilliseconds(start, end, freq);
}

double AverageBenchmark(int size, double ratio, int runs, long long& avgCalls)
{
    double totalTime = 0;

    long long totalCalls = 0;

    for(int i = 0; i < runs; i++)
    {
        long long calls = 0;

        totalTime += BenchmarkSolve(size, ratio, calls);

        totalCalls += calls;
    }

    avgCalls = totalCalls / runs;

    return totalTime / runs;
}

