
#include <iostream>
#include "Measurement.h"
#include "Temperature.h"

using namespace std;

int main ()
{
	cout << "test" << endl;

	Temperature temp(200, 30);

	cout << temp.toString() << endl;

	return 0;
}
