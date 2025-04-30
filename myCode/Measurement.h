/*
 * Measurement.h
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

#include <stdint.h>
#include <string>

class Measurement
{
private:

	uint16_t timestamp;

public:
	Measurement(uint16_t timestamp);
	virtual ~Measurement();

	uint16_t toTimestap(int hour, int minute);
	std::string toTimeOfDay(uint16_t timestamp);

	long getTimestamp() const;
	virtual std::string toString() const;
	void parseLine(const std::string& line, uint16_t timestamp, std::string& type, std::string& remainder);

};

#endif /* MEASUREMENT_H_ */
