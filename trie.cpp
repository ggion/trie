#include "trie.h"

Node::Node() {}
Node::Node(char c) : value(c) {}

char Node::get_value() const { return value < 0 ? -value : value; }

bool Node::get_leaf() const { return value < 0 ? true : false; }

// a string with char -128 or a nullchar will break this
void Node::set_leaf()
{
	if (value > 0)
		value = -value;
}

NodePointerComp::NodePointerComp(const char key) : key_(key) {}

bool NodePointerComp::operator()(Node const *n) const { return n->get_value() == key_; }

Node* Node::get_child(const char key)
{
	auto x = std::find_if(children.begin(), children.end(), NodePointerComp(key));
	if (x == children.end())
		return nullptr;
	
	return *x;
}

Node::~Node()
{
	for (auto c : children)
		delete c;
}


Trie::Trie()
{
	root = new Node();
}

void Trie::add_word(std::string const &word)
{
	Node *curr = root;

	uint32_t i = 0;
	for (i; i < word.length(); i++)
	{
		if (curr->get_child(word[i]) == nullptr)
			break;

		curr = curr->get_child(word[i]);
	}

	for (i; i < word.length(); i++)
	{
		curr->children.push_back(new Node(word[i]));
		curr = curr->children.back();
	}
	
	curr->set_leaf();
	
}


std::vector<std::string> Trie::find_suffix(std::string const & s, int max)
{
	Node *curr = find_string(s);
	if (!curr || max == 0)
		return {};
		
	std::vector<std::string> output;
	std::stack<std::pair<Node*, std::string>> st;

	for (auto c : curr->children)
		st.push({ c, ""});
	
	while (!st.empty())
	{
		auto p = st.top();
		st.pop();

		p.second += p.first->get_value();
		if (p.first->get_leaf())
		{
			output.push_back(p.second);
			if (output.size() == max)
				break;
		}

		for (auto c : p.first->children)
			st.push({ c, p.second });

	}

	return output;
}

Node* Trie::find_string(std::string const & word)
{
	Node *curr = root;
	std::string str;

	for (auto c : word)
		if ((curr = curr->get_child(c)) == nullptr)
			return nullptr;

	return curr;
}

bool Trie::search(std::string const &word)
{
	auto *p = find_string(word);
	if (p) return p->get_leaf();
	return false;
}

Trie::~Trie()
{
	delete root;
}