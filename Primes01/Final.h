#pragma once
#include "HomeworkSet.h"

class Final : public HomeworkSet
{
	public:
		Final();
		virtual ~Final();

		virtual void Run() const override;

	private:

		std::string m_display_sieve_of_eratosthenes(const NumType upper_limit,
													const NumVectorPair & primes_removed) const;

		NumPairList m_find_square_pairs(const NumType target, 
									    size_t expected_num_pairs = 0) const;

		void m_final_2() const;
		void m_final_3() const;
		void m_final_4() const;
		void m_final_99() const;
};

