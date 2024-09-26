#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "zoo-species.hpp"
#include <vector>

using namespace std;

int initialize_animals(string fileName, int &mp, int &rp, int &bp,
                       vector<Zoo_species *> &animals);

#endif
