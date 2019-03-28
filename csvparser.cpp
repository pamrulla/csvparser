#include "csvparser.h"
namespace CSVparser
{
	csvparser::csvparser(std::istream& src) : m_src(src), m_fieldSeperator(',')
	{
		NextChar();
	}


	csvparser::~csvparser()
	{
	}

	bool csvparser::NextRow(CSVRow & row)
	{
		row.clear();
		while (!IsRecordEnd())
		{
			ReadField(row);
		}
		return row.size() != 0;
	}
	bool csvparser::IsFieldEnd()
	{
		return m_nextCh == m_fieldSeperator || m_nextCh == REC_SEP || m_nextCh == END_INPUT;
	}
	bool csvparser::IsRecordEnd()
	{
		if (m_nextCh == END_INPUT || m_nextCh == REC_SEP)
		{
			NextChar();
			return true;
		}
		else
		{
			return false;
		}
	}
	void csvparser::NextChar()
	{
		if (!m_src.get(m_nextCh))
		{
			m_nextCh = END_INPUT;
		}
		if (m_nextCh == '\r')
		{
			NextChar();
		}
	}
	void csvparser::ReadField(CSVRow & row)
	{
		std::string field;
		while (!IsFieldEnd())
		{
			field += m_nextCh;
			NextChar();
		}
		row.push_back(field);
		if (m_nextCh == m_fieldSeperator)
		{
			NextChar();
		}
	}
}
