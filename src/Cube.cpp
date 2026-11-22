#include "Cube.h"

#include <stdexcept>
#include <cstdlib>
#include <ctime>

Cube::Cube(int size)
{
    if (size <= 0)
    {
        throw std::invalid_argument("Cube size must be greater than 0.");
    }

    n = size;

    cube = std::vector<std::vector<std::vector<int>>>
    (n, std::vector<std::vector<int>>
        (n, std::vector<int>(n, 0))
    );
}

int Cube::size() const
{
    return n;
}

int Cube::get(int layer, int row, int col) const
{
    if (layer < 0 || layer >= n ||
        row   < 0 || row   >= n ||
        col   < 0 || col   >= n)
    {
        throw std::out_of_range("Cube index out of range.");
    }

    return cube[layer][row][col];
}

void Cube::set(int layer, int row, int col, int value)
{
    if (layer < 0 || layer >= n ||
        row   < 0 || row   >= n ||
        col   < 0 || col   >= n)
    {
        throw std::out_of_range("Cube index out of range.");
    }

    cube[layer][row][col] = value;
}

void Cube::generateLatinCube()
{
    for (int layer = 0; layer < n; layer++)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cube[layer][row][col] = (layer + row + col) % n + 1;
            }
        }
    }
}

void Cube::maskCells(double ratio)
{
    if (ratio < 0.0 || ratio > 1.0)
    {
        throw std::invalid_argument("Mask ratio must be between 0 and 1.");
    }

    int totalCells = n * n * n;
    int cellsToMask = static_cast<int>(totalCells * ratio);

    int masked = 0;

    while (masked < cellsToMask)
    {
        int layer = std::rand() % n;
        int row   = std::rand() % n;
        int col   = std::rand() % n;

        if (cube[layer][row][col] != 0)
        {
            cube[layer][row][col] = 0;
            masked++;
        }
    }
}

#include <iostream>

void Cube::print() const
{
    for (int layer = 0; layer < n; layer++)
    {
        std::cout << "Layer " << layer << '\n';

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                std::cout << cube[layer][row][col] << ' ';
            }
            
            std::cout << '\n';
        }

        std::cout << '\n';
    }
}

