#include "strategies.h"

std::list<double> getStrategyWeights(int strategy, int quantity){
  std::list<double> weights;
  std::list<double> weightsPC = genUniformDistribution(strategyPCWeightMin, strategyPCWeightMax, quantity);
  std::list<double> weightsHuman = genExponentialDistribution(strategyHumanWeight, quantity);
  
  switch (strategy) {
    case 0:
      weights = weightsPC;
      break;
    case 1:
      weights = weightsHuman;
      weights.sort();
      break;
    case 2:
      weights = weightsHuman;
      weights.sort(std::greater<double>());
      break;
    case 3:
      weights = weightsHuman;
      weights.sort();
      break;
    case 4:
      weights = weightsHuman;
      weights.sort(std::greater<double>());
      break;
  }
  
  return weights;
}

std::list<double> getStrategyInterarrivals(int strategy, int quantity){
  std::list<double> interarrivals;

  switch (strategy) {
    case 0:
      interarrivals = genExponentialDistribution(strategyPCInterrarrivals, quantity);
      break;
    case 1:
      interarrivals = genExponentialDistribution(strategyHumanInterrarrival, quantity);
      break;
    case 2:
      interarrivals = genExponentialDistribution(strategyHumanInterrarrival, quantity);
      break;
    case 3:
      interarrivals = genInfiniteList(quantity);
      break;
    case 4:
      interarrivals = genInfiniteList(quantity);
      break;
  }
  
  return interarrivals;
}

std::list<double> strategyReorderWeightList(std::list<double> weights, double winnerWeight) {
  std::list<double> reorderedWeights;
  bool found = false;

  for (int i = 0; i < weights.size(); i++) {
    double top = weights.front();
    weights.pop_front();

    if (top > winnerWeight && found == false) {
      found = true;
      reorderedWeights.push_front(top);
    } else {
      reorderedWeights.push_back(top);
    }
  }

  return reorderedWeights;
}

std::list<double> strategyRandomWeight(std::list<double> weights) {
  std::list<double> reorderedWeights;
  int randomPosition = getRandomInt(0, weights.size() - 1);

  for (int i = 0; i < weights.size(); i++) {
    double top = weights.front();
    weights.pop_front();

    if (i == randomPosition) {
      reorderedWeights.push_front(top);
    } else {
      reorderedWeights.push_back(top);
    }
  }

  return reorderedWeights;
}