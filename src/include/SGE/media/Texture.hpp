#ifndef TEXTURE_HPP
#define TEXTURE_HPP

/*
 * SimpleGameEngine
 * Texture.hpp
 *
 * Class to hold data for SFML textures/sprites and methods for easier access with rest of program.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 11, 2015
 * Last updated: Jan 23, 2015
 * Since:        v0.1
 */

#include <SFML\Graphics.hpp>
//#include "../utility/Logger.hpp"
#include "../utility/XmlTag.hpp"

class Texture
{
public:
	Texture(std::string fileName);

	int getWidth();
	int getHeight();
	sf::IntRect getSize();

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setPositionOffset(sf::Vector2f offset);
	void setPositionOffset(float x, float y);

	sf::Vector2f getOffset();

	void draw(sf::RenderWindow& window);

	XmlTag getAsXmlTag();

	~Texture();

private:
	std::string fileName;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f positionOffset;
//	sge::Logger log;
};

namespace sge
{
Texture* getXmlTagAsTexture(XmlTag xmlTag);
}

#endif
