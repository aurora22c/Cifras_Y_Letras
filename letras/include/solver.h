 /* ***************************************** */
 /**
 * @file   solver.h
 * @brief  Archivo de definición del TDA solver
 * @author Aurora Casanova García
 *		     Andrés López Baena
 */

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
	/**
		* @brief  Constuctor con parámetros
		* @param  d, diccionario que contiene las palabras válidas del juego
		* @param ls, conjunto de letras
		* @doc 		Crea un nuevo objeto de la clase Solver
	**/
	Solver (Dictionary d, LettersSet ls);
	
	/**
	  * @brief  Destructor
	  * @doc 		Destruye objeto de la clase Solver
	**/
	~Solver ();
	
	/**
		* @brief  Obtiene las posibles soluciones a partir de un conjunto de 
		*			 letras
		* @param  available_letters, vector con las letras disponibles para 
		*			 formar palabras
		* @param 		  score_game, índica el modo de juego
		* @return Genera todas las palabras válidas que pueden formarse con 
		*			 las letras disponibles y devuelve aquellas que tengan
		*			 mayor puntuación o longitud, dependiendo del modo de juego
	**/
	vector<string> getSolutions (const vector<char> & available_letters, 
										  bool score_game);

private:

	/**
		* @brief  Comprueba si una palabra puede construirse con las letras
		*			 disponibles
		* @param  available_letters, vector con las letras disponibles 
		* @param 		           w, palabra que se quiere construir
		* @return true si la puede puede construirse,
		*			 false en caso contrario
	**/
	bool buildWord (vector<char> available_letters, string w);
	
	/**
		* @brief  Obtiene las soluciones priorizando la puntuación
		* @param  available_letters, vector con las letras disponibles 
		* @return Vector con las palabras que tienen la máxima puntuación posible
	**/
	vector<string> getSolutionsScore (const vector<char> & available_letters);
	
	/**
		* @brief  Obtiene las soluciones priorizando la longitud de las palabras
		* @param  available_letters, vector con las letras disponibles 
		* @return Vector con las palabras que tienen la máxima longitud posible
	**/
	vector<string> getSolutionsLength (const vector<char> & available_letters);
};

#endif // __SOLVER_H__
