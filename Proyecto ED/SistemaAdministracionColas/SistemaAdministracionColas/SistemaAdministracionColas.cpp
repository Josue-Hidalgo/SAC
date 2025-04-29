/*

	Descripción General:

	Nombre del archivo: SistemaAdministracionColas.cpp

	Descripción: 
	Implementación de un sistema de administración de colas utilizando un
	montículo mínimo. Este sistema permite gestionar la llegada y salida de
	usuarios (de tipos especificos), priorizando a aquellos con mayor urgencia
	(esto depende tanto del tipo de usuario como tramite a realizar).

	Autores: 
		Josue Hidalgo
		Sebastián 
		Marvin

*/

// Importar las librerías necesarias
#include <iostream>
#include <string>
#include <stdexcept>

// Importar con nombres conocidos
using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::string;
using std::invalid_argument;


// INPUT FUNCTIONS
int inputInt(const string& message) {
	string input;
	cout << message;
	getline(cin, input);
	return stoi(input); // stoi (string to integer) lanza std::out_of_range y std::invalid_argument si no es válido
}

string inputString(const string& message) {
	string input;
	cout << message;
	getline(cin, input);
	if (input.empty())
		throw invalid_argument("La entrada no puede estar vacía.");
	return input;
}

// PRINTS 

void printTitle() {
	cout << endl;
	cout << "Bienvenido a ... " << endl;
	cout << "Sistema de Administración de Colas" << endl;
	cout << endl;
	cout << " .----------------.  .----------------.  .----------------. " << endl;
	cout << "| .--------------. || .--------------. || .--------------. |" << endl;
	cout << "| |    _______   | || |      __      | || |     ______   | |" << endl;
	cout << "| |   /  ___  |  | || |     /  \\     | || |   .' ___  |  | |" << endl;
	cout << "| |  |  (__ \\_|  | || |    / /\\ \\    | || |  / .'   \\_|  | |" << endl;
	cout << "| |   '.___`-.   | || |   / ____ \\   | || |  | |         | |" << endl;
	cout << "| |  |`\\____) |  | || | _/ /    \\ \\_ | || |  \\ `.___.'\\  | |" << endl;
	cout << "| |  |_______.'  | || ||____|  |____|| || |   `._____.'  | |" << endl;
	cout << "| |              | || |              | || |              | |" << endl;
	cout << "| '--------------' || '--------------' || '--------------' |" << endl;
	cout << " '----------------'  '----------------'  '----------------' " << endl;
	cout << endl;

}

void printMenu() {
	cout << "Menu: " << endl;
	cout << "1. Estado de Colas." << endl;
	cout << "2. Tiquetes. Quiero obtener un tiquete y entrar en cola." << endl;
	cout << "3. Atender. Quiero saber donde puedo ser atendido." << endl;
	cout << "4. Administración. Soy un administrador" << endl;
	cout << "5. Estadísticas. Quiero ver las estadísticas del sistema." << endl;
	cout << "0. Quiero SALIR." << endl;
}

void printWaitKey() {
	cout << "Presione cualquier tecla para continuar..." << endl;
	string dummy;
	getline(cin, dummy);
}

void printNewPage() {
	for (int i = 0; i < 50; i++)
		cout << endl;
}

void printUserTypes() {
	cout << "Tipos de usuarios:" << endl;
	// Aquí se mostrarían los tipos de usuarios disponibles
	// Esta lista debe ser mostrada en el orden en
	// que se configuró en el sistema, no debe ser fija, ni por áreas.
}

void printTicketMenu() {
	cout << "Menu de Tiquetes:" << endl;
	cout << "1. Obtener un tiquete." << endl;
	cout << "0. SALIR. Regresa al menú principal." << endl;
}

void printServices() {
	// Aquí se mostrarían los servicios disponibles
}

void printAreas() {
	cout << "Áreas disponibles:" << endl;
	// Aquí se mostrarían las áreas disponibles
}

void printWindowNumber() {
	cout << "Número de ventanilla:" << endl;
	// Aquí se mostrarían los números de ventanilla disponibles
}

void printAdmMenu() {
	cout << "Menu de Administración:" << endl;
	cout << "1. Configuración de tipos de usuarios." << endl;
	cout << "2. Configuración de áreas." << endl;
	cout << "3. Configuración de servicios." << endl;
	cout << "4. Limpiar colas y estadísticas." << endl;
	cout << "0. SALIR." << endl;
}

void printAdmUserTypesMenu() {
	cout << "Menu de Administración de Tipos de Usuarios:" << endl;
	cout << "1. Agregar tipo de usuario." << endl;
	cout << "2. Eliminar tipo de usuario." << endl;
	cout << "0. SALIR." << endl;
}

void printAdmAreasMenu() {
	cout << "Menu de Administración de Áreas:" << endl;
	cout << "1. Agregar área." << endl;
	cout << "2. Eliminar área." << endl;
	cout << "3. Modificar cantidad de ventanillas." << endl;
	cout << "0. SALIR." << endl;
}

void printAdmServicesMenu() {
	cout << "Menu de Administración de Servicios:" << endl;
	cout << "1. Agregar servicio." << endl;
	cout << "2. Eliminar servicio." << endl;
	cout << "3. Reordenar lista de servicios." << endl;
	cout << "0. SALIR." << endl;
}

/*AUXILIARES*/

// AUX_GENERAL
void waitAndClear() {
	printWaitKey();
	printNewPage();
}

// AUX_OPCION 2
void createTicket(const int& userType, const int& service) {
	// Aquí se implementaría la lógica para crear un tiquete
	cout << "Creando un tiquete..." << endl;
	// Lógica para crear el tiquete y agregarlo a la cola correspondiente
}

