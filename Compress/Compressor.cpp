#include "Compressor.h"

std::string Compressor::compress_once(std::string& text) {
	std::string result;
	result.reserve(text.size() * 2);

	for (size_t i = 0; i < text.size(); ) {
		size_t j = i;
		while (j < text.size() && text[j] == text[i])
			++j;

		size_t count = j - i;
		if (count > 1)
			result += std::to_string(count);

		result += '#';
		result += text[i];

		i = j;
	}
	return result;
}

std::string Compressor::di_compress_once(std::string& text) {
	std::string result;
	result.reserve(text.size() * 2);

	for (size_t i = 0; i < text.size(); ) {
		std::string n;
		while (i < text.size() && text[i] != '#') {
			n += text[i];
			i++;
		}

		i += 2;

		if (n == "")
			result += text[i - 1];
		else result += std::string(std::stoi(n), text[i - 1]);
	}
	return result;
}

std::string Compressor::compress(std::string text, int times) {
	if (times <= 0)
		return text;

	std::string out = text;
	while (times--)
		out = Compressor::compress_once(out);

	return out;
}
std::string Compressor::compress(std::string text) {
	return Compressor::compress(text, 1);
}

std::pair<std::string, size_t> Compressor::compression(std::string text) {
	std::string min = text;
	text = Compressor::compress_once(text);
	size_t t = 0;
	for (; text.size() < min.size(); t++)
	{
		min = text;
		text = Compressor::compress_once(text);
	}
	return { min, t };
}

std::string Compressor::di_compress(std::string text, int times) {
	if (times <= 0)
		return text;

	std::string out = text;
	while (times--)
		out = Compressor::di_compress_once(out);

	return out;
}
std::string Compressor::di_compress(std::string text) {
	return Compressor::di_compress(text, 1);
}

std::string Compressor::di_compress(std::pair<std::string, size_t> p) {
	return Compressor::di_compress(p.first, p.second);
}