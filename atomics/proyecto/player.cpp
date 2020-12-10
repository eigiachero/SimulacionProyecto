#include "player.h"

void player::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);
  
  weights = genUniformDistribution(5.0, 8.0, 100);
  interarrivals = genExponentialDistribution(6.0, 100);
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

}

Event player::lambda(double t) {
  double weight = weights.front();
  printLog("%f %f\n", weight, interarrivals.front());

  return Event(&weight, 0);
}

void player::exit() {
  printLog("Fin Player PC");
}
