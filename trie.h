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
		Node() = default;
		~Node();
		Node(char c);
		char get_letter() const;
		bool is_leaf() const;
		void set_leaf();

		Node* get_child(const char key);
		std::vector<Node *> children;

	private:
		char letter;
	};
}

class NodePointerComp
{
public:
	explicit NodePointerComp(const char key);
	bool operator()(Node const *n) const;
	char const key_;

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