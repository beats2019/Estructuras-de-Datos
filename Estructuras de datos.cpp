#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Lista.h"




int main()
{
	Lista<int> miLista;
	miLista.insertarAlFinal(4);
	miLista.insertarAlFinal(4);
	
	cout << "EL elemento se encuentra en " << miLista.buscarNodo(miLista.obtenerPrimeroPtr(), 4);
	
}

