
/*

	Descripci�n General:

	Nombre del archivo: Node.h

	Descripci�n: Esta es una implementaci�n de la Estructura de Datos Node.
	Esta clase es una implementaci�n de un nodo el cual almacena un elemento
	y un puntero al siguiente nodo. Se utiliza en la implementaci�n de una 
	lista enlazada simple.

	Autor: Mauricio Avil�s Cisneros

*/

#pragma once

template <typename E>
class Node {
public:
	E element;
	Node<E>* next;

	// Puede haber problemas si se hace pilas de punteros. Pues los par�metros de sobrecarga deja ambiguo si es uno u otro.
	// Sobrecarga es colocar otro constructor para agregar o limitar par�metros.

	Node(E element, Node<E>* next = nullptr) {
		this->element = element;
		this->next = next;
	}

	Node(Node<E>* next = nullptr) : element(E()) {
		this->next = next;
	}

};
