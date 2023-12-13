// test.cpp

#include <iostream> 
#include <string>

#include "test.h"
#include "DoublyLinkedList.h"
#include "Node.h"
#include "account.h"
#include "product.h"

using namespace std;

void testClassComparisions() {
    account accA = account("aaaa", "aaaa", "customer");
    account accB = account("bbbb", "bbbb", "customer");
    string wordA = "aaaa";
    string wordB = "bbbb";

    cout << "Test cases for account objects" << endl;
    std::cout << "accA == accA:  true  " << std::boolalpha << (accA == accA) << std::endl;
    std::cout << "accA != accA:  false " << std::boolalpha << (accA != accA) << std::endl;
    std::cout << "accA <  accA:  false " << std::boolalpha << (accA <  accA) << std::endl;
    std::cout << "accA >  accA:  false " << std::boolalpha << (accA >  accA) << std::endl;
    std::cout << "accA <= accA:  true  " << std::boolalpha << (accA <= accA) << std::endl;
    std::cout << "accA >= accA:  true  " << std::boolalpha << (accA >= accA) << std::endl;

    std::cout << "\n";

    std::cout << "accA == wordA: true  " << std::boolalpha << (accA == wordA) << std::endl;
    std::cout << "accA != wordA: false " << std::boolalpha << (accA != wordA) << std::endl;
    std::cout << "accA <  wordA: false " << std::boolalpha << (accA <  wordA) << std::endl;
    std::cout << "accA >  wordA: false " << std::boolalpha << (accA >  wordA) << std::endl;
    std::cout << "accA <= wordA: true  " << std::boolalpha << (accA <= wordA) << std::endl;
    std::cout << "accA >= wordA: true  " << std::boolalpha << (accA >= wordA) << std::endl;

    std::cout << "\n";

    std::cout << "accA == accB:  false " << std::boolalpha << (accA == accB) << std::endl;
    std::cout << "accA != accB:  true  " << std::boolalpha << (accA != accB) << std::endl;
    std::cout << "accA <  accB:  true  " << std::boolalpha << (accA <  accB) << std::endl;
    std::cout << "accA >  accB:  false " << std::boolalpha << (accA >  accB) << std::endl;
    std::cout << "accA <= accB:  true  " << std::boolalpha << (accA <= accB) << std::endl;
    std::cout << "accA >= accB:  false " << std::boolalpha << (accA >= accB) << std::endl;

    std::cout << "\n";

    std::cout << "accA == wordB: false " << std::boolalpha << (accA == wordB) << std::endl;
    std::cout << "accA != wordB: true  " << std::boolalpha << (accA != wordB) << std::endl;
    std::cout << "accA <  wordB: true  " << std::boolalpha << (accA <  wordB) << std::endl;
    std::cout << "accA >  wordB: false " << std::boolalpha << (accA >  wordB) << std::endl;
    std::cout << "accA <= wordB: true  " << std::boolalpha << (accA <= wordB) << std::endl;
    std::cout << "accA >= wordB: false " << std::boolalpha << (accA >= wordB) << std::endl;

    std::cout << "\n";

    DoublyLinkedList<product>* proDLL = new DoublyLinkedList<product>();
    product pro1 = product("one", 11.11, 11, "dairy", 1111);
    product pro2 = product("two", 22.22, 22, "dairy", 2222);
    int num1 = 1111;
    int num2 = 2222;

    cout << "Test cases for product objects" << endl;
    std::cout << "pro1 == pro1:  true  " << std::boolalpha << (pro1 == pro1) << std::endl;
    std::cout << "pro1 != pro1:  false " << std::boolalpha << (pro1 != pro1) << std::endl;
    std::cout << "pro1 <  pro1:  false " << std::boolalpha << (pro1 <  pro1) << std::endl;
    std::cout << "pro1 >  pro1:  false " << std::boolalpha << (pro1 >  pro1) << std::endl;
    std::cout << "pro1 <= pro1:  true  " << std::boolalpha << (pro1 <= pro1) << std::endl;
    std::cout << "pro1 >= pro1:  true  " << std::boolalpha << (pro1 >= pro1) << std::endl;

    std::cout << "\n";

    std::cout << "pro1 == num1: true  " << std::boolalpha << (pro1 == num1) << std::endl;
    std::cout << "pro1 != num1: false " << std::boolalpha << (pro1 != num1) << std::endl;
    std::cout << "pro1 <  num1: false " << std::boolalpha << (pro1 <  num1) << std::endl;
    std::cout << "pro1 >  num1: false " << std::boolalpha << (pro1 >  num1) << std::endl;
    std::cout << "pro1 <= num1: true  " << std::boolalpha << (pro1 <= num1) << std::endl;
    std::cout << "pro1 >= num1: true  " << std::boolalpha << (pro1 >= num1) << std::endl;

    std::cout << "\n";

    std::cout << "pro1 == pro2:  false " << std::boolalpha << (pro1 == pro2) << std::endl;
    std::cout << "pro1 != pro2:  true  " << std::boolalpha << (pro1 != pro2) << std::endl;
    std::cout << "pro1 <  pro2:  true  " << std::boolalpha << (pro1 <  pro2) << std::endl;
    std::cout << "pro1 >  pro2:  false " << std::boolalpha << (pro1 >  pro2) << std::endl;
    std::cout << "pro1 <= pro2:  true  " << std::boolalpha << (pro1 <= pro2) << std::endl;
    std::cout << "pro1 >= pro2:  false " << std::boolalpha << (pro1 >= pro2) << std::endl;

    std::cout << "\n";

    std::cout << "pro1 == num2: false " << std::boolalpha << (pro1 == num2) << std::endl;
    std::cout << "pro1 != num2: true  " << std::boolalpha << (pro1 != num2) << std::endl;
    std::cout << "pro1 <  num2: true  " << std::boolalpha << (pro1 <  num2) << std::endl;
    std::cout << "pro1 >  num2: false " << std::boolalpha << (pro1 >  num2) << std::endl;
    std::cout << "pro1 <= num2: true  " << std::boolalpha << (pro1 <= num2) << std::endl;
    std::cout << "pro1 >= num2: false " << std::boolalpha << (pro1 >= num2) << std::endl;
    std::cout << "\n";

}

