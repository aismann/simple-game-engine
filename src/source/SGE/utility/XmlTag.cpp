/*
 * SimpleGameEngine
 * XmlTag.cpp
 *
 * Class for easy access to data in XML tags acting as a wrapper around the pugi::xml_node class.
 * This allows for easy conversion between classes in this project and XML data.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 15, 2015
 * Last updated: Jan 22, 2015
 * Since:        v0.1
 */

#include <string>
#include <iostream>
#include "../../../include/SGE/utility/XmlTag.hpp"

//TODO: find a way to implement a parent class if this is needed. Commenting out for now.
XmlTag::XmlTag() {
	id = 0;
	node.set_name("ERROR_NO_NAME_PROVIDED");
}

XmlTag::XmlTag(std::string name) {
	id = 0;
	node.set_name(name.c_str());
}
XmlTag::XmlTag(pugi::xml_node node) {
	this->node = node;
	id = sge::stringToInt(node.attribute(sge::XML_ID.c_str()).value()); //defaults to 0 if there is no 'id' attribute

//	if (node.parent() != node) { //TODO: fix this!
//		parent = new XmlTag(node.parent());
//	}
	for (pugi::xml_node childNode : node.children()) {
		XmlTag childTag(childNode);
//		childTag.setParent(this);
		children.push_back(childTag);
	}
	for (pugi::xml_attribute attribute : node.attributes()) {
		attributes.insert(std::make_pair(attribute.name(), attribute.value()));
	}
}

void XmlTag::setXmlFile(std::string fileName) {
	this->xmlFileName = fileName;
}
std::string XmlTag::getXmlFile() {
	return xmlFileName;
}

std::string XmlTag::getName() {
	return node.name();
}
void XmlTag::setName(std::string name) {
	node.set_name(name.c_str());
}

std::string XmlTag::getAttribute(std::string key) {
	if (attributes.find(key) == attributes.end()) {
		return "";
	}
	else {
		return attributes[key];
	}
}

/*std::shared_ptr<XmlTag> XmlTag::getParent() {
	return parent;
}
void XmlTag::setParent(XmlTag* parent) {
	this->parent = parent;
}*/

std::vector<XmlTag> XmlTag::getChildren() {
	return children;
}

void XmlTag::addAttribute(std::string name, std::string value) {
	std::string nodeValue = node.attribute(name.c_str()).value();
	if (nodeValue == "") {
		node.append_attribute(name.c_str());
	}
	node.attribute(name.c_str()).set_value(value.c_str());
	attributes[name] = value;
}
void XmlTag::addAttribute(std::string name, int value) {
	addAttribute(name, std::to_string(value));
}
void XmlTag::addAttribute(std::string name, float value) {
	addAttribute(name, std::to_string(value));
}

void XmlTag::addChild(XmlTag child) {
	//node.append_child(child->getAsNode());
	children.push_back(child);
}

pugi::xml_node XmlTag::getAsNode() {
	return node;
}

bool XmlTag::isObject() {
	std::vector<std::string> objectNames = { sge::XML_OBJECT, sge::XML_OBJ_BACKGROUND, sge::XML_OBJ_DYNAMIC, sge::XML_OBJ_STATIC };
	
	std::string nodeName = node.name();
	std::vector<std::string>::iterator iter = std::find(objectNames.begin(), objectNames.end(), nodeName);

	return iter != objectNames.end();
}

bool XmlTag::isTexture() {
	return node.name() == sge::XML_TEXTURE;
}

XmlTag::~XmlTag() {
//	delete parent;//shouldn't need since parent should have its own XmlTag?
//	for (XmlTag* tag : children) {
//		delete tag;
//	}
}
