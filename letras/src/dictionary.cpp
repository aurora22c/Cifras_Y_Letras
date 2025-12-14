/* ***************************************** */
/**
* @file   dictionary.cpp
* @brief  Archivo de implementación del TDA Dictionary
* @author Aurora Casanova García
*	  Andrés López Baena
*/

#include "dictionary.h"


Dictionary :: Dictionary () 
{}
  
Dictionary :: ~Dictionary ()
{}

void Dictionary :: clear ()
{
  words.clear();
}
  
unsigned int Dictionary :: size () const
{
  return words.size();
}

bool Dictionary :: empty () const
{
  return words.empty();
}

bool Dictionary :: exists (const string &val)
{
  return words.count(val);
}

bool Dictionary :: erase (const string &val)
{
  return words.erase(val);	
}


istream & operator >> (istream &is, Dictionary &dic)
{
  string w;
  
  while (is >> w)
  	dic.words.insert(w);
  
  return is;
}

ostream & operator << (ostream &os, const Dictionary &dic)
{
  for (auto it = dic.words.begin(); it != dic.words.end(); ++it)
  	os << *it << endl;
  	
  return os;
}

int Dictionary :: getOccurrences (const char c) const 
{
	int cont = 0;

	for (auto it = words.begin(); it != words.end(); ++it) 
		cont += count (it->begin(), it->end(), c);
	
	return cont;
}

int Dictionary :: getTotalLetters () const 
{
	int cont = 0;

	for (auto it = words.begin(); it != words.end(); ++it)
		cont += it->size();
	
	return cont;
}

vector<string> Dictionary :: getWordsLength (int length) 
{
	vector<string> w;

	for (auto it = words.begin(); it != words.end(); ++it)
		if (it->size() == length)
			w.push_back(*it);
	
	return w;
}


//---------------------- METODOS DE LA CLASE ITERATOR ------------------------//


Dictionary :: iterator :: iterator () 
{}

Dictionary :: iterator :: iterator(const set<string>::iterator &i) : it(i) 
{}

Dictionary :: iterator & Dictionary :: iterator :: operator = (const set<string>::iterator &i)
{
	it = i;
	
	return *this;
}
   
bool Dictionary :: iterator :: operator == (const iterator &i) const 
{
	return it == i.it;
}

bool Dictionary :: iterator :: operator != (const iterator &i) const 
{
	return !(it == i.it);
}

Dictionary :: iterator & Dictionary :: iterator :: operator ++ () 
{
	++it;
	return *this;
}

const string & Dictionary :: iterator :: operator * () 
{
	return *it;
}


//------------------- METODOS DE LA CLASE CONST_ITERATOR ---------------------//


Dictionary :: const_iterator :: const_iterator () 
{}

Dictionary :: const_iterator :: const_iterator(const set<string>::const_iterator &i) : it(i) 
{}

Dictionary :: const_iterator & Dictionary :: const_iterator :: operator = (const set<string>::const_iterator &i) 
{
	it = i;
	
	return *this;
}

bool Dictionary :: const_iterator :: operator == (const const_iterator &i) const 
{
	return it == i.it;
}

bool Dictionary :: const_iterator :: operator != (const const_iterator &i) const 
{
	return !(it == i.it);
}

Dictionary :: const_iterator & Dictionary :: const_iterator :: operator ++ () 
{
	++it;
	return *this;
}

const string & Dictionary :: const_iterator :: operator * () 
{
	return *it;
}

Dictionary :: iterator Dictionary :: find (const string &w)
{
	Dictionary::iterator i ( words.find(w) );
	
	return i;
}

pair<Dictionary :: iterator, bool> Dictionary :: insert (const string &val) {
	auto res = words.insert(val);
	
	Dictionary::iterator i (res.first);

	return {i, res.second};
}

pair<Dictionary :: iterator,Dictionary :: iterator> Dictionary :: range_prefix (const string &val) {
	auto res = words.equal_range(val);

	Dictionary::iterator i1, i2;
	i1 = res.first;
	i2 = res.second;

	return {i1, i2};
}

Dictionary :: iterator Dictionary :: begin ()
{
	Dictionary::iterator i ( words.begin() );
	
	return i;
}

Dictionary :: const_iterator Dictionary :: begin () const
{
	Dictionary::const_iterator i ( words.cbegin() );
	
	return i;
}

Dictionary :: iterator Dictionary :: end ()
{
	Dictionary::iterator i ( words.end() );
	
	return i;
}

Dictionary :: const_iterator Dictionary :: end () const
{
	Dictionary::const_iterator i ( words.cend() );
	
	return i;
}

