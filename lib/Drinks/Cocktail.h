#ifndef _DRINKS_COCKTAIL_H_
#define _DRINKS_COCKTAIL_H_

#include <vector>
#include <Macro.h>
#include "Beverage.h"
#include <Drinks.h>

/** \brief Maximum amount of mixed drinks */
#define MAX_AMOUNT_OF_DRINKS  (uint8_t)5

class Cocktail : IDrinks
{
    private:
        std::string name;
        std::vector<Beverage*> drinks;
        uint8_t drinkCount;
        uint16_t milileters;

    public:
        virtual std::string GetName() const;
        bool AddDrink(Beverage* drinks, uint16_t ml);
        void GetCocktailInfo();
        Cocktail(std::string name);
        ~Cocktail();
};

#endif /* _DRINKS_COCKTAIL_H_ */