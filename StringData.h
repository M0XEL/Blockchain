#pragma once
#include <string>

class StringData {
private:
	size_t hash;

public:
	std::string string;

	StringData() : StringData("") {}
	StringData(std::string string);
	size_t createHash();
	std::string show();
};

StringData::StringData(std::string string) : string{ string } {}

size_t StringData::createHash() {
	std::hash<std::string> hasher;
	return hasher(string);
}

std::string StringData::show() {
	return "String: " + string;
}