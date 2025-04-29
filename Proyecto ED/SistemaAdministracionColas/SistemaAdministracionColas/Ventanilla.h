#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "HeapPriorityQueue.h"
#include "Tiquete.h"
#include "Ventanilla.h"

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;


class Ventanilla {
private:
	string nombre;
	string tiqueteAtendido; // puede que este vacío al principio hasta que se atienda un tiquete

public:
	Ventanilla(string nombre) : nombre(nombre), tiqueteAtendido("") {}
	
	string getNombre() const { return nombre; }
	
	string getTiqueteAtendido() const { return tiqueteAtendido; }
	
	void setNombre(string nombre) { this->nombre = nombre; }
	
	void setTiqueteAtendido(string tiqueteAtendido) { this->tiqueteAtendido = tiqueteAtendido; }
	
	void print() const {
		cout << "Ventanilla: " << nombre << endl;
		cout << "Atendiendo Tiquete: " << tiqueteAtendido << endl;
	}
};

