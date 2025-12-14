/* ***************************************** */
/**
* @file   dictionary.h
* @brief  Archivo de definición del TDA Dictionary
* @author Aurora Casanova García
* @author Andrés López Baena
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <string>
#include <iostream>
#include <set>
#include <algorithm>

#include <vector>
using namespace std;

class Dictionary {
private:
  set<string> words;

public:

	/**
	  * @brief  Constuctor sin parámetros
	  * @doc 		Crea un nuevo objeto de la clase dictionary
	**/
  Dictionary ();
  
	/**
	  * @brief  Destructor
	  * @doc 		Elimina un objeto de la clase dictionary
	**/
  ~Dictionary ();
  
	/**
	  * @brief  Elimina todos los elementos del objeto
	  * @doc 		Vacía el objeto
	**/
  void clear ();
  
	/**
	  * @brief  Tamaño del conjunto
	  * @return Devuelve el nº de elementos del diccionario
	**/
  unsigned int size () const;
  
	/**
	  * @brief  Conjunto vacío
	  * @return true si el conjunto está vacío
	**/
  bool empty () const;
  
	/**
	  * @brief  Busca un elemento
	  * @param	val, referencia del elemento que se debe 
	  * 					buscar
		* @return true si el elemento está en el conjunto
	**/
  bool exists (const string &val);
  
	/**
	  * @brief  Eliminia un elemento
	  * @param	val, referencia del elemento que de debe
	  *						eliminar
	  * @return true si el elemento ha sido eliminado
	**/
  bool erase (const string &val);
  
	/**
	  * @brief  Sobrecarga del operador >>
	  * @param	is, referencia del flujo de entrada
	  *					dic, referencia del objeto dicctionary 
	  * @return	El flujo de entrada
	  * @doc 		Inicializa el diccionario con los elementos
	  *						que hay en is
	**/
  friend istream &operator >> (istream &is, Dictionary &dic);
  
	/**
	  * @brief  Sobrecarga del operador <<
	  * @param	os, referencia del flujo de salida
	  *					dic, referencia del objeto dicctionary 
	  * @return	El flujo de salida
	**/
  friend ostream &operator << (ostream &os, const Dictionary &dic);
  
	/**
	  * @brief  Cuenta un caracter
	  * @param	c, caracter que se debe contar
	  * @return El nº de veces que se usa el caracter
	  *						dado en el objeto
	**/
  int getOccurrences (const char c) const;
  
	/**
	  * @brief  Cuenta las letras totales
	  * @return El nº de letras que tienen todas las
	  *						palabras del diccionario
	**/
  int getTotalLetters () const;
  
	/**
	  * @brief  Busca parabras de una longitud concreta
	  * @param	length, longitud de las palabras a buscar
		*	@return	Un vector con todas las palabras que 
		*          tienen la longitud dada
	**/
  vector<string> getWordsLength (int length);
  
  class iterator {
  private:
    set<string>::iterator it;
      
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
	 iterator(const set<string>::iterator &i);
    
		/**
			* @brief  Sobrecarga del operador =
			* @param	i, iterador al que apuntar
			* @return	Referencia a si mismo
		**/
    iterator& operator = (const set<string>::iterator &i);
    
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
    const string & operator * ();
  };
  
  class const_iterator {
  private: 
    set<string>::const_iterator it;
      
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
		const_iterator(const set<string>::const_iterator &i);
    
		/**
			* @brief  Sobrecarga del operador =
			* @param	i, iterador al que apuntar
			* @return	Referencia a si mismo
		**/
    const_iterator& operator = (const set<string>::const_iterator &i);
    
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
    const string & operator * (); 
  };
  
	/**
	  * @brief  Busca un elemento en el conjunto
	  * @param	w, palabra a buscar
	  * @return	Iterador a la posición de la palabra, 
	  * 					si no está apunta al final
	**/
  iterator find (const string &w);
  
	/**
	  * @brief  Inserta un elemento en el conjunto
	  * @param	val, palabra a insertar
	  * @return	Iterador a la posición de la palabra tras
	  *						ser insertada y true si no existía
	  *						previamente
	**/
  pair<iterator, bool> insert (const string &val);
  
	/**
	  * @brief  Busca el rango del elemento
	  * @param	val, palabra a buscar el rango
	  * @return	Iterador a la primera posición de la 
	  *						palabra e iterador a la última posición
	  *						de inserción
	**/
  pair<iterator, iterator> range_prefix (const string &val);
  
	/**
	  * @brief  Inicio
	  * @return	Puntero a la posición inicial de words
	**/
  iterator begin ();
  
	/**
	  * @brief  Inicio
	  * @return	Puntero constante a la posición inicial 
	  *						de words
	**/
  const_iterator begin () const;
  
	/**
	  * @brief  Fin
	  * @return	Puntero a la última posición de words
	**/
  iterator end ();
  
	/**
	  * @brief  Fin
	  * @return	Puntero constante a la última posición 
	  *					inicial de words
	**/
  const_iterator end () const;
};
#endif //DICTIONARY_H
