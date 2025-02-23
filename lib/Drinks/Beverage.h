#ifndef _DRINKS_BEVERAGE_H_
#define _DRINKS_BEVERAGE_H_

#include <Macro.h>
#include <Drinks.h>

class Beverage: IDrinks
{
    private:
        std::string name;
    public:
        virtual std::string GetName() const;
        Beverage(std::string name);
        ~Beverage();
};

#endif /* _DRINKS_BEVERAGE_H_ */