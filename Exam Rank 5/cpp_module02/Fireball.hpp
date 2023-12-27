
#include <iostream>
#include <string>

#include "Fwoosh.hpp"

class Fireball: public ASpell
{
	public:
		Fireball();
		~Fireball();

		ASpell *clone(void) const;
};
