#include "numberGenerator.h"

using namespace std;

// Constants
#define strategyPCWeightMin 5
#define strategyPCWeightMax 8
#define strategyPCInterrarrivals 6

#define strategyHumanWeight 7.5
#define strategyHumanInterrarrival 10

// Functions
list<double> getStrategyWeights(int strategy, int quantity);

list<double> getStrategyInterarrivals(int strategy, int quantity);

list<double> strategyReorderWeightList(list<double> weights, double winnerWeight);

list<double> strategyRandomWeightFirst(list<double> weights);