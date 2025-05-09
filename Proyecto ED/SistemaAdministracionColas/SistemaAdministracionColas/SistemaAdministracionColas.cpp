/*

	Descripci�n General:

	Nombre del archivo: SistemaAdministracionColas.cpp

	Descripci�n:
	Implementaci�n de un sistema de administraci�n de colas utilizando un
	mont�culo m�nimo. Este sistema permite gestionar la llegada y salida de
	usuarios (de tipos especificos), priorizando a aquellos con mayor urgencia
	(esto depende tanto del tipo de usuario como tramite a realizar).

	Autores:
		Josue Hidalgo
		Sebasti�n
		Marvin

*/

// Importar las librer�as necesarias
#include <iostream>
#include <string>
#include <stdexcept>

// Clases 
#include "Controlador.h"
#include "AdmTiposUsuario.h"
#include "AdmAreas.h"
#include "AdmServicio.h"

// Importar con nombres conocidos
using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::string;
using std::invalid_argument;

/*VARIABLES GLOBALES*/
int indiceGlobal = 0; // Variable global para el �ndice de los tiquetes
Controlador controlador;

/*INPUT FUNCTIONS*/
static int inputInt(const string& message) {
	string input;
	cout << message;
	getline(cin, input);
	return stoi(input); // stoi (string to integer) lanza std::out_of_range y std::invalid_argument si no es v�lido
}

static string inputString(const string& message) {
	string input;
	cout << message;
	getline(cin, input);
	if (input.empty())
		throw invalid_argument("La entrada no puede estar vac�a.");
	return input;
}

