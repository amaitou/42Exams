#include "ASpell.hpp"

ASpell::ASpell(std::string const &name, std::string const &effect)
{
	this->name = name;
	this->effect = effect;
}

std::string const &ASpell::getName(void) const
{
	return (this->name);
}

std::string const &ASpell::getEffect(void) const
{
	return (this->effect);
}

ASpell::ASpell(ASpell const &copy)
{
	this->effect = copy.effect;
	this->name = copy.name;
}

ASpell & ASpell::operator = (ASpell const &object)
{
	this->effect = object.effect;
	this->name = object.name;
	return (*this);
}

void ASpell::launch(ATarget const &object)
{
	object.getHitBySpell(*this);
}

ASpell::~ASpell() {}