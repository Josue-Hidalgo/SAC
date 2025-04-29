#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "HeapPriorityQueue.h"
#include "Tiquete.h"
#include "Ventanilla.h"
#include "ArrayList.h"

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

template <typename E>
class Area {
private:
	string codigo;
	string nombre;
	string descripcion;
	int numeroVentanillas;
	ArrayList<Ventanilla> listaVentanillas;
	HeapPriorityQueue<Tiquete> colaTiquetes;

public:
	Area(string codigo, string nombre, string descripcion)
		: codigo(codigo), nombre(nombre), descripcion(descripcion) {
	}

	string getCodigo() const { return codigo; }
	
	string getNombre() const { return nombre; }
	
	string getDescripcion() const { return descripcion; }
	
	void setCodigo(string codigo) { this->codigo = codigo; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	
	void print() const {
		cout << "Área: " << nombre << endl;
		cout << "Descripción: " << descripcion << endl;
	}
};

