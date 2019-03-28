#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace CSVparser
{
	typedef std::vector<std::string> CSVRow;
	const char END_INPUT = 0;
	const char REC_SEP = '\n';
	const char D_QUOTE = '\"';

	class csvParserException : public std::exception
	{
	public:
		csvParserException(const std::string & msg) : mMsg(msg) {}
		~csvParserException() throw () {}
		const char * what() const throw() {
			return mMsg.c_str();
		}
	private:
		std::string mMsg;
	};

	class csvparser
	{
	public:
		csvparser(std::istream& src);
		~csvparser();

		bool NextRow(CSVRow& row);

	private:
		bool IsFieldEnd();
		bool IsRecordEnd();
		bool IsDQuote();
		void NextChar();
		void ReadField(CSVRow& row);
		void ThrowError(const std::string &msg);

		std::istream& m_src;
		char m_fieldSeperator;
		char m_nextCh;
	};
}
