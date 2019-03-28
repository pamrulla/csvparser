#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace CSVparser
{
	typedef std::vector<std::string> CSVRow;
	const char END_INPUT = 0;
	const char REC_SEP = '\n';

	class csvparser
	{
	public:
		csvparser(std::istream& src);
		~csvparser();

		bool NextRow(CSVRow& row);

	private:
		bool IsFieldEnd();
		bool IsRecordEnd();
		void NextChar();
		void ReadField(CSVRow& row);

		std::istream& m_src;
		char m_fieldSeperator;
		char m_nextCh;
	};
}
