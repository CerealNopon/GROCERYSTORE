// administrator.h

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "account.h"

class administrator : public account {
public:
    void adminMethod() const;
};

#endif // ADMINISTRATOR_H
