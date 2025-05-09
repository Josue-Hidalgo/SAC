/*
 * Descripci�n General:
 *
 * Nombre del archivo: AdmTiquetes.h
 *
 * Clase que representa un Administrados para los Tiquetes en el sistema de administraci�n de colas.
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
#include "LinkedPriorityQueue.h"
#include "ArrayList.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::runtime_error;

#pragma once
class AdmTiquetes {
private:
	string generarCodigo(string codigoArea, int indiceGlobal) {
		int consecutivo = ((indiceGlobal - 100) / 900) + 100;
		return codigoArea + to_string(consecutivo);
	}

	int generarPrioridad(int PU, int PS) {
		return (PU * 10) + PS;
	}

public:
	AdmTiquetes() {}

	~AdmTiquetes() {}

	Area agregar(Servicio servicio, TipoUsuario tipoUsuario, int indice) {

		Area area = servicio.getAreaAtencion();

		string codigoTiquete = generarCodigo(area.getCodigo(), indice);
		int prioridadTiquete = generarPrioridad(tipoUsuario.getPrioridad(), servicio.getPrioridad());
		
		Tiquete nuevoTiquete = Tiquete(codigoTiquete, prioridadTiquete);
		area.agregarTiquete(nuevoTiquete);
		
		return area;
	}

	//void eliminar();
	//void buscar();
	//void listar();
};