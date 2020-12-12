#include "stadistics.h"

void stadistics::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);

  PcArrivals = 0;
	PlayerArrivals = 0;
	PcCollisionWins = 0;
	PlayerCollisionWins = 0;
	CollisionDraws = 0;
  sigma = std::numeric_limits<double>::max();
}

double stadistics::ta(double t) {
  return sigma;
}

void stadistics::dint(double t) {
  sigma = std::numeric_limits<double>::max();
}

void stadistics::dext(Event x, double t) {
  in = *(std::tuple<int, double, double>*) x.value;
  event = std::get<0>(in);
  // printLog("evento:%d peso:%f\n",  std::get<0>(in), std::get<1>(in));
  
  switch (event) {
    case PC_ARRIVAL:
      PcArrivals++;
      break;
    case PLAYER_ARRIVAL:
      PlayerArrivals++;
      break;
    case COLLISION_PC_WINS:
      PcCollisionWins++;
      break;
    case COLLISION_PLAYER_WINS:
      PlayerCollisionWins++;
      break;
    case COLLISION_DRAW:
      CollisionDraws++;
      break;
  }

  sigma = 0;
}

Event stadistics::lambda(double t) {
  switch (event) {
    case PC_ARRIVAL:
      // printLog("pc arrival \n");
      out = PcArrivals;
      return Event(&out, 0);
      break;
    case PLAYER_ARRIVAL:
      // printLog("player arrival \n");
      out = PlayerArrivals;
      return Event(&out, 1);
      break;
    case COLLISION_PC_WINS:
      // printLog("pc collision \n");
      out = PcCollisionWins;
      return Event(&out, 2);
      break;
    case COLLISION_PLAYER_WINS:
      // printLog("player collision \n");
      out = PlayerCollisionWins;
      return Event(&out, 3);
      break;
    case COLLISION_DRAW:
      // printLog("collision \n");
      out = CollisionDraws;
      return Event(&out, 4);
      break;
  }
  return Event();
}

void stadistics::exit() {
  printLog("\n-------------- Simulation results ----------\n");
  printLog("Collisions winned by Pc: %d \n", PcCollisionWins);
  printLog("Collisions winned by Player: %d \n", PlayerCollisionWins);
  printLog("Colisiones ended with draw: %d \n", CollisionDraws);
  printLog("Pc Arrivals: %d \n",PcArrivals);
  printLog("Player Arrivals: %d \n",PlayerArrivals);
  printLog("-------------------------------------------------\n\n");
}

