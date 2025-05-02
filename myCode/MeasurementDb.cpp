/*
 * MeasurementDb.cpp
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#include "MeasurementDb.h"
#include "Temperature.h"
#include "Humidity.h"

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
	for(const auto& measurements : data)
	{
		to << '[' << measurements.first << ']' << "\n";
		for(const auto& vec : measurements.second)
		{
			to << vec.get()->getTimestamp() << ';' << vec.get()->toString() << "\n";
		}
	}
}

void MeasurementDb::load(std::istream &from)
{

	data.clear(); //clear the map containing all data
	string line;
	uint16_t timestamp;
	string type;
	string remainder;
	string location;

	shared_ptr<Measurement> ptr;
	while (getline(from, line))
	{
		if(line[0] == '[' && line[line.size() - 1] == ']') //location
		{
			line.erase(0, 1); //remove [
			line.erase(line.end() - 1); //remove ]
			location = line;
		}
		else
		{
			Measurement::parseLine(line, timestamp, type, remainder);
			if(type == "Temperature")
			{
				ptr = Temperature::fromString(timestamp, remainder);
			}
			else
			{
				ptr = Humidity::fromString(timestamp, remainder);
			}
			addMeasurements(location, ptr);
		}
	}
}

bool MeasurementDb::maximumTemperature(std::string &location, std::shared_ptr<Measurement> &measurement)
{
	return false;
}
