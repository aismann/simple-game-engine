#ifndef LOGGER_HPP
#define LOGGER_HPP

/*
 * SimpleGameEngine
 * Logger.hpp
 *
 * Defines a class to help save debug/error information to a log file.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Mar 22, 2014
 * Last updated: Mar 23, 2014
 * Since:        v0.1
 */

#include <fstream>

namespace sge
{

class Logger
{
public:
	Logger();
	Logger(std::string fileName);

	~Logger(void);

	void load(std::string fileName);
	void addMessage(std::string message);
	void addErrorMessage(std::string message);
	void addDebugMessage(std::string message);
	void addInfoMessage(std::string message);

	//void setFileName(std::string fileName);

private:
	std::string fileName;
	std::ofstream file;

};

}


#endif //LOGGER_HPP
