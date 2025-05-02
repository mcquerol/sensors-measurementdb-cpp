
#include <iostream>
#include <fstream>
#include "Measurement.h"
#include "MeasurementDb.h"
#include "Temperature.h"
#include "Humidity.h"

using namespace std;

int main ()
{

	Temperature Measurement1(Measurement::toTimestap(6,0), -3);
	cout << Measurement1.toString() << endl;
	//overloaded print;
	cout << Measurement1 << endl;
	MeasurementDb db;
	shared_ptr<Measurement> MeasurementPtr1 = make_shared<Humidity>(Measurement::toTimestap(8,0), 80.0f);
	shared_ptr<Measurement> MeasurementPtr2 = make_shared<Temperature>(Measurement::toTimestap(10,5), 20.0f);
	shared_ptr<Measurement> MeasurementPtr3 = make_shared<Temperature>(Measurement::toTimestap(12,0), 22.0f);
	db.addMeasurements("Bath", MeasurementPtr1);
	db.addMeasurements("Kitchen", MeasurementPtr2);
	db.addMeasurements("Kitchen", MeasurementPtr3);
	db.print();

	//write db contents to data.txt
	ofstream fileOut("data.txt");
	db.save(fileOut);
	fileOut.close();
	cout << endl;
	//reading file
	MeasurementDb db2;
	ifstream fileIn("data.txt");
	db2.load(fileIn);
	fileIn.close();
	cout << "Database 2 - data.txt contents" << endl;
	db2.print();

	//testing the maximum temperature of
	string testLocation;
	shared_ptr<Measurement> testPtr;
	if(db.maximumTemperature(testLocation, testPtr))
	{
		cout << "Max temperature: " << testLocation << ' ' << testPtr->toTimeOfDay(testPtr->getTimestamp()) << ' ' << testPtr->toString() << endl;
	}

	return 0;
}
