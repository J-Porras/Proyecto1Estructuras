#pragma once
template<class T>
class Nodo
{
private:
	T* data;
	Nodo* sig;
	Nodo* prev;
	int pos;//posicion dentro de la lista
public:
	Nodo(T*);
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

template<class T>
class ListaDoble
{
private:
	Nodo<T>* head;// primero de la lista
	int cantidad;
public: 
	ListaDoble() {head = nullptr,cantidad = 0};
	ListaDoble(ListaDoble<T>&);//constructor de copia

	int getCantidad();
	void setCantidad(int n);
	Nodo<T>* getHead();
	bool isEmpty();
	void push(Nodo<T>** head,T* _data);//añade un elemento al principio de la lista
	void pushEnd(Nodo<T>** head, T* _data);//añade un elemento al final de la lista
	void popfront(Nodo<T>** head);
};

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
bool ListaDoble<T>::isEmpty()
{
	return !head;
}

template<class T>
inline void ListaDoble<T>::push(Nodo<T>** head,T* _data)
{
	Nodo<T>* newhead = new Nodo<T> * (_data);
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
void ListaDoble<T>::pushEnd(Nodo<T>** head, T* _data)
{
	Nodo<T>* newend = new Nodo<T> * (_data);
	newend->setSig(nullptr);
	if (*(head) == nullptr)
	{
		newend->setPrev(nullptr);
		*head = newend;
		newend->setPos(cantidad++);
		return;
	}
	Nodo<T>* aux = *head;

	while (aux->getSig!=null)
	{
		aux = aux->getSig;
	}
	aux->setSig(newend);
	newend->setPrev(aux);
	newnend.setPos(cantidad++);
}

template<class T>
void ListaDoble<T>::popfront(Nodo<T>** head)
{
	if (*head == nullptr)
	{
		return;
	}
	head = (*head)->getSig();
	(*head)->getPrev()->setSig(nullptr);
	delete (*head)->getPrev();
	(*head)->setPrev(nullptr);
	
	Nodo<T>* aux = (*head);
	while (aux->getSig() !=null)
	{
		aux->setPos(aux->getPos() - 1);
	}


}









