
/*

	Descripción General:

	Nombre del archivo: LinkedQueue.h

	Descripción: Esta es una implementación de la Estructura de Datos LinkedQueue.
	Esta clase es una implementación de una cola enlazada que almacena elementos de forma
	dinámica. Utiliza nodos que contienen un elemento y un puntero al siguiente nodo.

	Autor: Mauricio Avilés Cisneros

*/

#pragma once

#include <stdexcept>
#include <iostream>
#include "Queue.h"
#include "Node.h"

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedQueue : public Queue <E> {
private:
	Node<E>* front;
	Node<E>* back;
	int size;

public:
	LinkedQueue() {
		back = front = new Node<E>();
		size = 0;
	}
	~LinkedQueue() {
		clear();
		delete front; // Se vuela la memoria. Al estar el front y el back apuntando a la misma vara NO HAY QUE BORRAR DOS VECES LO MISMO.
	}

	void enqueue(E element) {
		back = back->next = new Node<E>(element);
		size++;
	}

	E dequeue() {

		if (size == 0)
			throw runtime_error("Queue is Empty.");

		E result = front->next->element;
		Node<E>* temp = front->next;
		front->next = temp->next;
		delete temp;
		if (size == 1)
			back = front;
		size--;
		return result;
	}

	E frontValue() {

		return front->next->element;

	}

	void clear() {

		while (front->next != nullptr) {

			back = front->next;
			front->next = back->next;
			delete back;

		}

		back = front;

		size = 0;

	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void print() {

		cout << "[ ";
		Node<E>* temp = front->next;
		while (temp != nullptr) {
			cout << temp->element << " ";
			temp = temp->next;
		}
		cout << "]" << endl;

	}

};

