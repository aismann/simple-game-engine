/*
 * SimpleGameEngine
 * Scene.cpp
 *
 * Object to help construct the scene for a game. Will include gravity, check for physics/collisions, and draw all objects.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 24, 2015
 * Last updated: Jan 24, 2015
 * Since:        v0.1
 */

#include "../../include/SGE/Scene.hpp"

Scene::Scene() {
	gravity = sf::Vector2f(0.0f, -9.8f);
}
Scene::Scene(float gravityX, float gravityY) {
	gravity = sf::Vector2f(gravityX, gravityY);
}
Scene::Scene(sf::Vector2f gravity) {
	this->gravity = gravity;
}

sf::Vector2f Scene::getGravity() {
	return gravity;
}
void Scene::setGravity(float gravityX, float gravityY) {
	gravity = sf::Vector2f(gravityX, gravityY);
}
void Scene::setGravity(sf::Vector2f gravity) {
	this->gravity = gravity;
}

void Scene::clearObjects() {
	//should we delete?
	/*for (Object* o : objects) {
		delete o;
	}*/
	objects.clear();
}
void Scene::addObjects(std::vector<Object*> objects) {
	for (Object* object : objects) {
		this->objects.push_back(object);
	}
}

void Scene::addObject(Object* object) {
	objects.push_back(object);
}

void Scene::clearBackgroundObjects() {
	//should we delete?
	/*for (BackgroundObject* bo : backgroundObjects) {
		delete bo;
	}*/
	backgroundObjects.clear();
}
void Scene::addBackgroundObjects(std::vector<BackgroundObject*> backgroundObjects) {
	for (BackgroundObject* backgroundObject : backgroundObjects) {
		this->backgroundObjects.push_back(backgroundObject);
	}
}

void Scene::addBackgroundObject(BackgroundObject* backgroundObject) {
	backgroundObjects.push_back(backgroundObject);
}

void Scene::update() {
	//Add code to calculate physics

	//possible methods to do so..:
	//check all objects that are near each other
		//expanded..:
		//double-for loop for all objects and create pairs of 2 objects that positions+width/height are equal or intersecting
		//check if any object is in pairs multiple times, will make calculations a little more tricky, calculate rest with method below:
	//calculate if any intersect
	//get their velocity, acceleration, position, etc..
	//calculate both new vel, acc, pos using physics equations+gravity and friction/mass
	//set those objects new positions, and vel acc pos?
}
void Scene::draw(sf::RenderWindow& window) {
	//Check if object is within the camera
	//Create a sprite batch of like objects or all objects?
	//Create a sprite batch for background and always render it since it is static?

	//This is only for testing....
	for (BackgroundObject* backgroundObject : backgroundObjects) {
		backgroundObject->draw(window);
	}
	for (Object* object : objects) {
		object->draw(window);
	}
}

Scene::~Scene() {
	//Do we need to delete objects and backgroundObjects here?
}
