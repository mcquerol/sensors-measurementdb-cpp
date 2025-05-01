/*
 * MeasurementDb.cpp
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#include "MeasurementDb.h"
#include <iostream>

using namespace std;

void MeasurementDb::addMeasurements(const std::string &location, std::shared_ptr<Measurement> measurement)
{
	auto it = data.find(location);
	if(it != data.end())
	{
		data[location].emplace_back(measurement);
	}
	else
	{
		vector<shared_ptr<Measurement>> vec;
		vec.emplace_back(measurement);
		data.insert({location, vec});
	}
}

void MeasurementDb::print() const
{
	cout << "Contents of database: " << endl;
	for(const auto& measurements : data)
	{
		for(const auto& vec : measurements.second)
		{
			cout << measurements.first << ": ";
			cout << *vec.get();
		}
	}
}

void MeasurementDb::save(std::ostream &to)
{
}

void MeasurementDb::load(std::istream &from)
{
}

bool MeasurementDb::maximumTemperature(std::string &location, std::shared_ptr<Measurement> &measurement)
{
	return false;
}
