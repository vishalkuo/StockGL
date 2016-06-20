#include "CSVParser.h"

using namespace stock_util;

CSVRow::CSVRow() {}
CSVRow::~CSVRow(){}


std::string const& CSVRow::operator[](std::size_t index)
{
	return data[index];
}

std::size_t CSVRow::size()
{
	return data.size();
}

void CSVRow::read_next_row(std::istream &str)
{
	std::string         line;
	std::getline(str, line);

	std::stringstream   line_stream(line);
	std::string         cell;

	data.clear();
	while (std::getline(line_stream, cell, ','))
	{
		data.push_back(cell);
	}

	std::cout << line << std::endl;
}


std::string CSVRow::csvToStr(const std::string &filename)
{

	
	/*std::ifstream in;

	
	std::string line;
	std::string cell;

	in.open(filename);

	while (std::getline(in, cell, ','))
	{
		std::cout << cell << std::endl;
	}*/
	return filename;
}