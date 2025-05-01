/*
 * Humidity.cpp
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#include "Humidity.h"

using namespace std;

Humidity::Humidity(uint16_t timestamp, float humidity) : Measurement{timestamp}, humidity{humidity}
{
}

float Humidity::getHumidity()
{
	return humidity;
}

std::string Humidity::toString()
{
	return "Humidity: " + std::to_string(humidity) + " %";
}

std::shared_ptr<Humidity> Humidity::fromString(uint16_t timestamp, std::string value)
{
	shared_ptr<Humidity> ptr; //placeholder
	return ptr;
}

Humidity* Humidity::toType(Measurement *ptr)
{
	Humidity* temp; //placeholder
	return temp;
}
