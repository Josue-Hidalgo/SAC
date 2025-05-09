/*

	Descripcion General

	Nombre del archivo: AdmEstadisticas.h

	Descripcion:

	Autores:
	- Sebastian Masís 

*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "time.h"
#include "ArrayList.h"
#include "KVPair.h"

#pragma once
class AdmEstadisticas {
private:
	/*ATRIBUTOS*/

	// AREA-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Area, int>> tiempoArea;
	// AREA-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Area, int>> porArea;
	// VENTANILLA-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Ventanilla, int>> porVentanilla;
	// SERVICIO-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Servicio, int>> porServicio;
	// TIPO DE USUARIO-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<TipoUsuario, int>> porTipoUsuario;

public:
	/*METODOS*/
		// AREA - PROMEDIO TIEMPO
	ArrayList<KVPair<Area, int>> promedioEspera() { // Lista el promedio de espera por área
		int cantidadAreas = tiempoArea.getSize();

		ArrayList<KVPair<Area, int>> listaPromedios;

		for (int i = 0; i < cantidadAreas; i++) {

			listaPromedios.goToPos(i);
			tiempoArea.goToPos(i);
			porArea.goToPos(i);

			KVPair<Area, int> promedioArea = listaPromedios.getElement();
			KVPair<Area, int> areaTiquete = porArea.getElement();
			KVPair<Area, int> areaTiempo = tiempoArea.getElement();

			promedioArea.key = areaTiquete.key;
			promedioArea.value = areaTiempo.value / areaTiquete.value;
		}

		return listaPromedios;
	}
	void acumularTiqueteArea(Area area) { // Cuántos tiquetes ATENDIDOS POR ÁREA

		for (int i = 0; i < porArea.getSize(); i++) {

			porArea.goToPos(i);

			KVPair<Area, int> tupla = porArea.getElement();

			if (tupla.key == area) {
				tupla.value++;
				porArea.remove();
				porArea.append(tupla);
			}
		}
	}
	int tiquetesVentanilla(Ventanilla ventanilla) {
		for (int i = 0; i < porVentanilla.getSize(); i++) {
			porVentanilla.goToPos(i);
			KVPair<Ventanilla, int> tupla = porVentanilla.getElement();
			if (tupla.key == ventanilla) {
				return tupla.value;
			}
		}
		return 0;
	} // Cuántos tiquetes ATENDIDOS POR VENTANILLA
	int tiquetesServicio(Servicio servicio) { // Cuántos tiquetes ATENDIDOS POR SERVICIO
		for (int i = 0; i < porServicio.getSize(); i++) {
			porServicio.goToPos(i);
			KVPair<Servicio, int> tupla = porServicio.getElement();
			if (tupla.key == servicio) {
				return tupla.value;
			}
		}
		return 0;
	}
	int tiquetesTipoUsuario(TipoUsuario tipoUsuario) { // Cuántos tiquetes ATENDIDOS POR TIPO DE USUARIO
		for (int i = 0; i < porTipoUsuario.getSize(); i++) {
			porTipoUsuario.goToPos(i);
			KVPair<TipoUsuario, int> tupla = porTipoUsuario.getElement();
			if (tupla.key == tipoUsuario) {
				return tupla.value;
			}
		}
		return 0;

	}
	void sumarTiempoEspera(time_t tiempoFin, time_t tiempoIni) { // Sumar tiempo total de espera de un tiquete en una área

	}
};

