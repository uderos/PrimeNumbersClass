#pragma once
#include "HomeworkSet.h"

class Week2 : public HomeworkSet
{
	public:
		Week2();
		virtual ~Week2();

		virtual void Run() const override;

	private:
		std::string m_relative_primes(const NumType a, const NumType b) const;
		std::string m_display_fermat_square_pairs(const NumType target) const;


		void m_homework_2_1() const;
		void m_homework_2_2() const;
		void m_homework_2_3() const;

};

