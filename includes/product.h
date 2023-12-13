#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class product {
    public:
        product(std::string name, double price, int quantity, std::string type, int code);
        product();
        ~product();

        std::string getName() const;
        double getPrice() const;
        int getQuantity() const;
        std::string getType() const;
        int getCode() const;

        void setName(std::string name);
        void setPrice(double price);
        void setQuantity(int quantity);
        void setType(std::string type);
        void setCode(int code);

        bool operator==(const product& rhs);     // Compare to product
        bool operator!=(const product& rhs);     // Compare to product
        bool operator< (const product& rhs);     // Compare to product
        bool operator> (const product& rhs);     // Compare to product
        bool operator<=(const product& rhs);     // Compare to product
        bool operator>=(const product& rhs);     // Compare to product

        bool operator==(const int& rhs); // Compare to code
        bool operator!=(const int& rhs); // Compare to code
        bool operator< (const int& rhs); // Compare to code
        bool operator> (const int& rhs); // Compare to code
        bool operator<=(const int& rhs); // Compare to code
        bool operator>=(const int& rhs); // Compare to code

        bool operator==(const std::string& rhs); // Compare to code
        bool operator!=(const std::string& rhs); // Compare to code
        bool operator< (const std::string& rhs); // Compare to code
        bool operator> (const std::string& rhs); // Compare to code
        bool operator<=(const std::string& rhs); // Compare to code
        bool operator>=(const std::string& rhs); // Compare to code

        friend std::ostream& operator<<(std::ostream& os, const product& pro);

        // Declare the operator>> for account
        friend std::istream& operator>>(std::istream& is, product& pro);

    private:
        std::string name;
        double price;
        int quantity;
        std::string type;
        int code;
};

#endif // PRODUCT_H
