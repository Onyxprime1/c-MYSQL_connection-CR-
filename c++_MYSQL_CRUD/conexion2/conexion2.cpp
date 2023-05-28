//con este include llamamos a las funciones de sql dentro del IDE
#include <mysql.h>
#include <iostream>
#include<string>
#include "estudiante.h";
#include "asignacion.h";
using namespace std;

int main()
{
	int i;
	int a;
	int q_estado;
	estudiante es;
	asignacion as;
	//con esta secuencia mandamos a llamar dentro del programa las sintacios sql de MYSQL
	MYSQL* conectar;
	//lista los resultados en un espacio
	MYSQL_ROW fila;
	//optenemos una respuesta
	MYSQL_RES* resultado;
	//pedimos los datos ecenciales para realizar la conexion
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "", "Asignacion2", 3306, NULL, 0);



	try {
		do
		{
			cout << "asignacion de cursos  " << endl;
			cout << "ver datos ..........1   " << endl;
			cout << "ingresar  ..........2 " << endl;
			cout << "modificar ..........3 " << endl;
			cout << "eliminar  ...........4" << endl;
			cout << "finalizar  ...........5" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				do
				{
					cout << "profesor ..........1   " << endl;
					cout << "estudiante  ..........2 " << endl;
					cout << "clase ..........3 " << endl;
					cout << "asignacion  ...........4" << endl;
					cout << "cancel  ...........5" << endl;
					cin >> a;
					switch (a)
					{
					case 1:
						if (conectar) {
							//setencia query
							string buscar = "select * from Profesor;";
							//inicializaion del query
							const char* c = buscar.c_str();
							//ejecucion del query
							mysql_query(conectar, c);
							resultado = mysql_store_result(conectar);
							//recorido del queri para la optecion de datos 
							while (fila = mysql_fetch_row(resultado))
							{
								cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << endl;
							}
							cout << "conexion correctoa" << endl;
						}
						else {
							cout << "error" << endl;
						}
						break;
					case 2:
						if (conectar) {
							//setencia query
							string buscar = "select * from Estudiante;";
							//inicializaion del query
							const char* c = buscar.c_str();
							//ejecucion del query
							mysql_query(conectar, c);
							resultado = mysql_store_result(conectar);
							//recorido del queri para la optecion de datos 
							while (fila = mysql_fetch_row(resultado))
							{
								cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
							}
							cout << "conexion correctoa" << endl;
						}
						else {
							cout << "error" << endl;
						}
						break;
					case 3:
						if (conectar) {
							//setencia query
							string buscar = "select * from Clase;";
							//inicializaion del query
							const char* c = buscar.c_str();
							//ejecucion del query
							mysql_query(conectar, c);
							resultado = mysql_store_result(conectar);
							//recorido del queri para la optecion de datos 
							while (fila = mysql_fetch_row(resultado))
							{
								cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << endl;
							}
							cout << "conexion correctoa" << endl;
						}
						else {
							cout << "error" << endl;
						}
						break;
					case 4:
						if (conectar) {
							//setencia query
							string buscar = "select * from Asignacion;";
							//inicializaion del query
							const char* c = buscar.c_str();
							//ejecucion del query
							mysql_query(conectar, c);
							resultado = mysql_store_result(conectar);
							//recorido del queri para la optecion de datos 
							while (fila = mysql_fetch_row(resultado))
							{
								cout << fila[0] << "," << fila[1] << "," << fila[2] << endl;
							}
							cout << "conexion correctoa" << endl;
						}
						else {
							cout << "error" << endl;
						}
						break;
					default:
						cout << "opcion no existente" << endl;
						break;
					}
				} while (a != 5);
				break;
			default:
				break;
			case 2:
				do
				{
					cout << "estudiante  ..........1 " << endl;
					cout << "asignacion  ...........2" << endl;
					cout << "cancel  ...........3" << endl;
					cin >> a;
					switch (a)
					{
					case 1:
						if (conectar) {
							cout << "Ingrese el nombre del estudiante: ";
							string nombre;
							getline(cin.ignore(), nombre);
							es.setNombreE(nombre);

							cout << "Ingrese la edad del estudiante: ";
							int edad;
							cin >> edad;
							cin.ignore();
							es.setEdadE(edad);

							cout << "Ingrese el teléfono del estudiante: ";
							int tel;
							cin >> tel;
							cin.ignore();
							es.setTelE(tel);

							cout << "Ingrese el correo del estudiante: ";
							string correo;
							getline(cin.ignore(), correo);
							es.setCorreoE(correo);


							//setencia query
							string insert = "insert into Estudiante(nombreE, edadE, telE, correoE) value('" + es.getNombreE() + "', "
								+ to_string(es.getEdadE()) + ", " + to_string(es.getTelE()) + ", '" + es.getCorreoE() + "');";
							//inicializaion del query
							const char* c = insert.c_str();
							//ejecucion del query
							q_estado = mysql_query(conectar, c);
							if (!q_estado)
							{
								cout << "ingresado con exito" << endl;
							}
							else {
								cout << " no ingresado" << endl;
							}
						}
						else {
							cout << "error" << endl;
						}
						break;
					case 2:
						if (conectar) {

							cout << "Ingrese el ID del estudiante: ";
							int idE;
							cin >> idE;

							cout << "Ingrese el ID de la clase: ";
							int idC;
							cin >> idC;

							//setencia query
							string insert = "insert into Asignacion(idC,idE) value(" + to_string(idE) + ", " + to_string(idC) + ");";
							//inicializaion del query
							const char* c = insert.c_str();
							//ejecucion del query
							q_estado = mysql_query(conectar, c);
							if (!q_estado)
							{
								cout << "ingresado con exito" << endl;
							}
							else {
								cout << " no ingresado" << endl;
							}
						}
						else {
							cout << "error" << endl;
						}
						break;
					default:
						cout << "opcion no existente" << endl;
						break;
					}
				} while (a != 3);
				break;
			case 3:
				do
				{
					cout << "estudiante  ..........1 " << endl;
					cout << "asignacion  ...........2" << endl;
					cout << "cancel  ...........3" << endl;
					cin >> a;

					switch (a)
					{
					case 1:
						if (conectar) {
							// Obtener el ID del estudiante que deseas modificar
							int id;
							cout << "Ingrese el ID del estudiante a modificar: ";
							cin >> id;
							cin.ignore();

							string buscarM = "SELECT * FROM Estudiante WHERE idE = " + to_string(id) + ";";

							// Ejecutar la consulta
							const char* c = buscarM.c_str();
							q_estado = mysql_query(conectar, c);
							if (!q_estado)
							{
								resultado = mysql_store_result(conectar);
								if (fila = mysql_fetch_row(resultado))
								{
									// El estudiante fue encontrado, puedes mostrar los datos existentes antes de la modificación
									cout << "Datos del estudiante a modificar:" << endl;
									cout << "ID: " << fila[0] << endl;
									cout << "Nombre: " << fila[1] << endl;
									cout << "Edad: " << fila[2] << endl;
									cout << "Teléfono: " << fila[3] << endl;
									cout << "Correo: " << fila[4] << endl;

									// Solicitar los nuevos valores al usuario
									cout << "Ingrese el nuevo nombre del estudiante: ";
									string nombre;
									getline(cin, nombre);
									es.setNombreE(nombre);

									cout << "Ingrese la nueva edad del estudiante: ";
									int edad;
									cin >> edad;
									cin.ignore();
									es.setEdadE(edad);

									cout << "Ingrese el nuevo teléfono del estudiante: ";
									int tel;
									cin >> tel;
									cin.ignore();
									es.setTelE(tel);

									cout << "Ingrese el nuevo correo del estudiante: ";
									string correo;
									getline(cin, correo);
									es.setCorreoE(correo);

									// Construir la sentencia de actualización
									string update = "UPDATE Estudiante SET nombreE = '" + es.getNombreE() + "', edadE = "
										+ to_string(es.getEdadE()) + ", telE = " + to_string(es.getTelE()) + ", correoE = '"
										+ es.getCorreoE() + "' WHERE idE = " + to_string(id) + ";";

									// Ejecutar la sentencia de actualización
									const char* c = update.c_str();
									q_estado = mysql_query(conectar, c);
									if (!q_estado)
									{
										cout << "Dato modificado con éxito" << endl;
									}
									else {
										cout << "Error al modificar el dato" << endl;
									}
								}
								else {
									// El estudiante no fue encontrado
									cout << "No se encontró un estudiante con el ID especificado" << endl;
								}
							}
							else {
								cout << "Error al ejecutar la consulta" << endl;
							}

						}
						break;
					case 2:
						if (conectar) {
							// Obtener el ID del estudiante que deseas modificar
							int id;
							cout << "Ingrese el ID del estudiante a modificar: ";
							cin >> id;
							cin.ignore();

							string buscarM = "SELECT * FROM Asignacion WHERE idA = " + to_string(id) + ";";

							// Ejecutar la consulta
							const char* c = buscarM.c_str();
							q_estado = mysql_query(conectar, c);
							if (!q_estado)
							{
								resultado = mysql_store_result(conectar);
								if (fila = mysql_fetch_row(resultado))
								{
									// El estudiante fue encontrado, puedes mostrar los datos existentes antes de la modificación
									cout << "Datos del estudiante a modificar:" << endl;
									cout << "ID Asigncacion: " << fila[0] << endl;
									cout << "ID Estudiante: " << fila[1] << endl;
									cout << "Id Clase: " << fila[2] << endl;

									cout << "Ingrese el ID del estudiante: ";
									int idE;
									cin >> idE;

									cout << "Ingrese el ID de la clase: ";
									int idC;
									cin >> idC;

									// Construir la sentencia de actualización
									string update = "UPDATE Asignacion SET idE = '" + to_string(idE) + "', idC = "
										+ to_string(idC) + ";";

									// Ejecutar la sentencia de actualización
									const char* c = update.c_str();
									q_estado = mysql_query(conectar, c);
									if (!q_estado)
									{
										cout << "Dato modificado con éxito" << endl;
									}
									else {
										cout << "Error al modificar el dato" << endl;
									}
								}
								else {
									// El estudiante no fue encontrado
									cout << "No se encontró un estudiante con el ID especificado" << endl;
								}
							}
							else {
								cout << "Error al ejecutar la consulta" << endl;
							}

						}
						break;
					default:
						cout << "opcion no disponible" << endl;
						break;
					}

				} while (a != 3);
				break;
			case 4:
				string opcion;
				do
				{
					cout << "estudiante  ..........1 " << endl;
					cout << "asignacion  ...........2" << endl;
					cout << "cancel  ...........3" << endl;
					cin >> a;

					switch (a)
					{
					case 1:
						if (conectar) {
							// Obtener el ID del estudiante que deseas modificar
							int id;
							cout << "Ingrese el ID del estudiante a eliminar: ";
							cin >> id;
							cin.ignore();

							string buscarM = "SELECT * FROM Estudiante WHERE idE = " + to_string(id) + ";";

							// Ejecutar la consulta
							const char* c = buscarM.c_str();
							q_estado = mysql_query(conectar, c);
							if (!q_estado)
							{
								resultado = mysql_store_result(conectar);
								if (fila = mysql_fetch_row(resultado))
								{
									// El estudiante fue encontrado, puedes mostrar los datos existentes antes de la modificación
									cout << "Datos del estudiante a eliminar:" << endl;
									cout << "ID: " << fila[0] << endl;
									cout << "Nombre: " << fila[1] << endl;
									cout << "Edad: " << fila[2] << endl;
									cout << "Teléfono: " << fila[3] << endl;
									cout << "Correo: " << fila[4] << endl;

									// Mostrar confirmación antes de eliminar
									char opcion;
									cout << "¿Está seguro de eliminar el estudiante? (y/n): ";
									cin >> opcion;

									if (opcion == 'y' || opcion == 'Y') {
										// Construir la sentencia de eliminación
										string eliminar = "DELETE FROM Estudiante WHERE idE = " + to_string(id) + ";";

										// Ejecutar la sentencia de eliminación
										const char* c = eliminar.c_str();
										q_estado = mysql_query(conectar, c);
										if (!q_estado)
										{
											cout << "Dato eliminado con éxito" << endl;
										}
										else {
											cout << "Error al eliminar el dato" << endl;
										}
									}
									else {
										cout << "No se eliminó el estudiante" << endl;
									}
								}
							}
							else {
								// El estudiante no fue encontrado
								cout << "No se encontró un estudiante con el ID especificado" << endl;
							}
						}
						else {
							cout << "Error al ejecutar la consulta" << endl;
						}
						break;
					case 2:
						if (conectar) {
							// Obtener el ID del estudiante que deseas modificar
							int id;
							cout << "Ingrese el ID de la Asignacion a Eleminar: ";
							cin >> id;
							cin.ignore();

							string buscarM = "SELECT * FROM Asignacion WHERE idA = " + to_string(id) + ";";

							// Ejecutar la consulta
							const char* c = buscarM.c_str();
							q_estado = mysql_query(conectar, c);
							if (!q_estado)
							{
								resultado = mysql_store_result(conectar);
								if (fila = mysql_fetch_row(resultado))
								{
									// El estudiante fue encontrado, puedes mostrar los datos existentes antes de la modificación
									cout << "Datos de la Asignacion a eleminar:" << endl;
									cout << "ID Asignacion: " << fila[0] << endl;
									cout << "ID Clase: " << fila[1] << endl;
									cout << "ID estudiante: " << fila[2] << endl;

									// Mostrar confirmación antes de eliminar
									char opcion;
									cout << "¿Está seguro de eliminar el estudiante? (y/n): ";
									cin >> opcion;

									if (opcion == 'y' || opcion == 'Y') {
										// Construir la sentencia de eliminación
										string eliminar = "DELETE FROM Asignacion WHERE idA = " + to_string(id) + ";";

										// Ejecutar la sentencia de eliminación
										const char* c = eliminar.c_str();
										q_estado = mysql_query(conectar, c);
										if (!q_estado)
										{
											cout << "Dato eliminado con éxito" << endl;
										}
										else {
											cout << "Error al eliminar el dato" << endl;
										}
									}
									else {
										cout << "No se eliminó el estudiante" << endl;
									}
								}
							}
							else {
								// El estudiante no fue encontrado
								cout << "No se encontró un estudiante con el ID especificado" << endl;
							}
						}
						else {
							cout << "Error al ejecutar la consulta" << endl;
						}
						break;
					}
				} while (a != 3);


				break;
			}


		} while (i != 5);
	}
	catch (exception ex) {

		cout << "error" << endl;

	}

};

