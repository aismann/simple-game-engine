//============================================================================
// Name        : Random Generation Game
// Author      : Ryan Zembrodt
// Version     : 0.1
// Created     : 1/10/2015
// Description : 2D Game with SFML to test random/procedural generation processes
//				 as well as the basics of AI.
//============================================================================

#include <SFML/Graphics.hpp>
#include "include/SGE/utility/Logger.hpp"
#include "include/SGE/utility/XmlFile.hpp"
#include "include/SGE/utility/XmlTag.hpp"
#include "include/SGE/Object.hpp"

#include "include/SGE/primitive/Shape.hpp"
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(sge::SCREEN_WIDTH, sge::SCREEN_HEIGHT), sge::TITLE);

	sge::Logger log();

	XmlFile xmlFile("src/resources/test.xml");
	std::vector<XmlTag> xmlTags = xmlFile.getTags();
	std::vector<Object*> objects;
	for (XmlTag xmlTag : xmlTags) {
		if (xmlTag.isObject()) {
			objects.push_back(sge::getXmlTagAsObject(xmlTag));
		}
	}
	int i = 1;
	Object* o;
	if (i == 1) {
		std::vector<Texture*> testTextures;
		Texture* testTexture = new Texture("src/resources/images/test.png");
	//	testTexture.setPosition(69,69);
		testTextures.push_back(testTexture);
		o = new Object(testTextures);
		o->setPosition(69,69);
		o->debugMode(true);
	}
//	std::cout << "main: " << o.getPosition().x << ", " << o.getPosition().y << std::endl;
//	Object* obj = new Object(testTextures);
//	obj->setPosition(500,200);
//	objects.push_back(obj);

	/*sf::Texture textureTest;
	textureTest.loadFromFile("src/resources/images/test.png");
	sf::Sprite spriteTest;
	spriteTest.setTexture(textureTest);
	spriteTest.setPosition(200,200);*/

	sf::CircleShape shape(50);
	shape.setFillColor(sf::Color(100, 250, 50));

	while (window.isOpen())
	{
		//UPDATE
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// DRAW
		window.clear();

		for (Object* object : objects) {
			object->draw(window);//fixme
		}

		o->draw(window);
//		window.draw(shape);
//		window.draw(spriteTest);

		window.display();
	}

	for (Object* obj : objects) {
		delete obj;
	}

	return 0;
}
