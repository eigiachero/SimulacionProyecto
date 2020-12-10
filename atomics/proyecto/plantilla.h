//CPP:proyecto/player.cpp
#if !defined player_h
#define player_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

class player: public Simulator { 


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
