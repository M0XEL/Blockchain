#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <stdio.h>

#include "Blockchain.h"
#include "StringData.h"

int main() {

	Blockchain<StringData> blockchain;
	blockchain.addBlock(StringData("Data 1"));
	blockchain.addBlock(StringData("Data 2"));
	blockchain.addBlock(StringData("Data 3"));
	blockchain.show();
	std::cout << "\n\n\n\n";

	Blockchain<StringData> blockchain2;
	blockchain2.addBlock(StringData("Data 1"));
	blockchain2.addBlock(StringData("Data 2"));
	blockchain2.addBlock(StringData("Data 3"));
#if DEBUG == 1
	blockchain2.getChainAddress()->back().getDataAdress()->string = "Hacked";
#endif
	blockchain2.show();

	getchar();
	return 0;
}