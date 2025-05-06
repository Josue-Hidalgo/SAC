/*
 * Descripci�n General:
 *
 * Nombre del archivo: AdmTiposUsuario.h
 *
 * Clase que representa un Administrados para los Tipos de Usuario en el sistema de administraci�n de colas.
 *
 * Esta clase contiene m�todos para agregar, eliminar, modificar*, listar y buscar* tipos de usuario // Pongo * pues ser� a futuro
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
			cout << "No hay tipos de usuario registrados." << endl;
			return listaTiposUsuarios->isEmpty();
		}

		cout << "\nTipos de usuario registrados:\n" << endl;
		for (int i = 0; i < listaTiposUsuarios->getSize(); i++) {
			listaTiposUsuarios->goToPos(i);
			TipoUsuario tipoUsuario = listaTiposUsuarios->getElement();
			cout << "Tipo de Usuario #" << i + 1 << "\n" << tipoUsuario << endl;
		}
		return listaTiposUsuarios->isEmpty();
	}

	string eliminar(int pos) {
		if (listaTiposUsuarios->isEmpty()) {
			cout << "No hay tipos de usuario registrados." << endl;
			return "";
		}

		if (pos < 0 || pos >= listaTiposUsuarios->getSize()) {
			cout << "Posici�n inv�lida." << endl;
			return "";
		}

		listaTiposUsuarios->goToPos(pos);
		TipoUsuario tipoUsuarioEliminado = listaTiposUsuarios->remove();
		return tipoUsuarioEliminado.getNombre();
	}

	//void buscar();
	//void print();
};

