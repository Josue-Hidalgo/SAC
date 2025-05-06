
/*

	Descripción General:

	Nombre del archivo: Node.h

	Descripción: Esta es una implementación de la Estructura de Datos Node.
	Esta clase es una implementación de un nodo el cual almacena un elemento
	y un puntero al siguiente nodo. Se utiliza en la implementación de una 
	lista enlazada simple.

	Autor: Mauricio Avilés Cisneros

*/

#pragma once

template <typename E>
class Node {
public:
	E element;
	Node<E>* next;

	// Puede haber problemas si se hace pilas de punteros. Pues los parámetros de sobrecarga deja ambiguo si es uno u otro.
	// Sobrecarga es colocar otro constructor para agregar o limitar parámetros.

	Node(E element, Node<E>* next = nullptr) {
		this->element = element;
		this->next = next;
	}

	Node(Node<E>* next = nullptr) : element(E()) {
		this->next = next;
	}

};
