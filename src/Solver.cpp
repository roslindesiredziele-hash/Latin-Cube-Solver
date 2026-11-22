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

bool Solver::isValid(Cube& cube, int layer, int row, int col, int value)
{
    for (int c = 0; c < cube.size(); c++)
    {
        if (c != col && cube.get(layer, row, c) == value)
        {
            return false;
        }
    }

    for (int r = 0; r < cube.size(); r++)
    {
        if (r != row && cube.get(layer, r, col) == value)
        {
            return false;
        }
    }

    for (int l = 0; l < cube.size(); l++)
    {
        if (l != layer && cube.get(l, row, col) == value)
        {
            return false;
        }
    }

    return true;
}

bool Solver::solve(Cube& cube)
{
    calls++;

    int layer;
    int row;
    int col;

    if (!findEmpty(cube, layer, row, col))
    {
        return true;
    }

    for (int value = 1; value <= cube.size(); value++)
    {
        if (isValid(cube, layer, row, col, value))
        {
            cube.set(layer, row, col, value);

            if (solve(cube))
            {
                return true;
            }

            cube.set(layer, row, col, 0);
        }
    }

    return false;
}