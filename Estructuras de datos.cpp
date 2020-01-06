#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "Lista.h"
#include "NodoArbol.h"
#include "Arbol.h"



int main()
{
	Arbol<int> miArbol;
	Cola<NodoArbol<int>> miCola;

	miArbol.insertarNodo(10);
	miArbol.insertarNodo(15);
	miArbol.insertarNodo(5);
	miArbol.insertarNodo(7);
	miArbol.insertarNodo(1);
	

	miArbol.imprimirRecorridoNivel();


}