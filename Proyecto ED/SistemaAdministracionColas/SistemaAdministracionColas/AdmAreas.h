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

	bool listarCantVentanillasTiquetes() {

		if (listaAreas->isEmpty()) {
			cout << "No hay �reas registradas." << endl;
			return listaAreas->isEmpty();
		}

		cout << "\n�reas registradas:\n" << endl;

		for (int i = 0; i < listaAreas->getSize(); i++) {
			listaAreas->goToPos(i);

			Area area = listaAreas->getElement();
			LinkedPriorityQueue<Tiquete>* colaTiquetes = area.getColaTiquetes();

			cout << "Nombre del �rea:" << area.getNombre() << endl;
			cout << "  " << area.getNumeroVentanillas() << endl;

			cout << "\nTiquetes en cola del �rea " << area.getNombre() << ":" << endl;
			if (colaTiquetes->isEmpty())
				cout << "No hay tiquetes en cola." << endl;
			else
				colaTiquetes->print();
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

	void atenderSiguiente(Area& area, const int&windowNum) {
		
		LinkedPriorityQueue<Tiquete>* colaTiquetes = area.getColaTiquetes();

		// Verificar si la cola est� vac�a
		if (colaTiquetes->isEmpty()) {
			cout << "No hay usuarios en espera en el �rea seleccionada." << endl;
			return;
		}

		// Obtener el siguiente tiquete de la cola
		Tiquete siguienteTiquete = colaTiquetes->min();

		// Obtener la ventanilla seleccionada
		ArrayList<Ventanilla> listaVentanillas = area.getListaVentanillas();
		if (windowNum < 1 || windowNum > listaVentanillas.getSize()) {
			cout << "N�mero de ventanilla inv�lido." << endl;
			return;
		}

		Ventanilla ventanillaSeleccionada = listaVentanillas.get(windowNum - 1);

		// Asignar el tiquete a la ventanilla
		ventanillaSeleccionada.setTiqueteAtendido(siguienteTiquete.getCodigo());

		// Calcular el tiempo de espera
		time_t tiempoActual = time(nullptr);
		//int tiempoEspera = static_cast<int>(tiempoActual - siguienteTiquete.getHora());

		// Actualizar estad�sticas en AdmEstadisticas
		AdmEstadisticas estadisticas;
		//estadisticas.acumularTiqueteArea(areaSeleccionada, tiempoEspera);

		// Actualizar estad�sticas de la ventanilla
		//ventanillaSeleccionada.incrementarCantidadTiquetesAtendidos(); // M�todo hipot�tico para incrementar el contador de tiquetes atendidos

		// Mostrar informaci�n del tiquete atendido
		cout << "Tiquete atendido con �xito en la ventanilla " << ventanillaSeleccionada.getNombre() << ":" << endl;
		siguienteTiquete.print();
	}
};

