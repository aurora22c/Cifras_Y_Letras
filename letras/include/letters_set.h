/* ***************************************** */
/**
* @file   letters_set.cpp
* @brief  Archivo de definición del TDA LettersSet
* @author Aurora Casanova García
*	  Andrés López Baena
*/

#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <fstream>
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
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score): repetitions(reps), score(score){};
};


class LettersSet{
private:
  map<char, LetterInfo> charSet;

public:

class iterator {
	private:
		map<char, LetterInfo>::iterator it;

	public:

		/**
			* @brief  Constuctor sin parámetros
			* @doc 		Crea un nuevo objeto de la clase iterator
		**/
		iterator ();

		/**
			* @brief  Constuctor con parámetros
			* @param i, iterador al que apuntar
			* @doc 		Crea un nuevo objeto de la clase iterator
		**/
		iterator(const map<char, LetterInfo>::iterator &i);

		/**
			* @brief  Sobrecarga del operador =
			* @param	i, iterador al que apuntar
			* @return	Referencia a si mismo
		**/
		iterator& operator = (const map<char, LetterInfo>::iterator &i);

		/**
			* @brief	Sobrecarga del operador ==
			* @param	i, referenecia al elemento a comparar
			* @return	true si los dos objetos son iguales
		**/
		bool operator == (const iterator &i) const;

		/**
			* @brief	Sobrecarga del operador !=
			* @param	i, referenecia al elemento a comparar
			* @return	true si los dos objetos son diferentes
		**/
		bool operator != (const iterator &i) const;

		/**
			* @brief	Sobrecarga del operador ++
			* @return	Referencia a si mismo
			* @doc		Aumenta en 1 la posición del puntero
		**/
		iterator& operator ++ ();

		/**
			* @brief	Sobrecarga del operador *
			* @return	Elemento al que referencia el puntero
		**/
		pair<const char, LetterInfo> & operator * ();

		/**
			* @brief	Sobrecarga del operador ->
			* @return	Puntero al par (clave, valor) al que apunta el iterador
		**/
		pair<const char, LetterInfo> * operator -> ();

	}; // class iterator


	class const_iterator {
	private: 
		map<char, LetterInfo>::const_iterator it;

	public:

		/**
			* @brief  Constuctor sin parámetros
			* @doc 		Crea un nuevo objeto de la clase const_iterator
		**/
		const_iterator ();

		/**
			* @brief  Constuctor con parámetros
			* @param i, iterador al que apuntar
			* @doc 		Crea un nuevo objeto de la clase const_iterator
		**/
		const_iterator(const map<char, LetterInfo>::const_iterator &i);

		/**
			* @brief  Sobrecarga del operador =
			* @param	i, iterador al que apuntar
			* @return	Referencia a si mismo
		**/
		const_iterator& operator = (const map<char, LetterInfo>::const_iterator &i);

		/**
			* @brief	Sobrecarga del operador ==
			* @param	i, referenecia al elemento a comparar
			* @return	true si los dos objetos son iguales
		**/
		bool operator == (const const_iterator &i) const;

		/**
			* @brief	Sobrecarga del operador !=
			* @param	i, referenecia al elemento a comparar
			* @return	true si los dos objetos son diferentes
		**/
		bool operator != (const const_iterator &i) const;

		/**
			* @brief	Sobrecarga del operador ++
			* @return	Referencia a si mismo
			* @doc		Aumenta en 1 la posición del puntero
		**/
		const_iterator& operator ++ ();

		/**
			* @brief	Sobrecarga del operador *
			* @return	Elemento al que referencia el puntero
		**/
		const pair<const char, LetterInfo> & operator * ();

		/**
			* @brief	Sobrecarga del operador ->
			* @return	Puntero al par (clave, valor) al que apunta el iterador
		**/
		const pair<const char, LetterInfo> * operator -> ();

	}; // Class const_iterator


	/**
		* @brief  Constuctor sin parámetros
		* @doc 		Crea un nuevo objeto de la clase LettersSet
	**/
	LettersSet();

	/**
	  * @brief  Destructor
	  * @doc 		Destruye objeto de la clase LettersSet
	**/
	~LettersSet ();


	/**
		* @brief  Constuctor con parámetros
		* @param  fichero, fichero donde contiene toda la información
		*				sobre la creación de un LettersSet
		* @doc 		Crea un nuevo objeto de la clase LettersSet
	**/
	LettersSet(const string & fichero);


	/**
	  * @brief  Sobrecarga del operador >>
	  * @param	is, referencia del flujo de entrada
	  *			lettersSet, referencia del objeto LettersSet 
	  * @return	El flujo de entrada
	  * @doc 		Inicializa el LettersSet con los elementos
	  *						que hay en is
	**/
	friend istream & operator >> (istream & is, LettersSet & lettersSet);

	
	/**
	  * @brief  Calcula la puntuación total de una palabra
	  * @param	w, palabra que se quiere calcular la puntuación
	  * @return	Puntuación total de la palabra
	**/
	int score(const string & w) const;

	/**
	  * @brief  Inserta una letra con su información 
	  * @param	   c, letra a insertar
	  * @param  info, información de la letra (repetitions y score)
	  * @return	Par formado por el iterador al elemento insertado y un 
	  *			bool que indica si se insertó (true) o ya existía (false)
	**/
	pair<LettersSet::iterator, bool> insert(char c, const LetterInfo & info);


	/**
	  * @brief  Inicio
	  * @return	Puntero a la posición inicial de charSet
	**/
	iterator begin();

	/**
	  * @brief  Inicio
	  * @return	Puntero constante a la posición inicial 
	  *						de charSet
	**/
	const_iterator begin() const;

	/**
	  * @brief  Fin
	  * @return	Puntero a la última posición de charSet
	**/
	iterator end();

	/**
	  * @brief  Fin
	  * @return	Puntero constante a la última posición 
	  *					inicial de charSet
	**/
	const_iterator end() const;
  
};

#endif // __LETTER_SET_H__

