
#include "SpellBook.hpp"

SpellBook::~SpellBook()
{
	std::vector<ASpell *>::iterator t;

	t = this->b.begin();
	while (t != this->b.end())
	{
		delete *t;
		this->b.erase(t);
		++t;
	}
}

SpellBook::SpellBook() {}

void SpellBook::learnSpell(ASpell *object)
{
	std::vector<ASpell *>::iterator t;

	t = this->b.begin();
	while (t != this->b.end())
	{
		if ((*t)->getName() == object->getName())
			return ;
		++t;
	}
	this->b.push_back(object->clone());
	return ;
}

void SpellBook::forgetSpell(std::string const &spell)
{
	std::vector<ASpell *>::iterator t;

	t = this->b.begin();
	while (t != this->b.end())
	{
		if ((*t)->getName() == spell)
		{
			delete *t;
			this->b.erase(t);
			return ;
		}
		++t;
	}
	return ;
}

ASpell *SpellBook::createSpell(std::string const &name)
{
	std::vector<ASpell *>::iterator t;

	t = this->b.begin();
	while (t != this->b.end())
	{
		if ((*t)->getName() == name)
			return (*t)->clone();
		++t;
	}
	return (NULL);
}