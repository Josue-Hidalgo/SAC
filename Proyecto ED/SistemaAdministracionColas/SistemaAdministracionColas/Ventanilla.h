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
   string ultimoTiqueteAtendido; // puede que este vacío al principio hasta que se atienda un tiquete
   bool disponible;

public:
   // Constructor por defecto
   Ventanilla() : nombre("Ventanilla sin nombre"), ultimoTiqueteAtendido("No se ha atendido a ninguno."), disponible(true) {}

   Ventanilla(string nombre) : nombre(nombre), ultimoTiqueteAtendido("No se ha atendido a ninguno."), disponible(true) {}

   string getNombre() const { return nombre; }
   
   string getTiqueteAtendido() const { return ultimoTiqueteAtendido; }
   
   void setNombre(string nombre) { this->nombre = nombre; }
   
   void setTiqueteAtendido(string tiqueteAtendido) { this->ultimoTiqueteAtendido = tiqueteAtendido; }
   
   void asignarTiquete(string codigoTiquete) {
	   if (disponible) {
		   ultimoTiqueteAtendido = codigoTiquete;
		   disponible = false;
	   }
	   else
		   cout << "La ventanilla no está disponible para atender un nuevo tiquete." << endl;
   }

   void atenderTiquete() {
	   if (!disponible) {
		   cout << "Atendiendo el tiquete: " << ultimoTiqueteAtendido << endl;
		   ultimoTiqueteAtendido = "No se ha atendido a ninguno.";
		   disponible = true;
	   }
	   else
		   cout << "No hay tiquete para atender." << endl;
   }

   void print() const {
       cout << "Ventanilla: " << nombre << endl;
       cout << "Último tiquete atendido: " << ultimoTiqueteAtendido << endl;
   }
};
