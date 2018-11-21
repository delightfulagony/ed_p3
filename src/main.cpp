/**
 * @file main.cpp
 * @authors Manuel Gachs Ballegeer
 *	    Gonzalo Moreno Soto
 */

#include"PilaMax.h"
#include<iostream>

/**
 * @brief Muestra el menú del programa
 * @return La opción elegida por el usuario
 */
int menu();
/**
 * @brief Realiza la ejecución del programa de ejemplo
 * @param tipo Tipo de dato a usar en la pila
 *	       (1 = enteros, 2 = caracteres)
 */
void ejemploPilas(const size_t& tipo);

int main(){
	size_t opt = 0;
	do {
		opt = menu();
		switch (opt) {
			case 0:
				std::cout<<"Saliendo del programa...\n";
				break;
			case 1:
				std::cout<<"Ejemplo de uso de PilaMax con enteros:\n";
				ejemploPilas(opt);
				break;
			case 2:
				std::cout<<"Ejemplo de uso de PilaMax con caracteres:\n";
				ejemploPilas(opt);
				break;			
			default:
				std::cout<<"Error en la opcion elegida, pruebe de nuevo\n";
				break;
		}	
	} while (opt!=0);
	
	return 0;
}

int menu() {
	int aux = 0;
	std::cout<<".................MENU DEL PROGRAMA.................\n";
	std::cout<<"Lista de opciones:\n";
	std::cout<<"	0	Sale del programa\n";
	std::cout<<"	1	Realiza un ejemplo con numeros enteros\n";
	std::cout<<"	2	Realiza un ejemplo con caracteres\n";
	std::cout<<"...................................................\n";
	std::cout<<"Su opcion: ";
	std::cin>>aux;
	
	return aux;
}

void ejemploPilas(const size_t& tipo) {
	if (tipo==1) {
		std::cout<<"Se creara una pila con los numeros del intervalo [1-10]\n";
		PilaMax<int> pila;
		size_t aux = 1;
		bool correcto = true;
		for (size_t i=1;i<11;i++) {
			pila.insertar(i);
		}
			
		std::cout<<"\nLa pila tiene "<<pila.verNumElementos()<<" elementos\n";
		std::cout<<"El ultimo elemento de la pila es: "<<pila.verPila()<<std::endl;
		std::cout<<"El maximo de la pila es "<<pila.verMax()<<std::endl;
		
		std::cout<<"Elementos a borrar de la pila: ";
		std::cin>>aux;
		correcto = pila.borrar(aux);
		if (!correcto) {
			std::cout<<"Error en el borrado de elementos de la pila\n";
			return;
		}
		
		if (!pila.esVacia()) {
			std::cout<<"\nLa pila tiene "<<pila.verNumElementos()<<" elementos\n";
			std::cout<<"El ultimo elemento de la pila es: "<<pila.verPila()<<std::endl;
			std::cout<<"El maximo de la pila es "<<pila.verMax()<<std::endl;
		} else
			std::cout<<"La pila esta ahora vacia\n";
		
		std::cout<<"Introduce un numero en la pila: ";
		std::cin>>aux;
		correcto = pila.insertar(aux);
		if (!correcto) {
			std::cout<<"Error al insertar un elemento en la pila\n";
			return;
		}
		
		std::cout<<"\nLa pila tiene "<<pila.verNumElementos()<<" elementos\n";
		std::cout<<"El ultimo elemento de la pila es: "<<pila.verPila()<<std::endl;
		std::cout<<"El maximo de la pila es "<<pila.verMax()<<std::endl;
		
	} else if (tipo==2) {
		std::cout<<"Se creara una pila con los caracteres del intervalo [a-j]\n";
		PilaMax<char> pila;
		size_t aux = 1;
		char letra = 'a';
		bool correcto = true;
		for (char i='a';i<='j';i++) 
			pila.insertar(i);
			
		std::cout<<"\nLa pila tiene "<<pila.verNumElementos()<<" elementos\n";
		std::cout<<"El ultimo elemento de la pila es: "<<pila.verPila()<<std::endl;
		std::cout<<"El maximo de la pila es "<<pila.verMax()<<std::endl;
		
		std::cout<<"Elementos a borrar de la pila: ";
		std::cin>>aux;
		correcto = pila.borrar(aux);
		if (!correcto) {
			std::cout<<"Error en el borrado de elementos de la pila\n";
			return;
		}
		
		if (!pila.esVacia()) {
			std::cout<<"\nLa pila tiene "<<pila.verNumElementos()<<" elementos\n";
			std::cout<<"El ultimo elemento de la pila es: "<<pila.verPila()<<std::endl;
			std::cout<<"El maximo de la pila es "<<pila.verMax()<<std::endl;
		} else
			std::cout<<"La pila esta ahora vacia\n";
		
		std::cout<<"Introduce una letra en la pila: ";
		std::cin>>letra;
		correcto = pila.insertar(letra);
		if (!correcto) {
			std::cout<<"Error al insertar un elemento en la pila\n";
			return;
		}
		
		std::cout<<"\nLa pila tiene "<<pila.verNumElementos()<<" elementos\n";
		std::cout<<"El ultimo elemento de la pila es: "<<pila.verPila()<<std::endl;
		std::cout<<"El maximo de la pila es "<<pila.verMax()<<std::endl;	
		}
	
	return;
}
