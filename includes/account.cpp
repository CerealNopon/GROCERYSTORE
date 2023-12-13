// account.cpp

#include <string>
#include <iomanip>
#include "account.h"
#include "DoublyLinkedList.h"

account::account(std::string username, std::string password, std::string userType)
    : username(username), password(password), userType(userType) {}

account::account()
    : username(""), password(""), userType("") {}
    
account::~account() {}

std::string account::getUsername() const { return username; }
std::string account::getPassword() const { return password; }
std::string account::getUserType() const { return userType; }

void account::setUsername(std::string newUsername) { username = newUsername; }
void account::setPassword(std::string newPassword) { password = newPassword; }
void account::setUserType(std::string newUserType) { userType = newUserType; }

bool account::operator==(const account& rhs) { return  (  this->getUsername() == rhs.getUsername() &&
                                                          this->getPassword() == rhs.getPassword() &&
                                                          this->getUserType() == rhs.getUserType() ); }
bool account::operator!=(const account& rhs) { return !( *this == rhs                              ); }
bool account::operator< (const account& rhs) { return  (  this->getUsername() <  rhs.getUsername() ); }
bool account::operator> (const account& rhs) { return  (  this->getUsername() >  rhs.getUsername() ); }
bool account::operator<=(const account& rhs) { return !( *this > rhs                               ); }
bool account::operator>=(const account& rhs) { return !( *this < rhs                               ); }

bool account::operator==(const std::string& rhs) { return  (  this->getUsername() == rhs); }
bool account::operator!=(const std::string& rhs) { return !( *this == rhs               ); }
bool account::operator< (const std::string& rhs) { return  (  this->getUsername() <  rhs); }
bool account::operator> (const std::string& rhs) { return  (  this->getUsername() >  rhs); }
bool account::operator<=(const std::string& rhs) { return !( *this >  rhs               ); }
bool account::operator>=(const std::string& rhs) { return !( *this <  rhs               ); }

bool account::operator==(const int& rhs) { return  ( true ); }
bool account::operator!=(const int& rhs) { return !( true ); }
bool account::operator< (const int& rhs) { return  ( true ); }
bool account::operator> (const int& rhs) { return  ( true ); }
bool account::operator<=(const int& rhs) { return !( true ); }
bool account::operator>=(const int& rhs) { return !( true ); }

// Implement the operator<< for account
std::ostream& operator<<(std::ostream& os, const account& acc) {

    // Set the width for each field to ensure consistent spacing
    os << std::setw(20) << std::left << acc.getUsername()
       << std::setw(20) << std::left << acc.getPassword()
       << std::setw(15) << std::left << acc.getUserType();
    return os;

    // os << acc.getUsername() << " " << acc.getPassword() << " " << acc.getUserType();
    // return os;
}

// Implement the operator>> for account
std::istream& operator>>(std::istream& is, account& acc) {
    std::string username, password, userType;
    // Read data from the input stream
    is >> username >> password >> userType;
    // Set the data in the account object
    acc.setUsername(username);
    acc.setPassword(password);
    acc.setUserType(userType);
    return is;
}

void commonMethod(DoublyLinkedList<account>*& testLL) {
    std::cout << "commonMethod used" << std::endl;
    return;
}