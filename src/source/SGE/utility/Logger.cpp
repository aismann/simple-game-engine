/*
 * SimpleGameEngine
 * Logger.cpp
 *
 * Defines a class to help save debug/error information to a log file.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Mar 22, 2014
 * Last updated: Jan 11, 2014
 * Since:        v0.1
 */

#include <time.h>
#include <sstream>
#include <fstream>
#include "../../../include/SGE/utility/Logger.hpp"
#include "../../../include/SGE/utility/Utility.h"

// Constants
static const char NEWLINE = '\n';

// Constructors
sge::Logger::Logger()
{
	std::stringstream ss;
	ss << sge::LOG_FILE_FOLDER << sge::TITLE << sge::LOG_FILE_EXTENTION;

	load(ss.str());
}

sge::Logger::Logger(std::string fileName)
{
	load(fileName);
}

// Public methods
void sge::Logger::load(std::string fileName)
{
	this->fileName = fileName;
}

void sge::Logger::addMessage(std::string message)
{
	file.open(fileName.c_str(), std::ios::app);

	file << sge::getCurrentTime() << message << NEWLINE;

	file.close();
}

void sge::Logger::addErrorMessage(std::string message)
{
	const std::string ERROR_APPEND = " [ERROR]: ";

	std::stringstream ss;
	ss << ERROR_APPEND << message;
	addMessage(ss.str());
}

void sge::Logger::addDebugMessage(std::string message)
{
	const std::string DEBUG_APPEND = " [DEBUG]: ";

	std::stringstream ss;
	ss << DEBUG_APPEND << message;
	addMessage(ss.str());
}

void sge::Logger::addInfoMessage(std::string message)
{
	const std::string INFO_APPEND = " [INFO]:  ";

	std::stringstream ss;
	ss << INFO_APPEND << message;
	addMessage(ss.str());
}

// Destructor
sge::Logger::~Logger()
{	
	file.close();
}
