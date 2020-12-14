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

  sigma = 0;
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
  in = *(std::tuple<int, double, double>*) x.value;
  int event = (int) std::get<0>(in);

  if (!weights.empty()) {
    if (event == PLAYER_ARRIVAL) {
      if (strategy == 3 || strategy == 4) {
        sigma = 0;
      }
    }
    if (event == COLLISION_DRAW) {
      if (strategy == 3 || strategy == 4) {
        weights = strategyRandomWeight(weights);
        sigma = 0;
      }
    }
    if (event == COLLISION_PC_WINS) {
      if (strategy == 3) {
        weights = strategyReorderWeightList(weights, std::get<1>(in));
        sigma = 0;
      }
      if (strategy == 4) {
        sigma = 0;
      }
    } 
  }
}

Event player::lambda(double t) {
  out = weights.front();

  return Event(&out, 0);
}

void player::exit() {
  // printLog("Fin Player %s\n", name);
}
