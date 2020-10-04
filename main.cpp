#include<iostream>
#include"ListaDoble.h"

using namespace std;

//Universidad Nacional de Costa Rica
//Estructuras de Datos II Semestre 2020
//Integrantes
//Jose Andres Porras Muñoz 118170723


int main() {
	ListaDoble<int>* lista = new ListaDoble<int>;

	lista->pushEnd2(new int(1));


	lista->pushEnd2(new int(2));

	cout << lista->toString();
	




	delete lista;

	return 0;
}