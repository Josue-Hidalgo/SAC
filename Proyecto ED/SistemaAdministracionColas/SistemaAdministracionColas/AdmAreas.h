/*
 * Descripción General:
 *
 * Nombre del archivo: AdmAreas.h
 *
 * Clase que representa un Administrados para las Areas en el sistema de administración de colas.
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
			cout << "No hay áreas registradas." << endl;
			return listaAreas->isEmpty();
		}

		cout << "Total de áreas registradas: " << listaAreas->getSize() << endl;
		cout << "\nÁreas registradas:\n" << endl;
		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);
			Area area = listaAreas->getElement();
			cout << "Área #" << i + 1 << "\n" << area << "\n" << endl;
		}

		return false;
	}

	bool listarCantVentanillasTiquetes() {

		if (listaAreas->isEmpty()) {
			cout << "No hay áreas registradas." << endl;
			return listaAreas->isEmpty();
		}

		cout << "\nÁreas registradas:\n" << endl;

		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);

			Area area = listaAreas->getElement();
			LinkedPriorityQueue<Tiquete>* colaTiquetes = area.getColaTiquetes();

			cout << "Nombre del Área:" << area.getNombre() << endl;
			cout << "  " << area.getNumeroVentanillas() << endl;

			cout << "\nTiquetes en cola del Área " << area.getNombre() << ":" << endl;
			if (colaTiquetes->isEmpty())
				cout << "No hay tiquetes en cola." << endl;
			else
				colaTiquetes->print();
		}
		return false;
	}

	string eliminar(int posicion) {
		if (listaAreas->isEmpty()) {
			cout << "No hay áreas registradas." << endl;
			return "";
		}

		if (posicion < 0 || posicion >= listaAreas->getSize()) {
			cout << "Posición inválida." << endl;
			return "";
		}

		listaAreas->goToPos(posicion);
		Area area = listaAreas->remove();
		return area.getNombre();
	}

	void modificar(int posicion, int nuevoNumeroVentanillas) {
		if (posicion < 0 || posicion >= listaAreas->getSize())
			throw runtime_error("Posición inválida.");

		listaAreas->goToPos(posicion);
		Area area = listaAreas->getElement();
		area.setNuevoNumeroVentanillas(nuevoNumeroVentanillas);

		// Eliminar el área actual y agregar la modificada
		listaAreas->remove();
		listaAreas->insert(area);

		cout << "Número de ventanillas actualizado exitosamente." << endl;
	}

	Area buscar(int posicion) {
		if (posicion < 0 || posicion >= listaAreas->getSize())
			throw runtime_error("Posición a buscar inválida.");
		listaAreas->goToPos(posicion);
		return listaAreas->getElement();
	}

	void atenderSiguiente(Area& area, const int&windowNum) {
		
		LinkedPriorityQueue<Tiquete>* colaTiquetes = area.getColaTiquetes();

		// Verificar si la cola está vacía
		if (colaTiquetes->isEmpty()) {
			cout << "No hay usuarios en espera en el área seleccionada." << endl;
			return;
		}

		// Obtener el siguiente tiquete de la cola
		Tiquete siguienteTiquete = colaTiquetes->min();

		// Obtener la ventanilla seleccionada
		ArrayList<Ventanilla> listaVentanillas = area.getListaVentanillas();
		if (windowNum < 1 || windowNum > listaVentanillas.getSize()) {
			cout << "Número de ventanilla inválido." << endl;
			return;
		}

		Ventanilla ventanillaSeleccionada = listaVentanillas.get(windowNum - 1);

		// Asignar el tiquete a la ventanilla
		ventanillaSeleccionada.setTiqueteAtendido(siguienteTiquete.getCodigo());

		// Calcular el tiempo de espera
		time_t tiempoActual = time(nullptr);
		//int tiempoEspera = static_cast<int>(tiempoActual - siguienteTiquete.getHora());

		// Actualizar estadísticas en AdmEstadisticas
		AdmEstadisticas estadisticas;
		//estadisticas.acumularTiqueteArea(areaSeleccionada, tiempoEspera);

		// Actualizar estadísticas de la ventanilla
		//ventanillaSeleccionada.incrementarCantidadTiquetesAtendidos(); // Método hipotético para incrementar el contador de tiquetes atendidos

		// Mostrar información del tiquete atendido
		cout << "Tiquete atendido con éxito en la ventanilla " << ventanillaSeleccionada.getNombre() << ":" << endl;
		siguienteTiquete.print();
	}
};

