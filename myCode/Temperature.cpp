/*
 * Temperature.cpp
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#include "Temperature.h"

using namespace std;

Temperature::Temperature(uint16_t timestamp, float temperature) : Measurement{timestamp}, temperature{temperature}
{
}

float Temperature::getTemperature()
{
	return temperature;
}

std::string Temperature::toString()
{
	return "Temperature: " + std::to_string(temperature) + " *C";
}

std::shared_ptr<Temperature> Temperature::fromString(uint16_t timestamp, std::string value)
{
	return make_shared<Temperature>(timestamp, stof(value));
}

Temperature* Temperature::toType(Measurement *ptr)
{
	Temperature* temp; //placeholder
	return temp;
}