void testPrintAndPushBack() {
    if (true) {
        DoublyLinkedList<int>* intDLL = new DoublyLinkedList<int>();
        (*intDLL).push_back(1);
        (*intDLL).push_back(2);
        (*intDLL).push_back(3);
        (*intDLL).print();
        std::cout << "Size: " << (*intDLL).size() << std::endl;

        DoublyLinkedList<string>* strDLL = new DoublyLinkedList<string>();
        (*strDLL).push_back("one");
        (*strDLL).push_back("two");
        (*strDLL).push_back("thr");
        (*strDLL).print();
        std::cout << "Size: " << (*strDLL).size() << std::endl;

        DoublyLinkedList<account>* accDLL = new DoublyLinkedList<account>();
        (*accDLL).push_back( account("one", "pass", "customer") );
        (*accDLL).push_back( account("two", "pass", "customer") );
        (*accDLL).push_back( account("thr", "pass", "customer") );
        (*accDLL).print();
        std::cout << "Size: " << (*accDLL).size() << std::endl;

        DoublyLinkedList<product>* proDLL = new DoublyLinkedList<product>();
        (*proDLL).push_back( product("one", 19.34, 95, "dairy", 3455) );
        (*proDLL).push_back( product("two", 14.34, 45, "dairy", 3456) );
        (*proDLL).push_back( product("thr", 17.34, 25, "dairy", 3457) );
        (*proDLL).print();
        std::cout << "Size: " << (*proDLL).size() << std::endl;
    }
}

