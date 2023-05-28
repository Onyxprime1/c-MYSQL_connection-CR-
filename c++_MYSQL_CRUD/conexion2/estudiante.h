#pragma once
#include<iostream>
//#include<string>
using namespace std;

class estudiante
{
private:
	int idE;
	string nombreE;
	int edadE;
	int telE;
	string correoE;

public:
	estudiante() {};

	// Setters y Getters para los atributos
	void setIdE(int id) {
		idE = id;
	}

	void setNombreE(const string& nombre) {
		nombreE = nombre;
	}

	void setEdadE(int edad) {
		edadE = edad;
	}

	void setTelE(int telefono) {
		telE = telefono;
	}

	void setCorreoE(const string& correo) {
		correoE = correo;
	}

	int getIdE() const {
		return idE;
	}

	string getNombreE() const {
		return nombreE;
	}

	int getEdadE() const {
		return edadE;
	}

	int getTelE() const {
		return telE;
	}

	string getCorreoE() const {
		return correoE;
	}
};

