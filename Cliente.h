#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente
{
public:
	Cliente()
	{
		this->tiempoAtencion = rand() % (4 - 1 + 1) + 1;
	}

	Cliente(int hora)
	{
		this->tiempoAtencion = hora;
	}
	
	void reducirTiempo()
	{
		this->tiempoAtencion--;
	}
	
	int obtenerTiempoAtencion()const
	{
		return this->tiempoAtencion;
	}
		
	void operator =(const Cliente& clienteParaCopiar)
	{
		Cliente clienteFinal;
		this->tiempoAtencion = clienteParaCopiar.obtenerTiempoAtencion();
	}
private:
	int tiempoAtencion;
};
#endif // !Cliente_h

