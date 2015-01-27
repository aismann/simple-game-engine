#ifndef BACKGROUNDOBJECT_HPP
#define BACKGROUNDOBJECT_HPP

/*
 * SimpleGameEngine
 * BackgroundObject.hpp
 *
 * Defines methods and variables for an object that will be displayed in the background of an environment
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 18, 2015
 * Last updated: Jan 22, 2015
 * Since:        v0.1
 */

#include "../Object.hpp"
#include "../utility/XmlTag.hpp"

class BackgroundObject: public Object
{
public:
	BackgroundObject();

	XmlTag getAsXmlTag();

	~BackgroundObject();
private:

};

#endif
