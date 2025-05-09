/*
 * Descripción General:
 *
 * Nombre del archivo: Ventanilla.h
 *
 * Clase que representa una Ventanilla en el sistema de administración de colas.
 *
 * Ventanilla que contiene información sobre el nombre, el tiquete actual y la disponibilidad.
 * Este objeto se utiliza para gestionar la atención de los usuarios en el sistema y el tiempo 
 * que tarda en atender a cada uno de ellos. Una vez que se llega a la ventanilla se asigna un tiquete.
 *
 * Autor: Josue Hidalgo
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Tiquete.h"
#include "Ventanilla.h"

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

class Ventanilla {
private:
   string nombre;
   string tiqueteActual;
   bool disponible;

public:

	// Constructor de copia
	Ventanilla(const Ventanilla& other)
		: nombre(other.nombre),
		tiqueteActual(other.tiqueteActual),
		disponible(other.disponible) {}

	Ventanilla() : nombre("Ventanilla sin nombre"), tiqueteActual("No se ha atendido a ninguno."), disponible(true) {}

	Ventanilla(string nombre) : nombre(nombre), tiqueteActual("No se ha atendido a ninguno."), disponible(true) {}

	string getNombre() const { return nombre; }
   
	string getTiqueteActual() const { return tiqueteActual; }
   
	void setNombre(string nombre) { this->nombre = nombre; }
   
	void setTiqueteAtendido(string tiqueteActual) { 
		if (!estaDisponible())
			throw runtime_error("Ventanilla no disponible.");
		this->tiqueteActual = tiqueteActual; 
		disponible = false;
	}

	void liberarVentanilla() {
		tiqueteActual = "";
		disponible = true;
	}

	bool estaDisponible() const { return disponible; }

	void print() const {
		cout << "Ventanilla: " << nombre << endl;
		cout << "Último tiquete atendido: " << tiqueteActual << endl;
	}

	//Asignación
	Ventanilla& operator=(const Ventanilla& other) {
		if (this != &other) {
			nombre = other.nombre;
			tiqueteActual = other.tiqueteActual;
			disponible = other.disponible;
		}
		return *this;
	}
};
