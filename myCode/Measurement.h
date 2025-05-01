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
#include <ostream>

class Measurement
{
private:

	uint16_t timestamp;

public:
	Measurement(uint16_t timestamp);
	virtual ~Measurement();

	static uint16_t toTimestap(int hour, int minute);
	static std::string toTimeOfDay(uint16_t timestamp);

	long getTimestamp() const;
	virtual std::string toString() = 0;
	static void parseLine(const std::string& line, uint16_t timestamp, std::string& type, std::string& remainder);

};

std::ostream& operator<<(std::ostream& lhs, Measurement& rhs);

#endif /* MEASUREMENT_H_ */