void getTicket() {
	
	printUserTypes(); // Listar tipos de usuarios del 1 al número de tipos
	int userType = inputInt("Seleccione el tipo de usuario: ");
	
	printServices(); // Listar servicios del 1 al número de tipos
	int service = inputInt("Seleccione el servicio: ");
	
	createTicket(userType, service);
}

// AUX_OPCION 3
void searchInQueue(const int& area, const int& windowNum) {
	/*
		Busca en la cola respectiva el siguiente tiquete a atender. 
		
		Lo elimina de la cola y lo asigna como el tiquete que se está atendiendo
		actualmente en la caja. 
		
		Actualiza los datos necesarios para que se refleje en las estadísticas del sistema. 
		
		Si no hay ningún elemento en la cola respectiva, debe indicar que no hay usuarios en
		espera.

	*/
}

// AUX_OPCION 4

void admUserTypes() {

	int option = -1;

	while (option != 0) {
		waitAndClear();

		printAdmUserTypesMenu();
		
		option = inputInt("Seleccione una opción: ");
		
		switch (option) {
		case 1:
			// Implementación de la función para agregar tipo de usuario
			break;
		case 2:
			// Implementación de la función para eliminar tipo de usuario
			break;
		case 0:
			cout << "Regresando al menú principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opción válida (1-2)." << endl;
			break;
		}
	}
}

void admAreas() {

	int option = -1;

	while (option != 0) {
		waitAndClear();

		printAdmAreasMenu();

		option = inputInt("Seleccione una opción: "); 

		switch (option) {
		case 1:
			// Implementación de la función para agregar área
			break;
		case 2:
			// Implementación de la función para eliminar área
			break;
		case 3:
			// Implementación de la función para modificar cantidad de ventanillas
			break;
		case 0:
			cout << "Regresando al menú principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opción válida (1-3)." << endl;
			break;
		}
	}
}

void admServices() {

	int option = -1;

	while (option != 0) {
		waitAndClear();

		printAdmServicesMenu();

		option = inputInt("Seleccione una opción: ");
		switch (option) {
		case 1:
			// Implementación de la función para agregar servicio
			break;
		case 2:
			// Implementación de la función para eliminar servicio
			break;
		case 3:
			// Implementación de la función para reordenar lista de servicios
			break;
		case 0:
			cout << "Regresando al menú principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opción válida (1-3)." << endl;
			break;
		}

	}
}

void admClearQueueStatistics() {
	/*
	Elimina los contenidos de todas las colas de prioridad, los tiquetes atendidos en ventanillas y
	los datos de las estadísticas que se hayan registrado hasta el momento. Es una reinicialización
	del sistema sin alterar tipos de usuario, servicios, ni áreas. Luego de realizar la acción regresa al
	menú de administración.
	*/
	
	waitAndClear();
	cout << "Se limpiaron las colas y estadísticas" << endl;
}

/*OPCIONES PRINCIPALES*/

//OPCION 1
void queueState() {
	waitAndClear();
	// Implementación de la función para mostrar el estado de las colas
	cout << "Estado de las colas:" << endl;
}

//OPCION 2
void ticket() {
	int option = -1;
	while (option != 0) {
		waitAndClear();

		printTicketMenu();
		
		option = inputInt("Seleccione una opción: ");
		
		switch (option) {
		case 1:
			getTicket();
			break;
		case 0:
			cout << "Regresando al menú principal..." << endl;
			break;
		}
	}
}

//OPCION 3
void attend() {
	printAreas();
	int area = inputInt("Seleccione el área: ");

	printWindowNumber();
	int windowNum = inputInt("Seleccione el número de ventanilla: ");

	searchInQueue(area, windowNum);
}

//OPCION 4
void administration() {

	int option = -1;

	while (option != 0) {
		waitAndClear();

		printAdmMenu();

		option = inputInt("Seleccione una opción: ");

		switch (option) {
		case 1:
			admUserTypes();
			break;
		case 2:
			admAreas();
			break;
		case 3:
			admServices();
			break;
		case 4:
			admClearQueueStatistics();
			break;
		case 0:
			cout << "Regresando al menú principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opción válida (1-4)." << endl;
			break;
		}
	}
}

//OPCION 5
void statistics() {
	/*
	Se muestran todas las estadísticas explicadas anteriormente de una forma clara y concisa.Se
		espera a que el usuario presione alguna tecla para regresar al menú principal.
	*/
	cout << "Estadísticas del sistema:" << endl;
}

int main() {
	try {
		printTitle();

		int option = -1;
		while (option != 0) {
			waitAndClear();

			printMenu();

			option = inputInt("Seleccione una opción: ");

			switch (option) {
			case 1:
				queueState();
				break;
			case 2:
				ticket();
				break;
			case 3:
				attend();
				break;
			case 4:
				administration();
				break;
			case 5:
				statistics();
				break;
			case 0:
				cout << "Saliendo del sistema..." << endl;
				break;
			default:
				cout << "ERROR: Debe ingresar una opción válida (1-6)." << endl;
				break;
			}
		}
	} catch (const std::runtime_error& e) {
		cout << "Error: " << e.what() << endl;
		return 1;
	} catch (const std::invalid_argument&) {
		cout << "Error: Entrada no válida. No es un número." << endl;
	} catch (const std::out_of_range&) {
		cout << "Error: Número fuera de rango." << endl;
	} catch (const std::exception& e) {
		cout << "Error inesperado: " << e.what() << endl;
	}
	return 0;
}
