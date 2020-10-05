#pragma once
#include<sstream>

using namespace std;

template<class T>
class Nodo
{
private:
	T* data;
	Nodo* sig;
	Nodo* prev;
	int pos;//posicion dentro de la lista, como si fuera de un vector
public:
	Nodo(T*);
	Nodo(T*,int);
	T* getData();
	Nodo* getSig();
	Nodo* getPrev();
	int getPos();
	void setData(T*);
	void setSig(Nodo<T>*);
	void setPrev(Nodo<T>*);
	void setPos(int n);
	virtual ~Nodo();
};

template<class T>
Nodo<T>::Nodo(T* t) :data(t)
{}

template<class T>
Nodo<T>::Nodo(T* _data, int pos)
{
	this->data = _data;
	this->pos = pos;
}

template<class T>
T* Nodo<T>::getData()
{
	return data;
}

template<class T>
Nodo<T>* Nodo<T>::getSig()
{
	return sig;
}

template<class T>
Nodo<T>* Nodo<T>::getPrev()
{
	return prev;
}

template<class T>
int Nodo<T>::getPos()
{
	return pos;
}

template<class T>
void Nodo<T>::setData(T* _data)
{
	this->data = _data;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* sig)
{
	this->sig = sig;
}

template<class T>
void Nodo<T>::setPrev(Nodo<T>* prev)
{
	this->prev = prev;
}

template<class T>
void Nodo<T>::setPos(int n)
{
	pos = n;
}

template<class T>
Nodo<T>::~Nodo()
{
	delete data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class ListaDoble
{
private:
	Nodo<T>* head;// primero de la lista
	Nodo<T>* tail;
	int cantidad;
public:
	ListaDoble();
	ListaDoble(const ListaDoble<T>&);//constructor de copia

	int getCantidad();
	void setCantidad(int n);
	Nodo<T>* getHead();
	Nodo<T>* getTail();
	bool isEmpty();
	void push(Nodo<T>** head, T* _data);//añade un elemento al principio de la lista

	void pushEnd2(T* _data);//añade un elemento al final de la lista, similar a un array
	void popfront();
	void swap(Nodo<T>* n1, Nodo<T>* n2);

	Nodo<T>* getNodoAt(int posicion);

	string toString();

	ListaDoble<T>& operator=(const ListaDoble&);//sobrecarga operador "="

	virtual ~ListaDoble();
};

template<class T>
ListaDoble<T>::ListaDoble()
{
	head = nullptr;
	tail = nullptr; 
	cantidad = 0;
}

template<class T>
ListaDoble<T>::ListaDoble(const ListaDoble<T>& list2)
{
	if (list2.head == nullptr)
	{
		this->head = nullptr;
	}
	else
	{
		head = new Nodo<T>(list2.head->data,list2.head->pos);
		Nodo<T>* aux = list2.head;
		while (aux->getSig != nullptr)
		{
			head->sig = new Nodo<T>(aux->sig->data, aux->sig->pos);
			head->sig->prev = head;
			aux = aux->sig;
			head = head->sig;
		}
	}

}

template<class T>
int ListaDoble<T>::getCantidad()
{
	return cantidad;
}

template<class T>
void ListaDoble<T>::setCantidad(int n)
{
	cantidad = n;
}

template<class T>
Nodo<T>* ListaDoble<T>::getHead()
{
	return head;
}

template<class T>
Nodo<T>* ListaDoble<T>::getTail()
{
	return tail;
}

template<class T>
bool ListaDoble<T>::isEmpty()
{
	return !head;
}

template<class T>
inline void ListaDoble<T>::push(Nodo<T>** head,T* _data)
{
	Nodo<T>* newhead = new Nodo<T>* (_data);
	newhead->setSig(head);
	newhead->setPrev(nullptr);

	if (head !=nullptr)
	{
		(*head)->setPrev(newhead);
	}
	(*head) = newhead;
	newhead->setPos(cantidad++);
}


template<class T>
void ListaDoble<T>::pushEnd2(T* _data)
{
	if (head == nullptr)
	{
		head = new Nodo<T>(_data);
		head->setData(_data);
		head->setPos(cantidad);
		cantidad++;
		tail = head;
	}
	else
	{

		Nodo<T>* newend = new Nodo<T>(_data);
		Nodo<T>* aux = head;
		while (aux->getSig()!=nullptr)
		{

			aux = aux->getSig();

		}
		aux->setSig(newend);
		newend->setPrev(aux);
		newend->setPos(cantidad);
		cantidad++;
		tail = newend;

	}
}

//eliminamos el primero de la lista
template<class T>
void ListaDoble<T>::popfront()
{
	if (head == nullptr)
	{
		return;
	}
	if (head->getSig() == nullptr)
	{
		delete head;
		tail = nullptr;
	}
	head = head->getSig();
	head->getPrev()->setSig(nullptr);
	delete head->getPrev();
	head->setPrev(nullptr);

	


}

template<class T>
void ListaDoble<T>::swap(Nodo<T>* n1, Nodo<T>* n2)
{
	Nodo<T>* aux = new Nodo<T>(n1->getData());
	n1->setData(n2->getData());
	n2->setData(aux->getData());
	aux = nullptr;
}

template<class T>
Nodo<T>* ListaDoble<T>::getNodoAt(int posicion)
{
	if (this->isEmpty())
	{
		return nullptr;
	}
	if (posicion > cantidad)
	{
		return nullptr;
	}
	Nodo<T>* aux = head;
	for (int i = 0; i < posicion; i++)
	{
		aux = aux->getSig();
	}
	return aux;
}

template<class T>
string ListaDoble<T>::toString()
{
	stringstream s;
	Nodo<T>* aux = this->head;
	while (aux)
	{
		s << *(aux->getData()) << " , ";
		aux = aux->getSig();
	}
	s << "\n";
	return s.str();

}

template<class T>
ListaDoble<T>& ListaDoble<T>::operator=(const ListaDoble& origen)
{
	if (this!=&origen)
	{
		Nodo<T>* aux = origen.head;
		ListaDoble<T>* nueva = new ListaDoble<T>;
		while (aux)
		{
			nueva->pushEnd2(aux->getData());

			aux = aux->getSig();
		}


	}
	return *this;
}



template<class T>
ListaDoble<T>::~ListaDoble()
{
	Nodo<T>* aux;
	while (head!=nullptr)
	{
		aux = head->getSig();
		delete head;
		head = aux;
		
	}
}









