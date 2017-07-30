#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "trie.h"

int main()
{

	Trie myTrie;

	std::ifstream is("words_alpha.txt");
	std::string word;
	while (is >> word)
		myTrie.add_word(word);
	is.close();

	is.open("words_alpha.txt");
	while (is >> word)
		std::cout << myTrie.search(word) << std::endl;
	
	std::cout << myTrie.search("kdfsgl") << std::endl;
	std::cout << myTrie.search("hspfiugsoidugosir") << std::endl;


	/*
	myTrie.add_word("hello");
	myTrie.add_word("world");
	myTrie.add_word("fish");
	myTrie.add_word("elephant");
	
	std::cout << "hello : " << myTrie.search("hello") << std::endl;
	std::cout << "world : " << myTrie.search("world") << std::endl;
	std::cout << "fishing : " << myTrie.search("fishing") << std::endl;
	std::cout << "hell : " << myTrie.search("hell") << std::endl;
	std::cout << "derp : " << myTrie.search("derp") << std::endl;
	*/




	return 0;
}