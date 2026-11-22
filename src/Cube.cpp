#include "Cube.h"

#include <stdexcept>

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
    if (layer < 0 || layer >= n || row   < 0 || row   >= n || col   < 0 || col   >= n)
    {
        throw std::out_of_range("Cube index out of range.");
    }

    return cube[layer][row][col];
}

void Cube::set(int layer, int row, int col, int value)
{
    cube[layer][row][col] = value;
}
