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
	ColaPrioridad(){
		heap = nullptr;
		tamanio = isMax = 0;
	
	}

	ColaPrioridad(ListaDoble<T>*,bool = true);
	ColaPrioridad(const ColaPrioridad&);
	void clear();
	void add(T*);
	void popfront();
	T* peekfront();
	int size();
	string toString();
	~ColaPrioridad();
private:
	Heap<T>* getHeap();
};



template<class T>
ColaPrioridad<T>::ColaPrioridad(ListaDoble<T>* lis, bool isMax) {


	heap = new Heap<T>(lis, isMax);
	tamanio = lis->getCantidad();
	this->isMax = isMax;
}

template<class T>
ColaPrioridad<T>::ColaPrioridad(const ColaPrioridad& cola2)
{
	if (cola2.heap == nullptr)
	{
		this->heap ==  nullptr
	}
	else
	{
		this->heap = new Heap<T>(cola2.heap);
		this->isMax = cola2.isMax;
		this->tamanio = cola2.tamanio;
	}
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
Heap<T>* ColaPrioridad<T>::getHeap()
{
	return this->heap;
}


template<class T>
int ColaPrioridad<T>::size() {
	return tamanio;
}