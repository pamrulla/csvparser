#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace CSVparser
{
	typedef std::vector<std::string> CSVRow;

	class csvparser
	{
	public:
		csvparser(std::istream& src);
		~csvparser();

		bool NextRow(CSVRow& row);

	private:
		std::istream& m_src;
	};
}
