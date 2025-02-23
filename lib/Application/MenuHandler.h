#ifndef _APPLICATION_MENUHANDLER_H_
#define _APPLICATION_MENUHANDLER_H_

#include "Macro.h"
#include <vector>
#include <Drinks.h>
#include <Observer.h>
#include "InterCoreHandler.h"

class MenuHandler : public IObserver
{
    private:
        std::vector<IDrinks*> drinks;
        InterCoreHandler* icc;
    public:
        void Update(void* parameters);
        MenuHandler(InterCoreHandler* icc);
        ~MenuHandler();
};

#endif /* _APPLICATION_MENUHANDLER_H_ */