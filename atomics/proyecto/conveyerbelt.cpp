#include "conveyerbelt.h"

void conveyerbelt::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);

  velocity = (int) va_arg(parameters, double);
  length = (int) va_arg(parameters, double);

  sigma = std::numeric_limits<double>::max();
}

double conveyerbelt::ta(double t) {
  return sigma;
}

void conveyerbelt::dint(double t) {
}

void conveyerbelt::dext(Event x, double t) {
  in = *(double*) x.value;
  std::pair<double,double> box (in,0.0);
  // printLog("%d %f\n", x.port, in);
  if (x.port == PC) {
    PcBoxes.push_back(box);
  }
  if (x.port == Player) {
    PlayerBoxes.push_back(box);
  }

  /*
  printLog("%d\n",x.port);
  printLog("%f %f %d \n", PcBoxes.front().first, PcBoxes.back().first, PcBoxes.size());
  printLog("%f %f %d \n", PlayerBoxes.front().first, PlayerBoxes.back().first, PlayerBoxes.size());
  printLog("\n");
  */
}

Event conveyerbelt::lambda(double t) {
  return Event();
}

void conveyerbelt::exit() {
  printLog("Fin Cinta");
}
