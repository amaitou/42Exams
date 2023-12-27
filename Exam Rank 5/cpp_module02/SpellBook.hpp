
#ifndef SpellBook_HPP
#define SpellBook_HPP

#include <vector>
#include "ASpell.hpp"

class SpellBook
{
	private:
		SpellBook(SpellBook const &copy);
		SpellBook & operator = (SpellBook const &object);

		std::vector<ASpell *> v;
	
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *object);
		void forgetSpell(std::string const &name);
		ASpell *createSpell(std::string const &name);
};

#endif
