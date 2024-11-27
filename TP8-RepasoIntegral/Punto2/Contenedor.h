/*
 * CONTENEDOR.h
 *
 */

#ifndef CONTENEDOR_H_
#define CONTENEDOR_H_
#include <iostream>
using namespace std;

template <typename T>
class Iterador;

template <typename T>
class Contenedor{
	const  T indefinido;
	T *arreglo;
	int MAX;
	T* reservarMemoria(unsigned int tama);
	friend class Iterador<T>;
public:
		Contenedor(unsigned int dim, T indef);
		bool insertarElemento(T valor, int posicion);
		T  elemento(int posicion)const;
		bool eliminarElemento(int posicion);
		int capacidad() const;
		~Contenedor();
		
};

template <typename T>
T* Contenedor<T>::reservarMemoria(unsigned int tama){
	T *reserva = new T[tama];
	if(reserva==NULL){
		cout<<"Problema: no se pudo realizar la reserva";
	}
	return reserva;
}

template <typename T>
Contenedor<T>::Contenedor(unsigned int dim, T indef):indefinido(indef){
	this->MAX = dim;
	this->arreglo = reservarMemoria(this->MAX);
	if (this->arreglo ==NULL)
		this->MAX = 0;
	else
		for(int i=0;i<this->MAX;i++)
			this->arreglo[i]=this->indefinido;
}
template <typename T>
bool Contenedor<T>::insertarElemento(T valor, int posicion){
	bool resultado=  false;
	if(0<=posicion && posicion< this->MAX){
		this->arreglo[posicion] = valor;
		resultado =true;
	}
	return resultado;
}
template <typename T>
T  Contenedor<T>::elemento(int posicion)const{
	if(0<=posicion && posicion<this->MAX)
		return this->arreglo[posicion];
	else
		return this->indefinido;
}

template <typename T>
bool Contenedor<T>::eliminarElemento(int posicion){
	bool resultado = false;
	if(0<=posicion && posicion<this->MAX){
		this->arreglo[posicion]=this->indefinido;
		resultado = true;
	}
	return resultado;
}
template <typename T>
int Contenedor<T>::capacidad()const{
	return this->MAX;
}
template <typename T>
Contenedor<T>::~Contenedor(){
	this->MAX = 0;
	delete [] this->arreglo;
};


#endif /* CONTENEDOR_H_ */
