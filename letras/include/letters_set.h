#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <iofstream>
#include <map>

using namespace std;

struct LetterInfo{
  unsigned int repetitions;
  unsigned int score;

  /**
   * @brief Constructor por defecto
   */
  LetterInfo(): repetitions(0), score(0){}

  /**
   * @brief Constructor con parámetros
   *
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score): repetitions(reps), score(score){};
};


class LettersSet{
private:
  map<char, LetterInfo> charSet;

public:

	LettersSet();

	LettersSet(const string & fichero);

	friend istream & operator >> (istream & is, LettersSet & lettersSet);

	auto begin();

	auto end();

	auto begin() const;

	auto end() const;
  
};

#endif
