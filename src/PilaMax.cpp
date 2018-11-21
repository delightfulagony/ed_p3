/**
 * @file PilaMax.h
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 */

#include"VDG.h"

template <class T>
void PilaMax<T>::copiar(const PilaMax &copia) {
	if (copia.elementos!=0) {
		elementos = copia.elementos;
		pila.redimensionar(elementos);
		max.redimensionar(elementos);
		for (size_t i=0;i<pila.elementos();i++) {
			pila[i] = copia.pila[i];
			max[i] = copia.max[i];
		}
	}
}

template <class T>
PilaMax<T>::PilaMax() {
	elementos = 0;
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
bool PilaMax<T>::insertar(const T &t) {
	int aux = 1;
	T maximo;
	if (elementos>=0) {
		aux = pila.redimensionar(elementos+1);
		aux = max.redimensionar(elementos+1);
		elementos++;
		
		if (elementos==1)
			maximo = t;
		else
			maximo = t>=verMax()?t:verMax();		
		pila.asignar_componente(elementos-1,t);
		max.asignar_componente(elementos-1,maximo);
	}
	
	return aux==0?true:false;
}

template <class T>
bool PilaMax<T>::sacar() {	
	int aux = 1;
	if (elementos>0) {
		aux = pila.redimensionar(elementos-1);
		aux = max.redimensionar(elementos-1);
		elementos--;
	}
	
	return aux==0?true:false;
}

template <class T>
bool PilaMax<T>::borrar(const unsigned int &n) {
	int aux = 1;
	if (elementos>0 && n>=0) {
		if (n<elementos) {
			aux = pila.redimensionar(elementos-n);
			aux = max.redimensionar(elementos-n);
		} else {
			aux = pila.redimensionar(0);
			aux = pila.redimensionar(0);
		}
		elementos -= n;
	}
	return aux==0?true:false;
}
