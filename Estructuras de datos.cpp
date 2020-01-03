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
	miLista.insertarAlFinal(5);
	miLista.insertarAlFinal(6);
	miLista.insertarAlFinal(7);
	miLista.insertarAlFinal(8);
	miLista.insertarAlFinal(9);
	miLista.insertarAlFinal(10);
	miLista.insertarAlFinal(11);
	miLista.imprimirReves(miLista.obtenerPrimeroPtr());
}





