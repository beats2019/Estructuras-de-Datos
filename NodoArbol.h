#ifndef NODOARBOL_H
#define NODOARBOL_H

template<typename TIPONODO> class Arbol;

template<typename TIPONODO>
class NodoArbol
{
	friend class Arbol<TIPONODO>;
public:
	NodoArbol(const TIPONODO& data)
		: izquierdoPtr(NULL),
		derechoPtr(NULL),
		datos(data)
	{}

	TIPONODO obtenerDatos()const
	{
		return datos;
	}

	bool estaNodoVacio()const
	{
		if (izquierdoPtr == NULL and derechoPtr == NULL)
			return true;
		else
			return false;
	}


private:
	NodoArbol<TIPONODO>* izquierdoPtr;
	NodoArbol<TIPONODO>* derechoPtr;
	TIPONODO datos;
};

#endif // !1