// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "includes\DoublyLinkedList.h"
#include "includes\test.h"
#include "includes\account.h"
#include "includes\customer.h"
#include "includes\administrator.h"

#define ACCOUNTS_FILE "includes\\accounts.txt"
#define PRODUCTS_FILE "includes\\inventory.txt"

using namespace std;

account login(DoublyLinkedList<account>*& accLL) {
    string username, password;
    cout << "********************************" << endl;
    cout << "* Welcome to the login screen! *" << endl;
    cout << "********************************" << endl;
    string cont = "yes";

    while (cont == "yes") {
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        if (accLL->findNode(account(username, password, "customer"))) {
            cout << "Welcome customer!" << endl;
            return account(username, password, "customer");
        } else if (accLL->findNode(account(username, password, "administrator"))) {
            cout << "Welcome administrator!" << endl;
            return account(username, password, "administrator");
        } else {
            cout << "ERROR: We could not find your account :(\nWould you like to try again? yes or no" << endl;
            getline(cin, cont);
        }
    }
    return account("", "", "");
}

account createAccount(DoublyLinkedList<account>*& accLL) {
    string username, password, confirmPassword;
    string cont = "yes";
    cout << "********************************" << endl;
    cout << "* Please create your account   *" << endl;
    cout << "********************************" << endl;

    while (cont == "yes") {
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << "Confirm password: ";
        getline(cin, confirmPassword);

        if (password != confirmPassword) {
            cout << "ERROR: Passwords do not match." << endl;
        } if (accLL->findNode(username)) {
            cout << "ERROR: An account with that username already exists." << endl;
        } if (password != confirmPassword || accLL->findNode(username)) {
            cout << "Would you like to try again? yes or no" << endl;
            getline(cin, cont);
            continue;
        }
        cout << "Account Creation Successful. Logging you in!" << endl;
        (*accLL).push_back(account(username, password, "customer"));
        return account(username, password, "customer");
    }
    return account("", "", "");
}

string selectProductGroup() {
    int type;
    std::string group;

    do {
        std::cout << "What group does this product belong in?" << std::endl;
        std::cout << "1) Produce" << std::endl;
        std::cout << "2) Dairy" << std::endl;
        std::cout << "3) Bakery" << std::endl;
        std::cout << "4) Other" << std::endl;
        getline(cin, group);
        type = stoi(group);

        if (type < 1 || type > 4) {
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
        }

    } while (type < 1 || type > 4);

    switch (type) {
        case 1:
            group = "Produce";
            break;
        case 2:
            group = "Dairy";
            break;
        case 3:
            group = "Bakery";
            break;
        case 4:
            group = "Other";
            break;
    }

    return group;
}

string selectProductName(DoublyLinkedList<product>* proLL) {
    string name;
    bool isValidInput = false;
    Node<product>* current;

    do {
        cout << "Enter the name of the item: ";
        getline(cin, name);

        // Check if the entered name matches one of the instances
        current = (*proLL).getHead();
        if (current == nullptr) {
            return "";
        }
        while (current != nullptr) {
            if (name == current->getData().getName()) {
                isValidInput = true;
                break;
            }
            current = current->getNext();
        }

        if (!isValidInput) {
            cout << "Invalid input. Please enter a valid item name." << endl;
        }

    } while (!isValidInput);

    return name;
}

