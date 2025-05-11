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
		Sebasti�n Mas�s
		Marvin

*/

// Importar las librer�as necesarias
#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>

// Clases 
#include "Controlador.h"

// Importar con nombres conocidos
using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::string;
using std::invalid_argument;

/*VARIABLES GLOBALES*/
int indiceGlobal = 100; // Variable global para el �ndice de los tiquetes
Controlador controlador;

/*Funciones de Pruebas*/
static void agregarTiposUsuarios() {
	controlador.agregarTipoUsuario("Adulto Mayor", "Personas mayores de 65 a�os, con atenci�n prioritaria", 1);
	controlador.agregarTipoUsuario("Persona con Discapacidad", "Usuarios con alguna discapacidad, requieren atenci�n especial", 1);
	controlador.agregarTipoUsuario("Mujer Embarazada", "Mujeres embarazadas con prioridad en el servicio", 1);
	controlador.agregarTipoUsuario("Cliente Regular", "Usuarios comunes sin condiciones especiales", 3);
	controlador.agregarTipoUsuario("Cliente VIP", "Clientes con membres�a premium o trato preferencial", 2);
	controlador.agregarTipoUsuario("Funcionario Interno", "Empleados internos que acceden a servicios administrativos", 4);
	controlador.agregarTipoUsuario("Menor de Edad", "Menores que requieren acompa�amiento o tr�mite especial", 2);
}

static void agregarAreas() {
	controlador.agregarArea("GEN01", "Medicina General", "�rea de atenci�n m�dica b�sica sin especialidades", 3);
	controlador.agregarArea("EME01", "Sala de Emergencias", "�rea destinada a la atenci�n inmediata de urgencias", 5);
	controlador.agregarArea("ADM01", "Recepci�n", "�rea de tr�mites administrativos y atenci�n al p�blico", 4);
	controlador.agregarArea("PED01", "Pediatr�a", "�rea especializada en atenci�n m�dica a menores", 2);
	controlador.agregarArea("ODO01", "Odontolog�a", "�rea para servicios dentales generales y especializados", 2);
	controlador.agregarArea("LEG01", "Oficina Legal", "�rea de orientaci�n jur�dica a usuarios", 1);
	controlador.agregarArea("LAB01", "Laboratorio", "�rea de an�lisis cl�nicos y toma de muestras", 3);
	controlador.agregarArea("ENF01", "Enfermer�a", "�rea para aplicaci�n de tratamientos y vacunas", 2);
	controlador.agregarArea("PSI01", "Psicolog�a", "�rea de atenci�n psicol�gica y contenci�n emocional", 1);
	controlador.agregarArea("ESP01", "Atenci�n Especial", "�rea adaptada para usuarios con discapacidad", 2);
}

static void agregarServicios() {
	controlador.agregarServicio("Consulta General", "Atenci�n m�dica b�sica sin especialidad", 3, controlador.buscarArea(0)); // Medicina General
	controlador.agregarServicio("Emergencias", "Atenci�n inmediata por situaciones cr�ticas", 1, controlador.buscarArea(1)); // Sala de Emergencias
	controlador.agregarServicio("Tr�mites Administrativos", "Gesti�n de documentos, pagos o informaci�n", 4, controlador.buscarArea(2)); // Recepci�n
	controlador.agregarServicio("Atenci�n Pedi�trica", "Servicios dirigidos a menores de edad", 2, controlador.buscarArea(3)); // Pediatr�a
	controlador.agregarServicio("Atenci�n Odontol�gica", "Servicios dentales b�sicos y especializados", 3, controlador.buscarArea(4)); // Odontolog�a
	controlador.agregarServicio("Asesor�a Legal", "Orientaci�n jur�dica para usuarios del sistema", 4, controlador.buscarArea(5)); // Oficina Legal
	controlador.agregarServicio("Laboratorio Cl�nico", "Toma y an�lisis de muestras m�dicas", 2, controlador.buscarArea(6)); // Laboratorio
	controlador.agregarServicio("Vacunaci�n", "Aplicaci�n de vacunas seg�n el esquema nacional", 2, controlador.buscarArea(7)); // Enfermer�a
	controlador.agregarServicio("Atenci�n Psicol�gica", "Soporte emocional y diagn�stico psicol�gico", 3, controlador.buscarArea(8)); // Psicolog�a
	controlador.agregarServicio("Atenci�n para Discapacidad", "Servicios espec�ficos para personas con discapacidad", 1, controlador.buscarArea(9)); // Atenci�n Especial
}

