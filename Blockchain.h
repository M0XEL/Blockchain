#pragma once
#include <vector>
#include <iostream>

#include "Block.h"

template<typename T>
class Blockchain {
private:
	std::vector<Block<T>> chain;

public:
	Blockchain();
	void addBlock(T data);
	bool isChainValid();
	void show();

	// To change Blocks for testing
	std::vector<Block<T>>* getChainAddress();
};

template<typename T>
Blockchain<T>::Blockchain() {
	chain.push_back(Block<T>(0, T(), 0));
}

template<typename T>
void Blockchain<T>::addBlock(T data) {
	chain.push_back(Block<T>(chain.size(), data, chain.back().getHash()));
}

template<typename T>
bool Blockchain<T>::isChainValid() {
	typename std::vector<Block<T>>::iterator block;
	for (block = chain.begin(); block != chain.end(); ++block) {
		if (!block->isBlockValid())
			return false;
		if (block != chain.begin()) {
			if (block->getPreviousHash() != (--block)->getHash())
				return false;
			++block;
		}
	}
	return true;
}

template<typename T>
void Blockchain<T>::show() {
	for (Block<T> block : chain)
		block.show();
	std::cout << "Chain Valid  | " << isChainValid() << std::endl;
}

#if DEBUG == 1
template<typename T>
std::vector<Block<T>>* Blockchain<T>::getChainAddress() {
	return &chain;
}
#endif