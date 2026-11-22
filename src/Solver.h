#ifndef SOLVER_H
#define SOLVER_H
#include "Cube.h"

class Solver
{
    public:

    long long calls = 0;

    bool solve(Cube&);

    private:

    bool findEmpty(Cube&, int&, int&, int&);

    bool isValid(Cube&, int, int, int, int);
};

#endif