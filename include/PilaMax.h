/**
 * @file PilaMax.h
 * @brief Fichero de cabecera del TDA PilaMax
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @date Noviembre 2018
 * @license GPLv3
 */

#include"VDG.h"

#ifndef _PILAMAX_H
#define _PILAMAX_H

/**
 * @brief T.D.A. PilaMax
 * Una instancia @e c del tipo de dato abstracto @c cronologia es un objeto
 * que representa una pila de datos junto con el valor maximo que se ha dado
 * en la pila
 * @author Manuel Gachs Ballegeer
 * @author Gonzalo Moreno Soto
 * @date Noviembre 2018
 */
template <class T>
class PilaMax {
private:
	unsigned int elementos; ///> Número de elementos de la pila
	VectorDinamico<T> pila; ///> Pila per-sé
	VectorDinamico<T> max; ///> Pila donde se guarda el máximo de la pila
	void copiar(const PilaMax &copia); ///> Copia una pila en otra
public:
	/**
	 * @brief Constructor por defecto
	 */
	PilaMax();
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
	T verPila() {return pila[elementos-1];}
	/**
	 * @brief Observador de max, con posibilidad de modificación
	 * @return Valor max del último elemento de la pila
	 */
	T verMax() {return max[elementos-1];}
	/**
	 * @brief Observador del número de elementos de la pila
	 * @return El número de elementos de la pila
	 */
	size_t verNumElementos() const {return elementos;}
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
	 bool borrar(const unsigned int &n=-1);
	 /**
	  * @brief Comprueba si la pila es vacía
	  * @return 
	  * 	@retval true Si es vacía
	  *	@retval false Si no es vacía
	  */ 
	 bool esVacia() const {return elementos==0?true:false;}
};

#include"PilaMax.cpp"
#endif
