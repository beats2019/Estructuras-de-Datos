#ifndef COLA_H
#define COLA_H

#include "Lista.h"
#include "Cliente.h"

template <typename TIPOCOLA>
class Cola : private Lista<TIPOCOLA>
{
public:
	void enqueue(const TIPOCOLA& datos)
	{
		Lista<TIPOCOLA>::insertarAlFinal(datos);
	}

	bool dequeue(TIPOCOLA& datos)
	{
		return Lista<TIPOCOLA>::eliminarDelFrente(datos);
	}

	bool estaColaVacia()const
	{
		return Lista<TIPOCOLA>::estaVacia();
	}

	void imprimirCola() const
	{
		Lista<TIPOCOLA>::imprimir();
	}
};

#endif // !1