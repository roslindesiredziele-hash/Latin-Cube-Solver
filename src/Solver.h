#ifndef SOLVER_H
#define SOLVER_H
#include "Cube.h"

class Solver
{
    public:

    long long calls = 0;

    bool solve(Cube&);

    private:

    bool findempty(Cube&, int&, int&, int&);

    
};

#endif