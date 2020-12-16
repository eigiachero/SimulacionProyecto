#include "numberGenerator.h"

mt19937 generator;
random_device rd;

list<double> genExponentialDistribution(double mean, int quantity){
    generator.seed(rd());
    list<double> exponentialNumbers;

    exponential_distribution<double> distExp(1.0/mean);
    for (int i=0; i<quantity; i++){
        double num = distExp(generator);
        exponentialNumbers.push_back(num);
    }

    return exponentialNumbers;
};

list<double> genUniformDistribution(double min, double max, int quantity){
    generator.seed(rd());
    list<double> uniformNumbers;

    uniform_real_distribution<double> distUnif(min, max);
    for (int i=0; i<quantity; i++){
        double num = distUnif(generator);
        uniformNumbers.push_back(num);
    }

    return uniformNumbers;
};


list<double> genInfiniteList(int quantity) {
    list<double> listOfInfinites;

    for (int i=0; i<quantity; i++){
        listOfInfinites.push_back(numeric_limits<double>::max());
    }

    return listOfInfinites;
}

int getRandomInt(double min, double max) {
    generator.seed(rd());
    uniform_real_distribution<double> distUnif(min, max);

    return (int) distUnif(generator);
};