
#pragma once

using NumType = std::uintmax_t;
using NumList = std::multiset<NumType >;
using NumSet = std::set<NumType >;
using NumVector = std::vector<NumType>;
using NumPair = std::pair<NumType, NumType>;
using NumPairList = std::vector<NumPair>;
using NumVectorPair = std::pair<NumVector, NumVector>;

enum eWeek
{
	WEEK_1 = 0,
	WEEK_2,
	WEEK_3,
	WEEK_4,
	WEEK_FINAL,

	WEEK_ALL = 99
};

template <typename T>
struct triplet_t
{
	T a;
	T b;
	T c;
	triplet_t() : a(T(0)), b(T(0)), c(T(0)) {};
	triplet_t(const T aa, const T bb, const T cc) : a(aa), b(bb), c(cc) {};
};

using NumTriplet = triplet_t<NumType>;
using TripletList = std::vector<NumTriplet>;

using TripletEvaluator = std::function<NumType(const NumType, const NumTriplet &)>;

//#define COUT std::cout
#define COUT if(0)std::cout
