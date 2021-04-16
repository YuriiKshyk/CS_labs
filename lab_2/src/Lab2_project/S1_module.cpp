#include "S1_module.h"

void S1::calculate()
{
	sum = X.read() + Y.read();
	f1 = (X.read() ^ Y.read()) - (X.read() << 1);
}
