/*
 * Descripción General:
 * 
 * Nombre del archivo: TipoUsuario.h
 * 
 * Clase que representa un tipo de usuario en el sistema de administración de colas.
 * 
 * Tipo de usuario que contiene información sobre el nombre, la descripción y la prioridad.
 * Además, proporciona métodos para la manipulación de estos atributos, así como para imprimir los detalles.
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
using std::ostream;
using std::runtime_error;

class TipoUsuario {
private:
	string nombre;
	string descripcion;
	int prioridad;

public:
	TipoUsuario() : nombre(""), descripcion(""), prioridad(0) {}

	// Esta lista de inicialización de miembros es equivalente a:
	// this->nombre = nombre; y etc. Nada más que utilizando el constructor
	TipoUsuario(string nombre, string descripcion, int prioridad) 
		: nombre(nombre), descripcion(descripcion), prioridad(prioridad) {}
	
	string getNombre() const { return nombre; }
	
	string getDescripcion() const { return descripcion; }
	
	int getPrioridad() const { return prioridad; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	
	void setPrioridad(int prioridad) { 
		if (prioridad < 0) 
			throw runtime_error("La prioridad no puede ser negativa.");
		this->prioridad = prioridad; 
	}

	void print() const {
		cout << "Tipo de Usuario: " << nombre << endl;
		cout << "Descripción: " << descripcion << endl;
		cout << "Prioridad: " << prioridad << endl;
	}

	/*Operadores*/
	bool operator>(const TipoUsuario& otro) const {
		return this->prioridad > otro.prioridad;
	}
	
	friend ostream& operator<<(ostream& os, const TipoUsuario& tipoUsuario) {
		os << "Tipo de Usuario: " << tipoUsuario.nombre << "\n"
			//<< "Descripción: " << tipoUsuario.descripcion << "\n"
			<< "Prioridad: " << tipoUsuario.prioridad << "\n";
		return os;
	}

	bool operator==(const TipoUsuario& otro) const {
		return nombre == otro.nombre &&
			descripcion == otro.descripcion &&
			prioridad == otro.prioridad;
	}

};

