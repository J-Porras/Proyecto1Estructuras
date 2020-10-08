//Universidad Nacional de Costa Rica
//Estructuras de Datos, II Semestre 2020
//Integrantes
//Jose Andres Porras Muñoz 118170723
//Jam Carlos Ramirez Chaves 604510365
#include"Persona.h"
#include <iostream>
#include"ColaPrioridad.h"
#include"Heap.h"
#include<list>
using namespace std;

//To Do Constructor de Copia del Heap

int main() {
	ColaPrioridad<Persona>* cola = new ColaPrioridad<Persona>(true);
	ColaPrioridad<Persona>* cola2 = new ColaPrioridad<Persona>(false);
	ListaDoble<Persona>* lista = new ListaDoble<Persona>();
	
	cout << "\t\t\t\t\t[COLADEPRIORIDAD_1]\nCola De Prioridad de Maximos de Personas:\n";

	cola->add(new Persona("persona1", 1));
	cola->add(new Persona("persona2", 2));
	cola->add(new Persona("persona3", 3));
	cola->add(new Persona("persona4", 4));
	cola->add(new Persona("persona5", 5));
	cola->add(new Persona("persona6", 6));

	cout << cola->toString();

	cout << "\nCola1 size(): " << cola->size();
	cout << "\nCola1 Peekfront(): " << cola->peekfront()->toString();
	cola->popfront();
	cout<<"\n\nCola1 despues de 1 popfront():\n" << cola->toString();
	cout << "\nCola1 despues de 1 popfront size(): " << cola->size();
	cout << "\nCola1 despues de 1 popfrontPeekFront(): " << cola->peekfront()->toString();

	cout << "\n\n----------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t[COLADEPRIORIDAD_2]\nCola De Prioridad de Minimos de Personas: \n";

	cola2->add(new Persona("persona1", 1));
	cola2->add(new Persona("persona2", 2));
	cola2->add(new Persona("persona3", 3));
	cola2->add(new Persona("persona4", 4));
	cola2->add(new Persona("persona5", 5));
	cola2->add(new Persona("persona6", 6));
	cout << cola2->toString();

	cout << "\nCola2 size(): " << cola2->size();
	cout << "\nCola2 Peekfront(): " << cola2->peekfront()->toString();
	cola2->popfront();
	cout << "\n\nCola2 despues de 1 popfront():\n" << cola2->toString();
	cout << "\nCola2 despues de 1 popfront size(): " << cola2->size();
	cout << "\nCola2 despues de 1 popfrontPeekFront(): " << cola2->peekfront()->toString();

	cout << "\n\n----------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t\t[COLADEPRIORIDAD_3]\nCola De Prioridad Creada con el Constructor de Copia:\n";
	ColaPrioridad<Persona>* cola3 = new ColaPrioridad<Persona>((*cola));

	cout << cola3->toString();

	cout << "\nCola1 size(): " << cola->size();
	cout << "\nCola1 Peekfront(): " << cola->peekfront()->toString();
	//cola->popfront();
	//cout << "\n\nCola1 despues de 1 popfront():\n" << cola->toString();
	//cout << "\nCola1 despues de 1 popfront size(): " << cola->size();
	//cout << "\nCola1 despues de 1 popfrontPeekFront(): " << cola->peekfront()->toString();





	delete cola;
	delete cola2;
	return 0;
}
