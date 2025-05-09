/*
 * Descripci�n General:
 * 
 * Nombre del archivo: Servicio.h
 *
 * Clase que representa un servicio en el sistema de administraci�n de colas.
 * Esta clase contiene informaci�n sobre el nombre, descripci�n, prioridad
 * y �rea de atenci�n del servicio. Tambi�n proporciona m�todos para
 * la manipulaci�n de estos atributos, as� como para imprimir los detalles.
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
using std::ostream;
using std::runtime_error;

class Servicio {
private:
    string nombre;
    string descripcion;
    int prioridad;
    Area areaAtencion;

public:
    Servicio() : nombre(""), descripcion(""), prioridad(0), areaAtencion() {}

    Servicio(string nombre, string descripcion, int prioridad, Area areaAtencion) 
        :nombre(nombre), descripcion(descripcion), prioridad(prioridad), areaAtencion(areaAtencion) {}

    string getNombre() const { return nombre; }
    string getDescripcion() const { return descripcion; }
    Area getAreaAtencion() const { return areaAtencion; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setDescripcion(string descripcion) { this->descripcion = descripcion; }
    void setAreaAtencion(Area areaAtencion) { this->areaAtencion = areaAtencion; }

    void print() const {
        cout << "Servicio: " << nombre << endl;
        cout << "Descripci�n: " << descripcion << endl;
        cout << "�rea: " << areaAtencion.getNombre() << endl;
    }

	friend ostream& operator<<(ostream& os, const Servicio& servicio) {
		os << "Servicio: " << servicio.nombre << "\n"
			<< "Descripci�n: " << servicio.descripcion << "\n"
			<< "Prioridad: " << servicio.prioridad << "\n"
			<< "�rea de Atenci�n: " << servicio.areaAtencion.getNombre() << "\n";
		return os;
	}

    bool operator==(const Servicio& otro) const {
        return nombre == otro.nombre &&
            descripcion == otro.descripcion &&
            prioridad == otro.prioridad &&
            areaAtencion == otro.areaAtencion; // Requiere que Area tenga el operador ==
    }
	int getPrioridad() const { return prioridad; }
};

