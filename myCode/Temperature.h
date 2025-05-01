/*
 * Temperature.h
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Measurement.h"

#include <stdint.h>
#include <string>
#include <memory>

class Temperature : public Measurement
{
private:

	float temperature;

public:
	Temperature(uint16_t timestamp, float temperature);
	float getTemperature();
	std::string toString();
	static std::shared_ptr<Temperature> fromString(uint16_t timestamp, std::string value);
	static Temperature* toType(Measurement* ptr);
};

#endif /* TEMPERATURE_H_ */
