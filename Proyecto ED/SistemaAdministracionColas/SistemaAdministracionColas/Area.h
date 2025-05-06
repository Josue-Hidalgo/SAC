
/*
 * Descripción General:
 * 
 * Nombre del archivo: Area.h
 *
 * Clase que representa un área en el sistema de administración de colas.
 * Esta clase contiene información sobre el código, nombre, descripción,
 * y número de ventanillas. También gestiona una lista de ventanillas
 * en la que se pueden agregar o eliminar ventanillas, y una cola de
 * prioridad para manejar los tiquetes.
 *
 * Autor: Josue Hidalgo
 */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedPriorityQueue.h"
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
	ArrayList<Ventanilla> listaVentanillas;
	LinkedPriorityQueue<Tiquete>* colaTiquetes;

public:

	Area()
		: codigo(""), nombre(""), descripcion(""), numeroVentanillas(1) {
		listaVentanillas.append(Ventanilla());
		colaTiquetes = nullptr;
	}

	Area(string codigo, string nombre, string descripcion, int numeroVentanillas)
		: codigo(codigo), nombre(nombre), descripcion(descripcion), numeroVentanillas(numeroVentanillas), colaTiquetes(nullptr) {
		
		for (int i = 1; i <= numeroVentanillas; i++)
			listaVentanillas.append(Ventanilla(codigo + to_string(i)));
	}

	~Area() {
		delete colaTiquetes;
	}

    // Modificación del constructor de copia para corregir los errores
    Area(const Area& other)
		: codigo(other.codigo), nombre(other.nombre), descripcion(other.descripcion), numeroVentanillas(other.numeroVentanillas),
		listaVentanillas(other.listaVentanillas), colaTiquetes(other.colaTiquetes) {
    }

	string getCodigo() const { return codigo; }
	
	string getNombre() const { return nombre; }
	
	string getDescripcion() const { return descripcion; }
	
	ArrayList<Ventanilla> getListaVentanillas() {
		return listaVentanillas;
	}

	int getNumeroVentanillas() const { return numeroVentanillas; }

	void setCodigo(string codigo) { this->codigo = codigo; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	
	void setNuevoNumeroVentanillas(int numeroVentanillas) {
		if (numeroVentanillas <= 0)
			throw runtime_error("La cantidad de ventanillas debe ser mayor a cero.");
		this->numeroVentanillas = numeroVentanillas;
		eliminarVentanillas();
		for (int i = 1; i <= numeroVentanillas; i++)
			listaVentanillas.append(Ventanilla(codigo + to_string(i)));
	}

	void eliminarVentanillas() {
		listaVentanillas.clear();
	}

	void agregarTiquete(Tiquete tiquete) {
		if (colaTiquetes == nullptr)
			colaTiquetes = new LinkedPriorityQueue<Tiquete>();
		colaTiquetes->insert(tiquete, tiquete.getPrioridadFinal());
	}

	void mostrarEstadoVentanillas() {
		if (listaVentanillas.getSize() == 0)
			throw runtime_error("No hay ventanillas disponibles.");

		for (int i = 0; i < listaVentanillas.getSize(); i++) {
			listaVentanillas.goToPos(i);
			Ventanilla ventanilla = listaVentanillas.getElement();
			
			cout << "Ventanilla " << ventanilla.getNombre() << ": ";
			if (!ventanilla.estaDisponible())
				cout << "Atendiendo Tiquete " << ventanilla.getTiqueteActual() << endl;
			else
				cout << "Libre" << endl;
		}
	}

	void print() const {
		cout << "Área: " << nombre << endl;
		cout << "Descripción: " << descripcion << endl;
	}

	friend ostream& operator <<(ostream& os, const Area& area) {
		os << "Área: " << area.nombre << endl;
		//os << "Descripción: " << area.descripcion << endl;
		os << "Número de Ventanillas: " << area.numeroVentanillas << endl;
		return os;
	}
};

