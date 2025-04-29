#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class ArrayList : public List<E> {
private:
	E* elements;
	int max;
	int size;
	int pos;

	void resize(int newMax) {
		E* newElements = new E[newMax];
		for (int i = 0; i < size; i++)
			newElements[i] = elements[i];
		delete[] elements;
		elements = newElements;
		max = newMax;
	}

public:
	ArrayList(int max = DEFAULT_MAX) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		pos = size = 0;
		this->max = max;
	}

	~ArrayList() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max) // Al llenarse se hace un rezise
			resize(max * 2);

		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];

		elements[pos] = element;

		size++;
	}

	void append(E element) {
		if (size == max)
			throw runtime_error("List is full.");

		elements[size] = element;

		size++;
	}

	void next() {
		if (pos < size)
			pos++;
	}

	void previous() {
		if (pos > 0)
			pos--;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");

		E res = elements[pos];

		for (int i = pos; i < size; i++)
			elements[i] = elements[i + 1];
		size--;

		return res;
	}

	void clear() {
		pos = size = 0;
	}

	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");

		return elements[pos];
	}

	void goToStart() {
		pos = 0;
	}

	void goToEnd() {
		pos = size;
	}

	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of range.");
		this->pos = pos;
	}

	bool atStart() {
		return pos == 0;
	}

	bool atEnd() {
		return pos == size;
	}

	int getPos() {
		return pos;
	}

	int getSize() {
		return size;
	}

	void print() {

		cout << "[ ";

		for (int i = 0; i < size; i++) {
			if (i == pos)
				cout << "*";

			cout << elements[i] << " ";
		}

		if (pos == size)
			cout << "*";

		cout << "]" << endl;

	}

};

