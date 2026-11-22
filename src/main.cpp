#include "Cube.h"
#include "Solver.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Cube cube(3);

    cube.generateLatinCube();

    cube.maskCells(0.3);

    std::cout << "Puzzle:\n\n";

    cube.print();

    Solver solver;

    if (solver.solve(cube))
    {
        std::cout << "\nSolved:\n\n";

        cube.print();

        std::cout
            << "Recursive calls: "
            << solver.calls
            << '\n';
    }
    else
    {
        std::cout
            << "No solution found.\n";
    }

    return 0;
}