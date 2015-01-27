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

#include "../../../include/SGE/primitive/Ellipse.hpp"

Ellipse::Ellipse() {
	position = sf::Vector2f(0, 0);
	radii = sf::Vector2f(0, 0);

	setupEllipse();
}
Ellipse::Ellipse(float x, float y, float radiusWidth, float radiusHeight) {
	position = sf::Vector2f(x, y);
	radii = sf::Vector2f(radiusWidth, radiusHeight);

	setupEllipse();
}
Ellipse::Ellipse(sf::Vector2f position, sf::Vector2f radii) {
	this->position = position;
	this->radii = radii;

	setupEllipse();
}

void Ellipse::setRadiusWidth(float radiusWidth) {
	radii.x = radiusWidth;
}
void Ellipse::setRadiusHeight(float radiusHeight) {
	radii.y = radiusHeight;
}
void Ellipse::setRadii(sf::Vector2f radii) {
	this->radii = radii;
}

float Ellipse::getArea() const {
	return PI * radii.x * radii.y;
}
/*

std::vector<sf::Vector2f> Ellipse::getArea() {


	setupEllipse();
}
*/

bool Ellipse::intersects(Shape& shape) const {
	return false;
}

void Ellipse::draw(sf::RenderWindow& window) {
	ellipse.setPosition(position);
	window.draw(ellipse);
}

Ellipse::~Ellipse() {
}

void Ellipse::setupEllipse() {
	sf::ConvexShape newEllipse;
	newEllipse.setOutlineColor(DEBUG_OUTLINE);
	newEllipse.setFillColor(DEBUG_FILL);
	newEllipse.setOutlineThickness(OUTLINE_THICKNESS);

//	std::vector<sf::Vector2f> area = getArea();
//	newEllipse.setPointCount(area.size());

//	for (int i = 0; i < area.size(); i++) {
//		newEllipse.setPoint(i, area[i]);
//	}
	ellipse = newEllipse;
}
