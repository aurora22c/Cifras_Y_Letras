#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "operations.h"

using namespace std;

const vector<int> C = {1,2,3,4,5,6,7,8,9,10,25,50,75,100};

multiset<int> digitsBag ();

void Cifras (multiset<int> S, int objetivo, Operations actual, Operations & best);

vector<Operations> GeneraOperaciones (Operations actual, int n);

int AnalizaRespuesta (string operaciones, multiset<int> S);

int main(int argc, char *argv[])
{
  multiset<int> S = digitsBag ();
  srand( time(0) );
  int objetivo = 100 + rand() % (999 - 100 + 1);
  
  cout << endl
  		 << "   PROBLEMA DE LAS CIFRAS" << endl
       << "----------------------------" << endl << endl
  
   		 << "Las cifras que puedes usar son: " << endl;
  
	for (auto it = S.begin(); it != S.end(); ++it)
		cout << *it << "  ";
		
	cout << endl << endl << "El número que tienes que conseguir es:" << endl
			 << objetivo << endl;
  
  string operaciones;
  
  cout << endl << "Da las operaciones para lograr " << objetivo << endl;
	getline(cin, operaciones, '\n');
  
  int respuesta = AnalizaRespuesta (operaciones, S);
  
  cout << endl << "La respuesta dada es: " << endl
  		 << respuesta << endl << endl;
  
  Operations actual, best;
  Cifras (S, objetivo, actual, best);
  
  int solucion = objetivo;
  
  if (best.valor != objetivo) {
  	solucion = best.valor;
  	cout << "No se puede obtener el valor " << objetivo << endl << endl
  			 << "La mejor opción es: " << endl
  			 << best.valor << endl << endl;
  }
  
  cout << "La solución es: " << endl
  			 << best.operaciones << endl << endl;
  
	if ( abs(respuesta-objetivo) == abs(solucion-objetivo) )
		cout << "Tu respuesta es válida";
	else 
		cout << "Tu respuesta no es válida";
  	
  cout << endl;
  
  return 0;
}


multiset<int> digitsBag () 
{
	multiset<int> d;
	int tam = C.size();
	srand (time(0));
	
	for (int i = 0; i < 6; i++)
		d.insert( C[ rand() % tam ] );
		
	return d;
}

void Cifras (multiset<int> S, int objetivo, Operations actual, Operations & best)
{
	if (actual.valor == objetivo) {
		best = actual;
		return;
	}
	
	if ( abs(actual.valor-objetivo) < abs(best.valor-objetivo) ) {
		best = actual;
	}
	
	for (auto it = S.begin(); it != S.end(); ++it) {
		int n = *it;
		multiset<int> restantes (S);
		auto it2 = restantes.find(n);
		restantes.erase( it2 );
		
		vector<Operations> operations = GeneraOperaciones (actual, n);
		
		for (int i = 0; i < operations.size(); i++)
			Cifras(restantes, objetivo, operations[i], best);
	}

}

vector<Operations> GeneraOperaciones (Operations actual, int n)
{		
	vector<Operations> operations;
	
	// Evitamos que se guarden operaciones con 0
	if (actual.valor == 0) {
		operations.push_back({n, actual.operaciones});
	} else {
	
		operations.push_back({actual.valor+n, actual.operaciones + to_string(actual.valor) + "+" + to_string(n) + "  "});
		
		if ( actual.valor-n >= 0 )
			operations.push_back({actual.valor-n, actual.operaciones + to_string(actual.valor) + "-" + to_string(n) + "  "});
				
		operations.push_back({actual.valor*n, actual.operaciones + to_string(actual.valor) + "*" + to_string(n) + "  "});
		
		if ( (n != 0) && (actual.valor % n == 0) )
			operations.push_back({actual.valor/n, actual.operaciones + to_string(actual.valor) + "/" + to_string(n) + "  "});
	}
	
	return operations;
}

int AnalizaRespuesta (string operaciones, multiset<int> S)
{
	istringstream iss;
	iss.str (operaciones);
	
	int dato1, dato2, 
			sol = -1;
	char oper;
	// Añadir comprobación de que los datos pasados están en 
	// el vector
	while (iss >> dato1) {
		iss >> oper;
		iss >> dato2;
		
		auto it1 = S.find(dato1);
		
		if ( it1 == S.end() ) {
			cerr << "ERROR: Datos no válidos" << endl;
			exit (1);
		} else 
			S.erase(it1);
		
		auto it2 = S.find(dato2);
		
		if ( it2 == S.end() ) {
			cerr << "ERROR: Datos no válidos" << endl;
			exit (1);
		} else 
			S.erase(it2);
			
		
		switch (oper) {
			case '+':
				sol = dato1 + dato2;
				break;
			case '-':
				sol = dato1 - dato2;
				break;
			case '*':
				sol = dato1 * dato2;
				break;
			case '/':
				sol = dato1 / dato2;
				break;
			default:
				cerr << "ERROR: Operación no válida" << endl;
				exit (1);
		}
		
		S.insert(sol);
	}
	
	return sol;
}
