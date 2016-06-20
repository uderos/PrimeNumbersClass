#pragma once

#include "DataTypes.h"

class Utils
{
	public:
		Utils();
		virtual ~Utils();

		std::string to_string(const NumList & nl) const;
		std::string to_string(const NumTriplet & triplet) const;
};

