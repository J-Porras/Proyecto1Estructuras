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

	Heap<T>* crearHeap(ListaDoble<T>* lista,bool tipoHeap);

	string toString();

	void addElement(T*);
	void deleteElement(); //elimina el elemento de la raiz, funciona para Max y Min
	Nodo<T>* getRoot();
	//void maxHeap();

	//void minHeap();

	~Heap();
private:
	//algoritmos de heapify
	void heapifyMax(int i);
	void heapifyMin(int i);
	Nodo<T>* getPadre(int i);
	Nodo<T>* getLeft(int i);
	Nodo<T>* getRight(int i);
	ListaDoble<T>* getListHeap();

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
string Heap<T>::toString()
{
	stringstream s;
	s << this->listHeap->toString();
	return s.str();
}

template<class T>
Nodo<T>* Heap<T>::getPadre(int i)
{
	if (i < 0 || cantidad < i)
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


//crear un max-heap de una lista
template<class T>
void Heap<T>::heapifyMax(int i)//i es la raiz del arbol o subarbol
{
	Nodo<T>* aux = this->getPadre(i);
	int auxIndice = aux->getPos();
	//int* data1 = aux->getData();
	//int* data2 = heap->getNodoAt(i)->getData();
	while ((i > 0) && ((*aux->getData()) < (*listHeap->getNodoAt(i)->getData())))
	{
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(auxIndice));
		i = auxIndice;
		aux = this->getPadre(i);
		auxIndice = aux->getPos();
	}
}

//crear Min-Heap de lista
template<class T>
void Heap<T>::heapifyMin(int i)//i es la raiz del arbol o subarbol
{
	Nodo<T>* aux = this->getPadre(i);
	int auxIndice = aux->getPos();
	//int* data1 = aux->getData();
	//int* data2 = heap->getNodoAt(i)->getData();
	while ((i > 0) && ((*aux->getData()) > (*listHeap->getNodoAt(i)->getData())))
	{
		listHeap->swap(listHeap->getNodoAt(i), listHeap->getNodoAt(auxIndice));
		i = auxIndice;
		aux = this->getPadre(i);
		auxIndice = aux->getPos();
	}
}

template<class T>
void Heap<T>::addElement(T* _data)
{
	if (this->cantidad == 0)
	{
		this->listHeap->pushEnd2(_data);
		root = listHeap->getHead();
		cantidad++;
	}
	else
	{
		this->listHeap->pushEnd2(_data);
		cantidad++;
		if (this->isMax == true)
		{
			this->heapifyMax(cantidad-1);
		}
		else
		{
			this->heapifyMin(cantidad-1);
		}
		root = listHeap->getHead();
	}
	
}

template<class T>
void Heap<T>::deleteElement()
{
	this->listHeap.popfront();
	cantidad--;
	if (this->isMax == true)
	{
		this->heapifyMax(cantidad - 1);
	}
	else
	{
		
		this->heapifyMin(cantidad - 1);
	}

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


/*
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

}*/


