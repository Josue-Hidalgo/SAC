/*
 * Descripción General:
 *
 * Nombre del archivo: AdmTiquetes.h
 *
 * Clase que representa un Administrados para los Tiquetes en el sistema de administración de colas.
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
#include "LinkedPriorityQueue.h"
#include "Tiquete.h"
#include "Ventanilla.h"
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
	void agregar(string codigoArea, int indiceGlobal) {
		string codigoTiquete = generarCodigo(codigoArea, indiceGlobal);
	}
	void eliminar();
	void buscar();
	void listar();
};