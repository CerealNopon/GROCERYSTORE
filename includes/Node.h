// Node.h

#ifndef NODE_H
#define NODE_H

#include <string>
#include "account.h"
#include "product.h"

template <typename T>
class Node {
   public:
      // Constructors
      Node(T data);

      // Destructor
      ~Node();

      // Getters
      T getData() const;
      Node<T>* getNext() const;
      Node<T>* getPrev() const;

      // Setters
      void setData(T newData);
      void setNext(Node<T>* newNext);
      void setPrev(Node<T>* newPrev);

   private:
      // Attributes
      T data;
      Node<T>* next;
      Node<T>* prev;
};

// Operator Overloads
template <typename T> bool operator==(const Node<T>& lhs, const Node<T>& rhs);
template <typename T> bool operator!=(const Node<T>& lhs, const Node<T>& rhs);
template <typename T> bool operator< (const Node<T>& lhs, const Node<T>& rhs);
template <typename T> bool operator> (const Node<T>& lhs, const Node<T>& rhs);
template <typename T> bool operator<=(const Node<T>& lhs, const Node<T>& rhs);
template <typename T> bool operator>=(const Node<T>& lhs, const Node<T>& rhs);

template <typename T> bool operator==(const Node<T>& lhs, const Node<T>& rhs)     { return lhs.getData() == rhs.getData(); }
template <typename T> bool operator!=(const Node<T>& lhs, const Node<T>& rhs)     { return lhs.getData() != rhs.getData(); }
template <typename T> bool operator< (const Node<T>& lhs, const Node<T>& rhs)     { return lhs.getData() <  rhs.getData(); }
template <typename T> bool operator> (const Node<T>& lhs, const Node<T>& rhs)     { return lhs.getData() >  rhs.getData(); }
template <typename T> bool operator<=(const Node<T>& lhs, const Node<T>& rhs)     { return lhs.getData() <= rhs.getData(); }
template <typename T> bool operator>=(const Node<T>& lhs, const Node<T>& rhs)     { return lhs.getData() >= rhs.getData(); }

template <typename T> bool operator==(const Node<T>& lhs, const std::string& rhs);
template <typename T> bool operator!=(const Node<T>& lhs, const std::string& rhs);
template <typename T> bool operator< (const Node<T>& lhs, const std::string& rhs);
template <typename T> bool operator> (const Node<T>& lhs, const std::string& rhs);
template <typename T> bool operator<=(const Node<T>& lhs, const std::string& rhs);
template <typename T> bool operator>=(const Node<T>& lhs, const std::string& rhs);

template <typename T> bool operator==(const Node<T>& lhs, const std::string& rhs) { return lhs.getData() == rhs; }
template <typename T> bool operator!=(const Node<T>& lhs, const std::string& rhs) { return lhs.getData() != rhs; }
template <typename T> bool operator< (const Node<T>& lhs, const std::string& rhs) { return lhs.getData() <  rhs; }
template <typename T> bool operator> (const Node<T>& lhs, const std::string& rhs) { return lhs.getData() >  rhs; }
template <typename T> bool operator<=(const Node<T>& lhs, const std::string& rhs) { return lhs.getData() <= rhs; }
template <typename T> bool operator>=(const Node<T>& lhs, const std::string& rhs) { return lhs.getData() >= rhs; }

template <typename T> bool operator==(const Node<T>& lhs, const int& rhs);
template <typename T> bool operator!=(const Node<T>& lhs, const int& rhs);
template <typename T> bool operator< (const Node<T>& lhs, const int& rhs);
template <typename T> bool operator> (const Node<T>& lhs, const int& rhs);
template <typename T> bool operator<=(const Node<T>& lhs, const int& rhs);
template <typename T> bool operator>=(const Node<T>& lhs, const int& rhs);

template <typename T> bool operator==(const Node<T>& lhs, const int& rhs) { return lhs.getData() == rhs; }
template <typename T> bool operator!=(const Node<T>& lhs, const int& rhs) { return lhs.getData() != rhs; }
template <typename T> bool operator< (const Node<T>& lhs, const int& rhs) { return lhs.getData() <  rhs; }
template <typename T> bool operator> (const Node<T>& lhs, const int& rhs) { return lhs.getData() >  rhs; }
template <typename T> bool operator<=(const Node<T>& lhs, const int& rhs) { return lhs.getData() <= rhs; }
template <typename T> bool operator>=(const Node<T>& lhs, const int& rhs) { return lhs.getData() >= rhs; }


#endif // NODE_H
