#include "stdafx.h"
#include "Week3.h"


Week3::Week3()
{
}


Week3::~Week3()
{
}

std::string Week3::m_display_triplets(const NumType target, TripletEvaluator & evaluator) const
{
	PrimeUtils pu;
	Utils utils;
	TripletList triplet_list = pu.FindTriplet(target, evaluator);

	std::ostringstream oss;
	oss << "Target=" << target;
	if (triplet_list.empty())
	{
		oss << " No triplets found";
	}
	else
	{
		for (const auto & triplet : triplet_list)
			oss << ' ' << utils.to_string(triplet);
	}

	return oss.str();
}

void Week3::m_homework_3_3_1() const
{
	const NumType target = 17;
	TripletEvaluator evaluator = [](const NumType target, const NumTriplet & triplet) {
		const NumType result = (2 * triplet.a * triplet.a) +
							   (triplet.b * triplet.b) +
							   (8 * triplet.c * triplet.c);
		return result;
	};


	std::cout 
		<< '[' << __FUNCTION__ << ']' 
		<< m_display_triplets(target, evaluator) 
		<< std::endl;
}

void Week3::m_homework_3_3_2() const
{
	const NumType target = 17;
	TripletEvaluator evaluator = [](const NumType target, const NumTriplet & triplet) {
		const NumType result = (2 * triplet.a * triplet.a) + 
							   (triplet.b * triplet.b) + 
							   (32 * triplet.c * triplet.c);
		return result;
	};

	std::cout
		<< '[' << __FUNCTION__ << ']'
		<< m_display_triplets(target, evaluator)
		<< std::endl;
}

void Week3::Run() const
{
	m_homework_3_3_1();
	m_homework_3_3_2();
}

