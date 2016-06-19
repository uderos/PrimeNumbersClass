#include "stdafx.h"
#include "Week2.h"


Week2::Week2()
{
}


Week2::~Week2()
{
}

std::string Week2::m_relative_primes(const NumType a, const NumType b) const
{
	PrimeUtils pu;
	const bool are_relative_prime = pu.AreRelativePrimes(a, b);

	std::ostringstream oss;
	oss << a << " and " << b
		<< (are_relative_prime ? " ARE" : " are NOT")
		<< " relative primes";
	return oss.str();
}

std::string Week2::m_display_fermat_square_pairs(const NumType target) const
{
	PrimeUtils utils;
	NumPairList pairs = utils.FindFermatSquarePairs(target);

	std::ostringstream oss;
	oss << '[' << __FUNCTION__ << ']'
		<< " Fermat square pairs for N=" << target << ": ";

	for (const auto & p : pairs)
		oss << "(" << p.first << "," << p.second << ") ";

	return oss.str();
}


void Week2::m_homework_2_1() const
{
	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< std::endl;

	std::cout << "\t" << m_relative_primes(4, 7) << std::endl;
	std::cout << "\t" << m_relative_primes(10, 18) << std::endl;
	std::cout << "\t" << m_relative_primes(35, 99) << std::endl;
	std::cout << "\t" << m_relative_primes(122, 177) << std::endl;
	std::cout << "\t" << m_relative_primes(12345, 111111) << std::endl;
}

void Week2::m_homework_2_2() const
{
	std::cout << '[' << __FUNCTION__ << ']' << std::endl;
	std::cout << "\t" << m_display_fermat_square_pairs(233) << std::endl;
	std::cout << "\t" << m_display_fermat_square_pairs(349) << std::endl;
	std::cout << "\t" << m_display_fermat_square_pairs(821) << std::endl;
}

void Week2::m_homework_2_3() const
{
	std::cout << '[' << __FUNCTION__ << ']' << std::endl;
	std::cout << "\t" << m_display_fermat_square_pairs(221) << std::endl;
}

void Week2::Run() const
{
	m_homework_2_1();
	m_homework_2_2();
	m_homework_2_3();
}

