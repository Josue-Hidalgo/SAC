/*

	Descripci�n General:

	Nombre del archivo: SortedArrayList.h

	Descripci�n: Clase que implementa una lista ordenada utilizando herencia
    especializando la clase ArrayList.

	Autor: Mauricio Avil�s Cisneros // Josue Hidalgo

*/

#pragma once
#include "ArrayList.h"
#include "Definiciones.h"

template <typename E>
class SortedArrayList : public ArrayList<E> {
public:
	
	SortedArrayList(int max = DEFAULT_MAX) : ArrayList<E>(max) {}
	
	void insert(E element) {
		ArrayList<E>::goToStart();
		while (!ArrayList<E>::atEnd() && element > ArrayList<E>::getElement())
			ArrayList<E>::next();
		ArrayList<E>::insert(element);
	}
	
	void append(E element) {
		insert(element);
	}
};

