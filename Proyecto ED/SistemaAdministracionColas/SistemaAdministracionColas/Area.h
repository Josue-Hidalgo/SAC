
/*

	Descripción General:

	Nombre del archivo: Area.h

	Descripción: Esta es una implementación de la clase Area.
	Es donde se almacenan los datos de cada área del sistema.
	Area es una clase que representa un área en donde se formará 
	una cola de los tiquetes. 

	Autor: Mauricio Avilés Cisneros

*/

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
using std::to_string;
using std::runtime_error;

class Area {
private:
	/*
	// Asignación
	void operator=(const Area& other) {
		if (this != &other) {
			codigo = other.codigo;
			nombre = other.nombre;
			descripcion = other.descripcion;
			numeroVentanillas = other.numeroVentanillas;
			delete listaVentanillas;
			listaVentanillas = new ArrayList<Ventanilla>(*other.listaVentanillas);
			if (colaTiquetes)
				delete colaTiquetes;
			colaTiquetes = other.colaTiquetes ? new HeapPriorityQueue<Tiquete>(*other.colaTiquetes) : nullptr;
		}
	}

	// Constructor de copia
	Area(const Area& other)
		: codigo(other.codigo), nombre(other.nombre), descripcion(other.descripcion), numeroVentanillas(other.numeroVentanillas) {
		listaVentanillas = new ArrayList<Ventanilla>(*other.listaVentanillas);
		colaTiquetes = other.colaTiquetes ? new HeapPriorityQueue<Tiquete>(*other.colaTiquetes) : nullptr;
	}
	*/

	string codigo;
	string nombre;
	string descripcion;
	int numeroVentanillas;
	ArrayList<Ventanilla>* listaVentanillas;
	HeapPriorityQueue<Tiquete>* colaTiquetes;

public:

	Area()
		: codigo(""), nombre(""), descripcion(""), numeroVentanillas(1) {
		listaVentanillas = new ArrayList<Ventanilla>(1); // Inicializa con tamaño 0
		colaTiquetes = nullptr; // Inicializa como nullptr ya que no hay cola
	}

	Area(string codigo, string nombre, string descripcion, int numeroVentanillas)
		: codigo(codigo), nombre(nombre), descripcion(descripcion), numeroVentanillas(numeroVentanillas), colaTiquetes(nullptr) {
		
		listaVentanillas = new ArrayList<Ventanilla>(numeroVentanillas);
		for (int i = 1; i <= numeroVentanillas; i++)
			listaVentanillas->append(Ventanilla(nombre + to_string(i)));
	
	}

	~Area() {
		delete listaVentanillas;
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

	friend 
};

