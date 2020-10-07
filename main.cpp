//Universidad Nacional de Costa Rica
//Estructuras de Datos, II Semestre 2020
//Integrantes
//Jose Andres Porras Muñoz 118170723
//Jam Carlos Ramirez Chaves 604510365
#include"Persona.h"
#include <iostream>
#include"ColaPrioridad.h"
#include"Heap.h"
using namespace std;

int main() {
	ColaPrioridad<int>* cola = new ColaPrioridad<int>(true);//false = heap de minimos
	
	cola->add(new int(13));
	cola->add(new int(15));
	cola->add(new int(19));
	cola->add(new int(22));
	cola->add(new int(24));
	cout<<cola->toString();

	delete cola;

	/**
	ListaDoble<int>* li = new ListaDoble<int>;
	li->pushEnd2(new int(8));
	li->pushEnd2(new int(13));
	li->pushEnd2(new int(66));
	li->pushEnd2(new int(12));

	cout << li->toString();
	li->swap(li->getHead(), li->getTail()->getPrev());

	cout << li->toString();*/

	/*heap->addElement(new int(3));
	heap->addElement(new int(5));
	heap->addElement(new int(8));
	heap->addElement(new int(1));
	heap->addElement(new int(6));
	heap->addElement(new int(9));*/

	/*
	cout << &lista << "\n";
	cout << lista->toString();*/





	/*Persona* p = new Persona("Dios",100);
	Persona* p2 = new Persona("Pablo",100);

	std::cout <<"p "<< p->toString()<<"\n";
	std::cout <<"p2 "<< p2->toString() << "\n\n";

	if ((*p)<(*p2))
	{
		std::cout << "p<p2";
	}

	if ((*p)>(*p2))
	{
		std::cout << "p>p2";
	}

	if ((*p)==(*p2))
	{
		std::cout << "p==p2";
	}*/

	
	//delete li;
	return 0;
}
