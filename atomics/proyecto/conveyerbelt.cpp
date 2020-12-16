#include "conveyerbelt.h"

void conveyerbelt::init(double t,...) {
  va_list parameters;
  va_start(parameters,t);

  // Parameters
  velocity = va_arg(parameters, double);
  length = va_arg(parameters, double);

  sigma = numeric_limits<double>::max();
}

double conveyerbelt::ta(double t) {
  return sigma;
}

void conveyerbelt::dint(double t) {
  // Obtain the first box of each side, once all distances are updated
  PcBoxes = updateAllDistances(PcBoxes, e, velocity);
  PlayerBoxes = updateAllDistances(PlayerBoxes, e, velocity);
  pair<double,double> PcBox = PcBoxes.front();
  pair<double,double> PlayerBox = PlayerBoxes.front();

  if (PlayerBoxes.empty()) {      // Pc arrival
    PcBoxes.pop_front();
  } else if (PcBoxes.empty()) {   // Player arrival
    PlayerBoxes.pop_front();
  } else {                        // Collisions
    double PcCollisionPower = collisionPower(PcBox);
    double PlayerCollisionPower = collisionPower(PlayerBox);

    PcBoxes.pop_front();
    PlayerBoxes.pop_front();
    if (!isEqual(PlayerCollisionPower, PcCollisionPower)) {
      if (PlayerCollisionPower < PcCollisionPower) {  // Collision PC Win
        pair<double,double> box (updatedWeight(PcBox, PlayerBox), PcBox.second);
        PcBoxes.push_front(box);
      }
      if (PlayerCollisionPower > PcCollisionPower) {  // Collision Player Win
        pair<double,double> box (updatedWeight(PlayerBox, PcBox), PlayerBox.second);
        PlayerBoxes.push_front(box);
      }
    }
  }

  sigma = nextEvent(PcBoxes, PlayerBoxes, length, velocity);
}

void conveyerbelt::dext(Event x, double t) {
  in = *(double*) x.value;
  pair<double,double> box (in, 0.0);  // Box to add at the begin of the belt.

  PcBoxes = updateAllDistances(PcBoxes, e, velocity);
  PlayerBoxes = updateAllDistances(PlayerBoxes, e, velocity);
  if (x.port == PC) {
    PcBoxes.push_back(box);
  }
  if (x.port == Player) {
    PlayerBoxes.push_back(box);
  }

  sigma = nextEvent(PcBoxes, PlayerBoxes, length, velocity);
}

Event conveyerbelt::lambda(double t) {
  // Obtain the first box of each side, with their distance updated
  PcDistance = updatedDistance(PcBoxes.front().second, sigma, velocity);
  PlayerDistance = updatedDistance(PlayerBoxes.front().second, sigma, velocity);
  pair<double,double> PcBox (PcBoxes.front().first, PcDistance);
  pair<double,double> PlayerBox (PlayerBoxes.front().first, PlayerDistance);

  if (PlayerBoxes.empty()) { // PC arrival
    out = make_tuple(PC_ARRIVAL, PcBox.first, length);
    return Event(&out, ARRIVALS_PORT);

  } else if (PcBoxes.empty()) { // Player arrival
    out = make_tuple(PLAYER_ARRIVAL, PlayerBox.first, length);
    return Event(&out, ARRIVALS_PORT);

  } else { // Collisions
    double PcCollisionPower = collisionPower(PcBox);
    double PlayerCollisionPower = collisionPower(PlayerBox);

    if (isEqual(PlayerCollisionPower, PcCollisionPower)) { // Collision Draw
      out = make_tuple(COLLISION_DRAW, 0, PlayerDistance);
      return Event(&out, COLLISIONS_PORT);

    } else if (PlayerCollisionPower < PcCollisionPower) { // Collision PC wins
      out = make_tuple(COLLISION_PC_WINS, updatedWeight(PcBox, PlayerBox), PcDistance);
      return Event(&out, COLLISIONS_PORT);

    } else if (PlayerCollisionPower > PcCollisionPower) { // Collision Player wins
      out = make_tuple(COLLISION_PLAYER_WINS, updatedWeight(PlayerBox, PcBox), PlayerDistance);
      return Event(&out, COLLISIONS_PORT);

    }
  }

  return Event();
}

void conveyerbelt::exit() {
  // printLog("Fin Cinta\n");
}
