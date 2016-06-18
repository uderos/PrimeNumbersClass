#include "stdafx.h"
#include "PrimeUtils.h"


PrimeUtils::PrimeUtils()
{
}


PrimeUtils::~PrimeUtils()
{
}

NumList PrimeUtils::Factorize(const NumType product_in) const
{
	NumList factors;
	NumType product = product_in;

	for (NumType n = 2; n <= product; true)
	{
		COUT << "Trying with " << n << std::endl;
		if (product % n == 0)
		{
			factors.insert(n);
			product /= n;
			COUT << n << " is a factor. product <== " << product << std::endl;
		}
		else
		{
			n = m_calc_next_prime(n);
		}
	}

	return factors;
}

bool PrimeUtils::m_has_factors(const NumType target,
							const NumList & factors) const
{
	for (const auto f : factors)
	{
		if (target % f == 0)
		{
			COUT << "\t" << f << " is a factor of " << target << std::endl;
			return true;
		}
	}

	COUT << "\t" << target << " has no known factors" << std::endl;
	return false;
}

bool PrimeUtils::m_is_prime(const NumType number) const
{
	if (number == 2)
		return true;

	for (NumType n = 3; n * n <= number; n += 2)
	{
		if (number % n == 0)
		{
			return false;
		}
	}

	return true;
}

NumType PrimeUtils::m_calc_next_prime(const NumType last_prime) const
{
	NumType start = last_prime + (last_prime % 2 == 0 ? 1 : 2);
	for (NumType n = start; true; n += 2)
	{
		if (m_is_prime(n))
		{
			COUT << "The next prime after " << last_prime << " is " << n << std::endl;
			return n;
		}
	}
}

std::size_t PrimeUtils::FindNumPairs(const NumType from_number,
									 const NumType to_number) const
{
	std::size_t num_pairs = 0;

	NumType first = (m_is_prime(from_number) ? from_number : m_calc_next_prime(from_number));
	NumType second = m_calc_next_prime(first);

	while (second <= to_number)
	{
		if (first + 2 == second)
		{
			++num_pairs;

			COUT << "Pair found N=" << num_pairs
				 << " first=" << first 
				 << " second=" << second 
				 << std::endl;
		}

		first = second;
		second = m_calc_next_prime(first);
	}

	return num_pairs;
}


