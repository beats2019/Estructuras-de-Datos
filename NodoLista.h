//TODO Nueva clase nodo enlace doble (agregar un apuntador al nodo anterior)
//TODO Nueva clase lista enlace doble(agregar apuntador al último nodo)

#include "Cliente.h"

#ifndef NODOLISTA_H
#define NODOLISTA_H

template< typename TIPONODO > class Lista;

template< typename TIPONODO >
class NodoLista
{
	friend class Lista< TIPONODO >; // hace de Lista una amiga

public:
	NodoLista(const TIPONODO&); // constructor
	TIPONODO obtenerDatos() const; // devuelve los datos en el nodo
	NodoLista< TIPONODO >* obtenerSiguientePtr() const;

private:
	NodoLista< TIPONODO >* siguientePtr; 
	TIPONODO datos; // datos
}; // fin de la clase NodoLista

// constructor
template< typename TIPONODO >
NodoLista< TIPONODO >::NodoLista(const TIPONODO& info)
	: datos(info), siguientePtr(0)
{}

// devuelve una copia de los datos en el nodo
template< typename TIPONODO >
TIPONODO NodoLista< TIPONODO >::obtenerDatos() const
{
	return datos;
} // fin de la función obtenerDatos

template<typename TIPONODO>
inline NodoLista<TIPONODO>* NodoLista<TIPONODO>::obtenerSiguientePtr() const
{
	return this->siguientePtr;
}

#endif