/*INPUT FUNCTIONS*/
static int inputInt(const string& message) {
	while (true) {
		try {
			string input;
			cout << message;
			getline(cin, input);
			return stoi(input); // Convierte a entero, lanza excepciones si falla
		}
		catch (const std::invalid_argument&) {
			cout << "Error: Entrada no v�lida. Por favor, ingrese un n�mero entero." << endl;
		}
		catch (const std::out_of_range&) {
			cout << "Error: N�mero fuera de rango. Por favor, intente de nuevo." << endl;
		}
	}
}

static string inputString(const string& message) {
	while (true) {
		try {
			string input;
			cout << message;
			getline(cin, input);
			if (input.empty())
				throw invalid_argument("La entrada no puede estar vac�a.");
			return input;
		}
		catch (const std::invalid_argument& e) {
			cout << "Error: " << e.what() << " Por favor, intente de nuevo." << endl;
		}
	}
}

/* PRINTS */

//General
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

static void printWaitKey() {
	cout << "Presione ENTER para continuar..." << endl;
	string dummy;
	getline(cin, dummy);
}

static void printNewPage() {
	for (int i = 0; i < 50; i++)
		cout << endl;
}

//List Model
static void printUserTypes() {
	controlador.listarTiposUsuario();
}

static void printServices() {
	controlador.listarServicios();
}

static void printAreas() {
	controlador.listarAreas();
}

static void printWindowNumber() {
	controlador.listarAreasCantVentanillasTiquetes();
}

//Menus
static void printMenu() {
	cout << "Menu: " << endl;
	cout << "1. Estado de Colas." << endl;
	cout << "2. Tiquetes. Quiero obtener un tiquete y entrar en cola." << endl;
	cout << "3. Atender. Quiero saber quien ser� el siguiente en ser atendido." << endl;
	cout << "4. Administraci�n. Soy un administrador" << endl;
	cout << "5. Estad�sticas. Quiero ver las estad�sticas del sistema." << endl;
	cout << "0. Quiero SALIR." << endl;
}

static void printTicketMenu() {
	cout << "Menu de Tiquetes:" << endl;
	cout << "1. Obtener un tiquete." << endl;
	cout << "0. SALIR. Regresa al men� principal." << endl;
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
	bool flag = true;
	while (flag) {
		try {
			string nombre = inputString("Ingrese el nombre del tipo de usuario: ");
			string descripcion = inputString("Ingrese la descripci�n del tipo de usuario: ");
			int prioridad = inputInt("Ingrese la prioridad del tipo de usuario: ");

			if (prioridad < 0)
				throw runtime_error("La prioridad no puede ser negativa.");

			controlador.agregarTipoUsuario(nombre, descripcion, prioridad);
			cout << "Tipo de usuario agregado exitosamente." << endl;
			flag = false; // Salir del bucle si no hay errores
		}
		catch (const std::exception& e) {
			cout << "Error: " << e.what() << "\nPor favor, intente de nuevo." << endl;
		}
	}
}

static bool listUserTypes() {
	return controlador.listarTiposUsuario(); //Revisar, return se puso en el controlador
}

