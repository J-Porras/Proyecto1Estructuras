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

	void addElement(T*);
	void deleteElement(); //elimina el elemento de la raiz, funciona para Max y Min

	void maxHeap();

	void minHeap();

	~Heap();
private:
	//algoritmos de heapify
	void heapifyMax(ListaDoble<T>*,int i);
	void heapifyMin(ListaDoble<T>*,int i);

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
void Heap<T>::heapifyMax(ListaDoble<T>* lista,int i)//i es la raiz del arbol o subarbol
{
	int tamanio = lista->getCantidad();
	int mayor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;
	int* a = nullptr;
	int* b = nullptr;
	int* c = nullptr;
	if (lista->getNodoAt(mayor))
	{
		a = lista->getNodoAt(mayor)->getData();
	}
	if (lista->getNodoAt(izq))
	{
		b = lista->getNodoAt(izq)->getData();
	}
	if (lista->getNodoAt(der))
	{
		c = lista->getNodoAt(der)->getData();
	}

	if (5>3)
	{

	}

	if ((izq < tamanio) && (b > a))
	{
		mayor = izq;
	}
	
	if ((der < tamanio) && (c > a))
	{
		mayor = der;
	}

	if (mayor != i)
	{
		lista->swap(lista->getNodoAt(i), lista->getNodoAt(mayor));

		heapifyMax(lista, mayor);
	}
}

//crear Min-Heap de lista
template<class T>
void Heap<T>::heapifyMin(ListaDoble<T>* lista,int i)//i es la raiz del arbol o subarbol
{
	int tamanio = lista->getCantidad();
	int menor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;

	if (izq < tamanio && lista->getNodoAt(izq)->getData() < lista->getNodoAt(menor)->getData())
	{
		menor = izq;
	}

	if (der < tamanio && lista->getNodoAt(der)->getData() < lista->getNodoAt(menor)->getData())
	{
		menor = der;
	}

	if (menor != i)
	{
		lista.swap(lista->getNodoAt(i), lista->getNodoAt(menor));

		heapifyMin(lista, tamanio, menor);
	}
}


//ordena la lista en maxHeap
template<class T>
void Heap<T>::maxHeap()
{
	int index = (this->listHeap->getCantidad() / 2) - 1; //ultimo nodo antes de las hojas
	for (int i = index; i >= 0 ; i--)
	{
		heapifyMax(this->listHeap,i);
	}

}


//ordena la lista en minHeap
template<class T>
void Heap<T>::minHeap()
{
	int index = (this->listHeap->getCantidad() / 2) - 1; //ultimo nodo antes de las hojas
	for (int i = index; i >= 0; i--)
	{
		heapifyMin(this->listHeap,i);
	}

}





template<class T>
void Heap<T>::addElement(T* _data)
{
	if (this->listHeap->getCantidad() == 0)
	{
		this->listHeap->pushEnd2(_data);
	}
	else
	{
		this->listHeap->pushEnd2(_data);
		this->maxHeap();
	}
	
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

