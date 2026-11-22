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
    return cube[layer][row][col];
}