static void deleteUserType() {
	try {
		int posicion = inputInt("Ingrese el numero de Tipo de Usuario que quiere eliminar: ") - 1;
		cout << "Tipo de Usuario eliminado: " << controlador.eliminarTipoUsuario(posicion) << endl;
	} catch (runtime_error) {
		cout << "No se pudo eliminar el tipo de usuario." << endl;
	}
}

static TipoUsuario lookForUserType(int pos) {
	return controlador.buscarTipoUsuario(pos);
}

/*AREAS*/
static void addArea() {
	bool flag = true;
	while (flag) {
		try {
			string codigo = inputString("Ingrese el c�digo del �rea: ");
			string nombre = inputString("Ingrese el nombre del �rea: ");
			string descripcion = inputString("Ingrese la descripci�n del �rea: ");
			int numeroVentanillas = inputInt("Ingrese la cantidad de ventanillas: ");

			if (numeroVentanillas <= 0)
				throw runtime_error("La cantidad de ventanillas debe ser mayor a cero.");

			controlador.agregarArea(codigo, nombre, descripcion, numeroVentanillas);
			cout << "�rea agregada exitosamente." << endl;
			flag = false; // Salir del bucle si no hay errores
		}
		catch (const std::exception& e) {
			cout << "Error: " << e.what() << " Por favor, intente de nuevo." << endl;
		}
	}
}

static bool listAreas() {
	return controlador.listarAreas(); //Revisar, return se puso en el controlador
}