void testNodeComparisons() {
    
    // account with account & string (using getData())
    {
    Node<account> accNodeA(account("aaaa", "aaaa", "customer"));
    Node<account> accNodeB(account("bbbb", "bbbb", "customer"));
    string wordA = "aaaa";
    string wordB = "bbbb";  

    std::cout << "Comparing Node<account> to same Node<account>" << std::endl;
    std::cout << "accNodeA == accNodeA:  true  " << std::boolalpha << (accNodeA == accNodeA) << std::endl;
    std::cout << "accNodeA != accNodeA:  false " << std::boolalpha << (accNodeA != accNodeA) << std::endl;
    std::cout << "accNodeA <  accNodeA:  false " << std::boolalpha << (accNodeA <  accNodeA) << std::endl;
    std::cout << "accNodeA >  accNodeA:  false " << std::boolalpha << (accNodeA >  accNodeA) << std::endl;
    std::cout << "accNodeA <= accNodeA:  true  " << std::boolalpha << (accNodeA <= accNodeA) << std::endl;
    std::cout << "accNodeA >= accNodeA:  true  " << std::boolalpha << (accNodeA >= accNodeA) << std::endl;  
    std::cout << "\n";

    std::cout << "Comparing Node<account> to diff Node<account>" << std::endl;
    std::cout << "accNodeA == accNodeB:  false " << std::boolalpha << (accNodeA == accNodeB) << std::endl;
    std::cout << "accNodeA != accNodeB:  true  " << std::boolalpha << (accNodeA != accNodeB) << std::endl;
    std::cout << "accNodeA <  accNodeB:  true  " << std::boolalpha << (accNodeA <  accNodeB) << std::endl;
    std::cout << "accNodeA >  accNodeB:  false " << std::boolalpha << (accNodeA >  accNodeB) << std::endl;
    std::cout << "accNodeA <= accNodeB:  true  " << std::boolalpha << (accNodeA <= accNodeB) << std::endl;
    std::cout << "accNodeA >= accNodeB:  false " << std::boolalpha << (accNodeA >= accNodeB) << std::endl;  
    std::cout << "\n";

    std::cout << "Comparing Node<account> to same string" << std::endl;
    std::cout << "accNodeA == wordA: true  " << std::boolalpha << (accNodeA == wordA) << std::endl;
    std::cout << "accNodeA != wordA: false " << std::boolalpha << (accNodeA != wordA) << std::endl;
    std::cout << "accNodeA <  wordA: false " << std::boolalpha << (accNodeA <  wordA) << std::endl;
    std::cout << "accNodeA >  wordA: false " << std::boolalpha << (accNodeA >  wordA) << std::endl;
    std::cout << "accNodeA <= wordA: true  " << std::boolalpha << (accNodeA <= wordA) << std::endl;
    std::cout << "accNodeA >= wordA: true  " << std::boolalpha << (accNodeA >= wordA) << std::endl;

    std::cout << "\n";

    std::cout << "Comparing Node<account> to diff string" << std::endl;
    std::cout << "accNodeA == wordB: false " << std::boolalpha << (accNodeA == wordB) << std::endl;
    std::cout << "accNodeA != wordB: true  " << std::boolalpha << (accNodeA != wordB) << std::endl;
    std::cout << "accNodeA <  wordB: true  " << std::boolalpha << (accNodeA <  wordB) << std::endl;
    std::cout << "accNodeA >  wordB: false " << std::boolalpha << (accNodeA >  wordB) << std::endl;
    std::cout << "accNodeA <= wordB: true  " << std::boolalpha << (accNodeA <= wordB) << std::endl;
    std::cout << "accNodeA >= wordB: false " << std::boolalpha << (accNodeA >= wordB) << std::endl;

    std::cout << "\n";
    }

    // product with product & int (using getData())
    {
    Node<product> proNodeA(product("aaaa", 11.11, 11,"dairy",  1111));
    Node<product> proNodeB(product("bbbb", 22.22, 22,"dairy",  2222));
    int intA = 1111;
    int intB = 2222;
 
    std::cout << "Comparing Node<product> to same Node<product>" << std::endl;
    std::cout << "proNodeA == proNodeA:  true  " << std::boolalpha << (proNodeA == proNodeA) << std::endl;
    std::cout << "proNodeA != proNodeA:  false " << std::boolalpha << (proNodeA != proNodeA) << std::endl;
    std::cout << "proNodeA <  proNodeA:  false " << std::boolalpha << (proNodeA <  proNodeA) << std::endl;
    std::cout << "proNodeA >  proNodeA:  false " << std::boolalpha << (proNodeA >  proNodeA) << std::endl;
    std::cout << "proNodeA <= proNodeA:  true  " << std::boolalpha << (proNodeA <= proNodeA) << std::endl;
    std::cout << "proNodeA >= proNodeA:  true  " << std::boolalpha << (proNodeA >= proNodeA) << std::endl;
 
    std::cout << "\n";
    
    std::cout << "Comparing Node<product> to diff Node<product>" << std::endl;
    std::cout << "proNodeA == proNodeB:  false " << std::boolalpha << (proNodeA == proNodeB) << std::endl;
    std::cout << "proNodeA != proNodeB:  true  " << std::boolalpha << (proNodeA != proNodeB) << std::endl;
    std::cout << "proNodeA <  proNodeB:  true  " << std::boolalpha << (proNodeA <  proNodeB) << std::endl;
    std::cout << "proNodeA >  proNodeB:  false " << std::boolalpha << (proNodeA >  proNodeB) << std::endl;
    std::cout << "proNodeA <= proNodeB:  true  " << std::boolalpha << (proNodeA <= proNodeB) << std::endl;
    std::cout << "proNodeA >= proNodeB:  false " << std::boolalpha << (proNodeA >= proNodeB) << std::endl;
 
    std::cout << "\n";
 
    std::cout << "Comparing Node<product> to same int" << std::endl;
    std::cout << "proNodeA == intA: true  " << std::boolalpha << (proNodeA == intA) << std::endl;
    std::cout << "proNodeA != intA: false " << std::boolalpha << (proNodeA != intA) << std::endl;
    std::cout << "proNodeA <  intA: false " << std::boolalpha << (proNodeA <  intA) << std::endl;
    std::cout << "proNodeA >  intA: false " << std::boolalpha << (proNodeA >  intA) << std::endl;
    std::cout << "proNodeA <= intA: true  " << std::boolalpha << (proNodeA <= intA) << std::endl;
    std::cout << "proNodeA >= intA: true  " << std::boolalpha << (proNodeA >= intA) << std::endl;
 
    std::cout << "\n";

    std::cout << "Comparing Node<product> to diff int" << std::endl;
    std::cout << "proNodeA == intB: false " << std::boolalpha << (proNodeA == intB) << std::endl;
    std::cout << "proNodeA != intB: true  " << std::boolalpha << (proNodeA != intB) << std::endl;
    std::cout << "proNodeA <  intB: true  " << std::boolalpha << (proNodeA <  intB) << std::endl;
    std::cout << "proNodeA >  intB: false " << std::boolalpha << (proNodeA >  intB) << std::endl;
    std::cout << "proNodeA <= intB: true  " << std::boolalpha << (proNodeA <= intB) << std::endl;
    std::cout << "proNodeA >= intB: false " << std::boolalpha << (proNodeA >= intB) << std::endl;
 
    std::cout << "\n";
    }
}

