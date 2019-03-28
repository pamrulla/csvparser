#include "csvparser.h"
namespace CSVparser
{
	csvparser::csvparser(std::istream& src) : m_src(src)
	{
	}


	csvparser::~csvparser()
	{
	}
	bool csvparser::NextRow(CSVRow & row)
	{
		row.clear();
		char nextCh;
		std::string field;
		while (m_src.get(nextCh))
		{
			if (nextCh == ',')
			{
				row.push_back(field);
				field = "";
			}
			else if(nextCh == '\n')
			{
				row.push_back(field);
				field = "";
				break;
			}
			else if (nextCh == '\r')
			{
				continue;
			}
			else
			{
				field += nextCh;
			}
		}
		if (!field.empty())
		{
			row.push_back(field);
		}
		return row.size() != 0;
	}
}
