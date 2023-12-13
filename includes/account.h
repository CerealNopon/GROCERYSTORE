// account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
//#include "DoublyLinkedList.h"

template <class T> class DoublyLinkedList;

class account {
    public:
        account(std::string username, std::string password, std::string userType);
        account();
        virtual ~account();

        std::string getUsername() const;
        std::string getPassword() const;
        std::string getUserType() const;
        void setUsername(std::string username);
        void setPassword(std::string password);
        void setUserType(std::string userType);

        bool operator==(const account& rhs);     // Compare to account
        bool operator!=(const account& rhs);     // Compare to account
        bool operator< (const account& rhs);     // Compare to account
        bool operator> (const account& rhs);     // Compare to account
        bool operator<=(const account& rhs);     // Compare to account
        bool operator>=(const account& rhs);     // Compare to account

        bool operator==(const int& rhs); // Compare to username
        bool operator!=(const int& rhs); // Compare to username
        bool operator< (const int& rhs); // Compare to username
        bool operator> (const int& rhs); // Compare to username
        bool operator<=(const int& rhs); // Compare to username
        bool operator>=(const int& rhs); // Compare to username

        bool operator==(const std::string& rhs); // Compare to username
        bool operator!=(const std::string& rhs); // Compare to username
        bool operator< (const std::string& rhs); // Compare to username
        bool operator> (const std::string& rhs); // Compare to username
        bool operator<=(const std::string& rhs); // Compare to username
        bool operator>=(const std::string& rhs); // Compare to username

        // Define the operator<< for account
        friend std::ostream& operator<<(std::ostream& os, const account& acc);

        // Declare the operator>> for account
        friend std::istream& operator>>(std::istream& is, account& acc);

        void commonMethod(DoublyLinkedList<account>*& testLL);
        
    private:
        std::string username;
        std::string password;
        std::string userType;
};

#endif // ACCOUNT_H
