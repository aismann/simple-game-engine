#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

/*
 * SimpleGameEngine
 * Rectangle.hpp
 *
 * Primitive type for an Rectangle that inherits Shape
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 24, 2015
 * Last updated: Jan 25, 2015
 * Since:        v0.1
 */

#include "Shape.hpp"

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(sf::Vector2f position, sf::Vector2f size);
	Rectangle(float x, float y, float width, float height);

	void setWidth(float width);
	void setHeight(float height);
	void setSize(sf::Vector2f size);

	float getArea() const;
//	std::vector<sf::Vector2f> getArea();

	bool intersects(Shape& shape) const;

	void draw(sf::RenderWindow& window);

	~Rectangle();

private:
	sf::Vector2f size;
	sf::RectangleShape rectangle;
};


#endif
