#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <utility>
#include <vector>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

class Solver{
private:
  Dictionary dictionary;
	LettersSet letters_set;

public:
	Solver (Dictionary d, LettersSet ls);
	
	~Solver ();
	
	vector<string> getSolutions (const vector<char> & available_letters, bool score_game);

private:
	bool buildWord (vector<char> available_letters, string w);
	
	vector<string> getSolutionsScore (const vector<char> & available_letters);
	
	vector<string> getSolutionsLength (const vector<char> & available_letters);
};

#endif // __SOLVER_H__
