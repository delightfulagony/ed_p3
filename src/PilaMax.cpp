/**
 * @file PilaMax.h
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 */

#include"VDG.h"

template <class T>
void PilaMax::copiar(const PilaMax &copia) {
	if (copia.pila.dimension()!=0) {
		for (size_t i=0;i<pila.dimension();i++) {
			pila[i] = copia.pila[i];
			max[i] = copia.max[i]
		}
	}
}

template <class T>
PilaMax::PilaMax(const PilaMax &copia) {
	copiar(copia);
}

template <class T>
PilaMax::PilaMax(const T &t) {
	insertar(t);
}

template <class T>
PilaMax::~PilaMax() {
	pila.redimensionar(0);
	max.redimensionar(0);
}

template <class T>
T PilaMax::verPila() const {
	return pila[pila.dimension()-1];
}

template <class T>
T PilaMax::verMax() const {
	return max[max.dimension()-1];
}

template <class T>
bool PilaMax::insertar(const T &t) {
	int aux = 1;
	aux = pila.redimensionar(pila.dimension()+1);
	pila.asignar_componente(pila.dimension-1,t);
	aux = max.redimensionar(max.dimension()+1);
	max.asignar_componente(max.dimension()-1,(t<verMax()?verMax:t));
	
	return aux==0?true:false;
}

template <class T>
bool PilaMax::sacar() {
	int aux = 1;
	aux = pila.redimensionar(pila.dimension()-1);
	aux = max.redimensionar(max.dimension()-1);
	
	return aux==0?true:false;
}

template <class T>
bool PilaMax::borrar(const unsigned int &n) {
	int aux = 1;
	if (n>0 && n<pila.dimension()) {
		aux = pila.redimensionar(n);
		aux = max.redimensionar(n);
	} else {
		aux = pila.redimensionar(0);
		aux = max.redimensionar(0);
	}
	return aux==0?true:false;
}

template <class T>
bool PilaMax::esVacia() const {
	return pila.dimension()==0?true:false;
}

template <class T>
PilaMax& operator=(const PilaMax<T> &pila) {
	if (*this!=pila)
		copiar(pila);
	return *this;
}
