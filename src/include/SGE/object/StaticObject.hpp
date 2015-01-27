#ifndef STATICOBJECT_HPP
#define STATICOBJECT_HPP

/*
 * SimpleGameEngine
 * StaticObject.hpp
 *
 * Defines methods and variables for an object that will act statically with other objects.
 *
 * Author:       Ryan Zembrodt
 * Created on:   Jan 18, 2015
 * Last updated: Jan 22, 2015
 * Since:        v0.1
 */

#include "../Object.hpp"
#include "../utility/XmlTag.hpp"

class StaticObject : public Object
{
public:
	StaticObject();

	XmlTag getAsXmlTag();

	~StaticObject();

private:

};

#endif
