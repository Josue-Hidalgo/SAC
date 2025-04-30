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
	Tiquete(int codigo, time_t hora, int prioridadFinal)
		: codigo(codigo), hora(hora), prioridadFinal(prioridadFinal) {
	}
	
	int getCodigo() const { return codigo; }
	
	time_t getHora() const { return hora; }
	
	int getPrioridadFinal() const { return prioridadFinal; }
	
	void setCodigo(int codigo) { this->codigo = codigo; }
	
	void setHora(time_t hora) { this->hora = hora; }
	
	void setPrioridadFinal(int prioridadFinal) { this->prioridadFinal = prioridadFinal; }
	
	void print() const {
		cout << "Tiquete: " << codigo << endl;
		cout << "Hora: " << ctime(&hora); // se imprime hh:mm:ss
		cout << "Prioridad Final: " << prioridadFinal << endl;
	}
};

