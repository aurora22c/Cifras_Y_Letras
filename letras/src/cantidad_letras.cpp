#include <fstream>
#include <iostream>
#include <cmath>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 4){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    cout << "2.- El fichero con las letras" << endl;
    cout << "3.- El fichero de salida"<<endl;
    return 1;
  }
  
	string fich_dic = argv[1];
	string fich_let = argv[2];
	string fich_sal = argv[3];
	
	ifstream fi_dic (fich_dic);
	
	if (!fi_dic){
		cout << "No se pudo abrir el fichero del diccionario" << endl;
		return 1;
	}
	
	ifstream fi_let (fich_let);
	
	if (!fi_let){
		cout << "No se pudo abrir el fichero de letras" << endl;
		return 1;
	}
	
	ofstream fo_sal (fich_sal);
	
	if (!fo_sal){
		cout << "No se pudo abrir el fichero de salida" << endl;
		return 1;
	}
	
	Dictionary diccionario;
	LettersSet letters_set;
	
	fi_dic >> diccionario;
	fi_let >> letters_set;
	
	int total_letras = diccionario.getTotalLetters();
	double min = INFINITY;
	
	map<char,pair<long,double>> datos;
	
	for (auto it = letters_set.begin(); it != letters_set.end(); ++it) {
		char c = it->first;
		double ocur = diccionario.getOccurrences(c);
		double porc = ocur/total_letras;
		
		datos[c] = {ocur, porc};
		
		if (min > porc)
			min = porc;
	}
	
	double min_log = -log10(min);
	
	fo_sal << "Letra \t Cantidad \t Puntos" << endl;
	
	for (auto it = datos.begin(); it != datos.end(); ++it) {
		int puntos = 10 * ( -log10(it->second.second)/min_log );
		fo_sal << it->first << "\t" << it->second.first << "\t\t" << puntos << endl;
	}
	
	fi_dic.close();
	fi_let.close();
	fo_sal.close();
    
  return 0;
}
  
	
	
	
