/*
 * SimpleGameEngine
 * Utility.cpp
 *
 * Header file to contain global variables and methods to be accessed through "sge" namespace.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Mar 22, 2014
 * Last updated: Jan 24, 2015
 * Since:        v0.1
 */

#include <time.h>
#include <sstream>   // for std::stringstream
#include <algorithm> // for std::remove_if
#include <string>
//#include <ctype.h>   // for isspace
#include "../../../include/SGE/utility/Utility.h"

/* Derecated: Use sf::String */
std::vector<std::string> sge::split(const std::string& s, const char delimiter, bool trimWhitespace)// = false)
{
	const char NULL_CHAR_REPRESENTATION = '\0';

	std::vector<std::string> values;

	// If delimiter is '\0', return vector of string.
	if (delimiter == NULL_CHAR_REPRESENTATION) {
		values.push_back(s);

		return values;
	}

	std::stringstream ss(s);
	std::string value;

	while(std::getline(ss, value, delimiter))
	{			
		if (trim(value) != "") {
			if (trimWhitespace) {
				value = trim(value);
			}

			values.push_back(value);
		}
	}

	return values;
}

/* Deprecated: Use sf::String */
std::string sge::trim(std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());

	return s;
}

/*
 * Functions to get the current date and time as a std::string using <time.h>
 */
std::string sge::getCurrentTime()
{
	const std::string TIME_FORMAT = "%X";

	return sge::getCurrentTimeDate(TIME_FORMAT);
}

std::string sge::getCurrentTimeDate()
{
	const std::string TIME_FORMAT = "%m-%d-%Y %X";

	return sge::getCurrentTimeDate(TIME_FORMAT);
}

std::string sge::getCurrentTimeDate(std::string format)
{
	time_t currentTime = time(0);

	struct tm timeInfo;
	
	//timeStruct = *localtime(&currentTime); //deprecated
	localtime_s(&timeInfo, &currentTime);

	char timeBuffer[80];
	strftime(timeBuffer, sizeof(timeBuffer), format.c_str(), &timeInfo);

	return timeBuffer;
}

int sge::stringToInt(const std::string &s) {
	std::stringstream ss(s);
	int result;
	return ss >> result ? result : 0;
}

float sge::stringToFloat(const std::string &s) {
	std::stringstream ss(s);
	float result;
	return ss >> result ? result : 0.0f;
}
