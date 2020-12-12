#include "numberGenerator.h"

std::mt19937 generator;
std::random_device rd;

std::list<double> genExponentialDistribution(double mean, int quantity){
    generator.seed(rd());
    std::list<double> exponentialNumbers;

    std::exponential_distribution<double> distExp(1.0/mean);
    for (int i=0; i<quantity; i++){
        double num = distExp(generator);
        exponentialNumbers.push_back(num);
    }
    
    return exponentialNumbers;
};

std::list<double> genUniformDistribution(double min, double max, int quantity){
    generator.seed(rd());
    std::list<double> uniformNumbers;

    std::uniform_real_distribution<double> distUnif(min, max);
    for (int i=0; i<quantity; i++){
        double num = distUnif(generator);
        uniformNumbers.push_back(num);
    }

    return uniformNumbers;
};


std::list<double> genInfiniteList(int quantity) {
    std::list<double> listOfInfinites;

    for (int i=0; i<quantity; i++){
        listOfInfinites.push_back(std::numeric_limits<double>::max());
    }

    return listOfInfinites;
}

int getRandomInt(double min, double max) {
    generator.seed(rd());
    std::uniform_real_distribution<double> distUnif(min, max);
   
    return (int) distUnif(generator);
};