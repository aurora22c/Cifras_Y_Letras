#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "dictionary.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "solver.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 5){
		cout << "Los parametros son: " << endl;
		cout << "1.- El fichero con el diccionario" << endl;
		cout << "2.- El fichero con las letras" << endl;
		cout << "3.- El número de letras que se deben generar aleatoriamente" << endl;
		cout << "4.- El modo de juego:" << endl;
		cout << "	 -L:  Se buscará la palabra más larga" << endl;
		cout << "	 -P:  Se obtendrá la palabra de mayor puntuación" << endl;
		return 1;
	}

	// Extraemos los datos que nos han pasado
	string fichero_dic = argv[1];
	string fichero_letras = argv[2];
	int num_letras = stoi(argv[3]);
	string modo_juego = argv[4];


	// Hacemos comprobaciones de los datos
	if (modo_juego != "L" && modo_juego != "P"){
		cout << "Modo de juego incorrecto. Usa L o P" << endl;
		return 1;
	}

	
	// Abrimos el diccionario
	ifstream fi_dic(fichero_dic);

	if (!fi_dic){
		cout << "No se pudo abrir el fichero del diccionario" << endl;
		return 1;
	}


	// Abrimos letras
	ifstream fi_letras(fichero_letras);

	if (!fi_letras){
		cout << "No se pudo abrir el fichero de letras" << endl;
		return 1;
	}
	
	
	// Cargamos el diccionario y letras
	Dictionary diccionario;
	LettersSet letters_set;

	fi_dic >> diccionario;
	fi_letras >> letters_set;

	
	// Creamos la bolsa de letras
	LettersBag letters_bag(letters_set);

	// Creamos el objeto que nos dará las soluciones
	Solver solver(diccionario, letters_set);

	// Iniciamos el generador aleatorio
	srand(time(nullptr));

	char continuar = 'S';

	// Iniciamos el juego
	while (continuar == 'S' || continuar == 's'){
		
		// Extraemos las letras con las que se va a jugar
		vector<char> letras = letters_bag.extractLetters(num_letras);


		// Mostramos las letras 
		cout << endl;
		cout << "Las letras son: ";
	
		for (int i = 0; i < num_letras; i++)
			cout << letras[i] << "       ";
		
		cout << endl;

		
		// Pedimos la solución del usuario
		string solucion_usuario;

		cout << "Dime tu solución: ";

		cin >> solucion_usuario;


		// Comprobamos si es válida la palabra	
		bool valida = diccionario.exists(solucion_usuario);

		int puntuacion_usuario = 0;

		if (valida){
			if (modo_juego == "P")
				puntuacion_usuario = letters_set.score(solucion_usuario);
			else
				puntuacion_usuario = solucion_usuario.size();
		} 

		// Le mostramos los puntos de su solucion
		cout << endl;
		cout << solucion_usuario << "    Puntuación: " << puntuacion_usuario;
		cout << endl;

		
		// Calculamos las soluciones óptimas
		// Si modo_juego == "P", entonces calcula las soluciones por puntos
		// Si modo_juego != "P", entonces calcula las soluciones por longitud
		vector<string> soluciones = solver.getSolutions(letras, modo_juego == "P");

		int puntuacion_max = 0;

		// Mostramos la primera palabra para que nos calcule los puntos
		// No hace falta que saque los puntos del resto porque todos tienen 
		//	la misma puntuacion
		if (!soluciones.empty()){
			if (modo_juego == "P")
				puntuacion_max = letters_set.score(soluciones[0]);
			else
				puntuacion_max = soluciones[0].size();
		}

		// Mostramos las soluciones óptimas
		cout << "Mis soluciones son:" << endl;
		
		for (int i = 0; i < soluciones.size(); i++)
			cout << soluciones[i] << "    Puntuación: " << puntuacion_max << endl;
			
		if (puntuacion_usuario >= puntuacion_max)
			cout << "Mejor solución: " << solucion_usuario << endl;
		else
			cout << "Mejor solucion: " << soluciones[0] << endl;


		// Preguntamos si quiere seguir jugando
		cout << "¿Quieres seguir jugando [S/N]: ";
		cin >> continuar;


		// Rellenamos la bolsa si se queda sin letras
		if (letters_bag.size() < num_letras)
			letters_bag = LettersBag(letters_set);
			
	} // while


	return 0;
}
