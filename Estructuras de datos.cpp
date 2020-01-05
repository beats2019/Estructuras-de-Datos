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
	miArbol.insertarNodo(10);
	miArbol.insertarNodo(5);
	miArbol.insertarNodo(15);
	/*
	miArbol.insertarNodo(3);
	miArbol.insertarNodo(24);
	miArbol.insertarNodo(18);
	miArbol.insertarNodo(31);
	miArbol.insertarNodo(35);
	miArbol.insertarNodo(29);
	miArbol.insertarNodo(24);
	miArbol.insertarNodo(27);*/

	miArbol.eliminarNodo(10);
	miArbol.recorridoInOrden();
	
	
	
}