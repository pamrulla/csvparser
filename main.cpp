#include <iostream>
#include <sstream>
#include "csvparser.h"

using namespace CSVparser;

#define TEST( e ) \
	if(e) \
	{ \
		std::cout << "Passed: " #e << std::endl; \
	} \
	else \
	{ \
		std::cout << "Failed: " #e " at line : " << __LINE__ << std::endl; \
		goto EXIT; \
	}

int main(int argc, char* argv[])
{
	std::istringstream str1("1,2,3");
	csvparser parser1(str1);
	CSVRow row1;
	bool ret1 = parser1.NextRow(row1);

	TEST(ret1 == true);
	TEST(row1.size() == 3);
	TEST(row1[0] == "1");
	TEST(row1[1] == "2");
	TEST(row1[2] == "3");

	EXIT:
	int ch;
	std::cout << "Press any key to exit";
	std::cin >> ch;

	return 0;
}
