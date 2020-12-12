#include "beltLibrary.h"

double collisionPower(std::pair<double,double> box) {
  return box.first * box.second;
}

double updatedDistance(double oldDistance, double time, double velocity) {
  return oldDistance + time * velocity;
}

std::list<std::pair<double,double>> updateAllDistances(std::list<std::pair<double,double>> boxes, double time, double velocity) {
  std::list<std::pair<double,double>> updatedBoxes;
  int listSize = boxes.size();

  for (int i = 0; i < listSize; i++) {
    std::pair<double,double> box = boxes.back();
    std::pair<double,double> updatedBox (box.first, updatedDistance(box.second, time, velocity));
    updatedBoxes.push_front(updatedBox);
    boxes.pop_back();
  }

  return updatedBoxes;
}

double updatedWeight(std::pair<double,double> winnerBox, std::pair<double,double> loserBox) {
  return winnerBox.first * (collisionPower(loserBox) / collisionPower(winnerBox));
}

double nextEvent(std::list<std::pair<double,double>> PcBoxes, std::list<std::pair<double,double>> PlayerBoxes, double length, double velocity){
  if (!PcBoxes.empty() && !PlayerBoxes.empty()) {
    return (((length - PcBoxes.front().second - PlayerBoxes.front().second) / 2) / velocity);
  }
  if (!PcBoxes.empty()) {
    return (length - PcBoxes.front().second) / velocity;
  }
  if (!PlayerBoxes.empty()) {
    return (length - PlayerBoxes.front().second) / velocity;
  }
  return std::numeric_limits<double>::max();
}
