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
		Sebastián Masís
		Marvin

*/

// Importar las librerías necesarias
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
int indiceGlobal = 100; // Variable global para el índice de los tiquetes
Controlador controlador;

/*Funciones de Pruebas*/
static void agregarTiposUsuarios() {
	controlador.agregarTipoUsuario("Adulto Mayor", "Personas mayores de 65 años, con atención prioritaria", 1);
	controlador.agregarTipoUsuario("Persona con Discapacidad", "Usuarios con alguna discapacidad, requieren atención especial", 1);
	controlador.agregarTipoUsuario("Mujer Embarazada", "Mujeres embarazadas con prioridad en el servicio", 1);
	controlador.agregarTipoUsuario("Cliente Regular", "Usuarios comunes sin condiciones especiales", 3);
	controlador.agregarTipoUsuario("Cliente VIP", "Clientes con membresía premium o trato preferencial", 2);
	controlador.agregarTipoUsuario("Funcionario Interno", "Empleados internos que acceden a servicios administrativos", 4);
	controlador.agregarTipoUsuario("Menor de Edad", "Menores que requieren acompañamiento o trámite especial", 2);
}

static void agregarAreas() {
	controlador.agregarArea("GEN01", "Medicina General", "Área de atención médica básica sin especialidades", 3);
	controlador.agregarArea("EME01", "Sala de Emergencias", "Área destinada a la atención inmediata de urgencias", 5);
	controlador.agregarArea("ADM01", "Recepción", "Área de trámites administrativos y atención al público", 4);
	controlador.agregarArea("PED01", "Pediatría", "Área especializada en atención médica a menores", 2);
	controlador.agregarArea("ODO01", "Odontología", "Área para servicios dentales generales y especializados", 2);
	controlador.agregarArea("LEG01", "Oficina Legal", "Área de orientación jurídica a usuarios", 1);
	controlador.agregarArea("LAB01", "Laboratorio", "Área de análisis clínicos y toma de muestras", 3);
	controlador.agregarArea("ENF01", "Enfermería", "Área para aplicación de tratamientos y vacunas", 2);
	controlador.agregarArea("PSI01", "Psicología", "Área de atención psicológica y contención emocional", 1);
	controlador.agregarArea("ESP01", "Atención Especial", "Área adaptada para usuarios con discapacidad", 2);
}

static void agregarServicios() {
	controlador.agregarServicio("Consulta General", "Atención médica básica sin especialidad", 3, controlador.buscarArea(0)); // Medicina General
	controlador.agregarServicio("Emergencias", "Atención inmediata por situaciones críticas", 1, controlador.buscarArea(1)); // Sala de Emergencias
	controlador.agregarServicio("Trámites Administrativos", "Gestión de documentos, pagos o información", 4, controlador.buscarArea(2)); // Recepción
	controlador.agregarServicio("Atención Pediátrica", "Servicios dirigidos a menores de edad", 2, controlador.buscarArea(3)); // Pediatría
	controlador.agregarServicio("Atención Odontológica", "Servicios dentales básicos y especializados", 3, controlador.buscarArea(4)); // Odontología
	controlador.agregarServicio("Asesoría Legal", "Orientación jurídica para usuarios del sistema", 4, controlador.buscarArea(5)); // Oficina Legal
	controlador.agregarServicio("Laboratorio Clínico", "Toma y análisis de muestras médicas", 2, controlador.buscarArea(6)); // Laboratorio
	controlador.agregarServicio("Vacunación", "Aplicación de vacunas según el esquema nacional", 2, controlador.buscarArea(7)); // Enfermería
	controlador.agregarServicio("Atención Psicológica", "Soporte emocional y diagnóstico psicológico", 3, controlador.buscarArea(8)); // Psicología
	controlador.agregarServicio("Atención para Discapacidad", "Servicios específicos para personas con discapacidad", 1, controlador.buscarArea(9)); // Atención Especial
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
			cout << "Error: Entrada no válida. Por favor, ingrese un número entero." << endl;
		}
		catch (const std::out_of_range&) {
			cout << "Error: Número fuera de rango. Por favor, intente de nuevo." << endl;
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
				throw invalid_argument("La entrada no puede estar vacía.");
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
	cout << "3. Atender. Quiero saber quien será el siguiente en ser atendido." << endl;
	cout << "4. Administración. Soy un administrador" << endl;
	cout << "5. Estadísticas. Quiero ver las estadísticas del sistema." << endl;
	cout << "0. Quiero SALIR." << endl;
}

