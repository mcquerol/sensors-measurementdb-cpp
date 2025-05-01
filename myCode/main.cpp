
#include <iostream>
#include "Measurement.h"
#include "Temperature.h"

using namespace std;

int main ()
{

	Temperature Measurement1(Measurement::toTimestap(6,0), -3);
	cout << Measurement1.toString() << endl;

	return 0;
}
