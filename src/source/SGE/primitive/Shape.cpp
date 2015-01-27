/*
 * SimpleGameEngine
 * Shape.hpp
 *
 * Defines a shape object to be used for collision detecting, physics, etc. Inherited classes will contain SFML drawable shapes to allow for debugging.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 23, 2015
 * Last updated: Jan 25, 2015
 * Since:        v0.1
 */

#include "../../../include/SGE/primitive/Shape.hpp"

//TODO: Create separate Rectangle, Circle, and Convex classes to inherit this one ?

Shape::Shape() {
	position = sf::Vector2f(0, 0);
}

sf::Vector2f Shape::getPosition() const {
	return position;
}

void Shape::setPosition(sf::Vector2f position) {
	this->position = position;
}
void Shape::setPosition(float x, float y) {
	setPosition(sf::Vector2f(x, y));
}

float Shape::getArea() const {
	return 0.0f;
}
/*virtual std::vector<sf::Vector2f> Shape::getArea() const {
	std::vector<sf::Vector2f> area;
	area.push_back(position);
	return area;
}*/

bool Shape::intersects(Shape& shape) const {
	return false; // defined in inherited classes
}

void Shape::draw(sf::RenderWindow& window) {
}

Shape::~Shape() {
}
