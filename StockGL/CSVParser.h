#pragma once
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

namespace stock_util
{
	class CSVRow
	{
	public:
		std::string const& operator[](std::size_t index);

		std::size_t size();

		void read_next_row(std::istream &str);

		CSVRow();
		~CSVRow();
		std::string csvToStr(const std::string &filename);
	private:
		std::vector < std::string > data;
	};
}