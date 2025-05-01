/*
 * Humidity.h
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include "Measurement.h"
#include <stdint.h>
#include <string>
#include <memory>

class Humidity : public Measurement
{
private:

	float humidity;

public:
	Humidity(uint16_t timestamp, float humidity);
	float getHumidity();
	std::string toString();
	static std::shared_ptr<Humidity> fromString(uint16_t timestamp, std::string value);
	static Humidity* toType(Measurement* ptr);
};

#endif /* HUMIDITY_H_ */
