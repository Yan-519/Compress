#include <iostream>
#include <string>

#include "compressor.h"


void test_for_big() {
	for (int i = 0; i <= 10000000; i += 1000000)
	{
		std::pair<std::string, size_t> temp = Compressor::compression(std::string(i, '*'));
		std::cout << temp.first << "\t" << temp.second << "\t" << (Compressor::di_compress(temp) == std::string(i, '*')) << "\n";
	}
}

void test_for_times() {
	std::cout << ": ";
	std::string input;
	std::cin >> input;

	size_t prev = input.size();
	size_t temp;

	for (size_t i = 0; i < 50; i++)
	{
		input = Compressor::compress(input);
		temp = input.size();
		std::cout << i << ": " << (double)temp / prev << "\t" << input.size() << "\n";
		prev = temp;
	}
}

int main()
{
	return 0;
}