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
	ArrayList<KVPair<Area,int>> tiempoArea;
	// AREA-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Area,int>> porArea;
	// VENTANILLA-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Ventanilla,int>> porVentanilla;
	// SERVICIO-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<Servicio,int>> porServicio;
	// TIPO DE USUARIO-TIEMPO TARDADO EN ATENDER TODOS LOS TIQUETES
	ArrayList<KVPair<TipoUsuario,int>> porTipoUsuario;

public:
	/*METODOS*/
		// AREA - PROMEDIO TIEMPO
	ArrayList<KVPair<Area, int>> promedioEspera() {
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
	void acumularTiqueteArea(Area area) {

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
	int tiquetesVentanilla(Ventanilla ventanilla);
	int tiquetesServicio(Servicio servicio);
	int tiquetesTipoUsuario(TipoUsuario tipoUsuario);

};