static void printTicketMenu() {
	cout << "Menu de Tiquetes:" << endl;
	cout << "1. Obtener un tiquete." << endl;
	cout << "0. SALIR. Regresa al menú principal." << endl;
}

static void printAdmMenu() {
	cout << "Menu de Administración:" << endl;
	cout << "1. Configuración de tipos de usuarios." << endl;
	cout << "2. Configuración de áreas." << endl;
	cout << "3. Configuración de servicios." << endl;
	cout << "4. Limpiar colas y estadísticas." << endl;
	cout << "0. SALIR." << endl;
}

static void printAdmUserTypesMenu() {
	cout << "Menu de Administración de Tipos de Usuarios:" << endl;
	cout << "1. Agregar tipo de usuario." << endl;
	cout << "2. Eliminar tipo de usuario." << endl;
	cout << "0. SALIR." << endl;
}

static void printAdmAreasMenu() {
	cout << "Menu de Administración de Áreas:" << endl;
	cout << "1. Agregar área." << endl;
	cout << "2. Eliminar área." << endl;
	cout << "3. Modificar cantidad de ventanillas." << endl;
	cout << "0. SALIR." << endl;
}

static void printAdmServicesMenu() {
	cout << "Menu de Administración de Servicios:" << endl;
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
			string descripcion = inputString("Ingrese la descripción del tipo de usuario: ");
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
			string codigo = inputString("Ingrese el código del área: ");
			string nombre = inputString("Ingrese el nombre del área: ");
			string descripcion = inputString("Ingrese la descripción del área: ");
			int numeroVentanillas = inputInt("Ingrese la cantidad de ventanillas: ");

			if (numeroVentanillas <= 0)
				throw runtime_error("La cantidad de ventanillas debe ser mayor a cero.");

			controlador.agregarArea(codigo, nombre, descripcion, numeroVentanillas);
			cout << "Área agregada exitosamente." << endl;
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
	int posicion = inputInt("Ingrese el número de área que desea eliminar: ") - 1;
	cout << "Área eliminada: " << controlador.eliminarArea(posicion) << endl;
}

static void modifyArea() {
	int posicion = inputInt("Ingrese el número de área que desea modificar: ") - 1;
	int nuevoNumeroVentanillas = inputInt("Ingrese la nueva cantidad de ventanillas: ");

	controlador.modificarAreaVentanillas(posicion, nuevoNumeroVentanillas);

	cout << "Área modificada exitosamente." << endl;
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
	cout << "Se limpiaron las estadísticas correctamente." << endl;
}

/*SERVICES*/

