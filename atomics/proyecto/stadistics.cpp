#include "stadistics.h"

void stadistics::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);

  // Initialize accumulators
  PcArrivals = 0;
	PlayerArrivals = 0;
	PcCollisionWins = 0;
	PlayerCollisionWins = 0;
	CollisionDraws = 0;

  sigma = numeric_limits<double>::max();
}

double stadistics::ta(double t) {
  return sigma;
}

void stadistics::dint(double t) {
  sigma = numeric_limits<double>::max();
}

void stadistics::dext(Event x, double t) {
  // Increment the quantity of the event that has occurred.
  in = *(tuple<int, double, double>*) x.value;
  event = get<0>(in);

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
  // Return the quantity of the event that has occurred.
  switch (event) {
    case PC_ARRIVAL:
      out = PcArrivals;
      return Event(&out, 0);
      break;
    case PLAYER_ARRIVAL:
      out = PlayerArrivals;
      return Event(&out, 1);
      break;
    case COLLISION_PC_WINS:
      out = PcCollisionWins;
      return Event(&out, 2);
      break;
    case COLLISION_PLAYER_WINS:
      out = PlayerCollisionWins;
      return Event(&out, 3);
      break;
    case COLLISION_DRAW:
      out = CollisionDraws;
      return Event(&out, 4);
      break;
  }

  return Event();
}

void stadistics::exit() {
  // Info about the simulation.
  int total = PcCollisionWins + PlayerCollisionWins + PcArrivals  + PlayerArrivals + (CollisionDraws * 2); 
  printLog("\n-------------- Simulation results --------------\n");
  printLog("Collisions winned by Pc: %d\n", PcCollisionWins);
  printLog("Collisions winned by Player: %d\n", PlayerCollisionWins);
  printLog("Colisiones ended with draw: %d\n", CollisionDraws);
  printLog("Pc Arrivals: %d\n", PcArrivals);
  printLog("Player Arrivals: %d\n", PlayerArrivals);
  printLog("Total: %d\n", total);
  printLog("-------------------------------------------------\n");
}

