#pragma once
#include "Heap.h"

template<class T>
class ColaPrioridad
{
private:
	ListaDoble<T>* heap;
	int tamanio;
	bool isMax;//true = heap de max, 

public:
	ColaPrioridad() {
		heap = new ListaDoble<T>;
		isMax = true;
		tamanio = 0;
	}
	void add(T*);
	void heapify(int);
	string toString();
	~ColaPrioridad();
private:
	Nodo<T>* getPadre(int i);
};

template<class T>
void ColaPrioridad<T>::add(T* _data)
{
	heap->pushEnd2(_data);
	tamanio+=1;
	heapify(tamanio - 1);

}

template<class T>
void ColaPrioridad<T>::heapify(int i)
{
	Nodo<T>* aux = this->getPadre(i);
	int auxIndice = aux->getPos();
	//int* data1 = aux->getData();
	//int* data2 = heap->getNodoAt(i)->getData();
	while ((i>0) && ((*aux->getData()) < (*heap->getNodoAt(i)->getData())))
	{
		heap->swap(heap->getNodoAt(i), heap->getNodoAt(auxIndice));
		i = auxIndice;
		aux = this->getPadre(i);
		auxIndice = aux->getPos();
	}
}

template<class T>
string ColaPrioridad<T>::toString()
{
	stringstream s;
	s << heap->toString();


	return s.str();
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad()
{
	delete heap;
}

template<class T>
Nodo<T>* ColaPrioridad<T>::getPadre(int i)
{
	if (i<0 || tamanio<i)
	{
		return nullptr;
	}
	int padre = (i - 1) / 2;
	return heap->getNodoAt(padre);
}
