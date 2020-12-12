#include "conveyerbelt.h"

void conveyerbelt::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);

  velocity = va_arg(parameters, double);
  length = va_arg(parameters, double);
  printLog("parametros %f %f\n", velocity, length);

  sigma = std::numeric_limits<double>::max();
}

double conveyerbelt::ta(double t) {
  return sigma;
}

void conveyerbelt::dint(double t) {
}

void conveyerbelt::dext(Event x, double t) {
  in = *(double*) x.value;
  std::pair<double,double> box (in, 0.0);

  PcBoxes = updateAllDistances(PcBoxes, t, velocity);
  PlayerBoxes = updateAllDistances(PlayerBoxes, t, velocity);
  if (x.port == PC) {
    PcBoxes.push_back(box);
  }
  if (x.port == Player) {
    PlayerBoxes.push_back(box);
  }

  sigma = nextEvent(PcBoxes, PlayerBoxes, length, velocity);

  /*
  printLog("Sigma %f\n", sigma);   
  printLog("Puerto %d Tiempo %f\n",x.port, t);
  printLog("PC %f %f %d \n", PcBoxes.front().second, PcBoxes.back().second, PcBoxes.size());
  printLog("Player %f %f %d \n", PlayerBoxes.front().second, PlayerBoxes.back().second, PlayerBoxes.size());
  printLog("\n");
  */  
}

Event conveyerbelt::lambda(double t) {
  printLog("Llegue a 0\n");
  return Event();
}

void conveyerbelt::exit() {
  printLog("Fin Cinta\n");
}
