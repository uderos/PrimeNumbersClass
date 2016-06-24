#pragma once

#include "DataTypes.h"
class PrimeUtils
{
	public:
		PrimeUtils();
		virtual ~PrimeUtils();

		NumList Factorize(const NumType product) const;

		std::size_t FindPrimeTwins(const NumType from_number,
								   const NumType to_number) const;

		NumPairList FindGoldbachPairs(const NumType target) const;
		NumPairList FindGoldbachPairsFast(const NumType target) const;
		NumPairList FindFermatSquarePairs(const NumType target) const;

		bool AreRelativePrimes(const NumType a, const NumType b) const;

		TripletList FindTriplet(const NumType target, TripletEvaluator evaluator) const;

		NumType CalcConductor(const NumTriplet & triplet) const;

		NumVectorPair SieveOfEratosthenes(const NumType upper_limit) const;

		NumType CalcNextPrime(const NumType last_prime) const;

	private:

		bool m_has_factors(const NumType target, const NumList & factors) const;

		bool m_is_prime(const NumType number) const;
		NumType m_calc_next_prime(const NumType last_prime) const;

};

