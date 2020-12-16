//FLAGS:-std=c++11
//CPP:proyecto/player.cpp
//CPP:proyecto/Utilities/numberGenerator.cpp
//CPP:proyecto/Utilities/strategies.cpp
#if !defined player_h
#define player_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"
#include "limits"
#include "Utilities/strategies.h"
#include "Utilities/constants.h"
#include <list>
#include <tuple>

using namespace std;

class player: public Simulator {
	// State
	list<double> weights;
	list<double> interarrivals;
	// Parameters
	int strategy;
	int quantity;
	char* name;

	// Input parameters
	tuple<int, double, double> in; //(evento, peso_ganador, distancia_ganador)

	double out;
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
