
/*

	Descripción General:

	Nombre del archivo: PriorityQueue.h

	Descripción: 
	Esta es una interfaz para la Estructura de Datos PriorityQueue.
	Esta clase es una implementación de una cola de prioridad.
	Contiene métodos para insertar, eliminar y obtener elementos
	y realizar operaciones de gestión de prioridades en la cola pero siempre 
	manteniendo el orden de prioridad.

	Autor: Mauricio Avilés Cisneros

*/

#pragma once

template <typename E>
class PriorityQueue {
private:
	PriorityQueue(const PriorityQueue<E>& other) {}
	void operator = (const PriorityQueue<E>& other) {}

public:
	PriorityQueue() {}
	virtual ~PriorityQueue() {}

	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;
	virtual void print() = 0;
};
