#ifndef PILA_H
#define PILA_H

#include "Lista.h"

template <typename TIPOPILA>
class Pila : private Lista<TIPOPILA>
{
public:
	void push(const TIPOPILA& datos)
	{
		Lista<TIPOPILA>::insertarAlFrente(datos);
	}
	
	bool pop(TIPOPILA& datos)
	{
		return Lista<TIPOPILA>::eliminarDelFrente(datos);
	}
	
	bool estaPilaVacia() const
	{
		return Lista<TIPOPILA>::estaVacia();
	}

	void imprimirPila() const
	{
		this->imprimir();
	}

	NodoLista<TIPOPILA>* obtenerPrimeroPtr() const

	{
		return Lista<TIPOPILA>::obtenerPrimeroPtr();
	}
	
};

#endif // !1