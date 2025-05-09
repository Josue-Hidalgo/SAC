/*
 * Descripción General:
 *
 * Nombre del archivo: Tiquete.h
 *
 * Clase que representa un Tiquete en el sistema de administración de colas.
 *
 * Tiquete que contiene información sobre el código, la hora de emisión y la prioridad final.
 * Este tiquete se utiliza para gestionar la atención de los usuarios en las ventanillas.
 *
 * Autor: Josue Hidalgo
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include "Tiquete.h"
#include "Ventanilla.h"

using std::cout;
using std::endl;
using std::time_t;
using std::string;
using std::runtime_error;


class Tiquete {

private:
	string codigo;
	time_t hora;
	int prioridadFinal;

public:
	// Constructor por defecto
	Tiquete() : codigo(""), hora(0), prioridadFinal(0) {}

	Tiquete(string codigo, int prioridadFinal)
		: codigo(codigo), prioridadFinal(prioridadFinal) { hora = time(nullptr); }

	string getCodigo() const { return codigo; }
	
	time_t getHora() const { return hora; }
	
	int getPrioridadFinal() const { return prioridadFinal; }
	
	void setCodigo(string codigo) { this->codigo = codigo; }
	
	void setHora(time_t hora) { this->hora = hora; }
	
	void setPrioridadFinal(int prioridadFinal) { this->prioridadFinal = prioridadFinal; }
	
	void print() const {
		cout << *this;
	}

	friend ostream& operator<<(ostream& os, const Tiquete& tiquete) {
		/*Formateando la Hora*/
		struct tm timeInfo;
		localtime_s(&timeInfo, &tiquete.hora);
		char buffer[80];
		strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", &timeInfo);

		os << "Tiquete: " << tiquete.codigo << "Dia y hora de llegada: " << buffer << "Prioridad Final: " << tiquete.prioridadFinal << endl;

		return os;
	}
};

