/*
 * SimpleGameEngine
 * BackgroundObject.cpp
 *
 * Defines methods and variables for an object that will be displayed in the background of an environment
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 18, 2015
 * Last updated: Jan 24, 2015
 * Since:        v0.1
 */

#include "../../../include/SGE/object/BackgroundObject.hpp"

BackgroundObject::BackgroundObject() {
	friction = 0.0f;
	mass = 0.0f;
}

XmlTag BackgroundObject::getAsXmlTag() {
	XmlTag xmlTag = Object::getAsXmlTag(); // Will create a tag with position attributes and textures child-tags named Object.
	xmlTag.setName(sge::XML_OBJ_BACKGROUND);

	return xmlTag;
}

BackgroundObject::~BackgroundObject() {
}
