
#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator & operator = (TargetGenerator const &object);

		std::vector<ATarget *> v;

	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *object);
		void forgetTargetType(std::string const &name);
		ATarget *createTarget(std::string const &name);
};

#endif
