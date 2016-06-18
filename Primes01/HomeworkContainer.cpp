#include "stdafx.h"
#include "HomeworkContainer.h"

#include "Week1.h"

HomeworkContainer::HomeworkContainer()
{
//	m_homeworks.emplace(WEEK_1, std::make_shared<HomeworkSet>(Week1()));
	m_homeworks.emplace(WEEK_1, new Week1);
}


HomeworkContainer::~HomeworkContainer()
{
}

void HomeworkContainer::RunAll()
{
	for (auto h : m_homeworks)
		m_run(h.first, *(h.second));
}

void HomeworkContainer::Run(const eWeek week)
{
	auto & p = m_homeworks.find(week);
	if (p == m_homeworks.end())
	{
		std::ostringstream oss;
		oss << "Homework not found for week " << week
			<< " at " << __FILE__ << ":" << __LINE__;
		throw std::runtime_error(oss.str());
	}

	m_run(p->first, *(p->second));
}

void HomeworkContainer::m_run(const eWeek week, HomeworkSet & homework)
{
	std::cout
		<< "\n\n#############################################\n"
		<< "Running homeworks for week " << week
		<< std::endl;

	homework.Run();
}

