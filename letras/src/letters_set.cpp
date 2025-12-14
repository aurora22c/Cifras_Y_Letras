#include "letters_set.h"

LettersSet :: LettersSet(){}

LettersSet :: ~LettersSet(){}

LettersSet :: LettersSet(const string & fichero){
	ifstream fi(fichero);

	if (fi)
		fi >> *this;
}


istream & operator >> (istream & is, LettersSet & lettersSet){
	string cabecera;

	getline(is,cabecera);

	char letra;
	int cantidad, puntos;

	while (is >> letra >> cantidad >> puntos){
		lettersSet.insert(letra, LetterInfo(cantidad, puntos));
	}

	return is;
}


int LettersSet :: score(const string & w) const{
	int puntos = 0;
	
	// Recorremos la palabra
	for (int i = 0; i < w.size(); i++){
		auto it = charSet.find(w[i]); 	// Encontramos la letra en el map
		
		if (it != charSet.end())		
			puntos += it->second.score;
	}

	return puntos;
}

////////////////////////////////////////////////////////////////////////////////


pair<LettersSet::iterator, bool> LettersSet :: insert(char c, const LetterInfo & info){

	auto resultado = charSet.insert(pair<char, LetterInfo>(c, info));
	
	return { LettersSet::iterator(resultado.first), resultado.second };
}


LettersSet :: iterator LettersSet :: begin ()
{
	LettersSet::iterator i ( charSet.begin() );
	
	return i;
}

LettersSet :: const_iterator LettersSet :: begin () const
{
	LettersSet::const_iterator i ( charSet.cbegin() );
	
	return i;
}

LettersSet :: iterator LettersSet :: end ()
{
	LettersSet::iterator i ( charSet.end() );
	
	return i;
}

LettersSet :: const_iterator LettersSet :: end () const
{
	LettersSet::const_iterator i ( charSet.cend() );
	
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