void enterAccount(account& currentAccount, DoublyLinkedList<product>*& proLL, DoublyLinkedList<account>*& accLL) {
    string userType = currentAccount.getUserType();
    DoublyLinkedList<product>* cartLL = new DoublyLinkedList<product>;
    int choice = 0;
    Node<product>* current;
    Node<product>* cartCurrent;
    product tempProduct;
    string strChoice;
    string name, username, password, group;
    double price;
    int quantity, code, type, amount, amountLeft;


    string cartTextFile = "includes\\" + currentAccount.getUsername() + "Cart.txt";
    (*cartLL).loadCart(cartTextFile);


    while(choice != -1) {
        cout << endl;
        cout << "***********************************" << endl;
        if (userType == "administrator") {
            cout << "*  Administrator Menu             *" << endl;
        } else {
            cout << "*  Customer Menu                  *" << endl;
        }
        cout << "*  (1) Check Inventory            *" << endl;
        cout << "*  (2) Sort by name               *" << endl;

        if (userType == "administrator") {
            cout << "*  (3) Add new inventory          *" << endl;
            cout << "*  (4) Modify inventory           *" << endl;
            cout << "*  (5) Delete inventory           *" << endl;
            cout << "*  (6) Make administrator account *" << endl;
            cout << "*  (7) View Accounts              *" << endl;
        } else {
            cout << "*  (3) View Cart                  *" << endl;
            cout << "*  (4) Add to cart                *" << endl;
            cout << "*  (5) Remove from cart           *" << endl;
            cout << "*  (6) Purchase                   *" << endl;
        }
        cout << "* (-1) Exit                       *" << endl;
        cout << "*                 Select Number   *" << endl;
        cout << "***********************************" << endl;
        cout << "Input: ";
        getline(cin, strChoice);
        choice = stoi(strChoice);
        cout << endl;

        switch(choice) {
            case 1:
                cout << "**********************" << endl;
                cout << "* PRINTING INVENTORY *" << endl;
                cout << "**********************" << endl;
                cout << endl;
                cout << std::setw(15) << std::left << "NAME"
                     << std::setw(7) << std::left << "PRICE"
                     << std::setw(10) << std::left << "QUANTITY"
                     << std::setw(10) << std::left << "TYPE"
                     << std::setw(9) << std::left << "CODE" << endl;
                (*proLL).print();
                cout << endl;
                break;
            case 2:
                (*proLL).sort();
                cout << "*******************" << endl;
                cout << "* Sorted by name! *" << endl;
                cout << "*******************" << endl;
                cout << endl;
                break;
            case 3: // Add new inventory || View cart
                if (userType == "administrator") {
                    cout << "*****************************" << endl;
                    cout << "* Adding new inventory      *" << endl;
                    cout << "*****************************" << endl;
                    cout << endl;
                    cout << "What is the name of the product?" << endl;
                    getline(cin, name);
                    cout << "What is the quantity (int) of the product?" << endl;
                    getline(cin, strChoice);
                    quantity = stoi(strChoice);
                    cout << "What is the price (double) of the product?" << endl;
                    getline(cin, strChoice);
                    price = stod(strChoice);
                    group = selectProductGroup();
                    cout << "What is the code (4-digit int) of the product?" << endl;
                    getline(cin, strChoice);
                    code = stoi(strChoice);
                    (*proLL).push_back(product(name, price, quantity, group, code));
                    cout << "Inventory added successfully!" << endl;
                    cout << "Returning to account menu..." << endl;
                } else {
                    cout << "**********************" << endl;
                    cout << "* PRINTING CART      *" << endl;
                    cout << "**********************" << endl;
                    cout << std::setw(15) << std::left << "NAME"
                         << std::setw(7) << std::left << "PRICE"
                         << std::setw(10) << std::left << "QUANTITY"
                         << std::setw(10) << std::left << "TYPE"
                         << std::setw(9) << std::left << "CODE" << endl;
                    (*cartLL).print();
                    cout << "**********************" << endl;
                    cout << "* END OF CART        *" << endl;
                    cout << "**********************" << endl;
                }
                break;
            case 4: // Add existing inventory || Add to cart
                if (userType == "administrator") {

                    cout << "************************************" << endl;
                    cout << "* Modify Product in Inventory      *" << endl;
                    cout << "************************************" << endl;

                    name = selectProductName(proLL);

                    // Get pointer to product
                    current = (*proLL).getHead();
                    while (current != nullptr) {
                        if (current->getData().getName() == name) {
                            break;
                        }
                        current = current->getNext();
                    }
    
                    cout << "Current quantity: " << current->getData().getQuantity() << ". Change? yes or no" << endl;
                    getline(cin, strChoice);
                    if (strChoice == "yes") {
                        cout << "Change to what quantity (int): ";
                        getline(cin, strChoice);
                        quantity = stoi(strChoice);
                        cout << endl;
                    } else { quantity = current->getData().getQuantity(); }
                    cout << "Current price: " << current->getData().getPrice() << ". Change? yes or no" << endl;
                    getline(cin, strChoice);
                    if (strChoice == "yes") {
                        cout << "Change to what price (double): ";
                        getline(cin, strChoice);
                        price = stod(strChoice);
                        cout << endl;
                    } else { price = current->getData().getPrice(); }
                    cout << "Current code: " << current->getData().getCode() << ". Change? yes or no" << endl;
                    getline(cin, strChoice);
                    if (strChoice == "yes") {
                        cout << "Change to what code: ";
                        getline(cin, strChoice);
                        code = stoi(strChoice);
                        cout << endl;
                    } else { code = current->getData().getCode(); }
                    cout << "Current type: " << current->getData().getType() << ". Change? yes or no" << endl;
                    getline(cin, strChoice);
                    if (strChoice == "yes") {
                        group = selectProductGroup();
                    } else { group = current->getData().getType(); }

                    (*current).setData(product(name, price, quantity, group, code));

                    cout << name << " successfully modified. Returning to menu..." << endl;

                } else {

                    cout << "**********************" << endl;
                    cout << "* ADD TO CART        *" << endl;
                    cout << "**********************" << endl;
                    cout << endl;

                    // get item name from inventory
                    name = selectProductName(proLL);

                    // get pointer to item name in inventory
                    current = (*proLL).getHead();
                    while (current != nullptr) {
                        if (current->getData().getName() == name) {
                            break;
                        }                        
                        current = current->getNext();
                    }
                    cout << endl;


                    // select valid amount to take from inventory
                    do {
                        cout << "Select amount to purchase: ";
                        string strChoice;
                        getline(cin, strChoice);
                        amount = stoi(strChoice);

                        // Remove amount from Node, never past 0
                        amountLeft = current->getData().getQuantity() - amount;

                        // Check if the entered amount is too much
                        if (amountLeft < 0) {
                            cout << "Error: The entered amount is too much. Please try again." << endl;
                        }

                    } while (amountLeft < 0);

                    // initially add inventory into cart
                    (*cartLL).push_back(current->getData());


                    // get pointer to item name in cart
                    cartCurrent = (*cartLL).getHead();
                    while (cartCurrent != nullptr) {
                        if (cartCurrent->getData().getName() == name) {
                            break;
                        }                        
                        cartCurrent = cartCurrent->getNext();
                    }
                    cout << endl;

                    // get attributes from product
                    name = (*cartCurrent).getData().getName();
                    price = (*cartCurrent).getData().getPrice();
                    group = (*cartCurrent).getData().getType();
                    code = (*cartCurrent).getData().getCode();

                    // set both products in both LLs
                    (*cartCurrent).setData(product(name, price, amount, group, code));
                    (*current).setData(product(name, price, amountLeft, group, code));

                    cout << "Added " << amount << " " << name << " to your cart!" << endl;

                }
                break;

            case 5: // Delete inventory || Remove from cart


                if (userType == "administrator") {

                    cout << "**********************" << endl;
                    cout << "* Delete product      *" << endl;
                    cout << "**********************" << endl;
                    cout << endl;

                    name = selectProductName(proLL);

                    current = (*proLL).getHead();
                    while (current != nullptr) {
                        if (current->getData().getName() == name) {
                            cout << "Pointer to " << name << " found!" << endl;
                            break;
                        }                        
                        current = current->getNext();
                    }
                    cout << endl;

                    cout << current->getData().getName() << endl;
                    (*proLL).deleteNode(current->getData());
                    cout << name << " deleted successfully" << endl;

                } else {

                    cout << "**********************" << endl;
                    cout << "* Remove from cart   *" << endl;
                    cout << "**********************" << endl;
                    cout << endl;

                    if ((*cartLL).getHead() == nullptr) {
                        cout << "Cart is currently empty!" << endl;
                        break;
                    }

                    (*cartLL).print();
                    name = selectProductName(cartLL);

                    cartCurrent = (*cartLL).getHead();
                    while (cartCurrent != nullptr) {
                        if (cartCurrent->getData().getName() == name) {
                            break;
                        }                        
                        cartCurrent = cartCurrent->getNext();
                    }
                    amount = (*cartCurrent).getData().getQuantity();
                    name = (*cartCurrent).getData().getName();
                    price = (*cartCurrent).getData().getPrice();
                    group = (*cartCurrent).getData().getType();
                    code = (*cartCurrent).getData().getCode();

                    (*cartLL).deleteNode(cartCurrent->getData());


                    current = (*proLL).getHead();
                    while (current != nullptr) {
                        if (current->getData().getName() == name) {
                            break;
                        }                        
                        current = current->getNext();
                    }
                    amountLeft = amount + (*current).getData().getQuantity();
                    (*current).setData(product(name, price, amountLeft, group, code));
                    cout << "Removed " << name << " from your cart. Returned to inventory!" << endl;
                }
                break;

            case 6: // Create admin account || Make purchase
                if (userType == "administrator") {
                    cout << "*************************" << endl;
                    cout << "* Creat Admin Account   *" << endl;
                    cout << "*************************" << endl;
                    cout << endl;

                    cout << "username: ";
                    getline(cin, username);
                    cout << "password: ";
                    getline(cin, password);
                    (*accLL).push_back(account(username, password, "administrator"));
                    cout << "Administrator Account Successful";
                    cout << endl;

                } else {
                    cout << "**********************" << endl;
                    cout << "* PRINTING CART      *" << endl;
                    cout << "**********************" << endl;
                    cout << std::setw(15) << std::left << "NAME"
                         << std::setw(7) << std::left << "PRICE"
                         << std::setw(10) << std::left << "QUANTITY"
                         << std::setw(10) << std::left << "TYPE"
                         << std::setw(9) << std::left << "CODE" << endl;
                    (*cartLL).print();
                    cout << "**********************" << endl;
                    cout << "* END OF CART        *" << endl;
                    cout << "**********************" << endl;
                    cout << endl;

                    do {
                        cout << "Are you sure you're ready to check out? yes or no?";
                        getline(cin, strChoice);
                    } while (strChoice != "yes" && strChoice != "no");

                    if (strChoice == "no") {
                        break;
                    } else {
                        cout << "**********************" << endl;
                        cout << "* Receipt            *" << endl;
                        cout << "**********************" << endl;
                        cout << std::setw(15) << std::left << "NAME"
                         << std::setw(7) << std::left << "PRICE"
                         << std::setw(10) << std::left << "QUANTITY"
                         << std::setw(10) << std::left << "TYPE"
                         << std::setw(9) << std::left << "CODE" << endl;
                        (*cartLL).print();
                        (*cartLL).clear();
                    }
                }
                break;
            case 7: // Print Accounts
                if (userType == "administrator") {
                    cout << std::setw(20) << std::left << "USERNAME"
                        << std::setw(20) << std::left << "PASSWORD"
                        << std::setw(15) << std::left << "USERTYPE" << endl;
                    (*accLL).print();
                    cout << endl;
                } else {
                    cout << "ERROR: Invalid option, please choose again. " << endl;
                }
                break;
            case -1:
                cout << "Now logging you out!" << endl;
                if (userType == "customer") {
                    (*cartLL).writeToFile(cartTextFile);
                }
                (*accLL).writeToFile(ACCOUNTS_FILE);
                (*proLL).writeToFile(PRODUCTS_FILE);
                break;
            default:
                cout << "ERROR: Invalid option, please choose again. " << endl;
                break;
        }
    }
}

