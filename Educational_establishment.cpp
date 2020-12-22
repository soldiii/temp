#include "Educational_establishment.h"

Educational_establishment::Educational_establishment(String name)
{
	this->name = name;
}

String Educational_establishment::GetName() const
{
	return name;
}

void Educational_establishment::SetName(String name)
{
	this->name = name;
}


