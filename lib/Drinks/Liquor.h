#ifndef _DRINKS_LIQUOR_H_
#define _DRINKS_LIQUOR_H_

#include <Macro.h>
#include "Beverage.h"

class Liquor: Beverage
{
    private:
    
    public:
        Liquor(std::string name);
        ~Liquor();
};

#endif /* _DRINKS_LIQUOR_H_ */