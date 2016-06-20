#include "stdafx.h"
#include "PrimeUtils.h"
#include "Utils.h"


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

std::size_t PrimeUtils::FindPrimeTwins(const NumType from_number,
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

NumPairList PrimeUtils::FindGoldbachPairs(const NumType target) const
{
	NumPairList pairs;

	for (NumType first = 2; 
		 first < target; 
		 first = m_calc_next_prime(first))
	{
		for (NumType second = first;
			first + second <= target;
			second = m_calc_next_prime(second))
		{
			if (first + second == target)
			{
				pairs.emplace_back(first, second);

				COUT << "Goldback Pair: target=" << target
					<< " first=" << first
					<< " second=" << second
					<< std::endl;
			}
		}
	}

	return pairs;
}

NumPairList PrimeUtils::FindFermatSquarePairs(const NumType target) const
{
	NumPairList pairs;

	for (NumType first = 1; first * first < target; ++first)
	{
		for (NumType second = first; second * second < target; ++second)
		{
			const NumType current = (first * first) + (second * second);

			if (current < target)
			{
				;
			}
			else 
			{
				if (current == target)
				{
					pairs.emplace_back(first, second);

					COUT << "Fermat Pair: target=" << target
						<< " first=" << first
						<< " second=" << second
						<< std::endl;
				}

				break;
			}
		}
	}

	return pairs;
}


bool PrimeUtils::AreRelativePrimes(const NumType a, const NumType b) const
{
	const NumType target = std::min(a, b);
	for (NumType factor = 2;
		factor < target;
		factor = m_calc_next_prime(factor))
	{
		if ((a % factor == 0) && (b % factor == 0))
		{
			COUT << factor << " is a common factor of " 
				 << a << " and " << b << std::endl;
			return false;
		}
	}

	return true;
}

TripletList PrimeUtils::FindTriplet(const NumType target, TripletEvaluator evaluator) const
{
	Utils utils;
	TripletList triplet_list;

	NumTriplet triplet; // 0 0 0

	for (triplet.a = 0; triplet.a <= target; ++triplet.a)
	{
		triplet.b = triplet.c = NumType(0);
		if (evaluator(target, triplet) > target)
			break;

		for (triplet.b = 0; triplet.b <= target; ++triplet.b)
		{
			triplet.c = NumType(0);
			if (evaluator(target, triplet) > target)
				break;

			for (triplet.c = 0; triplet.c <= target; ++triplet.c)
			{
				const NumType current = evaluator(target, triplet);

				COUT << "Triplet check: target=" << target << " current=" << current
					<< " triplet=" << utils.to_string(triplet) << std::endl;

				if (current == target)
				{
					triplet_list.push_back(triplet);

					COUT << "Triplet FOUND: target=" << target 
						  << " triplet=" << utils.to_string(triplet) << std::endl;
				}
				else if (current > target)
				{
					break;
				}
			}
		}
	}

	return triplet_list;
}

template <typename T>
NumSet f_merge_num_lists(const T list_of_lists)
{
	NumSet result;
	for (const auto & list : list_of_lists)
	for (const auto & elem : list)
		result.insert(elem);

	return result;
}

NumType PrimeUtils::CalcConductor(const NumTriplet & triplet) const
{
	std::vector<NumList> factors_list;
	factors_list.push_back(Factorize(triplet.a));
	factors_list.push_back(Factorize(triplet.b));
	factors_list.push_back(Factorize(triplet.c));
	NumSet factors = f_merge_num_lists(factors_list);

	NumType conductor = 1;
	for (const auto & f : factors)
		conductor *= f;

	return conductor;

}
