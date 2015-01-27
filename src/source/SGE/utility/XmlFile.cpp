/*
 * SimpleGameEngine
 * XmlFile.cpp
 *
 * Utility file to help ease loading and reading data from XML files using the PUGI XML parser.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 10, 2015
 * Last updated: Jan 15, 2015
 * Since:        v0.1
 */

#include "../../../include/SGE/utility/XmlFile.hpp"
#include <iostream>
#include <windows.h>

XmlFile::XmlFile(std::string fileName) {
	//test for directory
	/*char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	std::string path = std::string(buffer).substr(0, pos);
	std::cout << "my directory is: " << path << std::endl;*/

//	std::string test = "src/resources/test.xml";
	xmlResult = xmlDocument.load_file(fileName.c_str());

	if (!xmlResult) {
		std::cout << "XmlFile could not open " << fileName << std::endl; //Update to use sge::Logger.
	}

	this->fileName = fileName;

	for (pugi::xml_node node : xmlDocument.children()) {
		XmlTag tag(node);
		tag.setXmlFile(this->fileName);
		tags.push_back(tag);
	}
}

std::vector<XmlTag> XmlFile::getTags() {
	return tags;
}

XmlFile::~XmlFile() {

}
