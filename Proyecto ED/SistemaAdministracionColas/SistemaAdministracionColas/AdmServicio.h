/*
 * Descripción General:
 *
 * Nombre del archivo: AdmServicio.h
 *
 * Clase que representa un Administrados para los Servicios en el sistema de administración de colas.
 *
 * Esta clase contiene métodos para agregar, eliminar, modificar, listar y buscar areas
 * en el sistema.
 *
 * Autor: Josue Hidalgo
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "ArrayList.h"
#include "Servicio.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::runtime_error;

#pragma once
class AdmServicio { 
private:	
	ArrayList<Servicio>* listaServicios;

	bool isEmpty() const { return listaServicios->isEmpty(); }
	bool isValidPosition(int posicion) const { return posicion >= 0 && posicion < listaServicios->getSize(); }

public:
	
	AdmServicio() : listaServicios(new ArrayList<Servicio>()) {}

	~AdmServicio() {
		delete listaServicios;
	}

	int getSize() const { return listaServicios->getSize(); }

	void agregar(string nombre, string descripcion, int prioridad, Area areaAtencion) {
		Servicio nuevoServicio(nombre, descripcion, prioridad, areaAtencion);
		listaServicios->append(nuevoServicio);
	}

	string eliminar(const int& posicion) {
		if (isEmpty())
			throw runtime_error("La lista de servicios está vacía.");
		if (!isValidPosition(posicion)) 
			throw runtime_error("Posición inválida.");

		listaServicios->goToPos(posicion);
		Servicio servicio = listaServicios->remove();
		return servicio.getNombre();
	}

	void eliminar(Area area) {
		if (isEmpty())
			throw runtime_error("La lista de servicios está vacía.");

		for (int i = 0; i < listaServicios->getSize(); i++) {
			listaServicios->goToPos(i);
			if (listaServicios->getElement().getAreaAtencion() == area)
				listaServicios->remove();
		}
	}

	void modificar(int posActual, int posNueva) {
		listaServicios->goToPos(posActual);
		Servicio servicio = listaServicios->remove();
		listaServicios->goToPos(posNueva);
		listaServicios->insert(servicio);
	}

	bool listar() {
		if (listaServicios->isEmpty()) {
			cout << "No hay servicios disponibles." << endl;
			return listaServicios->isEmpty();
		}
		for (int i = 0; i < listaServicios->getSize(); i++) {
			listaServicios->goToPos(i);
			Servicio servicio = listaServicios->getElement();
			cout << "Servicio #" << i+1 << endl;
			cout << servicio << endl;
		}
		return false;
	}

	Servicio buscarServicio(int pos) {
		if (isEmpty())
			throw runtime_error("La lista de servicios está vacía.");
		if (!isValidPosition(pos))
			throw runtime_error("Posición inválida.");
		listaServicios->goToPos(pos);
		return listaServicios->getElement();
	}
};