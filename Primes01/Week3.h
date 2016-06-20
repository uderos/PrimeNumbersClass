#pragma once
#include "HomeworkSet.h"

class Week3 : public HomeworkSet
{
	public:
		Week3();
		virtual ~Week3();

		virtual void Run() const override;

	private:

		std::string m_display_triplets(const NumType target, 
									   TripletEvaluator & evaluator) const;

		void m_homework_3_3_1() const;
		void m_homework_3_3_2() const;
};

