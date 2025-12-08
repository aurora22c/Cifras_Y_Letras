#include "letters_bag.h"

LettersBag::LettersBag(){}

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

		// Generamos un numero aleatorio
		random_device rd;          				 // fuente de aleatoriedad
		mt19937 gen(rd());         				 // generador
		uniform_int_distribution<int> distrib(0, letters.size() - 1); 

		// Generamos un indice aleatorio que sera la letra a extraer
    	int pos = distrib(gen);

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
int LettersBag::size() const {
	return letters.size();
}

// Inserta una letra en el conjunto
void LettersBag::insert(char letter){
	letters.push_back(letter);
}          

// Borra una ocurrencia de una letra dada
void LettersBag::erase(char letter){
	auto it = find(letters.begin(), letters.end(), letter);

	if (it != letters.end())
		letters.erase(it);
}

// Vacia el conjunto de letras
void LettersBag::clear(){
	letters.clear();
}

auto LettersBag::begin(){
	return letters.begin();
}

auto LettersBag::end(){
	return letters.end();
}

auto LettersBag::begin() const{
	return letters.begin();
}

auto LettersBag::end() const{
	return letters.end();
}

