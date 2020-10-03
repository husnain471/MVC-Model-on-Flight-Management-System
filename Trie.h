#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Utility.h"
using namespace std;


class TrieNode {
public:
	char alphabet;
	bool wordComplete;
	TrieNode* links[26];
	string word;

	TrieNode() {
		alphabet = ' ';
		wordComplete = 0;
		for (int i = 0; i < 26; i++)
			links[i] = NULL;
	}
};



class TRIE {
	TrieNode* root;
public:
	TRIE(string path);
	TrieNode* insertWord(string w);
	void Move(TrieNode* n, string s, string& res);
	string SpellChecker(string str);
	void makeDictionary(string path);
};



TRIE::TRIE(string path) {
	TrieNode* n = new TrieNode;
	root = n;
	makeDictionary(path);
}


void TRIE::makeDictionary(string path) {
	fstream ifile(path);
	string in;
	if (!ifile.is_open())
		return;
	do {
		getline(ifile, in);
		conver_to_lower_case(in);
		insertWord(in);
	} while (!ifile.eof());
}




TrieNode* TRIE::insertWord(string w) {
	TrieNode* t = root;

	for (int i = 1; i < w.length(); i++) {

		int num = w[i];

		if (t->links[num - 97] == NULL) {
			TrieNode* newNode = new TrieNode;
			newNode->alphabet = w[i];
			t->links[num - 97] = newNode;
		}

		t = t->links[w[i] - 97];
	}

	t->wordComplete = 1;
	t->word = w;

	return t;
}




void  TRIE::Move(TrieNode* n, string s, string& res) {

	if (n != NULL) {
		for (int i = 0; i < 26; i++) {
			Move(n->links[i], s, res);
		}
		if (n->wordComplete == 1) {
			if (check(n->word, s)) {
				res = n->word;
			}
		}
	}
}

string TRIE::SpellChecker(string str) {
	string s;
	conver_to_lower_case(str);
	Move(root, str, s);
	return s;
}

