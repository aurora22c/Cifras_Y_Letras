#include "letters_set.h"

LettersSet :: LettersSet(){}

LettersSet :: LettersSet(const string & fichero){
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



////////////////////////////////////////////////////////////////////////////////


LettersSet :: iterator LettersSet :: begin ()
{
	LettersSet::iterator i;
	i = charSet.begin();
	
	return i;
}

LettersSet :: const_iterator LettersSet :: begin () const
{
	LettersSet::const_iterator i;
	i = charSet.cbegin();
	
	return i;
}

LettersSet :: iterator LettersSet :: end ()
{
	LettersSet::iterator i;
	i = charSet.end();
	
	return i;
}

LettersSet :: const_iterator LettersSet :: end () const
{
	LettersSet::const_iterator i;
	i = charSet.cend();
	
	return i;
}


//---------------------- METODOS DE LA CLASE ITERATOR ------------------------//


LettersSet :: iterator :: iterator () 
{}

LettersSet :: iterator :: iterator(const map<char, LetterInfo>::iterator &i) : it(i) 
{}

LettersSet :: iterator & LettersSet :: iterator :: operator = (const map<char, LetterInfo>::iterator &i)
{
	it = i;
	
	return *this;
}
   
bool LettersSet :: iterator :: operator == (const iterator &i) const 
{
	return it == i.it;
}

bool LettersSet :: iterator :: operator != (const iterator &i) const 
{
	return !(it == i.it);
}

LettersSet :: iterator & LettersSet :: iterator :: operator ++ () 
{
	++it;
	return *this;
}

pair<const char, LetterInfo> & LettersSet :: iterator :: operator * () 
{
	return *it;
}

pair<const char, LetterInfo> * LettersSet :: iterator :: operator -> ()
{
	return &(*it);
}



//------------------- METODOS DE LA CLASE CONST_ITERATOR ---------------------//


LettersSet :: const_iterator :: const_iterator () 
{}

LettersSet :: const_iterator :: const_iterator(const map<char, LetterInfo>::const_iterator &i) : it(i) 
{}

LettersSet :: const_iterator & LettersSet :: const_iterator :: operator = (const map<char, LetterInfo>::const_iterator &i) 
{
	it = i;
	
	return *this;
}

bool LettersSet :: const_iterator :: operator == (const const_iterator &i) const 
{
	return it == i.it;
}

bool LettersSet :: const_iterator :: operator != (const const_iterator &i) const 
{
	return !(it == i.it);
}

LettersSet :: const_iterator & LettersSet :: const_iterator :: operator ++ () 
{
	++it;
	return *this;
}

const pair<const char, LetterInfo> & LettersSet :: const_iterator :: operator * () 
{
	return *it;
}

const pair<const char, LetterInfo> * LettersSet :: const_iterator :: operator -> ()
{
	return &(*it);
}
