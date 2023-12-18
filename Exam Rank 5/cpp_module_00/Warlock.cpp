
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