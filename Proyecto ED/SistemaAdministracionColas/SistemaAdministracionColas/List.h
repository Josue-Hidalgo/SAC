

/*

	Descripción General:

	Nombre del archivo: List.h

	Descripción: Esta es una interfaz para la Estructura de Datos List.
	Esta clase es una implementación de una lista. 
	Contiene métodos para insertar, eliminar, obtener elementos y
	realizar operaciones de navegación en la lista.

	Autor: Mauricio Avilés Cisneros

*/

#pragma once

template <typename E>
class List {
private:
	List(const List<E>& other) {}
	void operator =(const List<E>& other) {}

public:
	List() {}
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual E remove() = 0;
	virtual E getElement() = 0;
	virtual void clear() = 0;
	virtual void goToStart() = 0;
	virtual void goToEnd() = 0;
	virtual void goToPos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool atStart() = 0;
	virtual bool atEnd() = 0;
	virtual int getPos() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;

};