#include "Huffman.h" 

multimap<int, char> GetFrequency(string str)
{
	if (str.length() <= 1)
		throw invalid_argument("Длина строки не может быть меньше двух символов");
	map<char, int> freq;

	for (int i = 0; i < str.length(); i++)
		freq[str[i]] = 0;
	
	for (int i = 0; i < str.length(); i++)
		freq[str[i]]++;

	multimap<int, char> frequency = sortMap(freq);

	cout << "---Таблица встречаемости символов (символ - кол-во)---" << endl;
	for (auto& it : frequency)
		cout << '\t' << it.second << ": " << it.first << endl;
	return frequency;
}

multimap<int, char> sortMap(map<char, int>& M)
{
	multimap<int, char> MM;
	for(auto& it : M)
		MM.insert({it.second, it.first});
	return MM;
}

map<char, string> PrintCodes(class MinHeapNode* root, string str, map<char, string>& mp)
{
	if (!root) {
		return mp;
	}
	if (root->data != '$') {
		mp[root->data] = str;
		cout << root->data << ": " << str << endl;
	}

	PrintCodes(root->left, str + "0", mp);
	PrintCodes(root->right, str + "1", mp);

	return mp;
}

map<char, string> Huffman(multimap<int, char> freq)
{
	MinHeapNode* left, * right,* top;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (auto& it : freq)
		minHeap.push(new MinHeapNode(it.second, it.first));

	while (minHeap.size() != 1) 
	{
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}
	map<char, string> mp;
	cout << "Таблица соответствия символа и битовой последовательности" << endl;
	PrintCodes(minHeap.top(), "", mp);
	return mp;
}

string ShowSequence(string src, map<char, string> mp)
{
	string result;
	for (unsigned int i = 0; i < src.length(); i++)
	{
		result.append(mp[src[i]]);
	}
	return result;
}