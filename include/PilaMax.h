/**
 * @file PilaMax.h
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 */

#include"VDG.h"

#ifndef _PILAMAX_H
#define _PILAMAX_H

template <class T>
class PilaMax {
private:
	VectorDinamico<T> pila;
	VectorDinamico<T> max;
	void copiar(const PilaMax &copia);
public:
	/**
	 * @brief Constructor por defecto
	 */
	PilaMax() {}
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
	~PilaMax() {}
	/**
	 * @brief Observador de la pila, con posibilidad de modificación
	 * @return Devuelve el último elemento de la pila
	 */
	T verPila();
	/**
	 * @brief Observador de max, con posibilidad de modificación
	 * @return Valor max del último elemento de la pila
	 */
	T verMax();
	/**
	 * @brief Observador del número de elementos de la pila
	 * @return El número de elementos de la pila
	 */
	size_t verNumElementos() const;
	/**
	 * @brief Añade un elemento a la pila
	 * @param t Elemento a añadir
	 * @return 
	 * 	@retval true Si ha tenido éxito 
	 * 	@retval false Si ha habido algun error
	 */
	bool insertar(const T &t);
	 /**
	  * @brief Saca un elemento de la pila
	  * @return 
	  * 	@retval true Si ha tenido éxito 
	  *	@retval false Si ha habido algun error
	  */
	 bool sacar();
	  /**
	  * @brief Borra la pila
	  * @param n Numero de elementos que se quieren borrar
	  * @return 
	  * 	@retval true Si ha tenido éxito 
	  *	@retval false Si ha habido algun error
	  */
	 bool borrar(const int &n=0);
	 /**
	  * @brief Comprueba si la pila es vacía
	  * @return 
	  * 	@retval true Si es vacía
	  *	@retval false Si no es vacía
	  */ 
	 bool esVacia() const {return pila.dimension()==0?true:false;}
};

#include"PilaMax.cpp"
#endif
