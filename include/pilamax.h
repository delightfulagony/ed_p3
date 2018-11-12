/**
 * @file pilamax.h
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 */

#ifndef _PILAMAX_H
#define _PILAMAX_H

template <class T>
class PilaMax {
private:
	VectorDinamico<T> pila;
	VectorDinamico<T> max;
public:
	// PilaMax() {}
	/** 
	 * @brief Constructor por copia
	 * @param copia PilaMax que se copia
	 */
	PilaMax(const PilaMax &copia);
	/**
	 * @brief Constructor por parametros
	 * @param t Primer valor de la pila
	 */
	PilaMax(const T &t);
	/**
	 * @brief Destructor de la clase
	 */
	~PilaMax();
	/**
	 * @brief Observador de la pila
	 * @return Devuelve el ultimo elemento de la pila
	 */
	T verPila();
	/**
	 * @brief Observador de max
	 * @return Valor max del ultimo elemento de la pila
	 */
	 T verMax();
	 /**
	  * @brief Añade un elemento a la pila
	  * @param t Elemento a añadir
	  * @return 
	  * 	@retval true Si ha tenido exito 
	  *	@retval false Si ha habido algun error
	  */
	 bool insertar(const T &t);
	 /**
	  * @brief Saca un elemento de la pila
	  * @return 
	  * 	@retval true Si ha tenido exito 
	  *	@retval false Si ha habido algun error
	  */
	 bool sacar();
	  /**
	  * @brief Borra la pila
	  * @return 
	  * 	@retval true Si ha tenido exito 
	  *	@retval false Si ha habido algun error
	  */
	 bool borrar();
	 /**
	  * @brief Comprueba si la pila es vacia
	  * @return 
	  * 	@retval true Si es vacia
	  *	@retval false Si no es vacia
	  */ 
	 bool esVacia();
};

#include"pilamax.cpp"
#endif