int main() {

    DoublyLinkedList<account>* accLL = new DoublyLinkedList<account>;
    (*accLL).loadFromFile(ACCOUNTS_FILE);
    DoublyLinkedList<product>* proLL = new DoublyLinkedList<product>;
    (*proLL).loadFromFile(PRODUCTS_FILE);

    int choice = 0;
    string strChoice;
    account currentAccount;

    while(choice != -1) {
        cout << endl;
        cout << "*****************************" << endl;
        cout << "* Grocery Market Menu       *" << endl;
        cout << "* 1) Login to your account  *" << endl;
        cout << "* 2) Create an account      *" << endl;
        cout << "* 3) Exit                   *" << endl;
        cout << "*          Select Number    *" << endl;
        cout << "*****************************" << endl;
        cout << "Input: ";
        getline(cin, strChoice);
        choice = stoi(strChoice);
        cout << endl;
        cout << endl;

        switch(choice) {
            case 1:
                currentAccount = login(accLL);
                if (currentAccount != "") { enterAccount(currentAccount, proLL, accLL); }
                break;
            case 2:
                currentAccount = createAccount(accLL);
                if (currentAccount != "") { enterAccount(currentAccount, proLL, accLL); }
                break;
            case 3:
                cout << "Thanks for shopping with us! See you next time!" << endl;
                (*accLL).writeToFile(ACCOUNTS_FILE);
                (*proLL).writeToFile(PRODUCTS_FILE);
                return 0;
            default:
                cout << "ERROR: Invalid option, please choose again. " << endl;
                break;
        }
    }

    return 0;
}
