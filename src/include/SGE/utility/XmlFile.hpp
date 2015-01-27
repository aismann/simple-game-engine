#ifndef XMLFILE_HPP
#define XMLFILE_HPP

/*
 * SimpleGameEngine
 * XmlFile.hpp
 *
 * Utility file to help ease loading and reading data from XML files using the PUGI XML parser.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 10, 2015
 * Last updated: Jan 15, 2015
 * Since:        v0.1
 */

#include <vector>
#include "../pugixml/pugixml.hpp"
#include "Utility.h"
#include "XmlTag.hpp"

class XmlFile {

public:
	XmlFile(std::string fileName);

	std::vector<XmlTag> getTags();

	~XmlFile();

private:
	std::string fileName;
	pugi::xml_document xmlDocument;
	pugi::xml_parse_result xmlResult;
	std::vector<XmlTag> tags;
};

#endif
