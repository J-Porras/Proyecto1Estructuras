#pragma once
#include"ListaDoble.h"
template<class T>
class Heap
{
private:
	ListaDoble<T>* listHeap;
	bool isMax;//true = heap de max, 
public:
	Heap(ListaDoble<T>* lista,bool tipoHeap) { 
		this->listHeap = lista; 
		this->isMax = tipoHeap;
	};
	Heap<T>* crearHeap(ListaDoble<T>* lista,bool tipoHeap);
	T* getPadre(int i);
	T* getLeft(int i);
	T* getRight(int i);
	ListaDoble<T>* getListHeap();
	void heapifyMax(ListaDoble<T>*,int tamanio,int i);
	void heapifyMin(ListaDoble<T>*, int tamanio, int i);
	void maxHeap(ListaDoble<T>*, int tamanio);
	void minHeap(ListaDoble<T>*, int tamanio);
	void addElement(T*);
	void deleteElement(); //elimina el elemento de la raiz, funciona para Max y Min
	~Heap();

};



template<class T>
Heap<T>* Heap<T>::crearHeap(ListaDoble<T>* lista, bool tipoHeap)
{
	//se construye un nuevo heap con una copia profunda de la lista por parametro
	Heap<T>* newHeap = new Heap<T>(new ListaDoble(lista), tipoHeap);
	
	if (tipoHeap == true)
	{
		newHeap->maxHeap(newHeap->getListHeap(), newHeap->getListHeap()->getCantidad());
	}
	else
	{
		newHeap->minHeap(newHeap->getListHeap(), newHeap->getListHeap()->getCantidad());
	}
	return newHeap;
}

template<class T>
T* Heap<T>::getPadre(int i)
{

	return listHeap.getNodoAt((i-1)/2)->getData();
}

template<class T>
T* Heap<T>::getLeft(int i)
{
	return listHeap.getNodoAt((2 * i) + 1)->getData();
}

template<class T>
T* Heap<T>::getRight(int i)
{
	return listHeap.getNodoAt((2 * i) + 2)->getData();
}

template<class T>
ListaDoble<T>* Heap<T>::getListHeap()
{
	return listHeap;
}


//crear un max-heap de una lista
template<class T>
void Heap<T>::heapifyMax(ListaDoble<T>* lista, int tamanio, int i)//i es la raiz del arbol o subarbol
{
	int mayor = i;
	int izq = (2 * i) + 1;
	int der = (2 * 1) + 2;

	if (izq < tamanio && lista->getNodoAt(izq)->getData() > lista->getNodoAt(mayor)->getData())
	{
		mayor = izq;
	}
	
	if (der < tamanio && lista->getNodoAt(der)->getData() > lista->getNodoAt(mayor));
	{
		mayor = der;
	}

	if (mayor != i)
	{
		lista.swap(lista->getNodoAt(i), lista->getNodoAt(mayor));

		heapifyMax(lista, tamanio, mayor);
	}
}

//crear Min-Heap de lista
template<class T>
void Heap<T>::heapifyMin(ListaDoble<T>* lista, int tamanio, int i)//i es la raiz del arbol o subarbol
{
	int menor = i;
	int izq = this->getLeft(i);
	int der = this->getRight(i);

	if (izq < tamanio && lista->getNodoAt(izq)->getData() < lista->getNodoAt(mayor)->getData())
	{
		menor = izq;
	}

	if (der < tamanio && lista->getNodoAt(der)->getData() < lista->getNodoAt(mayor));
	{
		menor = der;
	}

	if (menor != i)
	{
		lista.swap(lista->getNodoAt(i), lista->getNodoAt(mayor));

		heapifyMin(lista, tamanio, mayor);
	}
}


//ordena la lista en maxHeap
template<class T>
void Heap<T>::maxHeap(ListaDoble<T>* list, int tamanio)
{
	int index = (tamanio / 2) - 1; //ultimo nodo antes de las hojas
	for (int i = index; i >= 0 ; i--)
	{
		heapifyMax(list, tamanio, i);
	}

}


//ordena la lista en minHeap
template<class T>
void Heap<T>::minHeap(ListaDoble<T>*, int tamanio)
{
	int index = (tamanio / 2) - 1; //ultimo nodo antes de las hojas
	for (int i = index; i >= 0; i--)
	{
		heapifyMin(list, tamanio, i);
	}

}




template<class T>
void Heap<T>::addElement(T* _data)
{
	this->listHeap.pushEnd(listHeap->getHead(),_data);
	this->maxHeap(listHeap, listHeap.cantidad());
}

template<class T>
void Heap<T>::deleteElement()
{
	this->listHeap.popfront();
	if (this->isMax == true)
	{
		this->maxHeap();
	}
	else
	{
		this->minHeap();
	}

}

template<class T>
Heap<T>::~Heap()
{
	delete listHeap;
}

