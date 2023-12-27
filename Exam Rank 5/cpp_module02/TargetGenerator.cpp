
#include "TargetGenerator.hpp"

TargetGenerator::~TargetGenerator() {}

TargetGenerator::TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *object)
{
	std::vector<ATarget *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getType() == object->getType())
			return ;
		++t;
	}
	this->v.push_back(object->clone());
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
	std::vector<ATarget *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getType() == name)
		{
			delete *t;
			this->v.erase(t);
			return ;
		}
		++t;
	}
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
	std::vector<ATarget *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getType() == name)
			return ((*t)->clone());
		++t;
	}
	return (NULL);

}
