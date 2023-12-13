// Node.cpp

#include <string>
#include "Node.h"
#include "account.h"
#include "product.h"

// Constructor
template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
T Node<T>::getData() const { return data; }

template <typename T>
Node<T>* Node<T>::getNext() const { return next; }

template <typename T>
Node<T>* Node<T>::getPrev() const { return prev; }

template <typename T>
void Node<T>::setData(T newData) { data = newData; }

template <typename T>
void Node<T>::setNext(Node* newNext) { next = newNext; }

template <typename T>
void Node<T>::setPrev(Node* newPrev) { prev = newPrev; }

template class Node<int>;
template class Node<std::string>;
template class Node<class account>;
template class Node<class product>;
