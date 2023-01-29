#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

map<char, string> PrintCodes(class MinHeapNode* root, string str, map<char, string>& mp);
map<char, string> Huffman(multimap<int, char> freq);
multimap<int, char> GetFrequency(string str);
multimap<int, char> sortMap(map<char, int>& M);
string ShowSequence(string src, map<char, string> mp);

class MinHeapNode
{
public:
	char data;
	unsigned freq;

	MinHeapNode* left, * right;
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};