#include "Solver.h"

bool Solver::findEmpty(Cube& cube, int& layer, int& row, int& col)
{
    for (layer = 0; layer < cube.size(); layer++)
    {
        for (row = 0; row < cube.size(); row++)
        {
            for (col = 0; col < cube.size(); col++)
            {
                if (cube.get(layer, row, col) == 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

