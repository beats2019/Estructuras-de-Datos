#ifndef NODODOBLE_H
#define NODODOBLE_H

template< typename TIPONODO > class ListaDoble;

template< typename TIPONODO >
class NodoDoble
{
	friend class ListaDoble< TIPONODO >; 

public:
	NodoDoble(const TIPONODO&); 
	TIPONODO obtenerDatos() const; 
	NodoDoble< TIPONODO >* obtenerSiguientePtr() const;
	NodoDoble< TIPONODO >* obtenerAnteriorPtr() const;

private:
	NodoDoble< TIPONODO >* siguientePtr; 
	NodoDoble< TIPONODO >* anteriorPtr;
	TIPONODO datos; 
}; 


template< typename TIPONODO >
NodoDoble< TIPONODO >::NodoDoble(const TIPONODO& info)
	: datos(info), siguientePtr(0), anteriorPtr(0)
{}


template< typename TIPONODO >
TIPONODO NodoDoble< TIPONODO >::obtenerDatos() const
{
	return datos;
}

template<typename TIPONODO>
inline NodoDoble<TIPONODO>* NodoDoble<TIPONODO>::obtenerSiguientePtr() const
{
	return this->siguientePtr;
}

template<typename TIPONODO>
inline NodoDoble<TIPONODO>* NodoDoble<TIPONODO>::obtenerAnteriorPtr() const
{
	return this->anteriorPtr;
}

#endif // !1