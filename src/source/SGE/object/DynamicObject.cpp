/*
 * SimpleGameEngine
 * DynamicObject.cpp
 *
 * Defines methods and variables for an object that will act dynamically with other objects.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 18, 2015
 * Last updated: Jan 22, 2015
 * Since:        v0.1
 */

#include "../../../include/SGE/object/DynamicObject.hpp"

DynamicObject::DynamicObject() {

}

XmlTag DynamicObject::getAsXmlTag() {
	XmlTag xmlTag = Object::getAsXmlTag(); // Will create a tag with position attributes and textures child-tags named Object.
	xmlTag.setName(sge::XML_OBJ_DYNAMIC);

	return xmlTag;
}

DynamicObject::~DynamicObject() {
}
