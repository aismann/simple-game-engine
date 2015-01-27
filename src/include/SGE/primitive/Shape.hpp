#ifndef SHAPE_HPP
#define SHAPE_HPP

/*
 * SimpleGameEngine
 * Shape.hpp
 *
 * Wrapper class around SFML's sf::CircularShape, sf::RectangularShape, or sf::ConvexShape that allows for abstraction.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 23, 2015
 * Last updated: Jan 25, 2015
 * Since:        v0.1
 */

#include <SFML/Graphics.hpp>
#include <vector>

//namespace sge {

class Shape {

public:
	Shape();

	sf::Vector2f getPosition() const;

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

//	virtual std::vector<sf::Vector2f> getCoordinates() const;

//	void setRotation(float angle);

	virtual float getArea() const;
//	virtual std::vector<sf::Vector2f> getArea() const;

	virtual bool intersects(Shape& shape) const;

	virtual void draw(sf::RenderWindow& window);

	virtual ~Shape();

protected:
	sf::Vector2f position;

	//Mathematical constants:
	const float PI = 3.14f; //add more...

	//Debug constants:
	const float OUTLINE_THICKNESS = 1.0f;
	const sf::Color DEBUG_OUTLINE = sf::Color(0, 255, 0, 0);
	const sf::Color DEBUG_FILL = sf::Color(0, 0, 0, 255);
};

//}

#endif
