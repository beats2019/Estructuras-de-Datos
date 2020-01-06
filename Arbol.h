#ifndef ARBOL_H
#define ARBOL_H

#include "NodoArbol.h"
#include "Cola.h"


template<typename TIPONODO>
class Arbol
{
public:
	Arbol();
	void insertarNodo(const TIPONODO&);
	void recorridoPreOrden() const;
	void recorridoInOrden() const;
	void recorridoPostOrden() const;
	NodoArbol<TIPONODO>* obtenerRaiz() const;
	int obtenerNivel()const;
	void eliminarNodo(const int&);
	void imprimirRecorridoNivel() const;

private:
	NodoArbol<TIPONODO>* raizPtr;
	void ayudanteInsertarNodo(NodoArbol<TIPONODO>**, const TIPONODO&);
	void ayudantePreOrden(NodoArbol<TIPONODO>*) const;
	void ayudanteInOrden(NodoArbol<TIPONODO>*) const;
	void ayudantePostOrden(NodoArbol<TIPONODO>*) const;
	void ayudanteObtenerNivel(NodoArbol<TIPONODO>*, int&) const;
	NodoArbol< TIPONODO >* buscarNodo(NodoArbol< TIPONODO >*, const int&) const;

};

template<typename TIPONODO>
Arbol<TIPONODO>::Arbol()
{
	raizPtr = nullptr;
}

template<typename TIPONODO>
void Arbol<TIPONODO>::insertarNodo(const TIPONODO& valor)
{
	ayudanteInsertarNodo(&raizPtr, valor);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInsertarNodo(NodoArbol<TIPONODO>** ptr, const TIPONODO& valor)
{
	if (*ptr == 0)
		*ptr = new NodoArbol<TIPONODO>(valor);
	else
	{
		if (valor < (*ptr)->datos)
			ayudanteInsertarNodo(&(*ptr)->izquierdoPtr, valor);
		else if (valor >= (*ptr)->datos)
			ayudanteInsertarNodo(&(*ptr)->derechoPtr, valor);
	}
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoPreOrden() const
{
	ayudantePreOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoInOrden() const
{
	ayudanteInOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoPostOrden() const
{
	ayudantePostOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInOrden(NodoArbol<TIPONODO>* ptr) const
{
	if (ptr != nullptr)
	{
		ayudanteInOrden(ptr->izquierdoPtr);
		cout << ptr->datos << ' ';
		ayudanteInOrden(ptr->derechoPtr);
	}

}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudantePreOrden(NodoArbol<TIPONODO>* ptr) const
{
	if (ptr != nullptr)
	{
		cout << ptr->datos << ' ';
		ayudantePreOrden(ptr->izquierdoPtr);
		ayudantePreOrden(ptr->derechoPtr);
	}
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudantePostOrden(NodoArbol<TIPONODO>* ptr) const
{
	if (ptr != nullptr)
	{
		ayudantePostOrden(ptr->izquierdoPtr);
		ayudantePostOrden(ptr->derechoPtr);
		cout << ptr->datos << ' ';
	}
}

template<typename TIPONODO>
inline NodoArbol<TIPONODO>* Arbol<TIPONODO>::obtenerRaiz() const
{
	return raizPtr;
}

template<typename TIPONODO>
inline int Arbol<TIPONODO>::obtenerNivel() const
{
	int nivel = 0;
	ayudanteObtenerNivel(raizPtr, nivel);
	return nivel;
}

template<typename TIPONODO>
inline void Arbol<TIPONODO>::ayudanteObtenerNivel(NodoArbol<TIPONODO>* nodoBasePtr, int& nivelActual) const
{
	int subIzq = 0;
	int subDer = 0;
	if (nodoBasePtr->estaNodoVacio())
		return;
	else
	{
		if (nodoBasePtr->derechoPtr != NULL)
		{
			ayudanteObtenerNivel(nodoBasePtr->derechoPtr, ++nivelActual);
			subDer = nivelActual;
		}
		nivelActual = 0;
		if (nodoBasePtr->izquierdoPtr != NULL)
		{
			ayudanteObtenerNivel(nodoBasePtr->izquierdoPtr, ++nivelActual);
			subIzq = nivelActual;
		}

	}
	nivelActual = (subDer > subIzq ? subDer : subIzq);

}

template<typename TIPONODO>
inline NodoArbol<TIPONODO>* Arbol<TIPONODO>::buscarNodo(NodoArbol<TIPONODO>* nodoActual, const int& clave) const
{
	NodoArbol<TIPONODO>* a = NULL;
	NodoArbol<TIPONODO>* b = NULL;
	if (nodoActual->datos == clave)
		return nodoActual;
	if (nodoActual->izquierdoPtr == NULL and nodoActual->derechoPtr == NULL)
		return NULL;
	else
	{
		if (nodoActual->izquierdoPtr != NULL)
			a = buscarNodo(nodoActual->izquierdoPtr, clave);
		if (nodoActual->derechoPtr != NULL)
			b = buscarNodo(nodoActual->derechoPtr, clave);
	}
	if (a == NULL and b == NULL)
		return NULL;
	else
		return (a != NULL ? a : b);
}

template<typename TIPONODO>
inline void Arbol<TIPONODO>::eliminarNodo(const int& dataNodo)
{
	NodoArbol<TIPONODO>* base = buscarNodo(this->raizPtr, dataNodo);
	if (base == NULL)
		cout << "El nodo que intentaste eliminar no existe" << endl;
	else
	{
		NodoArbol<TIPONODO>* padre = base;
		NodoArbol<TIPONODO>* hijo = base;

		hijo = base->derechoPtr;
		while (hijo->izquierdoPtr != NULL)
		{
			padre = hijo;
			hijo = hijo->izquierdoPtr;
		}
		base->datos = hijo->datos; //Se genera el duplicado

		if (padre->derechoPtr == hijo) // El arbol tiene nivel 1
		{
			if (hijo->estaNodoVacio())
			{
				padre->derechoPtr = NULL;
				hijo->CommitSuicide();
			}
			else
			{
				padre->derechoPtr = hijo->derechoPtr;
				hijo->CommitSuicide();
			}
		}
		else if (hijo->estaNodoVacio()) //Nodo hoja
		{
			padre->izquierdoPtr = NULL;
			hijo->CommitSuicide();
		}
		else //Con un hijo derecho
		{
			padre->izquierdoPtr = hijo->derechoPtr;
			hijo->CommitSuicide();
		}

	}
}

template<typename TIPONODO>
inline void Arbol<TIPONODO>::imprimirRecorridoNivel() const
{
	Cola<NodoArbol<TIPONODO>*> miCola;
	NodoArbol<TIPONODO>* nodoActual = NULL;
	
	miCola.enqueue(raizPtr);
	while (!miCola.estaColaVacia())
	{
		miCola.dequeue(nodoActual);
		cout << nodoActual->datos << " ";
		if (nodoActual->izquierdoPtr != NULL)
			miCola.enqueue(nodoActual->izquierdoPtr);
		if (nodoActual->derechoPtr != NULL)
			miCola.enqueue(nodoActual->derechoPtr);
	}
}





#endif
