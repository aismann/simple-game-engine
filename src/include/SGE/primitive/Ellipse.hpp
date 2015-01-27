#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

/*
 * SimpleGameEngine
 * Ellipse.hpp
 *
 * Primitive type for an Ellipse that inherits Shape
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 24, 2015
 * Last updated: Jan 25, 2015
 * Since:        v0.1
 */

#include "Shape.hpp"

class Ellipse : public Shape {
public:
	Ellipse();
	Ellipse(float x, float y, float radiusWidth, float radiusHeight);
	Ellipse(sf::Vector2f position, sf::Vector2f radii);

	void setRadiusWidth(float radiusWidth);
	void setRadiusHeight(float radiusHeight);
	void setRadii(sf::Vector2f radii);

	float getArea() const;
//	std::vector<sf::Vector2f> getArea();

	bool intersects(Shape& shape) const;

	void draw(sf::RenderWindow& window);


	~Ellipse();
private:
	sf::Vector2f radii;
	sf::ConvexShape ellipse;

	void setupEllipse();
};

#endif
