
/*

	Descripci�n General:

	Nombre del archivo: DNode.h

	Descripci�n: Implementaci�n de la Estructura de Datos DNode.
	Esta clase es una implementaci�n de un nodo doblemente enlazado.
	Lo utiliza una lista doblemente enlazada para almacenar elementos de
	forma din�mica. Cada nodo contiene un elemento y punteros al siguiente
	y anterior nodo.

	Autor: Mauricio Avil�s Cisneros

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

