/*
 * SimpleGameEngine
 * Object.cpp
 *
 * Master file to contain overall variables and method for objects defined through XML data and to then be inherited.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 10, 2015
 * Last updated: Jan 26, 2015
 * Since:        v0.1
 */

#include "../../include/SGE/Object.hpp"

#include <iostream>

Object::Object() {
	position = sf::Vector2f(-1, -1);
	mass = 1.0f;
	friction = 1.0f;
	isDebugMode = false;
	physicalBody = nullptr;
}
Object::Object(std::vector<Texture*> textures) {
	setTextures(textures);
	position = sf::Vector2f(-1, -1);
	mass = 1.0f;
	friction = 1.0f;
	isDebugMode = false;
}
Object::Object(XmlTag xmlTag) {
	int x = sge::stringToInt(xmlTag.getAttribute(sge::XML_POS_X));
	int y = sge::stringToInt(xmlTag.getAttribute(sge::XML_POS_Y));
	position = sf::Vector2f(x, y);

	mass = sge::stringToFloat(xmlTag.getAttribute(sge::XML_MASS));
	friction = sge::stringToFloat(xmlTag.getAttribute(sge::XML_FRICTION));

	isDebugMode = false;

	std::vector<Texture*> texturesFromTags;
	for (XmlTag childTag : xmlTag.getChildren()) {
		if (childTag.isTexture()) {
			Texture* texture = sge::getXmlTagAsTexture(childTag);
			texture->setPosition(position);
			texture->setPositionOffset(
					sge::stringToFloat(childTag.getAttribute(sge::XML_OFFSET_X)),
					sge::stringToFloat(childTag.getAttribute(sge::XML_OFFSET_Y)));
			texturesFromTags.push_back(texture);
		}
	}
	setTextures(texturesFromTags);
}

sf::Vector2f Object::getPosition() {
	return position;
}
void Object::setPosition(sf::Vector2f position) {
	this->position = position;
	physicalBody->setPosition(position);
}
void Object::setPosition(float x, float y) {
	setPosition(sf::Vector2f(x, y));
}

float Object::getMass() {
	return mass;
}
void Object::setMass(float mass) {
	this->mass = mass;
}

float Object::getFriction() {
	return friction;
}
void Object::setFriction(float friction) {
	this->friction = friction;
}

void Object::setTextures(std::vector<Texture*> textures) {
	this->textures = textures;
	//Physical body currently only support rectangles, change to allow different shapes.
	int physicalWidth = 0;
	int physicalHeight = 0;
	for (Texture* t : textures) {
		if (t->getWidth() + t->getOffset().x > physicalWidth)
			physicalWidth = t->getWidth() + t->getOffset().x;
		if (t->getHeight() + t->getOffset().y > physicalHeight)
			physicalHeight = t->getHeight() + t->getOffset().y;
	}
	Shape* tempBody = new Rectangle(sf::Vector2f(position.x, position.y), sf::Vector2f(physicalWidth, physicalHeight));
	delete physicalBody;
	physicalBody = tempBody;
	tempBody = nullptr;
}

void Object::debugMode(bool isDebugModeOn) {
	isDebugMode = isDebugModeOn;
}

void Object::draw(sf::RenderWindow& window) {
	for (Texture* texture : textures) {
		texture->setPosition(position);
		texture->draw(window);
	}

	if (isDebugMode) {
		physicalBody->draw(window);
	}
}

/**
 * Re-implement in child classes to specify tag name and specific attributes and child tags that are required.
 */
XmlTag Object::getAsXmlTag() {
	XmlTag xmlTag(sge::XML_OBJECT);

	xmlTag.addAttribute(sge::XML_POS_X, position.x);
	xmlTag.addAttribute(sge::XML_POS_Y, position.y);

	for (Texture* texture : textures) {
		xmlTag.addChild(texture->getAsXmlTag());
	}

	return xmlTag;
}

Object::~Object() {
	for (Texture* t : textures) {
		delete t;
	}
	delete physicalBody;
}


//TODO: Re-implement to return the specific class-type in XML tag.
Object* sge::getXmlTagAsObject(XmlTag xmlTag) {
	Object* object = new Object(xmlTag);
	return object;
}
