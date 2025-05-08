
/*
 * Descripción General:
 *
 * Nombre del archivo: Controlador.h
 *
 * Clase que Administra/Controla los administradores para facilitar el uso de los metodos
 * que se encuentran en los administradores de tipos de usuario, areas, servicios, tiquete, 
 * estadísticas.
 *
 * Autor: Josue Hidalgo
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

	void listarTiposUsuario() {
		adminTiposUsuario->listar();
		return;
	}

	void eliminarTipoUsuario(int posicion) {
		adminTiposUsuario->eliminar(posicion);
	}

	void buscarTipoUsuario();
	
	
	void agregarArea(string codigo, string nombre, string descripcion, int numeroVetanillas) {
		adminAreas->agregar(codigo, nombre, descripcion, numeroVetanillas);
	}
		
	void listarAreas() {
		adminAreas->listar();
		return;
	}

	void eliminarArea(int posicion) {
		adminAreas->eliminar(posicion);
	}

	void modificarAreaVentanillas(int posicion, int nuevoNumeroVentanillas) {
		adminAreas->modificar(posicion, nuevoNumeroVentanillas);
	}
	
	void buscarArea(int pos) {
		adminAreas->buscar(pos);
		return;
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

	void listarServicios() {
		adminServicio->listar();
		return;
	}
	
	
	void buscarServicio();


	void agregarTiquete();
	void eliminarTiquete();
	void listarTiquetes();
	void buscarTiquete();

	void listarEstadisticas();
};

