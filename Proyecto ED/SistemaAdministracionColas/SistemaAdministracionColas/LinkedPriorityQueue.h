
/*

	Descripción General:

	Nombre del archivo: LinkedPriorityQueue.h

	Descripción: Esta es una implementación de una cola de prioridad
	que utiliza una lista enlazada para almacenar los elementos y un arreglo
	para gestionar las prioridades. La clase permite insertar elementos
	y asignarles una prioridad, así como eliminar el elemento de mayor
	prioridad. 

	Autor: Josue Hidalgo Sandoval (Tarea#2)

*/

#pragma once

#include <stdexcept>
#include <iostream>
#include "LinkedQueue.h"
#include "PriorityQueue.h"

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue<E> {
private:
	LinkedQueue<E>* queues;
	int priorities;
	int size;

public:

	LinkedPriorityQueue(int priorities) {
		if (priorities <= 0)
			throw runtime_error("Number of priorities must be positive.");
		queues = new LinkedQueue<E>[priorities];
		this->priorities = priorities;
		size = 0;
	}

	~LinkedPriorityQueue() {
		clear();
		delete[] queues;
	}

	void insert(E element, int priority) {
		if (priorities < priority || priority < 0)
			throw runtime_error("Invalid Priority.");
		queues[priority].enqueue(element);
		size++;
	}

	E min() {
		if (size == 0)
			throw runtime_error("Priority Queue is Empty.");
		int i = 0;
		while (queues[i].isEmpty())
			i++;
		return queues[i].frontValue();
	}

	E removeMin() {
		if (size == 0)
			throw runtime_error("Priority Queue is Empty.");
		int i = 0;
		while (queues[i].isEmpty())
			i++;
		size--;
		return queues[i].dequeue();
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void clear() {
		for (int i = 0; i < priorities; i++)
			queues[i].clear();
		size = 0;
	}

	void print() {
		for (int i = 0; i < priorities; i++) {
			cout << i << ":";
			queues[i].print();
			cout << endl;
		}
	}
};