void testDeconstructor() {
    if (true) {
        DoublyLinkedList<int>* intDLL = new DoublyLinkedList<int>();
        (*intDLL).push_back(1);
        (*intDLL).push_back(2);
        (*intDLL).push_back(3);
        delete intDLL;

        DoublyLinkedList<string>* strDLL = new DoublyLinkedList<string>();
        (*strDLL).push_back("one");
        (*strDLL).push_back("two");
        (*strDLL).push_back("thr");
        delete strDLL;

        DoublyLinkedList<account>* accDLL = new DoublyLinkedList<account>();
        (*accDLL).push_back( account("one", "pass", "customer") );
        (*accDLL).push_back( account("two", "pass", "customer") );
        (*accDLL).push_back( account("thr", "pass", "customer") );
        delete accDLL;

        DoublyLinkedList<product>* proDLL = new DoublyLinkedList<product>();
        (*proDLL).push_back( product("one", 19.34, 95, "dairy", 3455) );
        (*proDLL).push_back( product("two", 14.34, 45, "dairy", 3456) );
        (*proDLL).push_back( product("thr", 17.34, 25, "dairy", 3457) );
        delete proDLL;
    }
}

void testDeleteNode() {
    // delete lastNode
    if (true) {
        DoublyLinkedList<int>* intDLL = new DoublyLinkedList<int>();
        (*intDLL).push_back(1);
        (*intDLL).push_back(2);
        (*intDLL).push_back(3);
        if ( !(*intDLL).deleteNode(3) ) {
            std::cout << "Error: Deleting int node failed" << std::endl;
        }
        (*intDLL).print();
        delete intDLL;
        
        DoublyLinkedList<string>* strDLL = new DoublyLinkedList<string>();
        (*strDLL).push_back("one");
        (*strDLL).push_back("two");
        (*strDLL).push_back("thr");
        if ( !(*strDLL).deleteNode("thr") ) {
            std::cout << "Error: Deleting str node failed" << std::endl;
        }
        (*strDLL).print();
        delete strDLL;

        DoublyLinkedList<account>* accDLL = new DoublyLinkedList<account>();
        (*accDLL).push_back( account("one", "pass", "customer") );
        (*accDLL).push_back( account("two", "pass", "customer") );
        (*accDLL).push_back( account("thr", "pass", "customer") );
        if ( !(*accDLL).deleteNode( account("thr", "pass", "customer") ) ) {
            std::cout << "Error: Deleting account node by account failed" << std::endl;
        }
        (*accDLL).print();
        delete accDLL;
        
        DoublyLinkedList<product>* proDLL = new DoublyLinkedList<product>();
        (*proDLL).push_back( product("one", 19.34, 95, "dairy", 3455) );
        (*proDLL).push_back( product("two", 14.34, 45, "dairy", 3456) );
        (*proDLL).push_back( product("thr", 17.34, 25, "dairy", 3457) );
        if ( !(*proDLL).deleteNode( product("thr", 17.34, 25, "dairy", 3457) ) ) {
            std::cout << "Error: Deleting product node by product failed" << std::endl;
        }
        (*proDLL).print();
        delete proDLL;

        DoublyLinkedList<account>* accDLL_1 = new DoublyLinkedList<account>();
        (*accDLL_1).push_back( account("one", "pass", "customer") );
        (*accDLL_1).push_back( account("two", "pass", "customer") );
        (*accDLL_1).push_back( account("thr", "pass", "customer") );
        if ( !(*accDLL_1).deleteNode( "thr" ) ) {
            std::cout << "Error: Deleting account node by string failed" << std::endl;
        }
        (*accDLL_1).print();
        delete accDLL_1;

        DoublyLinkedList<product>* proDLL_1 = new DoublyLinkedList<product>();
        (*proDLL_1).push_back( product("one", 19.34, 95, "dairy", 3455) );
        (*proDLL_1).push_back( product("two", 14.34, 45, "dairy", 3456) );
        (*proDLL_1).push_back( product("thr", 17.34, 25, "dairy", 3457) );
        if ( !(*proDLL_1).deleteNode( 3457 ) ) {
            std::cout << "Error: Deleting product node by int failed" << std::endl;
        }
        (*proDLL_1).print();
        delete proDLL_1;
    }
}

