#ifndef SCENE_HPP
#define SCENE_HPP

/*
 * SimpleGameEngine
 * Scene.hpp
 *
 * Object to help construct the scene for a game. Will include gravity, check for physics/collisions, and draw all objects.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 24, 2015
 * Last updated: Jan 24, 2015
 * Since:        v0.1
 */

#include <SFML/Graphics.hpp>
#include <vector>
#include "Object.hpp"
#include "object/BackgroundObject.hpp"

class Scene {
public:
	Scene(); //defaults gravity to -9.8 m/s^2
	Scene(float gravityX, float gravityY);
	Scene(sf::Vector2f gravity);

	sf::Vector2f getGravity();
	void setGravity(float gravityX, float gravityY);
	void setGravity(sf::Vector2f gravity);

	void clearObjects();
	void addObjects(std::vector<Object*> objects);
	void addObject(Object* object);

	void clearBackgroundObjects();
	void addBackgroundObjects(std::vector<BackgroundObject*> backgroundObjects);
	void addBackgroundObject(BackgroundObject* backgroundObject);

	void update();
	void draw(sf::RenderWindow& window);

	~Scene();

private:
	std::vector<Object*> objects; // for physics
	std::vector<BackgroundObject*> backgroundObjects;
	sf::Vector2f gravity;
};

#endif
