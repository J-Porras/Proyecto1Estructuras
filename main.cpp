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

int main() {
	ColaPrioridad<Persona>* cola = new ColaPrioridad<Persona>(true);


	/*Heap<Persona>* heap = new Heap<Persona>(false);*/
	cola->add(new Persona("persona1", 1));
	cola->add(new Persona("persona2", 2));
	cola->add(new Persona("persona3", 3));
	cola->add(new Persona("persona4", 4));
	cola->add(new Persona("persona5", 5));
	cola->add(new Persona("persona6", 6));

	cout << cola->toString();



	cola->popfront();
	cout << cola->toString();



	delete cola;
	return 0;
}
