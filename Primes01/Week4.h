#pragma once
#include "HomeworkSet.h"

class Week4 : public HomeworkSet
{
	public:
		Week4();
		virtual ~Week4();

		virtual void Run() const override;

	private:

		std::string m_display_conductor(const NumTriplet triplet) const;

		void m_homework_4_2_0() const;
		void m_homework_4_2_1() const;
		void m_homework_4_2_2() const;
		void m_homework_4_2_3() const;
};

