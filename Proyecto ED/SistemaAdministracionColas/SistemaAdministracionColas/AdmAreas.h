/*
 * Descripci�n General:
 *
 * Nombre del archivo: AdmAreas.h
 *
 * Clase que representa un Administrados para las Areas en el sistema de administraci�n de colas.
 *
 * Esta clase contiene m�todos para agregar, eliminar, modificar, listar y buscar areas
 * en el sistema.
 *
 * Autor: Josue Hidalgo
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "ArrayList.h"
#include "Area.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::runtime_error;

#pragma once
class AdmAreas {
private:
	ArrayList<Area>* listaAreas;

public:
	AdmAreas() {
		listaAreas = new ArrayList<Area>();
	}

	~AdmAreas() {
		delete listaAreas;
	}
	
	void agregar(string codigo, string nombre, string descripcion, int numeroVentanillas) {
		Area nuevaArea(codigo, nombre, descripcion, numeroVentanillas);
		listaAreas->append(nuevaArea);
	}

	bool listar() {
		
		if (listaAreas->isEmpty()) {
			cout << "No hay �reas registradas." << endl;
			return listaAreas->isEmpty();
		}
		
		cout << "Total de �reas registradas: " << listaAreas->getSize() << endl;
		cout << "\n�reas registradas:\n" << endl;
		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);
			Area area = listaAreas->getElement();
			cout << "�rea #" << i + 1 << "\n" << area << "\n" << endl;
		}

		return false;
	}

	bool listarAreasCantVentanillas() {
		if (listaAreas->isEmpty()) {
			cout << "No hay �reas registradas." << endl;
			return listaAreas->isEmpty();
		}
		cout << "\n�reas registradas:\n" << endl;
		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);

			Area area = listaAreas->getElement();
			LinkedPriorityQueue<Tiquete>* colaTiquetes = area.getColaTiquetes();

			cout << "Nombre del �rea: " << area.getNombre() << endl;
			cout << "Cantidad de Ventanillas: " << area.getNumeroVentanillas() << endl;
			/**/
			if (colaTiquetes == nullptr || colaTiquetes->isEmpty()) {
				cout << "Ning�n tiquete en espera." << endl;
			}
			else {
				cout << "Usuarios en espera: " << endl;
				cout << colaTiquetes;
			}
			cout << endl;

		}
		return false;
	}

	string eliminar(int posicion) {
		if (listaAreas->isEmpty()) {
			cout << "No hay �reas registradas." << endl;
			return "";
		}

		if (posicion < 0 || posicion >= listaAreas->getSize()) {
			cout << "Posici�n inv�lida." << endl;
			return "";
		}
		listaAreas->goToPos(posicion);
		Area area = listaAreas->remove();
		return area.getNombre();
	}

	void modificar(int posicion, int nuevoNumeroVentanillas) {
		if (posicion < 0 || posicion >= listaAreas->getSize())
			throw runtime_error("Posici�n inv�lida.");
		
		listaAreas->goToPos(posicion);
		Area area = listaAreas->getElement();
		area.setNuevoNumeroVentanillas(nuevoNumeroVentanillas);

		// Eliminar el �rea actual y agregar la modificada
		listaAreas->remove();
		listaAreas->insert(area);

		cout << "N�mero de ventanillas actualizado exitosamente." << endl;
	}

	Area buscar(int posicion) {
		if (posicion < 0 || posicion >= listaAreas->getSize())
			throw runtime_error("Posici�n a buscar inv�lida.");
		listaAreas->goToPos(posicion);
		return listaAreas->getElement();
	}

	bool modificarArea(Area area) {
		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);
			Area actual = listaAreas->getElement();
			if (area.getCodigo() == actual.getCodigo()) {
				listaAreas->remove();
				listaAreas->insert(area);
				return true;
			}
		}
		return false;
	}

	void limpiarColas() {
		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);
			Area area = listaAreas->getElement();
			LinkedPriorityQueue<Tiquete>* colaTiquetes = area.getColaTiquetes();
			if (colaTiquetes != nullptr) {
				colaTiquetes->clear();
			}
		}
		cout << "Colas de todas las �reas han sido limpiadas." << endl;
	}
};

