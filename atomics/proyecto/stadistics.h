//CPP:proyecto/stadistics.cpp
#if !defined stadistics_h
#define stadistics_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "Utilities/constants.h"
#include "limits"
#include <tuple>

using namespace std;

class stadistics: public Simulator {
	tuple<int, double, double> in; //(evento, peso_ganador, distancia_ganador)
	double out;
	int event;

	// State variables or info accumulators
	int PcArrivals;
	int PlayerArrivals;
	int PcCollisionWins;
	int PlayerCollisionWins;
	int CollisionDraws;

	double sigma;

	public:
		stadistics(const char *n): Simulator(n) {};
		void init(double, ...);
		double ta(double t);
		void dint(double);
		void dext(Event , double );
		Event lambda(double);
		void exit();
};
#endif
