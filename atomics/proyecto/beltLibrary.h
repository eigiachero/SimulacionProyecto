#include <list>
#include <utility>
#include <cmath>
#include "limits"

using namespace std;

bool isEqual(double A, double B);

double collisionPower(pair<double,double> box);

double updatedDistance(double oldDistance, double time, double velocity);

list<pair<double,double>> updateAllDistances(list<pair<double,double>> boxes, double time, double velocity);

double updatedWeight(pair<double,double> winnerBox, pair<double,double> loserBox);

double nextEvent(list<pair<double,double>> PcBoxes, list<pair<double,double>> PlayerBoxes, double length, double velocity);