#pragma once
#include "systemc.h"
#include <iostream>
#include <iomanip>

SC_MODULE(Display)
{
	sc_in<int> X{ "Dspl_X" };
	sc_in<int> Y{ "Dspl_Y" };
	sc_in<int> sum{ "Dspl_sum" };
	sc_in<int> f1{ "Dspl_f1" };
	sc_in<int> r1{ "Dspl_r1" };
	sc_in<int> r2{ "Dspl_r2" };
	sc_in<bool> CLK{ "Dspl_CLK" };

	void showResults();

	SC_CTOR(Display)
	{
		SC_THREAD(showResults);
		sensitive << CLK.pos();
	}
};
