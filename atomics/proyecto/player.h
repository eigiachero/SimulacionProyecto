//FLAGS:-std=c++11
//CPP:proyecto/player.cpp
//CPP:proyecto/numberGenerator.cpp
#if !defined player_h
#define player_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "limits"
#include "numberGenerator.h"

class player: public Simulator { 
	std::list<double> weights;
	std::list<double> interarrivals;
	int strategy;	

	double sigma;

	public:
		player(const char *n): Simulator(n) {};
		void init(double, ...);
		double ta(double t);
		void dint(double);
		void dext(Event , double );
		Event lambda(double);
		void exit();
};
#endif
