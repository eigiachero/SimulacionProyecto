#include <random>
#include <algorithm>
#include <list>
#include "limits"

using namespace std;

list<double> genExponentialDistribution(double mean, int qty);

list<double> genUniformDistribution(double min, double max, int qty);

list<double> genInfiniteList(int qty);

int getRandomInt(double min, double max);