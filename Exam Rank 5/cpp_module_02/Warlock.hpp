#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::vector<ASpell*> list;

		Warlock();
		Warlock(const Warlock &copy);
		Warlock & operator = (const Warlock &object);
	
	public:
		~Warlock();
		Warlock(std::string const &name, std::string const &title);
		const std::string &getName() const;
		const std::string &getTitle() const;
		void	setTitle(std::string const &title);
		void	introduce(void) const;
		void learnSpell(ASpell *object);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const &object);
};

#endif