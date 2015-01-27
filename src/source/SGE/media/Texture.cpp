/*
 * SimpleGameEngine
 * Texture.cpp
 *
 * Class to hold data for SFML textures/sprites and methods for easier access with rest of program.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 11, 2015
 * Last updated: Jan 23, 2015
 * Since:        v0.1
 */

#include "../../../include/SGE/media/Texture.hpp"

#include <iostream>

Texture::Texture(std::string fileName) {
	this->fileName = fileName;

	if (!texture.loadFromFile(fileName)) {
		std::cout << "Texture could not load image " << fileName << std::endl;
//		log.addErrorMessage("Could not find texture file " + fileName);
	}
	positionOffset = sf::Vector2f(0, 0);
	sprite.setTexture(texture);
	sprite.setPosition(-1.0f, -1.0f);
}

int Texture::getWidth() {
	return sprite.getTextureRect().width;
}

int Texture::getHeight() {
	return sprite.getTextureRect().height;
}

sf::IntRect Texture::getSize() {
	return sprite.getTextureRect();
}

void Texture::setPosition(sf::Vector2f position) {
	sprite.setPosition(sf::Vector2f(position.x + positionOffset.x, position.y + positionOffset.y));
}

void Texture::setPosition(float x, float y) {
	setPosition(sf::Vector2f(x, y));
}

void Texture::setPositionOffset(sf::Vector2f positionOffset) {
	this->positionOffset = positionOffset;
}

void Texture::setPositionOffset(float x, float y) {
	positionOffset = sf::Vector2f(x, y);
}

sf::Vector2f Texture::getOffset() {
	return positionOffset;
}

void Texture::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

XmlTag Texture::getAsXmlTag() {
	XmlTag xmlTag(sge::XML_TEXTURE);
	xmlTag.addAttribute(sge::XML_FILE, fileName);
	if (positionOffset.x != 0 || positionOffset.y != 0) {
		xmlTag.addAttribute(sge::XML_OFFSET_X, positionOffset.x);
		xmlTag.addAttribute(sge::XML_OFFSET_Y, positionOffset.y);
	}
	return xmlTag;
}

Texture::~Texture() {
}

Texture* sge::getXmlTagAsTexture(XmlTag xmlTag) {
//	if (xmlTag.isTexture()) {
		Texture* texture = new Texture(xmlTag.getAttribute(sge::XML_FILE));
		return texture;
//	} else {
		//what to return if not a texture?
//	}
}
