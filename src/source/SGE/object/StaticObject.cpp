/*
 * SimpleGameEngine
 * StaticObject.cpp
 *
 * Defines methods and variables for an object that will act statically with other objects.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 18, 2015
 * Last updated: Jan 24, 2015
 * Since:        v0.1
 */

#include "../../../include/SGE/object/StaticObject.hpp"

StaticObject::StaticObject() {
	mass = 100000.0f; // to make this object immovable.
}

XmlTag StaticObject::getAsXmlTag() {
	XmlTag xmlTag = Object::getAsXmlTag(); // Will create a tag with position attributes and textures child-tags named Object.
	xmlTag.setName(sge::XML_OBJ_STATIC);

	return xmlTag;
}

StaticObject::~StaticObject() {
}
