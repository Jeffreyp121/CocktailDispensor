#include "Beverage.h"

std::string Beverage::GetName() const
{
    return Beverage::name;
}

Beverage::Beverage(std::string name = "Unkown")
{
    Beverage::name = name;
}

Beverage::~Beverage()
{

}