#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <sstream>
#include "csvparser.h"

using namespace CSVparser;

TEST_CASE("Single CSV Record")
{
	//Arrange
	std::istringstream str("1,2,3");
	csvparser parser(str);
	CSVRow row;

	//Act
	bool ret = parser.NextRow(row);

	//Assert
	REQUIRE(ret == true);
	REQUIRE(row.size() == 3);
	CHECK(row[0] == "1");
	CHECK(row[1] == "2");
	CHECK(row[2] == "3");
}

TEST_CASE("Empty CSV content")
{
	//Arrange
	std::istringstream str("");
	csvparser parser(str);
	CSVRow row;

	//Act
	bool ret = parser.NextRow(row);

	//Assert
	REQUIRE(ret == false);
	REQUIRE(row.size() == 0);
}

TEST_CASE("Record Ends with carriage return only")
{
	//Arrange
	std::istringstream str("1,2,3\r");
	csvparser parser(str);
	CSVRow row;

	//Act
	bool ret = parser.NextRow(row);

	//Assert
	REQUIRE(ret == true);
	REQUIRE(row.size() == 3);
	CHECK(row[0] == "1");
	CHECK(row[1] == "2");
	CHECK(row[2] == "3");
}

TEST_CASE("Record Ends with next line only")
{
	//Arrange
	std::istringstream str("1,2,3\n");
	csvparser parser(str);
	CSVRow row;

	//Act
	bool ret = parser.NextRow(row);

	//Assert
	REQUIRE(ret == true);
	REQUIRE(row.size() == 3);
	CHECK(row[0] == "1");
	CHECK(row[1] == "2");
	CHECK(row[2] == "3");
}

TEST_CASE("Record Ends with carriage return and next line")
{
	//Arrange
	std::istringstream str("1,2,3\r\n");
	csvparser parser(str);
	CSVRow row;

	//Act
	bool ret = parser.NextRow(row);

	//Assert
	REQUIRE(ret == true);
	REQUIRE(row.size() == 3);
	CHECK(row[0] == "1");
	CHECK(row[1] == "2");
	CHECK(row[2] == "3");
}

TEST_CASE("Two records")
{
	//Arrange
	std::istringstream str("1,2,3\r\n4,5,6");
	csvparser parser(str);
	CSVRow row;

	//Act
	bool ret = parser.NextRow(row);

	//Assert
	REQUIRE(ret == true);
	REQUIRE(row.size() == 3);
	CHECK(row[0] == "1");
	CHECK(row[1] == "2");
	CHECK(row[2] == "3");
	ret = parser.NextRow(row);
	CHECK(row[0] == "4");
	CHECK(row[1] == "5");
	CHECK(row[2] == "6");
}
