
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
	ArrayList<Ventanilla> crearVentanillas(int cantidad) {
		if (cantidad <= 0)
			throw runtime_error("La cantidad de ventanillas debe ser mayor a cero.");

		ArrayList<Ventanilla> nuevaLista;
		for (int i = 1; i <= cantidad; i++)
			nuevaLista.append(Ventanilla(codigo + to_string(i)));

		return nuevaLista;
	}

public:

	Area()
		: codigo(""), nombre(""), descripcion(""), numeroVentanillas(1) {
		listaVentanillas.append(Ventanilla());
		colaTiquetes = nullptr;
	}

	Area(string codigo, string nombre, string descripcion, int numeroVentanillas)
		: codigo(codigo), nombre(nombre), descripcion(descripcion), numeroVentanillas(numeroVentanillas), colaTiquetes(nullptr) {
		listaVentanillas = crearVentanillas(numeroVentanillas);
	}

	~Area() {
		delete colaTiquetes;
	}

	// Modificación del constructor de copia para corregir los errores
	Area(const Area& other)
		: codigo(other.codigo), nombre(other.nombre), descripcion(other.descripcion), numeroVentanillas(other.numeroVentanillas),
		listaVentanillas(other.listaVentanillas), colaTiquetes(other.colaTiquetes) {
	}

	//GET
	string getCodigo() const { return codigo; }

	string getNombre() const { return nombre; }

	string getDescripcion() const { return descripcion; }

	ArrayList<Ventanilla> getListaVentanillas() {
		return listaVentanillas;
	}

	LinkedPriorityQueue<Tiquete>* getColaTiquetes() {
		return colaTiquetes;
	}

	int getNumeroVentanillas() const { return numeroVentanillas; }

	//SET
	void setCodigo(string codigo) { this->codigo = codigo; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	
	void setNuevoNumeroVentanillas(int nuevoNumeroVentanillas) {
		if (nuevoNumeroVentanillas <= 0)
			throw runtime_error("La cantidad de ventanillas debe ser mayor a cero.");
		
		ArrayList<Ventanilla> temp = crearVentanillas(nuevoNumeroVentanillas);
		
		if (nuevoNumeroVentanillas > numeroVentanillas) {
			for (int i = 0; i < numeroVentanillas; i++) {
				listaVentanillas.goToPos(i);
				temp.goToPos(i);
				temp.getElement().setTiqueteAtendido(listaVentanillas.getElement().getTiqueteActual());
			}
		}
		else {
			for (int i = 0; i < nuevoNumeroVentanillas; i++) {
				listaVentanillas.goToPos(i);
				temp.goToPos(i);
				temp.getElement().setTiqueteAtendido(listaVentanillas.getElement().getTiqueteActual());
			}
		}

		eliminarVentanillas();
		listaVentanillas = temp;
		this->numeroVentanillas = nuevoNumeroVentanillas;

	}

	// Métodos de Ventanilla
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

	// Sobrecarga del operador de igualdad
	bool operator==(const Area& other) const {
		return (codigo == other.codigo && nombre == other.nombre && descripcion == other.descripcion);
	}
};

