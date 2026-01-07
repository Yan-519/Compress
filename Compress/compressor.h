#pragma once

#include <string>
#include <utility>

class Compressor
{
private:
	static std::string compress_once(std::string& text);

	static std::string di_compress_once(std::string& text);

public:
	//Do not use a number or empty char as delimiter
	const char static delimiter = '#';

	static std::string compress(std::string text, int times);
	static std::string compress(std::string text);

	static std::pair<std::string, size_t> compression(std::string text);

	static std::string di_compress(std::string text, size_t times);
	static std::string di_compress(std::string text);

	static std::string di_compress(std::pair<std::string, size_t> p);

	Compressor() = delete;
};