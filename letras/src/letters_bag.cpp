/* ***************************************** */
/**
* @file   letters_bag.cpp
* @brief  Archivo de implementación del TDA LettersBag
* @author Aurora Casanova García
* @author Andrés López Baena
*/

#include <ctime>

#include "letters_bag.h"

LettersBag::LettersBag(){}

LettersBag :: ~LettersBag(){}

LettersBag::LettersBag(const LettersSet & letterSet){
	// Recorremos el letterSet
	for (auto it = letterSet.begin(); it != letterSet.end(); ++it){

		// Aniadimos la letra tantas veces como venga
		for (int i = 0; i < it->second.repetitions; i++)
			letters.push_back(it->first);
	}
}

// Extrae una letra de manera aleatoria 
char LettersBag::extractLetter(){
	char letter = '\0';

	if (!letters.empty()){
		
		// Generamos un indice aleatorio que sera la letra a extraer
    	int pos = rand () % (letters.size()); 

		// Sacamos la letra con ese indice
		letter = letters[pos];

		// Vamos a eliminar la letra de manera eficiente
		// Asignamos a la posicion que se va a borrar el ultimo elemento
		// Borramos el ultimo elemento que es el que hemos extraido

		letters[pos] = letters.back();
		letters.pop_back();
	}

	return letter;
}

// Saca el conjunto de letras con el que jugar
vector<char> LettersBag::extractLetters(int num){
	vector <char> resultado;

	for (int i = 0; i < num && !letters.empty(); i++)
		resultado.push_back(extractLetter());

	return resultado;
}

// Devuelve el tamanio del conjunto de letras
unsigned int LettersBag::size() const {
	return letters.size();
}

// Inserta una letra en el conjunto
void LettersBag::insert(char letter){
	letters.push_back(letter);
}          

// Borra una ocurrencia de una letra dada
bool LettersBag::erase(char letter){
	auto it = find(letters.begin(), letters.end(), letter);

	if (it != letters.end()){
		letters.erase(it);
		return true;
	}

	return false;
}

// Vacia el conjunto de letras
void LettersBag::clear(){
	letters.clear();
}

////////////////////////////////////////////////////////////////////////////////


LettersBag :: iterator LettersBag :: begin ()
{
	LettersBag::iterator i ( letters.begin() );
	
	return i;
}

LettersBag :: const_iterator LettersBag :: begin () const
{
	LettersBag::const_iterator i ( letters.cbegin() );
	
	return i;
}

LettersBag :: iterator LettersBag :: end ()
{
	LettersBag::iterator i ( letters.end() );
	
	return i;
}

LettersBag :: const_iterator LettersBag :: end () const
{
	LettersBag::const_iterator i ( letters.cend() );
	
	return i;
}


//---------------------- METODOS DE LA CLASE ITERATOR ------------------------//


LettersBag :: iterator :: iterator () 
{}

LettersBag :: iterator :: iterator(const vector<char>::iterator &i) : it(i) 
{}

LettersBag :: iterator & LettersBag :: iterator :: operator = (const vector<char>::iterator &i)
{
	it = i;
	
	return *this;
}
   
bool LettersBag :: iterator :: operator == (const iterator &i) const 
{
	return it == i.it;
}

bool LettersBag :: iterator :: operator != (const iterator &i) const 
{
	return !(it == i.it);
}

LettersBag :: iterator & LettersBag :: iterator :: operator ++ () 
{
	++it;
	return *this;
}

const char & LettersBag :: iterator :: operator * () 
{
	return *it;
}



//------------------- METODOS DE LA CLASE CONST_ITERATOR ---------------------//


LettersBag :: const_iterator :: const_iterator () 
{}

LettersBag :: const_iterator :: const_iterator(const vector<char>::const_iterator &i) : it(i) 
{}

LettersBag :: const_iterator & LettersBag :: const_iterator :: operator = (const vector<char>::const_iterator &i) 
{
	it = i;
	
	return *this;
}

bool LettersBag :: const_iterator :: operator == (const const_iterator &i) const 
{
	return it == i.it;
}

bool LettersBag :: const_iterator :: operator != (const const_iterator &i) const 
{
	return !(it == i.it);
}

LettersBag :: const_iterator & LettersBag :: const_iterator :: operator ++ () 
{
	++it;
	return *this;
}

const char & LettersBag :: const_iterator :: operator * () 
{
	return *it;
}




