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

void Final::m_final_99() const
{
	PrimeUtils pu;
	const NumType upper_limit = 100;

	NumVectorPair primes_removed = pu.SieveOfEratosthenes(upper_limit);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_sieve_of_eratosthenes(upper_limit,	primes_removed)
		<< std::endl;
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


void Final::Run() const
{
	//m_final_99();
	m_final_2();
}