void testLoadFromFile() {
    // Read In
    DoublyLinkedList<account>* accountsList = new DoublyLinkedList<account>();
    (*accountsList).loadFromFile("accounts.txt");

    DoublyLinkedList<product>* productsList = new DoublyLinkedList<product>();
    (*productsList).loadFromFile("inventory.txt");

    // Print
    (*accountsList).print();
    (*productsList).print();
}

void testWriteToFile() {
    // Read In
    std::string accountFile = "accounts.txt";
    std::string productFile = "inventory.txt";
    DoublyLinkedList<account>* accountsList = new DoublyLinkedList<account>();
    (*accountsList).loadFromFile(accountFile);
    DoublyLinkedList<product>* productsList = new DoublyLinkedList<product>();
    (*productsList).loadFromFile(productFile);

    // Print
    std::cout << "AFTER READING IN" << std::endl;
    (*accountsList).print();
    (*productsList).print();
    std::cout << std::endl;

    // Add node
    (*accountsList).push_back(account("superTest", "superTest", "customer"));
    (*productsList).push_back(product("pro", 19.12, 21, "dairy", 1245));

    // Print
    std::cout << "AFTER PUSHBACK IN" << std::endl;
    (*accountsList).print();
    (*productsList).print();
    std::cout << std::endl;

    (*accountsList).writeToFile(accountFile);
    (*productsList).writeToFile(productFile);
}

void testFindNode() {
    // Read In
    std::string accountFile = "accounts.txt";
    std::string productFile = "inventory.txt";
    DoublyLinkedList<account>* accountsList = new DoublyLinkedList<account>();
    (*accountsList).loadFromFile(accountFile);
    DoublyLinkedList<product>* productsList = new DoublyLinkedList<product>();
    (*productsList).loadFromFile(productFile);

    if ( (*accountsList).findNode( "hereWeGo@gmail.com" ) ) {
        std::cout << "We found the node in accountsList" << std::endl;
    } else {
        std::cout << "We did not find the node in accountsList" << std::endl;
    }
    delete accountsList;

    if ( (*productsList).findNode( 95 ) ) {
        std::cout << "We found the node in productsList" << std::endl;
    } else {
        std::cout << "We did not find the node in productsList" << std::endl;
    }
    delete productsList;
}

void testSort() {
    // Read In
    DoublyLinkedList<account>* accountsList = new DoublyLinkedList<account>();
    (*accountsList).loadFromFile("accounts.txt");

    DoublyLinkedList<product>* productsList = new DoublyLinkedList<product>();
    (*productsList).loadFromFile("inventory.txt");

    // Print
    std::cout << "UNSORTED:" << std::endl;
    (*accountsList).print();
    (*productsList).print();

    (*accountsList).sort();
    (*productsList).sort();

    // (*accountsList).swapNodes((*accountsList).getHead(), (*accountsList).getTail());
    // (*productsList).swapNodes((*productsList).getHead(), (*productsList).getTail());

    std::cout << "SORTED:" << std::endl;
    (*accountsList).print();
    (*productsList).print();
}