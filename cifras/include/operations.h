 /* ***************************************** */
 /**
 * @file   operations.h
 * @brief  Archivo de definición del TDA Operations
 * @author Aurora Casanova García
 * @author Andrés López Baena
 */


#ifndef __OPERATIONS__
#define __OPERATIONS__

#include <string>

using namespace std;

struct Operations {
	int valor;
	string operaciones;
	
	/**
		* @brief  Constuctor sin parámetros
		* @doc 	  Crea un nuevo objeto Operations
	**/
	Operations () : valor(0), operaciones("")
	{}
	
	/**
		* @brief  Constuctor con parámetros
		* @param  v, valor actual
		* @param  o, operaciones realizadas
		* @doc 	  Crea un nuevo objeto Operations
	**/
	Operations (int v, string o) : valor(v), operaciones(o)
	{}
};

#endif
