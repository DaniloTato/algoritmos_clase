#ifndef directorio
#define directorio

#include <string>
#include <iostream>

struct file{
    std::string name;
};

struct directory{
    std::string name;
    std::vector<file> files;
    std::vector<directory> subdirectory;
};

#endif