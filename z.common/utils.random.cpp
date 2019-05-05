//
// Created by Gintoki-97 on 2019-05-04.
//

#include <iostream>
#include <random>

using std::cout; using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;

default_random_engine re(time(nullptr));

int randomInt(int max) {
    uniform_int_distribution<unsigned> u(0, max);
    return u(re);
}