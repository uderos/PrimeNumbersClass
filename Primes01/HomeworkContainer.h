#pragma once

#include "HomeworkSet.h"

class HomeworkContainer
{
public:
	HomeworkContainer();
	virtual ~HomeworkContainer();

	void RunAll();
	void Run(const eWeek week);

	private:

//		using ContainerType = std::map<eWeek, std::shared_ptr<HomeworkSet>>;
		using ContainerType = std::map<eWeek, HomeworkSet*>;

		ContainerType m_homeworks;

		void m_run(const eWeek week, HomeworkSet & homework);
};

