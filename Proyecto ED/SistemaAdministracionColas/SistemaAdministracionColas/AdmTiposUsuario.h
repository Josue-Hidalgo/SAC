/*
 * Descripción General:
 *
 * Nombre del archivo: AdmTiposUsuario.h
 *
 * Clase que representa un Administrados para los Tipos de Usuario en el sistema de administración de colas.
 *
 * Esta clase contiene métodos para agregar, eliminar, modificar*, listar y buscar* tipos de usuario // Pongo * pues será a futuro
 * en el sistema.
 *
 * Autor: Josue Hidalgo
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "SortedArrayList.h"
#include "TipoUsuario.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::runtime_error;

#pragma once

class AdmTiposUsuario {

private:
	SortedArrayList<TipoUsuario>* listaTiposUsuarios;
public:
	int getSize() { return listaTiposUsuarios->getSize(); }

	AdmTiposUsuario() {
		listaTiposUsuarios = new SortedArrayList<TipoUsuario>();
	}

	~AdmTiposUsuario() {
		delete listaTiposUsuarios;
	}

	void agregar(string nombre, string descripcion, int prioridad) {
		TipoUsuario nuevoTipoUsuario(nombre, descripcion, prioridad);
		listaTiposUsuarios->append(nuevoTipoUsuario);
	}

	bool listar() {
		if (listaTiposUsuarios->isEmpty()) {
			cout << "No hay Tipos Registrados." << endl;
			return "";
		}

		cout << "\nTipos de usuario registrados:\n" << endl;
		for (int i = 0; i < listaTiposUsuarios->getSize(); i++) {
			listaTiposUsuarios->goToPos(i);
			TipoUsuario tipoUsuario = listaTiposUsuarios->getElement();
			cout << "Tipo de Usuario #" << i + 1 << ": " << tipoUsuario << endl;
		}
		return listaTiposUsuarios->isEmpty();
	}

	string eliminar(int pos) {
		if (listaTiposUsuarios->isEmpty()) {
			cout << "No hay tipos de usuario registrados." << endl;
			return "";
		}

		if (pos < 0 || pos >= listaTiposUsuarios->getSize()) {
			cout << "Posición inválida." << endl;
			return "";
		}

		listaTiposUsuarios->goToPos(pos);
		TipoUsuario tipoUsuarioEliminado = listaTiposUsuarios->remove();
		return tipoUsuarioEliminado.getNombre();
	}

	TipoUsuario buscar(int pos) {
		if (pos < 0 || pos >= listaTiposUsuarios->getSize()) 
			throw runtime_error("Posición inválida.");
		listaTiposUsuarios->goToPos(pos);
		TipoUsuario tipoUsuarioBuscado = listaTiposUsuarios->getElement();
		cout << "Tipo de Usuario #" << pos + 1 << ": " << tipoUsuarioBuscado << endl;
		return tipoUsuarioBuscado;
	}
};

