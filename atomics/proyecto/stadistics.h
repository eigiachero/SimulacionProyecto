//CPP:proyecto/stadistics.cpp
#if !defined stadistics_h
#define stadistics_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "constants.h"
#include "limits"
#include <tuple>

class stadistics: public Simulator {
	std::tuple<int, double, double> in;
	double out;
	int event;

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
