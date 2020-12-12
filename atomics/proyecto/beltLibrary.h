#include <list>
#include <utility>
#include <cmath>
#include "limits"

bool isEqual(double A, double B);

double collisionPower(std::pair<double,double> box);

double updatedDistance(double oldDistance, double time, double velocity);

std::list<std::pair<double,double>> updateAllDistances(std::list<std::pair<double,double>> boxes, double time, double velocity);

double updatedWeight(std::pair<double,double> winnerBox, std::pair<double,double> loserBox);

double nextEvent(std::list<std::pair<double,double>> PcBoxes, std::list<std::pair<double,double>> PlayerBoxes, double length, double velocity);