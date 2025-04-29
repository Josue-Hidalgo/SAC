/*
 * 
 * Nombre del archivo: TipoUsuario.h
 * 
 * Clase que representa un tipo de usuario en el sistema de administración de colas.
 * 
 * Descripción General:
 * Tipo de usuario que contiene información sobre el nombre, la descripción y la prioridad.
 * 
 * Autor: Josue Hidalgo
 * 
 */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

class TipoUsuario {
private:
	string nombre;
	string descripcion;
	int prioridad;

public:

	// Esta lista de inicialización de miembros es equivalente a:
	// this->nombre = nombre; y etc.
	TipoUsuario(string nombre, string descripcion, int prioridad) 
		: nombre(nombre), descripcion(descripcion), prioridad(prioridad) {}
	
	// const despues del nombre de la funcion indica que no se va a modificar el objeto
	string getNombre() const { return nombre; }
	
	string getDescripcion() const { return descripcion; }
	
	int getPrioridad() const { return prioridad; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	
	void setPrioridad(int prioridad) { this->prioridad = prioridad; }

	bool operator<(const TipoUsuario& otro) const {
		return this->prioridad < otro.prioridad;
	}

	void print() const {
		cout << "Tipo de Usuario: " << nombre << endl;
		cout << "Descripción: " << descripcion << endl;
		cout << "Prioridad: " << prioridad << endl;
	}
};