/* PRINTS */
static void printTitle() {
	cout << endl;
	cout << "Bienvenido a ... " << endl;
	cout << "Sistema de Administraci�n de Colas" << endl;
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

static void printMenu() {
	cout << "Menu: " << endl;
	cout << "1. Estado de Colas." << endl;
	cout << "2. Tiquetes. Quiero obtener un tiquete y entrar en cola." << endl;
	cout << "3. Atender. Quiero saber quien ser� el siguiente en ser atendido." << endl;
	cout << "4. Administraci�n. Soy un administrador" << endl;
	cout << "5. Estad�sticas. Quiero ver las estad�sticas del sistema." << endl;
	cout << "0. Quiero SALIR." << endl;
}

static void printWaitKey() {
	cout << "Presione ENTER para continuar..." << endl;
	string dummy;
	getline(cin, dummy);
}

static void printNewPage() {
	for (int i = 0; i < 50; i++)
		cout << endl;
}

static void printUserTypes() {
	controlador.listarTiposUsuario();
}

static void printTicketMenu() {
	cout << "Menu de Tiquetes:" << endl;
	cout << "1. Obtener un tiquete." << endl;
	cout << "0. SALIR. Regresa al men� principal." << endl;
}

static void printServices() {
	// Aqu� se mostrar�an los servicios disponibles
}

static void printAreas() {
	cout << "�reas disponibles:" << endl;
	// Aqu� se mostrar�an las �reas disponibles
}

static void printWindowNumber() {
	cout << "N�mero de ventanilla:" << endl;
	// Aqu� se mostrar�an los n�meros de ventanilla disponibles
}

static void printAdmMenu() {
	cout << "Menu de Administraci�n:" << endl;
	cout << "1. Configuraci�n de tipos de usuarios." << endl;
	cout << "2. Configuraci�n de �reas." << endl;
	cout << "3. Configuraci�n de servicios." << endl;
	cout << "4. Limpiar colas y estad�sticas." << endl;
	cout << "0. SALIR." << endl;
}

static void printAdmUserTypesMenu() {
	cout << "Menu de Administraci�n de Tipos de Usuarios:" << endl;
	cout << "1. Agregar tipo de usuario." << endl;
	cout << "2. Eliminar tipo de usuario." << endl;
	cout << "0. SALIR." << endl;
}

static void printAdmAreasMenu() {
	cout << "Menu de Administraci�n de �reas:" << endl;
	cout << "1. Agregar �rea." << endl;
	cout << "2. Eliminar �rea." << endl;
	cout << "3. Modificar cantidad de ventanillas." << endl;
	cout << "0. SALIR." << endl;
}

static void printAdmServicesMenu() {
	cout << "Menu de Administraci�n de Servicios:" << endl;
	cout << "1. Agregar servicio." << endl;
	cout << "2. Eliminar servicio." << endl;
	cout << "3. Reordenar lista de servicios." << endl;
	cout << "0. SALIR." << endl;
}

/*OPERATIONS*/

/*USERTYPE*/
static void addUserType() {
	string nombre = inputString("Ingrese el nombre del tipo de usuario: ");
	string descripcion = inputString("Ingrese la descripci�n del tipo de usuario: ");
	int prioridad = inputInt("Ingrese la prioridad del tipo de usuario: ");
	
	if (prioridad < 0)
		throw runtime_error("La prioridad no puede ser negativa.");

	controlador.agregarTipoUsuario(nombre, descripcion, prioridad);

	cout << "Tipo de usuario agregado exitosamente." << endl;
}

static bool listUserTypes() {
	return controlador.listarTiposUsuario(); //Revisar, return se puso en el controlador
}

static void deleteUserType() {
	try {
		int posicion = inputInt("Ingrese el numero de Tipo de Usuario que quiere eliminar: ") - 1;
		
		string nombre = controlador.eliminarTipoUsuario(posicion);

		cout << "Tipo de Usuario eliminado: " << nombre << endl;
		
		//controlador.eliminarTipoUsuario(posicion);
	
	} catch (runtime_error) {
		cout << "No se pudo eliminar el tipo de usuario." << endl;
	}
}

/*AREAS*/
static void addArea() {
	string codigo = inputString("Ingrese el c�digo del �rea: ");
	string nombre = inputString("Ingrese el nombre del �rea: ");
	string descripcion = inputString("Ingrese la descripci�n del �rea: ");
	int numeroVentanillas = inputInt("Ingrese la cantidad de ventanillas: ");
	
	if (numeroVentanillas <= 0)
		throw runtime_error("La cantidad de ventanillas debe ser mayor a cero.");

	controlador.agregarArea(codigo, nombre, descripcion, numeroVentanillas);

	cout << "�rea agregada exitosamente." << endl;
}

static bool listAreas() {
	return controlador.listarAreas(); //Revisar, return se puso en el controlador
}

static void deleteArea() {
	int posicion = inputInt("Ingrese el n�mero de �rea que desea eliminar: ") - 1;
	string nombre = controlador.eliminarArea(posicion);
	cout << "�rea eliminada: " << nombre << endl;
}

static void modifyArea() {
	int posicion = inputInt("Ingrese el n�mero de �rea que desea modificar: ") - 1;
	int nuevoNumeroVentanillas = inputInt("Ingrese la nueva cantidad de ventanillas: ");

	controlador.modificarAreaVentanillas(posicion, nuevoNumeroVentanillas);

	cout << "�rea modificada exitosamente." << endl;
}

static Area lookForArea(int pos) {
	return controlador.buscarArea(pos);// Retornar un objeto de tipo Area //Revisar, return se puso en el controlador
}

/*SERVICES*/

static void addService() {
	string nombre = inputString("Ingrese el nombre del servicio: ");
	string descripcion = inputString("Ingrese la descripci�n del servicio: ");
	int prioridad = inputInt("Ingrese la prioridad del servicio: ");
	
	listAreas();
	int area = inputInt("Ingrese el n�mero de �rea: ") - 1;

	if (prioridad < 0)
		throw runtime_error("La prioridad no puede ser negativa.");

	Area areaAtencion = lookForArea(area);
	controlador.agregarServicio(nombre, descripcion, prioridad, areaAtencion);
	cout << "Servicio agregado exitosamente." << endl;
}

static void deleteService() {
	int posicion = inputInt("Ingrese el n�mero de servicio que desea eliminar: ") - 1;
	string nombre = controlador.eliminarServicio(posicion);
	cout << "Servicio eliminado: " << nombre << endl;
}

static void reorderService() {
	int posicion = inputInt("Ingrese el n�mero de servicio que desea reordenar: ") - 1;
	int nuevaPrioridad = inputInt("Ingrese la nueva prioridad del servicio: ") - 1;
	if (nuevaPrioridad < 0)
		throw runtime_error("La prioridad no puede ser negativa.");
	controlador.reordenarServicios(posicion, nuevaPrioridad);
	cout << "Servicio modificado exitosamente." << endl;
}

static bool listServices() {
	// Aqu� se mostrar�an los servicios disponibles
	cout << "Servicios disponibles:" << endl;
	return controlador.listarServicios(); //Revisar, return se puso en el controlador
}

/*AUXILIARES*/

// AUX_GENERAL
static void waitAndClear() {
	printWaitKey();
	printNewPage();
}

// AUX_OPCION 2
static void createTicket(const int& userType, const int& service) {
	// Aqu� se implementar�a la l�gica para crear un tiquete
	cout << "Creando un tiquete..." << endl;
	// L�gica para crear el tiquete y agregarlo a la cola correspondiente
}

static void getTicket() {

	printUserTypes(); // Listar tipos de usuarios del 1 al n�mero de tipos
	int userType = inputInt("Seleccione el numero de tipo de usuario: ");

	printServices(); // Listar servicios del 1 al n�mero de tipos
	int service = inputInt("Seleccione el numero de servicio: ");

	createTicket(userType, service);
}

// AUX_OPCION 3
static void searchInQueue(const int& area, const int& windowNum) {
	/*
		Busca en la cola respectiva el siguiente tiquete a atender.

		Lo elimina de la cola y lo asigna como el tiquete que se est� atendiendo
		actualmente en la caja.

		Actualiza los datos necesarios para que se refleje en las estad�sticas del sistema.

		Si no hay ning�n elemento en la cola respectiva, debe indicar que no hay usuarios en
		espera.

	*/
}

// AUX_OPCION 4

static void admUserTypes() {
	bool isEmpty = false;
	int option = -1;

	while (option != 0) {
		//waitAndClear();

		printAdmUserTypesMenu();

		option = inputInt("Seleccione una opci�n: ");

		switch (option) {
		case 1:
			// Implementaci�n de la funci�n para agregar tipo de usuario
			addUserType();
			break;
		case 2:{
			// Implementaci�n de la funci�n para eliminar tipo de usuario
			isEmpty = listUserTypes();
			if (!isEmpty)
				deleteUserType();
			break;
		}
		case 0:
			cout << "Regresando al men� principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opci�n v�lida (1-2)." << endl;
			break;
		}
	}
}

static void admAreas() {
	bool isEmpty = false;
	int option = -1;

	while (option != 0) {
		//waitAndClear();

		printAdmAreasMenu();

		option = inputInt("Seleccione una opci�n: ");

		switch (option) {
		case 1:
			// Implementaci�n de la funci�n para agregar �rea
			addArea();
			break;
		case 2:
			// Implementaci�n de la funci�n para eliminar �rea
			isEmpty = listAreas();
			if (!isEmpty)
				deleteArea();
			break;
		case 3:
			// Implementaci�n de la funci�n para modificar cantidad de ventanillas
			isEmpty = listAreas();
			if (!isEmpty)
				modifyArea();
			break;
		case 0:
			cout << "Regresando al men� principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opci�n v�lida (1-3)." << endl;
			break;
		}
	}
}

static void admServices() {

	int option = -1;

	while (option != 0) {
		//waitAndClear();

		bool isEmpty = false;
		printAdmServicesMenu();

		option = inputInt("Seleccione una opci�n: ");
		switch (option) {
		case 1:
			// Implementaci�n de la funci�n para agregar servicio
			addService();
			break;
		case 2:
			// Implementaci�n de la funci�n para eliminar servicio
			isEmpty = listServices();
			if (!isEmpty)
				deleteService();
			break;
		case 3:
			// Implementaci�n de la funci�n para reordenar lista de servicios
			isEmpty = listServices();
			if (!isEmpty)
				reorderService();
			break;
		case 0:
			cout << "Regresando al men� principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opci�n v�lida (1-3)." << endl;
			break;
		}

	}
}

static void admClearQueueStatistics() {
	/*
	Elimina los contenidos de todas las colas de prioridad, los tiquetes atendidos en ventanillas y
	los datos de las estad�sticas que se hayan registrado hasta el momento. Es una reinicializaci�n
	del sistema sin alterar tipos de usuario, servicios, ni �reas. Luego de realizar la acci�n regresa al
	men� de administraci�n.
	*/

	//waitAndClear();
	cout << "Se limpiaron las colas y estad�sticas" << endl;
}

/*OPCIONES PRINCIPALES*/

//OPCION 1
static void queueState() {
	//waitAndClear();
	cout << "--- Estado de las colas ---" << endl;
	controlador.listarAreasCantVentanillasTiquetes();
}

//OPCION 2
static void ticket() {
	int option = -1;
	while (option != 0) {
		//waitAndClear();

		printTicketMenu();

		option = inputInt("Seleccione una opci�n: ");

		switch (option) {
		case 1:
			getTicket();
			break;
		case 0:
			cout << "Regresando al men� principal..." << endl;
			break;
		}
	}
}

//OPCION 3
static void attend() {
	printAreas();
	int area = inputInt("Seleccione el �rea: ");

	printWindowNumber();
	int windowNum = inputInt("Seleccione el n�mero de ventanilla: ");

	searchInQueue(area, windowNum);
}

//OPCION 4
static void administration() {

	int option = -1;

	while (option != 0) {
		//waitAndClear();

		printAdmMenu();

		option = inputInt("Seleccione una opci�n: ");

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
			cout << "Regresando al men� principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opci�n v�lida (1-4)." << endl;
			break;
		}
	}
}

//OPCION 5
static void statistics() {
	cout << "Estad�sticas del sistema:" << endl;
	controlador.listarEstadisticas();
}

/*MAIN*/
int main() {

	try {
		printTitle();

		int option = -1;
		while (option != 0) {
			//waitAndClear();

			printMenu();

			option = inputInt("Seleccione una opci�n: ");

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
				cout << "ERROR: Debe ingresar una opci�n v�lida (1-6)." << endl;
				break;
			}
		}
	}
	catch (const std::runtime_error& e) {
		cout << "Error: " << e.what() << endl;
		return 1;
	}
	catch (const std::invalid_argument&) {
		cout << "Error: Entrada no v�lida. No es un n�mero." << endl;
	}
	catch (const std::out_of_range&) {
		cout << "Error: N�mero fuera de rango." << endl;
	}
	catch (const std::exception& e) {
		cout << "Error inesperado: " << e.what() << endl;
	}

	return 0;
}