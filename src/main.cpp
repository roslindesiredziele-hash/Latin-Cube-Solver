#include "Cube.h"
#include "Solver.h"

#include <windows.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq);

double BenchmarkSolve(int size, double ratio, long long& calls);

double AverageBenchmark(int size, double ratio, int runs, long long& avgCalls);

void GenerateSampleFiles();

void RunBenchmarks(const std::vector<int>& sizes, const std::vector<double>& ratios, int runs);

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<int> sizes =
    {
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10
    };

    std::vector<double> ratios =
    {
        0.10,
        0.20,
        0.30,
        0.40,
        0.50,
        0.60,
    };

    constexpr int runs = 20;

    GenerateSampleFiles();

    RunBenchmarks(sizes, ratios, runs);

    std::cout << "Benchmark complete.\n";

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

void RunBenchmarks(const std::vector<int>& sizes, const std::vector<double>& ratios, int runs)
{
    std::ofstream file("data/benchmark.csv");

    if(!file)
    {
        std::cerr << "Failed to open benchmark.csv\n";

        return;
    }

    file
        << "CubeSize,"
        << "MaskRatio,"
        << "RuntimeMs,"
        << "RecursiveCalls\n";

    for(int size : sizes)
    {
        for(double ratio : ratios)
        {
            long long calls = 0;

            double runtime = AverageBenchmark(size, ratio, runs, calls);

            file
                << size << ","
                << ratio << ","
                << runtime << ","
                << calls << "\n";

            std::cout
                << "Size: " << size
                << " Ratio: " << ratio
                << " Runtime: "
                << runtime
                << " ms Calls: "
                << calls
                << '\n';
        }
    }

    file.close();
}

void GenerateSampleFiles()
{
    Cube generated(4);

    generated.generateLatinCube();

    generated.renameSymbols();
    generated.permuteLayers();

    generated.saveCSV("data/generated_cube.csv");
    
    Cube masked(4);

    masked.generateLatinCube();

    masked.renameSymbols();
    masked.permuteLayers();

    masked.maskCells(0.30);

    masked.saveCSV("data/masked_cube.csv");
    
    Cube solved(4);

    solved.generateLatinCube();

    solved.renameSymbols();
    solved.permuteLayers();

    solved.maskCells(0.30);

    Solver solver;

    solver.solve(solved);

    solved.saveCSV("data/solved_cube.csv");
}