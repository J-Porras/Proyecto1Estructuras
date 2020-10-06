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
	void add(T*);
	void popfront();
	T* peekfront();

	string toString();
	~ColaPrioridad();
private:
};

template<class T>
void ColaPrioridad<T>::add(T* _data)
{
	this->heap->addElement(_data);
}

template<class T>
void ColaPrioridad<T>::popfront()
{
	this->heap->deleteElement();
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
