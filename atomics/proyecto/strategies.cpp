#include "strategies.h"

list<double> getStrategyWeights(int strategy, int quantity){
  list<double> weights;
  list<double> weightsPC = genUniformDistribution(strategyPCWeightMin, strategyPCWeightMax, quantity);
  list<double> weightsHuman = genExponentialDistribution(strategyHumanWeight, quantity);
  
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
      weights.sort(greater<double>());
      break;
    case 3:
      weights = weightsHuman;
      weights.sort();
      weights = strategyRandomWeightFirst(weights);
      break;
    case 4:
      weights = weightsHuman;
      weights.sort(greater<double>());
      weights = strategyRandomWeightFirst(weights);
      break;
  }
  
  return weights;
}

list<double> getStrategyInterarrivals(int strategy, int quantity){
  list<double> interarrivals;

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

list<double> strategyReorderWeightList(list<double> weights, double winnerWeight) {
  list<double> reorderedWeights;
  bool found = false;
  int size = (int) weights.size();

  for (int i = 0; i < size; i++) {
    double top = weights.front();
    weights.pop_front();

    if ((top > winnerWeight) && found == false) {
      found = true;
      reorderedWeights.push_front(top);
    } else {
      reorderedWeights.push_back(top);
    }
  }

  return reorderedWeights;
}

list<double> strategyRandomWeightFirst(list<double> weights) {
  list<double> reorderedWeights;
  int randomPosition = getRandomInt(0, weights.size() - 1);
  int size = (int) weights.size();

  for (int i = 0; i < size; i++) {
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