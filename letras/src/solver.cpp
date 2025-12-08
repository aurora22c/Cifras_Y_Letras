#include <cctype>
#include "solver.h"

using namespace std;

Solver :: Solver(Dictionary d, LettersSet ls)
{
	dictionary = d;
	letters_set = ls;
}
	
Solver :: ~Solver()
{}

vector<string> Solver :: getSolutions (const vector<char> & available_letters, bool score_game)
{
	vector<char> letras;
	
	// Es necesario pasarlas a minúscula porque en el diccionario
	// tratamos todas la letras de está forma y si comparamos no 
	// funcionaría
	for (int i = 0; i < available_letters.size(); i++)
		letras[i] = tolower( available_letters[i] );
	
	if (score_game)
		return getSolutionsScore(letras);
	else 
		return getSolutionsLength(letras);
}

bool Solver :: buildWord (vector<char> available_letters, string w)
{	
	// Comprobamos que la palabra tenga menos o igual
	// número de letras que las dadas
	if (w.size() > available_letters.size()) return false;
	
	for (int i = 0; i < w.size(); i++) {
		char c = w[i];
		bool seguir = true;
		auto it = available_letters.begin();
		
		while ( it != available_letters.end() && seguir) {
			// La eliminamos para que no se pueda volver a usar
			if (c == *it) {
				it = available_letters.erase(it);
				seguir = false;
			} else
				++it;
		}
		
		// Si no hemos encontrado la letra de la palabra
		// en el vector no se puede contruir y salimos
		if (seguir) return false;
	}
	
	return true;
}

vector<string> Solver :: getSolutionsScore (const vector<char> & available_letters)
{
	vector<string> solver;
	int max_score = 0;
	
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		string w = *it;
		
		bool exis = buildWord (available_letters, w);
		
		if (exis) {
			// No se si está bien
			int score = letters_set.score(w);
			
			if (max_score < score) {
				max_score = score;
				solver.clear();
				solver.push_back(w);
			} else if (max_score == score)
				solver.push_back(w);
								
		}
				
	}
	
	return solver;
}

vector<string> Solver :: getSolutionsLength (const vector<char> & available_letters)
{
	vector<string> solver;
	int max_length = 0;
	
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		string w = *it;
		
		bool exis = buildWord (available_letters, w);
		
		if (exis) {
			int length = w.size();
			
			if (max_length < length) {
				max_length = length;
				solver.clear();
				solver.push_back(w);
			} else if (max_length == length)
				solver.push_back(w);
								
		}
				
	}
	
	return solver;
}
