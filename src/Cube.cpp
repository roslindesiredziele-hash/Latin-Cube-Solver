#include "Cube.h"

Cube::Cube(int size):
        n(size),
        cube
        (size, std::vector<std::vector<int>>
            (size, std::vector<int>
                (size, 0)
            )
        )
{

}

