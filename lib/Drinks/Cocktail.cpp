#include "Cocktail.h"

std::string Cocktail::GetName() const
{
   return Cocktail::name;
}

bool Cocktail::AddDrink(Beverage* drink, uint16_t ml)
{
    bool success = (drinkCount < MAX_AMOUNT_OF_DRINKS);

    if(true == success)
    {
        drinks.push_back(drink);
        drinkCount++;
    }

    return success;
}

void Cocktail::GetCocktailInfo()
{
    for(Beverage* beverage : drinks)
    {
        //TODO: find way to print in a generic module
    }
}

Cocktail::Cocktail(std::string name)
{
    Cocktail::drinkCount = 0;
    Cocktail::milileters = 0;
}

Cocktail::~Cocktail()
{
    for(Beverage* beverage : drinks)
    {
        delete(beverage);
        beverage = NULL;
    }
}