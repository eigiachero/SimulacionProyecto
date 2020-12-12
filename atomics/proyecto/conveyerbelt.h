//CPP:proyecto/conveyerbelt.cpp
//CPP:proyecto/beltLibrary.cpp
#if !defined conveyerbelt_h
#define conveyerbelt_h
#define PC 0
#define Player 1

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "limits"
#include "beltLibrary.h"
#include <list>
#include <utility>

class conveyerbelt: public Simulator {
	double length;
	double velocity;
	std::list<std::pair<double,double>> PcBoxes;
	std::list<std::pair<double,double>> PlayerBoxes;

	double sigma;
	double in;

	public:
		conveyerbelt(const char *n): Simulator(n) {};
		void init(double, ...);
		double ta(double t);
		void dint(double);
		void dext(Event , double );
		Event lambda(double);
		void exit();
};
#endif
