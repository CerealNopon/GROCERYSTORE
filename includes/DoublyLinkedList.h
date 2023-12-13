// DoublyLinkedList.h

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h" // Include Node.h to use the Node template
#include "account.h" // Include account.h for the account type
#include "product.h" // Include product.h for the product type

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int listSize;

public:
    DoublyLinkedList(); 
    ~DoublyLinkedList();
    Node<T>* getHead();
    Node<T>* getTail();
    int size() const;

    void push_back(T data);

    void loadFromFile(std::string filename);
    void loadCart(std::string filename);
    void writeToFile(std::string filename) const;

    template <typename T2>
    bool deleteNode(T2 data);

    template <typename T2>
    Node<T>* findNode(T2 data);

    void swapNodes(Node<T>* node1, Node<T>* node2);
    void sort();

    void print() const;
    bool isEmpty() const;
    void clear();

};

template <typename T>
template <typename T2>
bool DoublyLinkedList<T>::deleteNode(T2 data) {
    Node<T>* current = findNode(data);  // Use findNode directly to get the node to delete
    if (current) {
        if (current == head) {
            head = current->getNext();
            if (head) {
                head->setPrev(nullptr);
            }
        } else if (current == tail) {
            tail = current->getPrev();
            tail->setNext(nullptr);
        } else {
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
        }

        delete current;
        listSize--;
        return true;
    }
    return false;
}

template <typename T>
template <typename T2>
Node<T>* DoublyLinkedList<T>::findNode(T2 data) {
    Node<T>* current = head;
    while (current) {
        if (current->getData() == data) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

#endif // DOUBLYLINKEDLIST_H