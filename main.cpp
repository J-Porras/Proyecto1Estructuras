#include<iostream>
#include"ListaDoble.h"

using namespace std;

//Universidad Nacional de Costa Rica
//Estructuras de Datos II Semestre 2020
//Integrantes
//Jose Andres Porras Muñoz 118170723
//Jam Carlos Ramirez Chaves 604510365
#include"Persona.h"
#include <iostream>
#include"ListaDoble.h"
using namespace std;

int main() {
	ListaDoble<int>* lista = new ListaDoble<int>;

	lista->pushEnd2(new int(1));


	lista->pushEnd2(new int(2));

	cout << lista->toString();
	


	ListaDoble<int> list();

	//cout<<list->getCantidad();
	//cout << list->getHead();


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




	delete lista;

	return 0;
}
