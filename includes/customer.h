// customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "account.h"

class customer : public account {
public:
    void customerMethod() const;
};

#endif // CUSTOMER_H
