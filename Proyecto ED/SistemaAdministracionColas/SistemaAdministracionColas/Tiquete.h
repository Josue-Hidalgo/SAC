#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include "HeapPriorityQueue.h"
#include "Tiquete.h"
#include "Ventanilla.h"

using std::cout;
using std::endl;
using std::time_t;
using std::string;
using std::runtime_error;


class Tiquete {

private:
	int codigo;
	time_t hora;
	int prioridadFinal;

public:
	Tiquete(int codigo, int prioridadFinal)
		: codigo(codigo), prioridadFinal(prioridadFinal) {
		// inicializa la hora al momento de crear el tiquete con la hora actual
		hora = time(nullptr);

	}

	
	int getCodigo() const { return codigo; }
	
	time_t getHora() const { return hora; }
	
	int getPrioridadFinal() const { return prioridadFinal; }
	
	void setCodigo(int codigo) { this->codigo = codigo; }
	
	void setHora(time_t hora) { this->hora = hora; }
	
	void setPrioridadFinal(int prioridadFinal) { this->prioridadFinal = prioridadFinal; }
	
	void print() const {
		cout << "Tiquete: " << codigo << endl;

		// Convertir el tiempo a una estructura legible
		struct tm* timeInfo = localtime(&hora);
		char buffer[80];
		strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeInfo);

		cout << "Hora: " << buffer << endl; // Imprime la hora formateada
		cout << "Prioridad Final: " << prioridadFinal << endl;
	}

};

