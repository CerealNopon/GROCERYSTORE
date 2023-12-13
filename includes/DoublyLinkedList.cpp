// DoublyLinkedList.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "DoublyLinkedList.h"
#include "Node.h"
#include "account.h"
#include "product.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getHead() {
    return head;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getTail() {
    return tail;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
   Node<T>* current = head;
   
   while(current != nullptr) {
      Node<T>* temp = current->getNext();
      delete current;
      current = temp;
   }
   
   head = nullptr;
   tail = nullptr;
   
   listSize = 0;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
   return head == nullptr;
}

template <typename T>
int DoublyLinkedList<T>::size() const {
    return listSize;
}

template <typename T>
void DoublyLinkedList<T>::push_back(T data) {

    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }
    listSize++;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->getData() << std::endl;
        current = current->getNext();
    }
}

template <typename T>
void DoublyLinkedList<T>::loadFromFile(std::string filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        if (!isEmpty()) {
            clear();
        }

        std::string line;
        while (getline(file, line)) {
            // Create a node based on the content of the file
            std::istringstream iss(line);
            T data;
            iss >> data;

            // Check if the read was successful
            if (!iss.fail()) {
                push_back(data);
            } else {
                // Handle the case where the line doesn't contain the expected values.
                std::cerr << "Error: Invalid line - " << line << std::endl;
                // You might want to throw an exception or take appropriate action.
            }
        }

        file.close();
    } else {
        std::cerr << "Could not open file: " << filename << std::endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::loadCart(std::string filename) {
    std::ifstream file(filename);

    // Check if the file exists, if not, create it
    if (!file.is_open()) {
        std::ofstream createFile(filename);
        createFile.close();

        // Try opening the file again
        file.open(filename);

        if (!file.is_open()) {
            std::cerr << "Could not create or open file: " << filename << std::endl;
            return;
        }
    }

    if (!isEmpty()) {
        clear();
    }

    std::string line;
    while (getline(file, line)) {
        // Create a node based on the content of the file
        std::istringstream iss(line);
        T data;
        iss >> data;

        // Check if the read was successful
        if (!iss.fail()) {
            push_back(data);
        } else {
            // Handle the case where the line doesn't contain the expected values.
            std::cerr << "Error: Invalid line - " << line << std::endl;
            // You might want to throw an exception or take appropriate action.
        }
    }

    file.close();
}



template <typename T>
void DoublyLinkedList<T>::writeToFile(std::string filename) const {
    std::ofstream file(filename);

    if (file.is_open()) {
        Node<T>* current = head;

        while (current) {
            // Write the data to the file
            file << current->getData() << std::endl;

            current = current->getNext();
        }

        file.close();
    } else {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::swapNodes(Node<T>* node1, Node<T>* node2) {
    T temp = node1->getData();
    node1->setData(node2->getData());
    node2->setData(temp);
}

template <typename T>
void DoublyLinkedList<T>::sort() {
    // Check if the list is empty or has only one element
    if (head == nullptr || head == tail) {
        return;
    }

    bool swapped;
    Node<T>* last = nullptr;

    do {
        swapped = false;
        Node<T>* current = head;

        while (current->getNext() != last) {
            // Compare adjacent nodes and swap them if they are in the wrong order
            if (current->getData() > current->getNext()->getData()) {
                swapNodes(current, current->getNext());
                swapped = true;
            }
            current = current->getNext();
        }

        // Move the last swapped node to the end
        last = current;

    } while (swapped);
}


template class DoublyLinkedList<int>;
template class DoublyLinkedList<std::string>;
template class DoublyLinkedList<account>;
template class DoublyLinkedList<product>;
