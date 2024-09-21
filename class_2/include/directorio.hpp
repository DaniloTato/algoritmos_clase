#ifndef directorio
#define directorio

#include <string>
#include <iostream>

struct command{
    std::string name;
};

struct directory{
    std::string name;
    std::vector<command> commands;
    std::vector<directory> subdirectory;
};

#endif