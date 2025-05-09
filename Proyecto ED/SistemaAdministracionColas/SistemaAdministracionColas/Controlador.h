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
	AdmEstadisticas* estadisticas;
	AdmTiquetes adminTiquetes;

public:
	Controlador() {
		adminTiposUsuario = new AdmTiposUsuario();
		adminServicio = new AdmServicio();
		adminAreas = new AdmAreas();
		estadisticas = new AdmEstadisticas();
	}

	~Controlador() {
		delete adminTiposUsuario;
		delete adminServicio;
		delete adminAreas;
		delete estadisticas;
	}

	void agregarTipoUsuario(string nombre, string descripcion, int prioridad) {
		adminTiposUsuario->agregar(nombre, descripcion, prioridad);
	}

	bool listarTiposUsuario() {
		return adminTiposUsuario->listar();
	}

	string eliminarTipoUsuario(int posicion) {
		return adminTiposUsuario->eliminar(posicion);
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
		return adminAreas->listarAreasCantVentanillas();
	}

	string eliminarArea(int posicion) {
		Area area = buscarArea(posicion);
		adminServicio->eliminar(area);
		return adminAreas->eliminar(posicion);
	}

	void limpiarColas() {
		adminAreas->limpiarColas();
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

	string eliminarServicio(int posicion) {
		return adminServicio->eliminar(posicion);
	}

	void eliminarServicio(Area area) {
		adminServicio->eliminar(area);
	}

	void reordenarServicios(int posicion, int nuevaPos) {
		adminServicio->modificar(posicion, nuevaPos);
	}

	bool listarServicios() {
		return adminServicio->listar();
	}

	Servicio buscarServicio(int pos) {
		if (pos < 0 || pos >= adminServicio->getSize())
			throw runtime_error("Posición inválida.");
		return adminServicio->buscarServicio(pos);

	}

	bool agregarTiquete(Servicio servicio, TipoUsuario tipoUsuario, int indice) {
		
		if (indice < 100 || indice > 999)
			throw runtime_error("El índice debe estar entre 100 y 999.");

		Area areaConTiqueteAgregado = adminTiquetes.agregar(servicio, tipoUsuario, indice);
		return adminAreas->modificarArea(areaConTiqueteAgregado);
	}

	//void eliminarTiquete();

	//void listarTiquetes();
	
	//void listarCodigosTiquetes();

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

	void limpiarEstadisticas() {
		estadisticas->limpiar();
	}

	int prioridadTipoUsuario(int pos) {
		if (pos < 0 || pos >= adminTiposUsuario->getSize())
			throw runtime_error("Posición inválida.");
		return adminTiposUsuario->buscar(pos).getPrioridad();
	}
};