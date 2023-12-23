#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;

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
};

#endif