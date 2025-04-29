/*

	Descripción General:

	Nombre del archivo: KVPair.h

	Descripción: Implementación de una clase KVPair (par clave-valor) genérica.
	Esta clase es básicamente una tupla de dos elementos, donde el primero es 
	la clave de tipo K y el segundo es el valor de tipo V. 
	Se utiliza en la implementación de un HeapPriorityQueue (Cola de Prioridad) 
	La clase proporciona operadores de comparación.

	Autor: Mauricio Avilés Cisneros

*/

#pragma once
#include <iostream>

using std::ostream;

template <typename K, typename V>
class KVPair {
public:
	K key;
	V value;

	KVPair() {}
	KVPair(K key) {
		this->key = key;
	}
	KVPair(K key, V value) {
		this->key = key;
		this->value = value;
	}
	KVPair(const KVPair<K, V>& other) {
		key = other.key;
		value = other.value;
	}
	void operator =(const KVPair<K, V>& other) {
		key = other.key;
		value = other.value;
	}
	bool operator ==(const KVPair<K, V>& other) {
		return key == other.key;
	}
	bool operator !=(const KVPair<K, V>& other) {
		return key != other.key;
	}
	bool operator <(const KVPair<K, V>& other) {
		return key < other.key;
	}
	bool operator <=(const KVPair<K, V>& other) {
		return key <= other.key;
	}
	bool operator >(const KVPair<K, V>& other) {
		return key > other.key;
	}
	bool operator >=(const KVPair<K, V>& other) {
		return key >= other.key;
	}
};

template <typename K, typename V>
ostream& operator <<(ostream& os, const KVPair<K, V>& pair) {
	os << "(" << pair.key << ", " << pair.value << ")";
	return os;
}
