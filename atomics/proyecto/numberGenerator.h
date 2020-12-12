#include <random>
#include <algorithm>
#include <list>
#include "limits"

std::list<double> genExponentialDistribution(double mean, int qty);

std::list<double> genUniformDistribution(double min, double max, int qty);

std::list<double> genInfiniteList(int qty);

int getRandomInt(double min, double max);