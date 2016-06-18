
#pragma once

using NumType = std::uintmax_t;
using NumList = std::multiset<NumType >;

enum eWeek
{
	WEEK_1 = 0,
	WEEK_2,
	WEEK_3,
	WEEK_4,

	WEEK_ALL = 99
};

#define COUT std::cout
//#define COUT if(0)std::cout
