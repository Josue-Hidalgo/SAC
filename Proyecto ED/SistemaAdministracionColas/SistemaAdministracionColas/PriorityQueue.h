/*

	Descripci�n General: 

	Nombre del archivo: PriorityQueue.h

	Descripci�n: Interfaz de la clase PriorityQueue (clase abstracta), que define los m�todos
	que deben implementar las clases que hereden de ella. Esta clase es una implementaci�n de 
	una cola de prioridad.

	Autor: Mauricio Avil�s Cisneros

*/


#pragma once

template <typename E>
class PriorityQueue {
private:
	PriorityQueue(const PriorityQueue<E>& other) {}
	void operator =(const PriorityQueue<E>& other) {}

public:
	PriorityQueue() {}
	virtual ~PriorityQueue() {}
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};

