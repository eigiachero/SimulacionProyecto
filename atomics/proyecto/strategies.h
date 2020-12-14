#include "numberGenerator.h"
#include "simulator.h" // TODO: Borrar

// Constantes
#define strategyPCWeightMin 5
#define strategyPCWeightMax 8
#define strategyPCInterrarrivals 6

#define strategyHumanWeight 7.5
#define strategyHumanInterrarrival 10

//Funciones
std::list<double> getStrategyWeights(int strategy, int quantity);

std::list<double> getStrategyInterarrivals(int strategy, int quantity);

std::list<double> strategyReorderWeightList(std::list<double> weights, double winnerWeight);

std::list<double> strategyRandomWeight(std::list<double> weights);