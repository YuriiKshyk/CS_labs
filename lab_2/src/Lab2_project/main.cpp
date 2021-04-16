#include "systemc.h"
#include "S1_module.h"
#include "S2_module.h"
#include "Display_module.h"

int sc_main(int argc, char* argv[])
{
	sc_clock CLK("CLK", 1, SC_NS);
	sc_signal<int> X{ "X" }, Y{ "Y" }, sum{ "sum" }, f1{ "f1" }, r1{ "r1" }, r2{ "r2" };

	X = 12;
	Y = 'K' + 'Y';

	S1 s1("s1");
	s1.CLK(CLK);
	s1.X(X);
	s1.Y(Y);
	s1.sum(sum);
	s1.f1(f1);

	S2 s2("s2");
	s2.CLK(CLK);
	s2.a(sum);
	s2.b(f1);
	s2.r1(r1);
	s2.r2(r2);

	Display display("display");
	display.CLK(CLK);
	display.X(X);
	display.Y(Y);
	display.sum(sum);
	display.f1(f1);
	display.r1(r1);
	display.r2(r2);

	sc_start();

	return (0);
}
