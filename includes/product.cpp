// product.cpp

#include <string>
#include <iomanip>
#include "product.h"

product::product(std::string name, double price, int quantity, std::string type, int code)
    : name(name), price(price), quantity(quantity), type(type), code(code) {}

product::product()
    : name(""), price(0.0), quantity(0), type(""), code(0) {}

product::~product() {}

std::string product::getName() const { return name;}
double product::getPrice() const { return price; }
int product::getQuantity() const { return quantity; }
std::string product::getType() const { return type; }
int product::getCode() const { return code; }

void product::setName(std::string name) { this->name = name; }
void product::setPrice(double price) { this->price = price; }
void product::setQuantity(int quantity) { this->quantity = quantity; }
void product::setType(std::string type) { this->type = type; }
void product::setCode(int code) { this->code = code; }

bool product::operator==(const product& rhs) { return  (  getName() == rhs.getName() ); }
bool product::operator!=(const product& rhs) { return !(  *this == rhs                      ); }
bool product::operator< (const product& rhs) { return  (  getName() <  rhs.getName() ); }
bool product::operator> (const product& rhs) { return  (  getName() >  rhs.getName() ); }
bool product::operator<=(const product& rhs) { return !(  *this >  rhs                      ); }
bool product::operator>=(const product& rhs) { return !(  *this <  rhs                      ); }

bool product::operator==(const std::string& rhs) { return  (  getName() == rhs ); }
bool product::operator!=(const std::string& rhs) { return !(  *this == rhs            ); }
bool product::operator< (const std::string& rhs) { return  (  getName() <  rhs ); }
bool product::operator> (const std::string& rhs) { return  (  getName() >  rhs ); }
bool product::operator<=(const std::string& rhs) { return !(  *this >  rhs            ); }
bool product::operator>=(const std::string& rhs) { return !(  *this <  rhs            );  }

bool product::operator==(const int& rhs) { return  (  getCode() == rhs ); }
bool product::operator!=(const int& rhs) { return !(  *this == rhs            ); }
bool product::operator< (const int& rhs) { return  (  getCode() <  rhs ); }
bool product::operator> (const int& rhs) { return  (  getCode() >  rhs ); }
bool product::operator<=(const int& rhs) { return !(  *this >  rhs            ); }
bool product::operator>=(const int& rhs) { return !(  *this <  rhs            ); }

// Implement the operator<< for account
std::ostream& operator<<(std::ostream& os, const product& pro) {
    os << std::setw(15) << std::left << pro.getName()
       << std::setw(7) << std::left << pro.getPrice()
       << std::setw(10) << std::left << pro.getQuantity()
       << std::setw(10) << std::left << pro.getType()
       << std::setw(9) << std::left << pro.getCode();
    return os;

    //os << pro.getName() << " " << pro.getPrice() << " " << pro.getQuantity() << " " << pro.getCode();
    //return os;
}


// Implement the operator>> for account
std::istream& operator>>(std::istream& is, product& pro) {
    std::string name, type;
    double price;
    int quantity, code;
    // Read data from the input stream
    is >> name >> price >> quantity >> type >> code;
    // Set the data in the account object
    pro.setName(name);
    pro.setPrice(price);
    pro.setQuantity(quantity);
    pro.setType(type);
    pro.setCode(code);
    return is;
}