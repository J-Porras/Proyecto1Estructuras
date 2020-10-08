#pragma once
#include "Heap.h"

template<class T>
class ColaPrioridad
{
private:
	Heap<T>* heap;
	int tamanio;
	bool isMax;//true = mayorvalor, mayor prioridad, 

public:
	ColaPrioridad(bool tipoHeap = true) {
		isMax = tipoHeap;
		heap = new Heap<T>(isMax);
		
		tamanio = 0;
	}
	//ColaPrioridad(ColaPrioridad<T>*);
	ColaPrioridad(ListaDoble<T>*,bool = true);
	void clear();
	void add(T*);
	void popfront();
	T* peekfront();
	int size();
	string toString();
	~ColaPrioridad();
};

//template<class T>
//ColaPrioridad<T>::ColaPrioridad(ColaPrioridad<T>* col2) {
//
//
//}

template<class T>
ColaPrioridad<T>::ColaPrioridad(ListaDoble<T>* lis, bool isMax) {


	heap = new Heap<T>(lis, isMax);
	tamanio = lis->getCantidad();
	this->isMax = isMax;
}


template<class T>
void ColaPrioridad<T>::clear() {
	delete heap;
	tamanio = 0;

	heap = new Heap<T>(isMax);
}


template<class T>
void ColaPrioridad<T>::add(T* _data)
{
	this->heap->addElement(_data);
	tamanio++;
}

template<class T>
void ColaPrioridad<T>::popfront()
{
	this->heap->deleteElement();
	tamanio--;
}

template<class T>
T*  ColaPrioridad<T>::peekfront()
{
	return this->heap->getRoot()->getData();
}

template<class T>
string ColaPrioridad<T>::toString()
{
	stringstream s;
	s << this->heap->toString();
	return s.str();
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad()
{
	delete heap;
}


template<class T>
int ColaPrioridad<T>::size() {
	return tamanio;
}