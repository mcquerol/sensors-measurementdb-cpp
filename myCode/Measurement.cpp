/*
 * Measurement.cpp
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#include "Measurement.h"

#include <iostream>

using namespace std;

Measurement::Measurement(uint16_t timestamp) : timestamp{timestamp}
{
}

Measurement::~Measurement()
{
}

uint16_t Measurement::toTimestap(int hour, int minute)
{

	if(hour < 0 || hour > 23 || minute < 0 || minute > 59)
	{
		throw std::invalid_argument("Hour or minute out of range");;
	}

	return hour * 60 + minute;
}

std::string Measurement::toTimeOfDay(uint16_t timestamp)
{
	string timeOfDayStr;
	if (timestamp < 0 || timestamp >= 1440)
	{
	    throw std::invalid_argument("Timestamp out of range (must be 0–1439)");
	}
	int hours = timestamp / 60;
	int minutes = timestamp % 60;
	if(hours < 10)
	{
		timeOfDayStr += '0';
	}
	timeOfDayStr += to_string(hours);
	timeOfDayStr += ":";
	if(minutes < 10)
	{
		timeOfDayStr += '0';
	}
	timeOfDayStr += to_string(minutes);

	return timeOfDayStr;
}

long Measurement::getTimestamp() const
{
	return timestamp;
}

void Measurement::parseLine(const std::string &line, uint16_t timestamp,std::string &type, std::string &remainder)
{

}

std::ostream& operator <<(std::ostream &lhs, Measurement &rhs)
{
	return lhs << rhs.toTimeOfDay(rhs.getTimestamp()) << ' ' << rhs.toString() << endl;
}
