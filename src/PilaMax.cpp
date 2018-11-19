/**
 * @file PilaMax.h
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 */

#include"VDG.h"

template <class T>
void PilaMax<T>::copiar(const PilaMax &copia) {
	if (copia.pila.dimension()!=0) {
		for (size_t i=0;i<pila.dimension();i++) {
			pila[i] = copia.pila[i];
			max[i] = copia.max[i];
		}
	}
}

template <class T>
PilaMax<T>::PilaMax(const PilaMax &copia) {
	copiar(copia);
}

template <class T>
PilaMax<T>::PilaMax(const T &t) {
	insertar(t);
}

template <class T>
T PilaMax<T>::verPila() {
	T aux = pila[pila.dimension()-1];
	return aux;
}

template <class T>
T PilaMax<T>::verMax() {
	T aux = max[max.dimension()-1];
	return aux;
}

template <class T>
size_t PilaMax<T>::verNumElementos() const {
	size_t aux = pila.dimension();
	return aux;
}

template <class T>
bool PilaMax<T>::insertar(const T &t) {
	int aux = 1;
	aux = pila.redimensionar(pila.dimension()+1);
	pila.asignar_componente(pila.dimension()-1,t);
	aux = max.redimensionar(max.dimension()+1);
	max.asignar_componente(max.dimension()-1,(t<verMax()?verMax():t));
	
	return aux==0?true:false;
}

template <class T>
bool PilaMax<T>::sacar() {
	int aux = 1;
	aux = pila.redimensionar(pila.dimension()-1);
	aux = max.redimensionar(max.dimension()-1);
	
	return aux==0?true:false;
}

template <class T>
bool PilaMax<T>::borrar(const int &n) {
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
