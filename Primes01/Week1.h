#pragma once
#include "HomeworkSet.h"

class Week1 : public HomeworkSet
{
	public:
		Week1();
		virtual ~Week1();

		virtual void Run() const override;

	private:
		std::string m_display_factors(const NumType product) const;
		std::string m_display_num_prime_twins(const NumType from_number,
										      const NumType to_number) const;


		void m_homework_1_1_1() const;
		void m_homework_1_1_2() const;
		void m_homework_1_1_3() const;
		void m_homework_1_2() const;
};