static void deleteArea() {
	int posicion = inputInt("Ingrese el n�mero de �rea que desea eliminar: ") - 1;
	cout << "�rea eliminada: " << controlador.eliminarArea(posicion) << endl;
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

static void cleanQueue() {
	controlador.limpiarColas();
	cout << "Se limpiaron las colas correctamente." << endl;
}

/*STATISTICS*/

static void cleanStatistics() {
	controlador.limpiarEstadisticas();
	cout << "Se limpiaron las estad�sticas correctamente." << endl;
}

/*SERVICES*/

static void addService() {
	bool flag = true;
	while (flag) {
		try {
			string nombre = inputString("Ingrese el nombre del servicio: ");
			string descripcion = inputString("Ingrese la descripci�n del servicio: ");
			int prioridad = inputInt("Ingrese la prioridad del servicio: ");

			if (prioridad < 0)
				throw runtime_error("La prioridad no puede ser negativa.");

			listAreas();
			int area = inputInt("Ingrese el n�mero de �rea: ") - 1;

			Area areaAtencion = lookForArea(area);
			controlador.agregarServicio(nombre, descripcion, prioridad, areaAtencion);
			cout << "Servicio agregado exitosamente." << endl;
			flag = false; // Salir del bucle si no hay errores
		}
		catch (const std::exception& e) {
			cout << "Error: " << e.what() << " Por favor, intente de nuevo." << endl;
		}
	}
}

static void deleteService() {
	int posicion = inputInt("Ingrese el n�mero de servicio que desea eliminar: ") - 1;
	cout << "Servicio eliminado: " << controlador.eliminarServicio(posicion) << endl;
}

static void reorderService() {
	int posicion = inputInt("Ingrese el n�mero de servicio que desea reordenar: ") - 1;
	int nuevaPos = inputInt("Ingrese la nueva posici�n del servicio: ") - 1;
	if (nuevaPos < 0)
		throw runtime_error("La prioridad no puede ser negativa.");
	controlador.reordenarServicios(posicion, nuevaPos);
	cout << "Servicio modificado exitosamente." << endl;
}

static bool listServices() {
	// Aqu� se mostrar�an los servicios disponibles
	cout << "Servicios disponibles:" << endl;
	return controlador.listarServicios(); //Revisar, return se puso en el controlador
}

static Servicio lookForService(int pos) {
	return controlador.buscarServicio(pos);
}

/*AUXILIARES*/

// AUX_GENERAL
static void waitAndClear() {
	printWaitKey();
	printNewPage();
}

// AUX_OPCION 2
static void createTicket(const int& userType, const int& service) {
	bool ticketCreated = false;
	
	Servicio servicioAsociado = lookForService(service);
	TipoUsuario tipoUsuarioAsociado = lookForUserType(userType);
	
	indiceGlobal++;
	indiceGlobal = ((indiceGlobal - 100) % 900) + 100;

	bool agregadoCorrectamente = controlador.agregarTiquete(servicioAsociado, tipoUsuarioAsociado, indiceGlobal);
	
	if (agregadoCorrectamente) {
		cout << "Tiquete agregado correctamente." << endl;
		ticketCreated = true; // Salir del bucle si se crea correctamente
	}
	else {
		throw runtime_error("Tiquete no se agreg� correctamente.");
	}

}

static void getTicket() {

	printUserTypes(); // Listar tipos de usuarios del 1 al n�mero de tipos
	int userType = inputInt("Seleccione el numero de tipo de usuario: ") - 1;

	printServices(); // Listar servicios del 1 al n�mero de tipos
	int service = inputInt("Seleccione el numero de servicio: ") - 1;

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

	
	Area areaSeleccionada = controlador.buscarArea(area - 1); // Restar 1 porque los �ndices del usuario son 1-based
	LinkedPriorityQueue<Tiquete>* colaTiquetes = areaSeleccionada.getColaTiquetes();

	// Verificar si la cola est� vac�a
	if (colaTiquetes->isEmpty()) {
		cout << "No hay usuarios en espera en el �rea seleccionada." << endl;
		return;
	}

	// Obtener el siguiente tiquete de la cola
	Tiquete siguienteTiquete = colaTiquetes->min();

	// Obtener la ventanilla seleccionada
	ArrayList<Ventanilla> listaVentanillas = areaSeleccionada.getListaVentanillas();
	if (windowNum < 1 || windowNum > listaVentanillas.getSize()) {
		cout << "N�mero de ventanilla inv�lido." << endl;
		return;
	}

	Ventanilla ventanillaSeleccionada = listaVentanillas.get(windowNum - 1);

	// Asignar el tiquete a la ventanilla
	ventanillaSeleccionada.setTiqueteAtendido(siguienteTiquete.getCodigo());

	// Calcular el tiempo de espera
	time_t tiempoActual = time(nullptr);
	//int tiempoEspera = static_cast<int>(tiempoActual - siguienteTiquete.getHora());

	// Actualizar estad�sticas en AdmEstadisticas
	AdmEstadisticas estadisticas;
	//estadisticas.acumularTiqueteArea(areaSeleccionada, tiempoEspera);

	// Actualizar estad�sticas de la ventanilla
	//ventanillaSeleccionada.incrementarCantidadTiquetesAtendidos(); // M�todo hipot�tico para incrementar el contador de tiquetes atendidos

	// Mostrar informaci�n del tiquete atendido
	cout << "Tiquete atendido con �xito en la ventanilla " << ventanillaSeleccionada.getNombre() << ":" << endl;
	siguienteTiquete.print();*/
}

// AUX_OPCION 4

static void admUserTypes() {
	bool isEmpty = false;
	int option = -1;

	while (option != 0) {
		waitAndClear();

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
		waitAndClear();

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
		waitAndClear();

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
	waitAndClear();
	cleanQueue();
	cleanStatistics();
}

/*OPCIONES PRINCIPALES*/

//OPCION 1
static void queueState() {
	waitAndClear();
	cout << "--- Estado de las colas ---" << endl;
	controlador.listarAreasCantVentanillasTiquetes();
}

//OPCION 2
static void ticket() {
	int option = -1;

	while (option != 0) {
		waitAndClear();

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
		waitAndClear();

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

	/*PRUEBA*/
	agregarAreas();agregarServicios();agregarTiposUsuarios();
	//printAreas();printServices();printUserTypes();

	try {
		printTitle();

		int option = -1;
		while (option != 0) {
			waitAndClear();

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