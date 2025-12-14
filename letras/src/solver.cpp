/* ***************************************** */
/**
* @file   solver.cpp
* @brief  Archivo de implementación del TDA Solver
* @author Aurora Casanova García
* @author Andrés López Baena
*/

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
	vector<string> solver;
	int max_score = 0;
	
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		string w = *it;
		
		bool exis = buildWord (available_letters, w);
		
		if (exis) {
			int score;
			
			if (score_game)
				score = letters_set.score(w);
			else
				score = w.size();
			
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
