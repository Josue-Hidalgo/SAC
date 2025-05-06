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
    Area areaAtencion;

public:

    Servicio() : nombre(""), descripcion(""), prioridad(0), areaAtencion() {}

    Servicio(string nombre, string descripcion, int prioridad, Area areaAtencion) 
        :nombre(nombre), descripcion(descripcion), prioridad(prioridad), areaAtencion(areaAtencion) {}

    /*
    // Constructor de copia
    Servicio(const Servicio& other)
        : nombre(other.nombre), descripcion(other.descripcion), prioridad(other.prioridad), areaAtencion(other.areaAtencion) {}

    // Operador de asignación
    Servicio& operator=(const Servicio& other) {
        if (this != &other) {
            nombre = other.nombre;
            descripcion = other.descripcion;
            prioridad = other.prioridad;
            areaAtencion = other.areaAtencion;
        }
        return *this;
    }
    */

    string getNombre() const { return nombre; }
    string getDescripcion() const { return descripcion; }
    Area getAreaAtencion() const { return areaAtencion; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setDescripcion(string descripcion) { this->descripcion = descripcion; }
    void setAreaAtencion(Area areaAtencion) { this->areaAtencion = areaAtencion; }

    void print() const {
        cout << "Servicio: " << nombre << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Área: " << areaAtencion.getNombre() << endl;
    }
};

