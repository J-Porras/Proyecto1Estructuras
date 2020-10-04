//#pragma once
//#include "Heap.h"
//
//template<class T>
//class ColaPrioridad
//{
//private:
//	bool isMax;//true = heap de max, 
//	Heap<T>* heap;
//public:
//
//	ColaPrioridad(bool = true);
//	ColaPrioridad(ColaPrioridad&);
//	//ColaPrioridad(bool,ListaDoble);
//	//boolean add(T*);
//	//void clear();
//	//T* peek(); //Devuelve el Elemento cabeza pero no lo remueve
//	//T* poll(); //Devuelve el Elemento cabeza y lo remueve
//	//int size();
//
//	bool getIsMax();
//	Heap<T>* getHeap();
//
//
//	bool compara(T& obj_a, T& obj_b);
//
//};
//
//template<class T>
//ColaPrioridad<T>::ColaPrioridad(bool a) {
//	isMax = a;
//	heap = new Heap<T>(new ListaDoble<T>());
//}
//
//template<class T>
//ColaPrioridad<T>::ColaPrioridad(ColaPrioridad& c) {
//	isMax = c.getIsMax()
//	ListaDoble list<T>(c.getHeap()->getList());
//	heap = new Heap<T>(list);
//
//
//}
//
//
//template<class T>
//bool ColaPrioridad<T>::getIsMax() {
//	return isMax;
//}
//
//template<class T>
//Heap<T>* ColaPrioridad<T>::getHeap() {
//	return heap;
//}
//
//template <class T>	
//bool ColaPrioridad<T>::compara(T& obj_a, T& obj_b) {
//	return (obj_a > obj_b) ? true : false;
//}
//
