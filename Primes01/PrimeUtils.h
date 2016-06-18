#pragma once

#include "DataTypes.h"
class PrimeUtils
{
	public:
		PrimeUtils();
		virtual ~PrimeUtils();

		NumList Factorize(const NumType product) const;

		std::size_t FindNumPairs(const NumType from_number,
								 const NumType to_number) const;

	private:

		bool m_has_factors(const NumType target, const NumList & factors) const;

		bool m_is_prime(const NumType number) const;
		NumType m_calc_next_prime(const NumType last_prime) const;

};

