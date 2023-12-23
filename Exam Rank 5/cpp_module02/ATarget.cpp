#include "ATarget.hpp"

ATarget::ATarget(ATarget const &copy)
{
	this->type = copy.type;
}

ATarget & ATarget::operator = (ATarget const &object)
{
	this->type = object.type;
	return (*this);
}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

std::string const &ATarget::getType(void) const
{
	return (this->type);
}

void ATarget::getHitBySpell(ASpell const &object) const
{
	std::cout 	<< this->getType()
				<< " has been "
				<< object.getEffect()
				<< "!\n";
}

ATarget::~ATarget() {}