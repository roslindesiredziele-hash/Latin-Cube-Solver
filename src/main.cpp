#include "Cube.h"
#include "Solver.h"

#include <windows.h>
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

    try
    {
        Cube cube(4);

        std::cout << "Generating Latin cube...\n";

        cube.generateLatinCube();

        std::cout << "\nOriginal Cube:\n\n";
        cube.print();

        cube.saveCSV("data/generated_cube.csv");

        std::cout << "Renaming symbols...\n";
        cube.renameSymbols();

        std::cout << "Permuting layers...\n";
        cube.permuteLayers();

        std::cout << "\nRandomized Cube:\n\n";
        cube.print();

        std::cout << "Masking 30% of cells...\n";

        cube.maskCells(0.30);

        std::cout << "\nPuzzle:\n\n";
        cube.print();

        cube.saveCSV("data/masked_cube.csv");

        Solver solver;

        std::cout << "Solving...\n";

        if (solver.solve(cube))
        {
            std::cout << "\nSolved Cube:\n\n";
            cube.print();

            cube.saveCSV("data/solved_cube.csv");

            std::cout << "\nSolution found.\n";
            std::cout
                << "Recursive calls: "
                << solver.calls
                << '\n';
        }
        else
        {
            std::cout << "\nNo solution found.\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr
            << "Error: "
            << e.what()
            << '\n';

        return 1;
    }

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

    return MeasureMilliseconds(
        start,
        end,
        freq
    );
}