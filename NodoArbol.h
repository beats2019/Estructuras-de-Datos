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
	void CommitSuicide()
	{
		delete this;
	}
	TIPONODO obtenerDatos()const
	{
		return datos;
	}

	bool estaNodoVacio()const
	{
		return (izquierdoPtr == NULL and derechoPtr == NULL);
	}


private:
	NodoArbol<TIPONODO>* izquierdoPtr;
	NodoArbol<TIPONODO>* derechoPtr;
	TIPONODO datos;
};

#endif // !1