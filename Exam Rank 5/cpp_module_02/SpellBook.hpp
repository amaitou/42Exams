#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
	private:
		SpellBook();
		SpellBook(SpellBook const &copy);
		SpellBook & operator = (SpellBook const &object);
		std::vector<ASpell *> b;
	
	public:
		~SpellBook();

		void learnSpell(ASpell *object);
		void forgetSpell(std::string const &spell);
		ASpell *createSpell(std::string const &name);
}

#endif