static void addService() {
	bool flag = true;
	while (flag) {
		try {
			string nombre = inputString("Ingrese el nombre del servicio: ");
			string descripcion = inputString("Ingrese la descripción del servicio: ");
			int prioridad = inputInt("Ingrese la prioridad del servicio: ");

			if (prioridad < 0)
				throw runtime_error("La prioridad no puede ser negativa.");

			listAreas();
			int area = inputInt("Ingrese el número de área: ") - 1;

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
	int posicion = inputInt("Ingrese el número de servicio que desea eliminar: ") - 1;
	cout << "Servicio eliminado: " << controlador.eliminarServicio(posicion) << endl;
}

static void reorderService() {
	int posicion = inputInt("Ingrese el número de servicio que desea reordenar: ") - 1;
	int nuevaPos = inputInt("Ingrese la nueva posición del servicio: ") - 1;
	if (nuevaPos < 0)
		throw runtime_error("La prioridad no puede ser negativa.");
	controlador.reordenarServicios(posicion, nuevaPos);
	cout << "Servicio modificado exitosamente." << endl;
}

static bool listServices() {
	// Aquí se mostrarían los servicios disponibles
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
		throw runtime_error("Tiquete no se agregó correctamente.");
	}

}

static void getTicket() {

	printUserTypes(); // Listar tipos de usuarios del 1 al número de tipos
	int userType = inputInt("Seleccione el numero de tipo de usuario: ") - 1;

	printServices(); // Listar servicios del 1 al número de tipos
	int service = inputInt("Seleccione el numero de servicio: ") - 1;

	createTicket(userType, service);
}

// AUX_OPCION 3
static void searchInQueue(const int& area, const int& windowNum) {

	/*
		Busca en la cola respectiva el siguiente tiquete a atender.

		Lo elimina de la cola y lo asigna como el tiquete que se está atendiendo
		actualmente en la caja.

		Actualiza los datos necesarios para que se refleje en las estadísticas del sistema.

		Si no hay ningún elemento en la cola respectiva, debe indicar que no hay usuarios en
		espera.

	
	Area areaSeleccionada = controlador.buscarArea(area - 1); // Restar 1 porque los índices del usuario son 1-based
	LinkedPriorityQueue<Tiquete>* colaTiquetes = areaSeleccionada.getColaTiquetes();

	// Verificar si la cola está vacía
	if (colaTiquetes->isEmpty()) {
		cout << "No hay usuarios en espera en el área seleccionada." << endl;
		return;
	}

	// Obtener el siguiente tiquete de la cola
	Tiquete siguienteTiquete = colaTiquetes->min();

	// Obtener la ventanilla seleccionada
	ArrayList<Ventanilla> listaVentanillas = areaSeleccionada.getListaVentanillas();
	if (windowNum < 1 || windowNum > listaVentanillas.getSize()) {
		cout << "Número de ventanilla inválido." << endl;
		return;
	}

	Ventanilla ventanillaSeleccionada = listaVentanillas.get(windowNum - 1);

	// Asignar el tiquete a la ventanilla
	ventanillaSeleccionada.setTiqueteAtendido(siguienteTiquete.getCodigo());

	// Calcular el tiempo de espera
	time_t tiempoActual = time(nullptr);
	//int tiempoEspera = static_cast<int>(tiempoActual - siguienteTiquete.getHora());

	// Actualizar estadísticas en AdmEstadisticas
	AdmEstadisticas estadisticas;
	//estadisticas.acumularTiqueteArea(areaSeleccionada, tiempoEspera);

	// Actualizar estadísticas de la ventanilla
	//ventanillaSeleccionada.incrementarCantidadTiquetesAtendidos(); // Método hipotético para incrementar el contador de tiquetes atendidos

	// Mostrar información del tiquete atendido
	cout << "Tiquete atendido con éxito en la ventanilla " << ventanillaSeleccionada.getNombre() << ":" << endl;
	siguienteTiquete.print();*/
}

// AUX_OPCION 4

static void admUserTypes() {
	bool isEmpty = false;
	int option = -1;

	while (option != 0) {
		waitAndClear();

		printAdmUserTypesMenu();

		option = inputInt("Seleccione una opción: ");

		switch (option) {
		case 1:
			// Implementación de la función para agregar tipo de usuario
			addUserType();
			break;
		case 2:{
			// Implementación de la función para eliminar tipo de usuario
			isEmpty = listUserTypes();
			if (!isEmpty)
				deleteUserType();
			break;
		}
		case 0:
			cout << "Regresando al menú principal..." << endl;
			break;
		default:
			cout << "ERROR: Debe ingresar una opción válida (1-2)." << endl;
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

		option = inputInt("Seleccione una opción: ");

		switch (option) {
		case 1:
			// Implementación de la función para agregar área
			addArea();
			break;
		case 2:
			// Implementación de la función para eliminar área
			isEmpty = listAreas();
			if (!isEmpty)
				deleteArea();
			break;
		case 3:
			// Implementación de la función para modificar cantidad de ventanillas
			isEmpty = listAreas();
			if (!isEmpty)
				modifyArea();
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

static void admServices() {

	int option = -1;

	while (option != 0) {
		waitAndClear();

		bool isEmpty = false;
		printAdmServicesMenu();

		option = inputInt("Seleccione una opción: ");
		switch (option) {
		case 1:
			// Implementación de la función para agregar servicio
			addService();
			break;
		case 2:
			// Implementación de la función para eliminar servicio
			isEmpty = listServices();
			if (!isEmpty)
				deleteService();
			break;
		case 3:
			// Implementación de la función para reordenar lista de servicios
			isEmpty = listServices();
			if (!isEmpty)
				reorderService();
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
static void attend() {
	printAreas();
	int area = inputInt("Seleccione el área: ");

	printWindowNumber();
	int windowNum = inputInt("Seleccione el número de ventanilla: ");

	searchInQueue(area, windowNum);
}

//OPCION 4
static void administration() {

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
static void statistics() {
	cout << "Estadísticas del sistema:" << endl;
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
	}
	catch (const std::runtime_error& e) {
		cout << "Error: " << e.what() << endl;
		return 1;
	}
	catch (const std::invalid_argument&) {
		cout << "Error: Entrada no válida. No es un número." << endl;
	}
	catch (const std::out_of_range&) {
		cout << "Error: Número fuera de rango." << endl;
	}
	catch (const std::exception& e) {
		cout << "Error inesperado: " << e.what() << endl;
	}

	return 0;
}