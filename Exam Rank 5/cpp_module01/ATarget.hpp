#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

	public:
		virtual ~ATarget();
		ATarget(ATarget const &copy);
		ATarget & operator = (ATarget const &object);
		ATarget(std::string const &type);
		std::string const &getType(void) const;
		void getHitBySpell(ASpell const &object) const;

		virtual ATarget *clone(void) const = 0;
};

#endif