#include "player.h"

void player::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);

  //Parameters
  strategy = (int) va_arg(parameters, double);
  quantity = (int) va_arg(parameters, double);
  name = va_arg(parameters, char*);
  
  //Variables
  weights = getStrategyWeights(strategy, quantity);
  interarrivals = getStrategyInterarrivals(strategy, quantity);

  sigma = interarrivals.front();
}

double player::ta(double t) {
  return sigma;
}

void player::dint(double t) {
  weights.pop_front();
  interarrivals.pop_front();

  if (!weights.empty()) {     
    sigma = interarrivals.front();
  } else {
    sigma = std::numeric_limits<double>::max();
  }
}

void player::dext(Event x, double t) {
  // TODO
}

Event player::lambda(double t) {
  double weight = weights.front();
  printLog("%s %f %f\n",name, weight, interarrivals.front());

  return Event(&weight, 0);
}

void player::exit() {
  printLog("Fin Player %s\n", name);
}
