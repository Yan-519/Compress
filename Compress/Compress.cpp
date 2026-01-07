#include <iostream>
#include <string>
#include <utility>

#include "compressor.h"


void static test_for_big() {
	for (int i = 1; i <= std::pow(10, 7); i *= 10)
	{
		std::pair<std::string, size_t> temp = Compressor::compression(std::string(i, '*'));
		std::cout << temp.first << "\t" << temp.second << "\t" << (Compressor::di_compress(temp) == std::string(i, '*')) << "\n";
	}
}

void static test_for_times() {
	std::cout << ": ";
	std::string input;
	std::cin >> input;

	size_t prev = input.size();
	size_t temp;

	for (size_t i = 0; i < 50; i++, prev = temp)
	{
		input = Compressor::compress(input);
		temp = input.size();
		std::cout << i << ": " << (double)temp / prev << "\t" << input.size() << "\n";
	}
}

int main()
{
	std::cout << "delimiter: " << Compressor::delimiter << "\n";
	test_for_big();
	test_for_times();
	return 0;
}