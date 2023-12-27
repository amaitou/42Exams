
#include "SpellBook.hpp"

SpellBook::SpellBook() {}

void SpellBook::learnSpell(ASpell *object)
{
	std::vector<ASpell *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getName() == object->getName())
			return ;
		++t;
	}
	this->v.push_back(object->clone());
}

void SpellBook::forgetSpell(std::string const &name)
{
	std::vector<ASpell *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getName() == name)
		{
			delete *t;
			this->v.erase(t);
			return;
		}
		++t;
	}
}

SpellBook::~SpellBook()
{
	std::vector<ASpell *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		delete *t;
		this->v.erase(t);
		++t;
	}
}

ASpell *SpellBook::createSpell(std::string const &name)
{
	std::vector<ASpell *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getName() == name)
			return (*t)->clone();
		++t;
	}
	return (NULL);
}
