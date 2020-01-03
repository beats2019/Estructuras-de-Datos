#ifndef ARBOL_H
#define ARBOL_H

#include "NodoArbol.h"

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
private:
	NodoArbol<TIPONODO>* raizPtr;
	void ayudanteInsertarNodo(NodoArbol<TIPONODO>**, const TIPONODO&);
	void ayudantePreOrden(NodoArbol<TIPONODO>*) const;
	void ayudanteInOrden(NodoArbol<TIPONODO>*) const;
	void ayudantePostOrden(NodoArbol<TIPONODO>*) const;
	void ayudanteObtenerNivel(NodoArbol<TIPONODO>*,int&) const;
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
		else if(valor >= (*ptr)->datos)
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


#endif
