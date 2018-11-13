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
T PilaMax::verPila() {
	return pila[pila.dimension()-1];
}

template <class T>
T PilaMax::verMax() {
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
bool PilaMax::borrar() {
	int aux = 1;
	aux = pila.redimensionar(0);
	aux = max.redimensionar(0);
		
	return aux==0?true:false;
}

template <class T>
bool PilaMax::esVacia() {
	return pila.dimension()==0?true:false;
}
