#include "stdafx.h"
#include "Utils.h"


Utils::Utils()
{
}


Utils::~Utils()
{
}

std::string Utils::to_string(const NumList & nl) const
{
	std::ostringstream oss;
	for (const auto & n : nl)
	{
		if (oss.str().size())
			oss << ", ";
		oss << n;
	}

	return oss.str();
}

std::string Utils::to_string(const NumTriplet & triplet) const
{
	std::ostringstream oss;
	oss << "(" << triplet.a << "," << triplet.b << "," << triplet.c << ")";
	return oss.str();
}
