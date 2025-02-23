#ifndef _INTERFACES_DRINKS_H_
#define _INTERFACES_DRINKS_H_
#include <string>

class IDrinks
{
    public:
       virtual std::string GetName() const;
       virtual ~IDrinks();
};

#endif /* _INTERFACES_DRINKS_H_ */