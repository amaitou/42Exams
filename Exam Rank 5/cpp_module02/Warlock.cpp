
#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->getName() << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->getName() << ": My job here is done!\n";
}

const std::string &Warlock::getName() const
{
	return this->name;
}

const std::string &Warlock::getTitle() const
{
	return this->title;
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce(void) const
{
	std::cout 	<< this->getName() << ": I am "
				<< this->getName() << ", "
				<< this->getTitle() << "!\n";
}

void Warlock::learnSpell(ASpell *object)
{
	this->b.learnSpell(object);
}

void Warlock::forgetSpell(std::string name)
{
	this->b.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const &object)
{
	ASpell *_object;

	_object = this->b.createSpell(name);
	if (_object == NULL)
		return ;
	_object->launch(object);
	delete _object;
}