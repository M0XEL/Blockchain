#pragma once
#include <chrono>
#include <string>
#include <iostream>

#define DEBUG 1

template<typename T>
class Block {
private:
	int64_t index, timestamp;
	size_t hash, previousHash;
	T data;

public:
	Block(int64_t index, T data, size_t previousHash);
	size_t getHash();
	size_t getPreviousHash();
	size_t createHash();
	bool isBlockValid();
	void show();

	// To change Data for testing
	T* getDataAdress();
};

template<typename T>
Block<T>::Block(int64_t index, T data, size_t previousHash) :
	index{ index },
	data{ data },
	previousHash{ previousHash }
{
	using namespace std::chrono;
	timestamp = duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count();
	hash = createHash();
}

template<typename T>
size_t Block<T>::getHash() {
	return hash;
}

template<typename T>
size_t Block<T>::getPreviousHash() {
	return previousHash;
}

template<typename T>
size_t Block<T>::createHash() {
	std::hash<std::string> hasher;
	return hasher(std::to_string(index) + std::to_string(previousHash) + std::to_string(timestamp) + std::to_string(data.createHash()));
}

template<typename T>
bool Block<T>::isBlockValid() {
	return hash == createHash();
}

template<typename T>
void Block<T>::show() {
	std::cout << "###########################" << std::endl;
	std::cout << "Block Index  | " << index << std::endl;
	std::cout << "Block Valid  | " << isBlockValid() << std::endl;
	std::cout << "PreviousHash | " << previousHash << std::endl;
	std::cout << "Hash         | " << hash << std::endl;
	std::cout << "Timestamp    | " << timestamp << std::endl;
	std::cout << "-----------Data------------\n" << data.show() << std::endl;
	std::cout << "###########################\n" << std::endl;
}

#if DEBUG == 1
template<typename T>
T* Block<T>::getDataAdress() {
	return &data;
}
#endif