#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Node
{
public:
	Node();
	Node(char c);
	
	char get_value() const;
	bool get_leaf() const;
	void set_leaf();

	Node* get_child(const char key);
	std::vector<Node *> children;
	
private:
	char value;

};

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
	void add_word(std::string const &word);
	bool search(std::string const &word);

private:
	Node *root;
};

