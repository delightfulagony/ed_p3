/**
 * @file PilaMax.h
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
	void copiar(const PilaMax &copia);
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
	 * @return Devuelve el último elemento de la pila
	 */
	T verPila() const;
	/**
	 * @brief Observador de max
	 * @return Valor max del último elemento de la pila
	 */
	T verMax() co
	nst;
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
	 bool borrar(const unsigned int &n=0);
	 /**
	  * @brief Comprueba si la pila es vacía
	  * @return 
	  * 	@retval true Si es vacía
	  *	@retval false Si no es vacía
	  */ 
	 bool esVacia() const;
	 /**
	  * @brief Sobrecarga del operador de asignacion
	  * @param pila La pila que se quiere asginar
	  * @return La pila con la asginacion realizada
	  */
	 PilaMax& operator=(const PilaMax<T> &pila);
};

#include"PilaMax.cpp"
#endif
