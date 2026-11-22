#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <string>

class Cube
{
    private:
    int n;
    std::vector<std::vector<std::vector<int>>> cube;
    
    public:
    Cube(int);

    int size() const;
    int get(int, int, int) const;
};


#endif