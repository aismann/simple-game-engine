#ifndef UTILITY_H
#define UTILITY_H

/*
 * SimpleGameEngine
 * Utility.h
 *
 * Header file to contain global variables and methods to be accessed through "sge" namespace.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Mar 22, 2014
 * Last updated: Jan 24, 2015
 * Since:        v0.1
 */

#include <vector>

namespace sge
{
	const std::string TITLE = "PGD";
	const int SCREEN_WIDTH  = 1280;
	const int SCREEN_HEIGHT = 720;
	const int BPP           = 32;

	// Logger constants
	const std::string LOG_FILE_EXTENTION = ".log";
	const std::string LOG_FILE_FOLDER    = "log/";

	// XML File constants
	const std::string XML_FILE           = "file";
	const std::string XML_FRICTION       = "friction";
	const std::string XML_ID             = "id";
	const std::string XML_MASS           = "mass";
	const std::string XML_NAME           = "name";
	const std::string XML_OBJECT         = "Object";
	const std::string XML_POS_X          = "x";
	const std::string XML_POS_Y          = "y";
	const std::string XML_OBJ_BACKGROUND = "BackgroundObject";
	const std::string XML_OBJ_DYNAMIC    = "DynamicObject";
	const std::string XML_OBJ_STATIC     = "StaticObject";
	const std::string XML_OFFSET_X       = "offsetX";
	const std::string XML_OFFSET_Y       = "offsetY";
	const std::string XML_TEXTURE        = "Texture";
	const std::string XML_TYPE           = "type";
	

	/*
	 * Splits a string according to the passed delimiter.
	 * If an escaped 0, '\0', is passed, the string is not split.
	 * Pass '0' as delimiter instead of '\0' to split by 0.
	 */
	std::vector<std::string> split(const std::string& s, const char delimiter, bool trimWhiteSpace = false);

	/*
	 * Returns a copy of the passed string with whitespace trimmed.
	 */
	std::string trim(std::string s);

	std::string getCurrentTime();
	std::string getCurrentTimeDate();
	std::string getCurrentTimeDate(std::string);

	int stringToInt(const std::string &s);
	float stringToFloat(const std::string &s);
}

#endif //UTILITY_H
