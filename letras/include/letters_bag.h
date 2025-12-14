/* ***************************************** */
/**
* @file   letters_bag.h
* @brief  Archivo de implementación del TDA LettersBag
* @author Aurora Casanova García
* @author Andrés López Baena
*/


#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;


class LettersBag {
private:
	vector<char> letters;		// Contiene las letras 

public:

	class iterator {
	private:
		vector<char>::iterator it;

	public:

		/**
			* @brief  Constuctor sin parámetros
			* @doc 		Crea un nuevo objeto de la clase iterator
		**/
		iterator ();

		/**
			* @brief  Constuctor con parámetros
			* @param i iterador al que apuntar
			* @doc 		Crea un nuevo objeto de la clase iterator
		**/
		iterator(const vector<char>::iterator &i);

		/**
			* @brief  Sobrecarga del operador =
			* @param	i iterador al que apuntar
			* @return	Referencia a si mismo
		**/
		iterator& operator = (const vector<char>::iterator &i);

		/**
			* @brief	Sobrecarga del operador ==
			* @param	i referenecia al elemento a comparar
			* @return	true si los dos objetos son iguales
		**/
		bool operator == (const iterator &i) const;

		/**
			* @brief	Sobrecarga del operador !=
			* @param	i referenecia al elemento a comparar
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
		const char & operator * ();

	}; // class iterator


	class const_iterator {
	private: 
		vector<char>::const_iterator it;

	public:

		/**
			* @brief  Constuctor sin parámetros
			* @doc 		Crea un nuevo objeto de la clase const_iterator
		**/
		const_iterator ();

		/**
			* @brief  Constuctor con parámetros
			* @param i iterador al que apuntar
			* @doc 		Crea un nuevo objeto de la clase const_iterator
		**/
		const_iterator(const vector<char>::const_iterator &i);

		/**
			* @brief  Sobrecarga del operador =
			* @param	i iterador al que apuntar
			* @return	Referencia a si mismo
		**/
		const_iterator& operator = (const vector<char>::const_iterator &i);

		/**
			* @brief	Sobrecarga del operador ==
			* @param	i referenecia al elemento a comparar
			* @return	true si los dos objetos son iguales
		**/
		bool operator == (const const_iterator &i) const;

		/**
			* @brief	Sobrecarga del operador !=
			* @param	i referenecia al elemento a comparar
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
		const char & operator * (); 

	}; // Class const_iterator


	/**
	  * @brief  Constuctor sin parámetros
	  * @doc 		Crea un nuevo objeto de la clase LettersBag
	**/
	LettersBag();

	/**
	  * @brief  Destructor
	  * @doc 		Destruye objeto de la clase LettersBag
	**/
	~LettersBag ();

	/**
		* @brief  Constuctor con parámetros
		* @param	letterSet objeto donde contiene todas las letras
		* @doc 	Crea un nuevo objeto de la clase LettersBag
	**/
	LettersBag(const LettersSet & letterSet);


	/**
		* @brief	Extrae una letra de manera aleatoria 
		* @return	Una letra del LettersBag
	**/
	char extractLetter();


	/**
		* @brief	Saca el conjunto de letras con el que jugar
		* @param	num nº de letras que se quiere extraer
		* @return	conjunto de letras aleatorias con las que se va a jugar
	**/
	vector<char> extractLetters(int num);


	/**
	  * @brief  Tamaño del conjunto
	  * @return Devuelve el nº de elementos del LettersBag
	**/
	unsigned int size() const;

	/**
	  * @brief  Inserta un elemento en el conjunto
	  * @param	letter letra a insertar
	**/
	void insert(char letter);

	/**
	  * @brief  Eliminia un elemento
	  * @param	letter letra que se va a eliminar
	  * @return true si el elemento ha sido eliminado
	**/
	bool erase(char letter);

	/**
	  * @brief  Elimina todos los elementos del objeto
	  * @doc 		Vacía el objeto
	**/
	void clear();

	/**
	  * @brief  Inicio
	  * @return	Puntero a la posición inicial de letters
	**/
	iterator begin();

	/**
	  * @brief  Inicio
	  * @return	Puntero constante a la posición inicial 
	  *						de letters
	**/
	const_iterator begin() const;

	/**
	  * @brief  Fin
	  * @return	Puntero a la última posición de letters
	**/
	iterator end();

	/**
	  * @brief  Fin
	  * @return	Puntero constante a la última posición 
	  *					inicial de letters
	**/
	const_iterator end() const;

};

#endif // __LETTERS_BAG_H__
