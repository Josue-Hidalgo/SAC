/*
 *
 * Nombre del archivo: Servicio.h
 *
 * Clase que representa un servicio en el sistema de administración de colas.
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
#include "Area.h"

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

class Servicio {
private:
	string nombre;
	string descripcion;
	int prioridad;
	Area area;

public:
	Servicio(string nombre, string descripcion, Area area)
		: nombre(nombre), descripcion(descripcion), area(area) {}

	string getNombre() const { return nombre; }

	string getDescripcion() const { return descripcion; }

	Area getArea() const { return area; }

	void setNombre(string nombre) { this->nombre = nombre; }

	void setDescripcion(string descripcion) { this->descripcion = descripcion; }

	void setArea(Area area) { this->area = area; }

	void print() const {
		cout << "Servicio: " << nombre << endl;
		cout << "Descripción: " << descripcion << endl;
		cout << "Área: " << area.getNombre() << endl;
	}
};

