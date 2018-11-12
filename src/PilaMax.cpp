/**
 * @file PilaMax.h
 * @author Gonzalo Moreno Soto
 * @author Manuel Gachs Ballegeer
 */

template <class T>
PilaMax::PilaMax(const PilaMax &copia) {
	pila = copia.pila;
	max = copia.max;
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
PilaMax::T verPila() {
	return pila[pila.dimension()-1];
}

template <class T>
PilaMax::T verMax() {
	return max[max.dimension()-1];
}

template <class T>
PilaMax::insertar(const T &t) {
	pila.redimensionar(pila.dimension()+1);
	pila.asignar_componente(pila.dimension-1,t);
	max.redimensionar(max.dimension()+1);
	max.asignar_componente(max.dimension()-1,(t<verMax()?verMax:t));
}

