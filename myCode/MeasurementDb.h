/*
 * MeasurementDb.h
 *
 *  Created on: 30 Apr 2025
 *      Author: Mateo C. Querol
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_

#include "Measurement.h"

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <istream>
#include <ostream>

class MeasurementDb
{
private:

	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;

public:

	void addMeasurements(const std::string& location, std::shared_ptr<Measurement> measurement);
	void print() const;
	void save(std::ostream& to);
	void load(std::istream& from);
	bool maximumTemperature(std::string& location, std::shared_ptr<Measurement>& measurement);
};

#endif /* MEASUREMENTDB_H_ */
