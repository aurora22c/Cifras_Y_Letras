#ifndef __OPERATIONS__
#define __OPERATIONS__

#include <string>

using namespace std;

struct Operations {
	int valor;
	string operaciones;
	
	Operations () : valor(0), operaciones("")
	{}
	
	Operations (int v, string o) : valor(v), operaciones(o)
	{}
};

#endif
