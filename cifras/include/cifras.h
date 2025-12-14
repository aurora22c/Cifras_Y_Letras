/* ***************************************** */
/**
* @file   cifras.h
* @brief  Archivo de definición de varias funciones
* @author Aurora Casanova García
* @author Andrés López Baena
*/

#include <vector>
#include <set>

#include "operations.h"

const vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};

const int TAM = 6;

/**
  * @brief	Rellena un vector con elementos de C
  * @return	Vector con elementos aleatorios de C
  **/
multiset<int> digitsBag ();

/**
  * @brief	Busca la mejor solución para lograr un número
  * @param	S números disponibles
  * @param      objetivo número que queremos conseguir
  * @param      actual operaciones actuales
  * @param      best mejor solución hasta el momento
  **/
void Cifras (multiset<int> S, int objetivo, Operations actual, Operations & best);

/**
  * @brief	Calcula las soluciones a +, -, *, /
  * @param	actual operaciones actuales
  * @param      n número con el que operar
  * @return	Todas las soluciones posibles
  **/
vector<Operations> GeneraOperaciones (Operations actual, int n);

/**
  * @brief	Analiza una respuesta
  * @param	operaciones solución
  * @param      S números disponibles
  * @return	Resultado de las operaciones
  **/
int AnalizaRespuesta (string operaciones, multiset<int> S);
