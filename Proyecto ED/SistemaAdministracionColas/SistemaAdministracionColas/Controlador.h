/*
 * Descripción General:
 *
 * Nombre del archivo: Controlador.h
 *
 * Clase que Administra/Controla los administradores para facilitar el uso de los metodos
 * que se encuentran en los administradores de tipos de usuario, areas, servicios, tiquete, 
 * estadísticas.
 *
 * Autor: Josue Hidalgo // Marvin Campos
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "AdmTiposUsuario.h"
#include "AdmAreas.h"
#include "AdmServicio.h"
#include "AdmTiquetes.h"
#include "AdmEstadisticas.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::runtime_error;

class Controlador {
private:
	AdmTiposUsuario* adminTiposUsuario;
	AdmServicio* adminServicio;
	AdmAreas* adminAreas;
	AdmEstadisticas* admEstadisticas;

public:
	Controlador() {
		adminTiposUsuario = new AdmTiposUsuario();
		adminServicio = new AdmServicio();
		adminAreas = new AdmAreas();
	}

	~Controlador() {
		delete adminTiposUsuario;
		delete adminServicio;
		delete adminAreas;
	}

	void agregarTipoUsuario(string nombre, string descripcion, int prioridad) {
		adminTiposUsuario->agregar(nombre, descripcion, prioridad); //Estos fue lo que se usó en el main
	}

	bool listarTiposUsuario() {
		return adminTiposUsuario->listar();
	}

	void eliminarTipoUsuario(int posicion) {
		adminTiposUsuario->eliminar(posicion);
	}

	TipoUsuario buscarTipoUsuario(int pos) {
		if (pos < 0 || pos >= adminTiposUsuario->getSize())
			throw runtime_error("Posición inválida.");
		return adminTiposUsuario->buscar(pos);
	}

	void agregarArea(string codigo, string nombre, string descripcion, int numeroVetanillas) {
		adminAreas->agregar(codigo, nombre, descripcion, numeroVetanillas);
	}

	bool listarAreas() {
		return adminAreas->listar();
	}

	bool listarAreasCantVentanillasTiquetes() {
		return adminAreas->listarCantVentanillasTiquetes();
	}

	void eliminarArea(int posicion) {
		adminAreas->eliminar(posicion);
	}

	void modificarAreaVentanillas(int posicion, int nuevoNumeroVentanillas) {
		adminAreas->modificar(posicion, nuevoNumeroVentanillas);
	}

	Area buscarArea(int pos) {
		return adminAreas->buscar(pos);
	}

	void agregarServicio(string nombre, string descripcion, int prioridad, Area areaAtencion) {
		adminServicio->agregar(nombre, descripcion, prioridad, areaAtencion);
	}

	void eliminarServicio(int posicion) {
		adminServicio->eliminar(posicion);
	}

	void reordenarServicios(int posicion, int nuevaPrioridad) {
		adminServicio->modificar(posicion, nuevaPrioridad);
	}

	bool listarServicios() {
		return adminServicio->listar();
	}

	Servicio buscarServicio(int pos) {
		if (pos < 0 || pos >= adminServicio->getSize())
			throw runtime_error("Posición inválida.");
		return adminServicio->buscarServicio(pos);

	}

	//void agregarTiquete();

	//void eliminarTiquete();

	void listarTiquetes();
	
	void listarCodigosTiquetes();

	//void buscarTiquete();

	void listarEstadisticas() {
		AdmEstadisticas estadisticas;
		ArrayList<KVPair<Area, int>> lista = estadisticas.promedioEspera();

		for (int i = 0; i < lista.getSize(); i++) {
			lista.goToPos(i);
			KVPair<Area, int> promedioArea = lista.getElement();
			cout << "Área: " << promedioArea.key.getNombre() << ", el tiempo promedio de espera de esta area es: " << promedioArea.value << endl;
		}

		//estadisticas.acumularTiqueteArea();
		//estadisticas.acumularTiqueteVentanilla();
		//estadisticas.acumularTiqueteServicio();
		//estadisticas.acumularTiqueteTipoUsuario();
	}

	int prioridadTipoUsuario(int pos) {
		if (pos < 0 || pos >= adminTiposUsuario->getSize())
			throw runtime_error("Posición inválida.");
		return adminTiposUsuario->buscar(pos).getPrioridad();
	}
	
	void atenderSiguiente(const int& area, const int& windowNum) { // Busca el siguiente tiquete a ser atendido
		Area areaSeleccionada = buscarArea(area - 1); // Restar 1 porque los índices del usuario son 1-based
		Ventanilla window = areaSeleccionada.getListaVentanillas().get(windowNum - 1);
		adminAreas->atenderSiguiente(areaSeleccionada, windowNum);
		

		// Calcular el tiempo de espera
		time_t tiempoFin = time(nullptr);
		time_t tiempoIni = areaSeleccionada.getColaTiquetes()->min().getHora();

		// Actualizar estadísticas en AdmEstadisticas
		admEstadisticas->acumularTiqueteArea(areaSeleccionada);
		admEstadisticas->sumarTiempoEspera(tiempoFin, tiempoIni);

		// Actualizar estadísticas de la ventanilla
		window.incrementarCantidadTiquetesAtendidos(); // Método hipotético para incrementar el contador de tiquetes atendidos
		admEstadisticas->actualizar();// Revisar parámetros necesarios
	}
};