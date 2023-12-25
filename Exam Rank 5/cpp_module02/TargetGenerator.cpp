#include "TargetGenerator.hpp"

TargetGenerator::~TargetGenerator()
{
	for (size_t i = 0; i < v.size(); i++) {
		delete v[i];
		v.erase(v.begin() + i);
	}
}

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
	return ;
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	std::vector<ATarget *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getType() == type)
		{
			delete *t;
			this->v.erase(t);
			return ;
		}
		++t;
	}
	return ;
}

ATarget *TargetGenerator::createTarget(std::string const &type)
{
	std::vector<ATarget *>::iterator t;

	t = this->v.begin();
	while (t != this->v.end())
	{
		if ((*t)->getType() == type)
			return ((*t)->clone());
		++t;
	}
	return (NULL) ;
}