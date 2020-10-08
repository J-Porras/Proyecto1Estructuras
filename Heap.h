#pragma once
#include"ListaDoble.h"
template<class T>

class Heap
{
private:
	ListaDoble<T>* listHeap;
	Nodo<T>* root;
	bool isMax;//true = heap de max, 
	int cantidad;
public:
	Heap(ListaDoble<T>* lista,bool tipoHeap) { 
		this->listHeap = lista; 
		this->isMax = tipoHeap;
		root = listHeap->getHead();
		cantidad = 0;
	};

	Heap(bool tipoHeap) {
		this->listHeap = new ListaDoble<T>;
		this->isMax = tipoHeap;
		root = nullptr;
		cantidad = 0;
	};

	Heap(const Heap& heap2);

	Heap<T>* crearHeap(ListaDoble<T>* lista,bool tipoHeap);

	string toString();

	void addElement(T*);
	void deleteElement(); //elimina el elemento de la raiz, funciona para Max y Min
	Nodo<T>* getRoot();
	

	~Heap();
private:
	//algoritmos de heapify
	void heapifyMax(int can, int i);
	void heapifyMin(int cant, int i);
	void heapifyMin(int i);


	void maxHeap(int i);
	void minHeap(int i);

	Nodo<T>* getPadre(int i);
	Nodo<T>* getLeft(int i);
	Nodo<T>* getRight(int i);
	ListaDoble<T>* getListHeap();

};



template<class T>
Heap<T>::Heap(const Heap& heap2)
{
	if (heap2.listHeap == nullptr)
	{
		this->listHeap = nullptr;
	}
	else
	{
		this->listHeap = new ListaDoble<T>(heap2.listHeap);
		this->root = heap2.root;
		Nodo<T>* aux = heap2.root;
		this->cantidad = heap2.cantidad;
		this->isMax = heap2.isMax;
		if (this->isMax == true)
		{
			this->maxHeap(listHeap->getCantidad() - 1);

		}
		else
		{
			this->minHeap(listHeap->getCantidad() - 1);
		}
	}
}

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
string Heap<T>::toString()
{
	stringstream s;
	s << this->listHeap->toString();
	return s.str();
}

template<class T>
Nodo<T>* Heap<T>::getPadre(int i)
{
	if (i < 0 || this->listHeap->getCantidad() < i)
	{
		return nullptr;
	}
	int padre = (i - 1) / 2;
	return listHeap->getNodoAt(padre);
}

template<class T>
Nodo<T>* Heap<T>::getLeft(int i)
{
	return listHeap->getNodoAt((2 * i) + 1);
}

template<class T>
Nodo<T>* Heap<T>::getRight(int i)
{
	return listHeap->getNodoAt((2 * i) + 2);

}

template<class T>
ListaDoble<T>* Heap<T>::getListHeap()
{
	return listHeap;
}


template<class T>
void Heap<T>::maxHeap(int i)
{
	int auxIndice = (i - 1) / 2;

	while (i >= 0 && ((*listHeap->getNodoAt(auxIndice)->getData()) < (listHeap->getNodoAt(i)->getData())))
	{
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(auxIndice));
		i = auxIndice;
		auxIndice = (i - 1) / 2;
	}
}

template<class T>
void Heap<T>::minHeap(int i)
{
	int auxIndice = (i - 1) / 2;

	while ((i > 0) && ((*listHeap->getNodoAt(auxIndice)->getData()) > (listHeap->getNodoAt(i)->getData())))
	{
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(auxIndice));
		i = auxIndice;
		auxIndice = (i - 1) / 2;
	}
}

template<class T>
void Heap<T>::heapifyMax(int cant, int i) {
	int mayor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;

	if (izq < cant && (*listHeap->getNodoAt(izq)->getData()) > (listHeap->getNodoAt(mayor)->getData())) {
		mayor = izq;
	}

	if (der < cant && (*listHeap->getNodoAt(der)->getData()) > (listHeap->getNodoAt(mayor)->getData())) {
		mayor = der;
	}

	if (mayor != i) {
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(mayor));

		heapifyMax(cant, mayor);
	}
}

template<class T>
void Heap<T>::heapifyMin(int cant, int i)
{
	int menor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;

	if (izq < cant && (*listHeap->getNodoAt(izq)->getData()) <(listHeap->getNodoAt(menor)->getData())) {
		menor = izq;
	}

	if (der < cant && (*listHeap->getNodoAt(der)->getData()) <(listHeap->getNodoAt(menor)->getData())) {
		menor = der;
	}

	if (menor != i) {
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(menor));

		heapifyMin(cant,menor);
	}
}

template<class T>
void Heap<T>::heapifyMin(int i)
{
	int menor = i;
	int izq = (2 * i) + 1;
	int der = (2 * i) + 2;

	if (izq < this->listHeap->getCantidad() && (*listHeap->getNodoAt(izq)->getData()) < (listHeap->getNodoAt(menor)->getData())) {
		menor = izq;
	}

	if (der < this->listHeap->getCantidad() && (*listHeap->getNodoAt(der)->getData()) < (listHeap->getNodoAt(menor)->getData())) {
		menor = der;
	}

	if (menor != i) {
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(menor));

		heapifyMin(menor);
	}
}

template<class T>
void Heap<T>::addElement(T* _data)
{
	this->listHeap->pushEnd2(_data);
	cantidad++;
	if (this->isMax == true)
	{
		this->maxHeap(listHeap->getCantidad() - 1);

	}
	else
	{
		this->minHeap(listHeap->getCantidad() - 1);
	}
	root = listHeap->getHead();
	
}

template<class T>
void Heap<T>::deleteElement()
{
	this->listHeap->popfront();

	cantidad--;
	if (this->isMax == true)
	{
		this->heapifyMax(listHeap->getCantidad(),0);
	}
	else
	{
		this->heapifyMin(0);
	}
	root = listHeap->getHead();
}

template<class T>
Nodo<T>* Heap<T>::getRoot()
{
	return root;
}

template<class T>
Heap<T>::~Heap()
{
	delete listHeap;
}



