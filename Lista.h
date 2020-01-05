
#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;

#include "NodoLista.h" // definición de la clase NodoLista
#include "Cliente.h"

template< typename TIPONODO >
class Lista
{
public:
	Lista(); // constructor
	~Lista(); // destructor
	void insertarAlFrente(const TIPONODO&);
	void insertarAlFinal(const TIPONODO&);
	bool eliminarDelFrente(TIPONODO&);
	bool eliminarDelFinal(TIPONODO&);
	bool estaVacia() const;
	void imprimir() const;
	void imprimirReves(NodoLista< TIPONODO >*) const;
	NodoLista< TIPONODO >* buscarNodo(NodoLista< TIPONODO >*, const int&) const;


	NodoLista< TIPONODO >* obtenerPrimeroPtr() const;
	NodoLista< TIPONODO >* obtenerUltimoPtr() const;
	void modificarUltimoPtr(NodoLista< TIPONODO >*);

private:
	NodoLista< TIPONODO >* primeroPtr; // apuntador al primer nodo
	NodoLista< TIPONODO >* ultimoPtr; // apuntador al último nodo
	NodoLista< TIPONODO >* obtenerNuevoNodo(const TIPONODO&);
};

template< typename TIPONODO >
Lista< TIPONODO >::Lista()
	: primeroPtr(0), ultimoPtr(0)
{}

// destructor
template< typename TIPONODO >
Lista< TIPONODO >::~Lista()
{

	if (!estaVacia()) 
	{
		NodoLista< TIPONODO >* actualPtr = primeroPtr;
		NodoLista< TIPONODO >* tempPtr;

		while (actualPtr != 0) // elimina los nodos restantes
		{
			tempPtr = actualPtr;
			//cout << tempPtr->datos << '\n';
			actualPtr = actualPtr->siguientePtr;
			delete tempPtr;
		} 
	} 
}

// inserta un nodo al frente de la lista
template< typename TIPONODO >
void Lista< TIPONODO >::insertarAlFrente(const TIPONODO& valor)
{
	NodoLista< TIPONODO >* nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

	if (estaVacia()) // la Lista está vacía
		primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
	else // la Lista no está vacía
	{
		nuevoPtr->siguientePtr = primeroPtr; // apunta el nuevo nodo al nodo que antes era
		primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
	} // fin de else
} // fin de la función insertarAlFrente

// inserta un nodo al final de la lista
template< typename TIPONODO >
void Lista< TIPONODO >::insertarAlFinal(const TIPONODO& valor)
{
	NodoLista< TIPONODO >* nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

	if (estaVacia()) // la Lista está vacía
		primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista sólo tiene un nodo
	else // la Lista no está vacía
	{
		ultimoPtr->siguientePtr = nuevoPtr; // actualiza el nodo que antes era el último
		ultimoPtr = nuevoPtr; // nuevo último nodo
	} // fin de else
} // fin de la función insertarAlFinal


template< typename TIPONODO >
bool Lista< TIPONODO >::eliminarDelFrente(TIPONODO& valor)
{
	if (estaVacia()) 
		return false;
	else
	{
		NodoLista< TIPONODO >* tempPtr = primeroPtr; 

		if (primeroPtr == ultimoPtr)
			primeroPtr = ultimoPtr = 0; 
		else
			primeroPtr = primeroPtr->siguientePtr; 

		valor = tempPtr->datos; 
		delete tempPtr; 
		return true; 
	} 
} 


template< typename TIPONODO >
bool Lista< TIPONODO >::eliminarDelFinal(TIPONODO& valor)
{
	if (estaVacia()) // la Lista está vacía
		return false; // la eliminación no tuvo éxito
	else
	{
		NodoLista< TIPONODO >* tempPtr = ultimoPtr; // contiene tempPtr a eliminar

		if (primeroPtr == ultimoPtr) // la Lista tiene un elemento
			primeroPtr = ultimoPtr = 0; // no hay nodos después de la eliminación
		else
		{
			NodoLista< TIPONODO >* actualPtr = primeroPtr;

			// localiza el penúltimo elemento
			while (actualPtr->siguientePtr != ultimoPtr)
				actualPtr = actualPtr->siguientePtr; // se desplaza al siguiente nodo

			ultimoPtr = actualPtr; // elimina el último nodo
			actualPtr->siguientePtr = 0; // ahora éste es el último nodo
		} // fin de else

		valor = tempPtr->datos; // devuelve el valor del nodo que antes era el último
		delete tempPtr; // reclama el nodo que antes era el último
		return true; // la eliminación tuvo éxito
	} // fin de else
} // fin de la función eliminarDelFinal


template< typename TIPONODO >
bool Lista< TIPONODO >::estaVacia() const
{
	return primeroPtr == 0;
} // fin de la función estaVacia

template< typename TIPONODO >
NodoLista< TIPONODO >* Lista< TIPONODO >::obtenerNuevoNodo(
	const TIPONODO& valor)
{
	return new NodoLista< TIPONODO >(valor);
}

template< typename TIPONODO >
void Lista< TIPONODO >::imprimir() const
{
	if (estaVacia()) // la Lista está vacía
	{
		cout << "La lista esta vacia\n\n";
		return;
	} // fin de if

	NodoLista< TIPONODO >* actualPtr = primeroPtr;
	

	cout << "Los elementos son: ";

	while (actualPtr != 0) // obtiene los datos del elemento
	{
		cout << actualPtr->datos << ' ';
		actualPtr = actualPtr->siguientePtr;
	} 

	cout << "\n\n";
}

template<typename TIPONODO>
inline void Lista<TIPONODO>::imprimirReves(NodoLista< TIPONODO >* nodoActual) const
{
	if (nodoActual->obtenerSiguientePtr() == NULL)
	{
		cout << nodoActual->obtenerDatos() << endl;
		return;
	}
	else
	{
		imprimirReves(nodoActual->obtenerSiguientePtr());
		cout << nodoActual->obtenerDatos() << endl;
	}
}

template< typename TIPONODO >
void Lista< TIPONODO >::modificarUltimoPtr(NodoLista< TIPONODO >* introducidoPtr)
{
	this->ultimoPtr = introducidoPtr;
}

template< typename TIPONODO >
NodoLista< TIPONODO >* Lista< TIPONODO >::obtenerPrimeroPtr() const
{
	return this->primeroPtr;
}

template<typename TIPONODO>
inline NodoLista<TIPONODO>* Lista<TIPONODO>::obtenerUltimoPtr() const
{
	return this->ultimoPtr;
}


template<typename TIPONODO>
inline NodoLista<TIPONODO>* Lista<TIPONODO>::buscarNodo(NodoLista<TIPONODO>* nodoActual, const int& clave) const
{
	if (nodoActual->obtenerDatos() == clave)
		return nodoActual;
	if (nodoActual->obtenerSiguientePtr() == NULL)
		return NULL;
	else
		return buscarNodo(nodoActual->obtenerSiguientePtr(), clave);
}



#endif