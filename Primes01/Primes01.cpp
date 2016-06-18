// Primes01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HomeworkContainer.h"
#include "Utils.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{

		HomeworkContainer homeworks;

		homeworks.RunAll();
		std::cout << "\nTHE END" << std::endl;
	}
	catch (const std::exception e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}

