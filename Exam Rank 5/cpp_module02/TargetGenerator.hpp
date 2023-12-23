#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
# include <vector>

class TargetGenerator
{
	public:
		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator & operator = (TargetGenerator const &object);
		std::vector<ATarget *> v;
	
	public:
		TargetGenerator();
		virtual ~TargetGenerator();

		void learnTargetType(ATarget *object);
		void forgetTargetType(std::string const &type);
		ATarget *createTarget(std::string const &type);

};

#endif