#pragma once

#include "DataTypes.h"
#include "PrimeUtils.h"
#include "Utils.h"

class HomeworkSet
{
	public:
		HomeworkSet();
		virtual ~HomeworkSet();

		virtual void Run() const = 0;
};

