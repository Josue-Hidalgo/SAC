
/*

	Descripción General:

	Nombre del archivo: DNode.h

	Descripción: Implementación de la Estructura de Datos DNode.
	Esta clase es una implementación de un nodo doblemente enlazado.
	Lo utiliza una lista doblemente enlazada para almacenar elementos de
	forma dinámica. Cada nodo contiene un elemento y punteros al siguiente
	y anterior nodo.

	Autor: Mauricio Avilés Cisneros

*/
#pragma once

template <typename E>
class DNode {
public:
	E element;
	DNode<E>* next;
	DNode<E>* previous;

	DNode(E element, DNode<E>* next, DNode<E>* previous) {
		this->element = element;
		this->next = next;
		this->previous = previous;
	}
	DNode(DNode<E>* next, DNode<E>* previous) {
		this->next = next;
		this->previous = previous;
	}
};

