#pragma once

#include "DataTypes.h"

class Utils
{
	public:
		Utils();
		virtual ~Utils();

		std::string to_string(const NumList & nl) const;
		std::string to_string(const NumTriplet & triplet) const;

		template <typename CONTAINER_T>
		std::string container_to_string(const CONTAINER_T & container) const;
};

template <typename CONTAINER_T>
std::string Utils::container_to_string(const CONTAINER_T & container) const
{
	std::ostringstream oss;
	for (const auto & elem : container)
		oss << elem << " ";
	return oss.str();
}
