#ifndef _APPLICATION_MENUHANDLERPROXY_H_
#define _APPLICATION_MENUHANDLERPROXY_H_

#include <Observer.h>
#include "InterCoreHandler.h"
#include <Drinks.h>

class MenuHandlerProxy : public IObserver
{
    private:
        InterCoreHandler* icc;

    public:
        void Update(void* parameters);
        MenuHandlerProxy(InterCoreHandler* icc);
        ~MenuHandlerProxy();
};


#endif /* _APPLICATION_MENUHANDLERPROXY_H_ */