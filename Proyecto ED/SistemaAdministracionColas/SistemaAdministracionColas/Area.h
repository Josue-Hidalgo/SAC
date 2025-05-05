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
	string codigo;
	string nombre;
	string descripcion;
	int numeroVentanillas;
	ArrayList<Ventanilla>* listaVentanillas;
	HeapPriorityQueue<Tiquete>* colaTiquetes;

public:

	
	Area(string codigo, string nombre, string descripcion, int numeroVentanillas)
		: codigo(codigo), nombre(nombre), descripcion(descripcion), numeroVentanillas(numeroVentanillas) {
		listaVentanillas = new ArrayList<Ventanilla>(numeroVentanillas);
		for (int i = 1; i <= numeroVentanillas; i++)
			listaVentanillas->append(Ventanilla(nombre + to_string(i)));
	}

	~Area() {
		// Destructor
		delete[] listaVentanillas;
	}

	string getCodigo() const { return codigo; }
	
	string getNombre() const { return nombre; }
	
	string getDescripcion() const { return descripcion; }
	
	void setCodigo(string codigo) { this->codigo = codigo; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	
	void printQueueState() const {
		cout << "Nombre: " << nombre << codigo << endl;
		cout << "Número de ventanillas: " << numeroVentanillas << endl;
		
		for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next()) {
			Ventanilla ventanilla = listaVentanillas->getElement();
			cout << "Ventanilla " << ventanilla.getNombre() << ": " << ventanilla.getTiqueteAtendido() << endl;
			listaVentanillas->next();
		}
	}

	void print() const {
		cout << "Área: " << nombre << endl;
		cout << "Descripción: " << descripcion << endl;
	}
};

