#include "stdafx.h"
#include "Week1.h"


Week1::Week1()
{
}


Week1::~Week1()
{
}

std::string Week1::m_display_factors(const NumType product) const
{
	PrimeUtils pu;
	Utils utils;
	const NumList  factors = pu.Factorize(product);
	
	std::ostringstream oss;
	oss << "Product=" << product << "  Factors={" << utils.to_string(factors) << "}";
	return oss.str();
}


std::string Week1::m_display_num_prime_twins(const NumType from_number,
	const NumType to_number) const
{
	PrimeUtils utils;
	const std::size_t num_twins = utils.FindNumPairs(from_number, to_number);

	std::ostringstream oss;
	oss << '[' << __FUNCTION__ << ']'
		<< " Number of twin pairs between " << from_number << " and " << to_number
		<< " = " << num_twins
		<< std::endl;

	return oss.str();
}



void Week1::m_homework_1_1_1() const
{
	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_factors(100)
		<< std::endl;
}

void Week1::m_homework_1_1_2() const
{
	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_factors(555)
		<< std::endl;
}

void Week1::m_homework_1_1_3() const
{
	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_factors(112233)
		<< std::endl;
}


void Week1::m_homework_1_2() const
{
	NumType from_number = 1000;
	NumType to_number = 1500;

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_num_prime_twins(from_number, to_number)
		<< std::endl;
}

void Week1::Run() const
{
	m_homework_1_1_1();
	m_homework_1_1_2();
	m_homework_1_1_3();
	m_homework_1_2();
}

