#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;


class LettersBag {	// Implementar como map o multimap
private:
	vector<char> letters;		// Contiene las letras 

public:

	// Constructor sin parametros
	LettersBag();

	// Constructor con parametros
	LettersBag(const LettersSet & letterSet);

	// Extrae una letra de manera aleatoria 
	char extractLetter();

	// Saca el conjunto de letras con el que jugar
	vector<char> extractLetters(int num);

	int size() const;

	void insert(char letter);

	void erase(char letter);

	void clear();

	auto begin();

	auto end();

	auto begin() const;

	auto end() const;
};

#endif
