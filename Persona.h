#pragma once
#include <string>
#include <sstream>

class Persona
{
private:
	std::string nombre;
	int edad;
public:

	Persona(std::string = "indef", int = -1);
	Persona(Persona*);
	int getEdad();
	std::string getNombre();
	std::string toString();

	bool operator==(Persona& p);
	bool operator>(Persona& p);
	bool operator<(Persona& p);
	bool operator>=(Persona& p);
	bool operator<=(Persona& p);
};

Persona::Persona(std::string a, int b) : nombre(a), edad(b) {}

Persona::Persona(Persona* a) {
	nombre = a->getNombre();
	edad = a->getEdad();
}

int Persona::getEdad() {
	return edad;
}

std::string Persona::getNombre() {
	return nombre;
}

std::string Persona::toString() {
	std::stringstream s;
	s << nombre << " - " << edad;
	return s.str();
}

bool Persona::operator==(Persona& p) {
	if (this->edad == p.getEdad()) {
		return true;
	}
	return false;
}

bool Persona::operator>(Persona& p) {
	if (this->edad > p.getEdad()) {
		return true;
	}
	return false;
}

bool Persona::operator<(Persona& p) {
	if (this->edad < p.getEdad()) {
		return true;
	}
	return false;
}

bool Persona::operator<=(Persona& p) {
	if (this->edad <= p.getEdad()) {
		return true;
	}
	return false;
}

bool Persona::operator>=(Persona& p) {
	if (this->edad >= p.getEdad()) {
		return true;
	}
	return false;
}