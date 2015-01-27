#ifndef DYNAMICOBJECT_HPP
#define DYNAMICOBJECT_HPP

/*
 * SimpleGameEngine
 * DynamicObject.hpp
 *
 * Defines methods and variables for an object that will act dynamically with other objects.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 18, 2015
 * Last updated: Jan 22, 2015
 * Since:        v0.1
 */

#include "../Object.hpp"
#include "../utility/XmlTag.hpp"

class DynamicObject: public Object
{
public:

	DynamicObject();

	XmlTag getAsXmlTag();

	~DynamicObject();

private:

};

#endif
