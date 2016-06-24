#include "stdafx.h"
#include "Final.h"


Final::Final()
{
}


Final::~Final()
{
}




std::string Final::m_display_sieve_of_eratosthenes(
		const NumType upper_limit,
		const NumVectorPair & primes_removed) const
{
	Utils utils;

	std::ostringstream oss;
	oss << "Sieve of Eratosthenes "
		<< " UpperLimit=" << upper_limit
		<< "\n\t Primes=" << utils.container_to_string(primes_removed.first)
		<< "\n\t Removed=" << utils.container_to_string(primes_removed.second);

	return oss.str();
}

NumPairList Final::m_find_square_pairs(const NumType target, size_t expected_num_pairs) const
{
	NumPairList pairs;

	for (NumType first = 1; first <= target; ++first)
	{
		COUT << __FUNCTION__ << " first <== " << first << std::endl;
		for (NumType second = first; first + second <= target; ++second)
		{
			if ((first*first) + (second*second) == target)
			{
				pairs.emplace_back(first, second);

				COUT << "Square Pair: target=" << target
					<< " first=" << first
					<< " second=" << second
					<< std::endl;

				if (expected_num_pairs && expected_num_pairs == pairs.size())
					return pairs;
			}
		}
	}

	return pairs;
}

void Final::m_final_99() const
{
	PrimeUtils pu;
	Utils utils;

	for (NumType target = 10; target < 40; target += 4)
	{
		const NumPairList pairs = m_find_square_pairs(target);

		std::cout
			<< '[' << __FUNCTION__ << ']'
			<< " List square pairs for N=" << target
			<< "(n=" << pairs.size() << ") "
			<< ":";

		for (const auto gp : pairs)
			std::cout << " (" << gp.first << "," << gp.second << ")";

		std::cout << std::endl;
	}
}


void Final::m_final_2() const
{
	PrimeUtils pu;
	const NumType upper_limit = 100000;

	NumVectorPair primes_removed = pu.SieveOfEratosthenes(upper_limit);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_sieve_of_eratosthenes(upper_limit, primes_removed)
		<< std::endl;
}

void Final::m_final_3() const
{
	PrimeUtils pu;
	Utils utils;
	const std::size_t num_primes = 10;
	NumSet primes_list;

	for (NumType p = 2; primes_list.size() < num_primes; p = pu.CalcNextPrime(p))
	{
		COUT << "\t p=" << p << " p mod 8 = " << p % 8 << std::endl;
		if (p % 8 == 7)
		{
			primes_list.insert(p);
			COUT << "Found: p=" << p << " n=" << primes_list.size() << std::endl;
		}
	}

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< " List of primes = 7 mod 8: "
		<< utils.container_to_string(primes_list)
		<< std::endl;
}

void Final::m_final_4() const
{
	PrimeUtils pu;
	Utils utils;
	const NumType target = 239693;
	const size_t expected_num_pairs = 2;

	const NumPairList pairs = m_find_square_pairs(target, expected_num_pairs);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< " List square pairs for N=" << target 
		<< "(n=" << pairs.size() << ") " 
		<< ":";

	for (const auto p : pairs)
		std::cout << " (" << p.first << "," << p.second << ")";

	std::cout << std::endl;
}



void Final::Run() const
{
	//m_final_99();
	// m_final_2();
	//m_final_3();
	m_final_4();
}

