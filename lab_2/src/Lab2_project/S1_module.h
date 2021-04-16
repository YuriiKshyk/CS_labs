#pragma once
#include "systemc.h"

struct S1 : sc_module
{
	sc_in<int> X{ "S1_X" };
	sc_in<int> Y{ "S1_Y" };
	sc_in<bool> CLK{ "S1_CLK" };
	sc_out<int> sum{ "S1_sum" };
	sc_out<int> f1{ "S1_f1" };

	void calculate();

	SC_CTOR(S1)
	{
		SC_METHOD(calculate);
		sensitive << CLK.neg();
	}
};
