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

#include "../../../include/SGE/primitive/Rectangle.hpp"

Rectangle::Rectangle() {
	position = sf::Vector2f(0, 0);
	size = sf::Vector2f(0, 0);

	rectangle.setSize(size);
	rectangle.setOutlineColor(DEBUG_OUTLINE);
	rectangle.setFillColor(DEBUG_FILL);
	rectangle.setOutlineThickness(OUTLINE_THICKNESS);
}
Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size) {
	this->position = position;
	this->size = size;

	rectangle.setSize(size);
	rectangle.setOutlineColor(DEBUG_OUTLINE);
	rectangle.setFillColor(DEBUG_FILL);
	rectangle.setOutlineThickness(OUTLINE_THICKNESS);
}
Rectangle::Rectangle(float x, float y, float width, float height) {
	position = sf::Vector2f(x, y);
	size = sf::Vector2f(width, height);

	rectangle.setSize(size);
	rectangle.setOutlineColor(DEBUG_OUTLINE);
	rectangle.setFillColor(DEBUG_FILL);
	rectangle.setOutlineThickness(OUTLINE_THICKNESS);
}

void Rectangle::setWidth(float width) {
	size.x = width;
	rectangle.setSize(size);
}
void Rectangle::setHeight(float height) {
	size.y = height;
	rectangle.setSize(size);
}
void Rectangle::setSize(sf::Vector2f size) {
	this->size = size;
	rectangle.setSize(size);
}

float Rectangle::getArea() const {
	return size.x * size.y;
}
/*std::vector<sf::Vector2f> Rectangle::getArea() const {
	std::vector<sf::Vector2f> area;
	area.push_back(position);
	area.push_back(sf::Vector2f(position.x + size.x, position.y));
	area.push_back(sf::Vector2f(position.x, position.y + size.y));
	area.push_back(sf::Vector2f(position.x + size.x, position.y + size.y));

	return area;
}*/

bool Rectangle::intersects(Shape& shape) const {
	return false;
}

void Rectangle::draw(sf::RenderWindow& window) {
	rectangle.setPosition(position);
	window.draw(rectangle);
}

Rectangle::~Rectangle() {
}
