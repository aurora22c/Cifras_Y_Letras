#include "letters_set.h"

LettersSet(){}

LettersSet(const string & fichero){
	ifstream fi(fichero);

	if (fi)
		fi >> *this;
}


istream & operator >> (istream & is, LettersSet & lettersSet){
	string cabecera;

	is >> cabecera;

	char letra;
	int cantidad, puntos;

	while (is >> letra >> cantidad >> puntos){
		LetterInfo info(cantidad, puntos);
		lettersSet.insert(letra, info);
	}

	return is;
}

auto LettersSet::begin(){
	return charSet.begin();
}

auto LettersSet::end(){
	return charSet.end();
}

auto LettersSet::begin() const{
	return charSet.begin();
}

auto LettersSet::end() const{
	return charSet.end();
}
