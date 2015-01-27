#ifndef OBJECT_HPP
#define OBJECT_HPP

/*
 * SimpleGameEngine
 * Object.hpp
 *
 * Master file to contain overall variables and method for objects defined through XML data and to then be inherited.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 10, 2015
 * Last updated: Jan 26, 2015
 * Since:        v0.1
 */

#include <SFML/Graphics.hpp>
#include "utility/XmlTag.hpp"
#include "media/Texture.hpp"
#include "primitive/Shape.hpp"
#include "primitive/Rectangle.hpp"

class Object {

public:
	Object();
	Object(std::vector<Texture*> textures);
	Object(XmlTag xmlTag);

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	float getMass();
	void setMass(float mass);

	float getFriction();
	void setFriction(float friction);

	void setTextures(std::vector<Texture*> textures);

	/*
	 * Turns on outline shapes of the physical body
	 * Will not be using sprite batches, so may reduce framerate.
	 */
	void debugMode(bool isDebugModeOn);

	//virtual void update();
	void draw(sf::RenderWindow& window);

	virtual XmlTag getAsXmlTag();

	virtual ~Object();

protected:
	sf::Vector2f position;
	float mass;
	float friction;
	std::vector<Texture*> textures;
	Shape* physicalBody;
	bool isDebugMode;
};

namespace sge
{
Object* getXmlTagAsObject(XmlTag xmlTag);
}

#endif
