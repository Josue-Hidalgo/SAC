
/*

	Descripción General:

	Nombre del archivo: Queue.h

	Descripción: Esta es una interfaz para la Estructura de Datos Queue.
	Esta clase es una implementación de una cola. Que funciona como una
	estructura de datos FIFO (First In First Out). 

	Autor: Mauricio Avilés Cisneros

*/

#pragma once

template <typename E>
class Queue {
private:
	Queue(const Queue<E>& other) {}
	void operator=(const Queue<E>& other) {}

public:

	Queue() {}
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual E frontValue() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;

};

