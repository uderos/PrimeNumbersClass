#include "stdafx.h"
#include "Week4.h"


Week4::Week4()
{
}


Week4::~Week4()
{
}




std::string Week4::m_display_conductor(const NumTriplet triplet) const
{
	PrimeUtils pu;
	Utils utils;

	const NumType conductor = pu.CalcConductor(triplet);

	std::ostringstream oss;
	oss << "Conductor of " << utils.to_string(triplet)
		<< " = " << conductor;
	return oss.str();
}

void Week4::m_homework_4_2_0() const
{
	const NumTriplet triplet(5, 18, 30);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_conductor(triplet)
		<< std::endl;
}

void Week4::m_homework_4_2_1() const
{
	const NumTriplet triplet(23, 73, 96);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_conductor(triplet)
		<< std::endl;
}

void Week4::m_homework_4_2_2() const
{
	const NumTriplet triplet(1, 127, 128);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_conductor(triplet)
		<< std::endl;
}

void Week4::m_homework_4_2_3() const
{
	const NumTriplet triplet(1, 4374, 4375);

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_conductor(triplet)
		<< std::endl;
}



void Week4::Run() const
{
//	m_homework_4_2_0();
	m_homework_4_2_1();
	m_homework_4_2_2();
	m_homework_4_2_3();
}

