#include "Compressor.h"

#include <string>
#include <utility>

std::string Compressor::compress_once(std::string& text) {
	std::string result;
	result.reserve(text.size() * 2);

	for (size_t i = 0, j = 0; i < text.size(); ) {
		while (j < text.size() && text[j] == text[i])
			j++;

		size_t count = j - i;
		if (count > 1)
			result += std::to_string(count);

		result += Compressor::delimiter;
		result += text[i];

		i = j;
	}
	return result;
}

std::string Compressor::di_compress_once(std::string& text) {
	std::string result;
	std::string n;
	result.reserve(text.size() * 2);

	for (size_t i = 0; i < text.size(); n = "", i++) {
		while (i < text.size() && text[i] != Compressor::delimiter)
			n += text[i++];

		i++;

		if (n == "")
			result += text[i];

		else result += std::string(std::stoi(n), text[i]);
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

std::string Compressor::di_compress(std::string text, size_t times) {
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