#include "beltLibrary.h"

bool isEqual(double A, double B) {
  double epsilon = 0.000000001;

  return fabs(A - B) < epsilon;
}

double collisionPower(pair<double,double> box) {
  return box.first * box.second;
}

double updatedDistance(double oldDistance, double time, double velocity) {
  return oldDistance + time * velocity;
}

list<pair<double,double>> updateAllDistances(list<pair<double,double>> boxes, double time, double velocity) {
  list<pair<double,double>> updatedBoxes;
  int listSize = boxes.size();

  for (int i = 0; i < listSize; i++) {
    pair<double,double> box = boxes.back();
    pair<double,double> updatedBox (box.first, updatedDistance(box.second, time, velocity));
    updatedBoxes.push_front(updatedBox);
    boxes.pop_back();
  }

  return updatedBoxes;
}

double updatedWeight(pair<double,double> winnerBox, pair<double,double> loserBox) {
  return winnerBox.first * (collisionPower(loserBox) / collisionPower(winnerBox));
}

// Return the time left for the next event to occur.
double nextEvent(list<pair<double,double>> PcBoxes, list<pair<double,double>> PlayerBoxes, double length, double velocity){
  if (!PcBoxes.empty() && !PlayerBoxes.empty()) {   // Next event is a collision
    return (((length - PcBoxes.front().second - PlayerBoxes.front().second) / 2) / velocity);
  }
  if (!PcBoxes.empty()) {       // Next event is a PC arrival
    return (length - PcBoxes.front().second) / velocity;
  }
  if (!PlayerBoxes.empty()) {   // Next event is a Player arrival
    return (length - PlayerBoxes.front().second) / velocity;
  }

  return numeric_limits<double>::max();   // There are no elements in the belt
}
