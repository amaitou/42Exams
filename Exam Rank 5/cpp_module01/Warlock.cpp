
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
	std::vector<ASpell *>::iterator t = this->list.begin();
	while (t != this->list.end())
	{
		delete (*t);
		this->list.erase(t);
		++t;
	}
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
	std::vector<ASpell *>::iterator t = this->list.begin();
	while (t != this->list.end())
	{
		if ((*t)->getName() == (*object).getName())
			return ;
		++t;
	}
	this->list.push_back(object->clone());
}

void Warlock::forgetSpell(std::string name)
{
	std::vector<ASpell *>::iterator t = this->list.begin();
	while (t != this->list.end())
	{
		if ((*t)->getName() == name)
		{
			delete (*t);
			this->list.erase(t);
		}
		else
			++t;
	}
}

void Warlock::launchSpell(std::string name, ATarget const &object)
{
	std::vector<ASpell *>::iterator t = this->list.begin();
	while (t != this->list.end())
	{
		if ((*t)->getName() == name)
		{
			(*t)->launch(object);
			return;
		}
		++t;
	}
}