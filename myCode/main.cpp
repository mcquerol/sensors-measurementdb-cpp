
#include <iostream>
#include "Measurement.h"
#include "Temperature.h"

using namespace std;

int main ()
{

	Temperature Measurement1(Measurement::toTimestap(6,0), -3);
	cout << Measurement1.toString() << endl;
	//overloaded print;
	cout << Measurement1 << endl;

	return 0;
}
