#ifndef XMLTAG_HPP
#define XMLTAG_HPP

/*
 * SimpleGameEngine
 * XmlTag.hpp
 *
 * Utility file to store data in an XML tag as an object for easy conversion between game classes and XmlTags.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 15, 2015
 * Last updated: Jan 22, 2015
 * Since:        v0.1
 */

#include "../pugixml/pugixml.hpp"
#include "Utility.h"
#include <map>
#include <algorithm>
#include <memory>

class XmlTag {
public:
	XmlTag();
	XmlTag(std::string name);    // Use to create your own tag
	XmlTag(pugi::xml_node node); // Use to have tag generated from a pugi xml_node

	void setXmlFile(std::string fileName);
	std::string getXmlFile();

	std::string getName();
	void setName(std::string name);
	std::string getAttribute(std::string key);
//	std::shared_ptr<XmlTag> getParent();
//	void setParent(XmlTag* parent);
	std::vector<XmlTag> getChildren();
	
	void addAttribute(std::string name, std::string value);
	void addAttribute(std::string name, int value);
	void addAttribute(std::string name, float value);

	void addChild(XmlTag child);

	pugi::xml_node getAsNode();
	
	bool isObject();
	bool isTexture();

	~XmlTag();

private:
	int id;
	pugi::xml_node node;
	std::string xmlFileName;
	std::vector<XmlTag> children;
//	std::shared_ptr<XmlTag> parent;
	std::map<std::string, std::string> attributes;
};

#endif
