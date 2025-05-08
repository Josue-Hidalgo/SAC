
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

	void eliminarTipoUsuario();
	void listarTiposUsuario();
	void buscarTipoUsuario();
	
	void agregarArea();
	void eliminarArea();
	void listarAreas();
	void buscarArea();
	void modificarAreaVentanillas();
	
	void agregarServicio();
	void eliminarServicio();
	void listarServicios();
	void buscarServicio();
	void reordenarServicios();

	void agregarTiquete();
	void eliminarTiquete();
	void listarTiquetes();
	void buscarTiquete();

	void listarEstadisticas();
};

