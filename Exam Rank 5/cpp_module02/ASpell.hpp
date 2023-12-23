#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effect;

	public:
		virtual ~ASpell();
		ASpell(ASpell const &copy);
		ASpell & operator = (ASpell const &object);
		ASpell(std::string const &name, std::string const &effect);
		std::string	const &getName(void) const;
		std::string const &getEffect(void) const;
		void launch(ATarget const &object);

		virtual ASpell *clone(void) const = 0;
};

#endif