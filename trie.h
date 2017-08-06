#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

namespace {
	class Node
	{
	public:
		Node();
		~Node();
		Node(char c);
		char get_value() const;
		bool get_leaf() const;
		void set_leaf();

		Node* get_child(const char key);
		std::vector<Node *> children;

	private:
		char value;
	};
}

class NodePointerComp
{
public:
	explicit NodePointerComp(const char key);
	char const key_;
	bool operator()(Node const *n) const;

};

class Trie
{
public:
	Trie();
	~Trie();
	void add_word(std::string const &word);
	bool search(std::string const &word);
	std::vector<std::string> find_suffix(std::string const &s, int max);

private:
	Node *root;
	Node* find_string(std::string const &word);
};