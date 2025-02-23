#include "MenuHandlerProxy.h"

void MenuHandlerProxy::Update(void* parameters)
{
    Serial.print("Sending data");
    InterCoreData data(NULL, 0 ,COMMUNICATOR_MENUHANDLER);
    (void)icc->SendBetweenCores(ICC_DELEGATE, &data);
}

MenuHandlerProxy::MenuHandlerProxy(InterCoreHandler* icc)
{
    MenuHandlerProxy::icc = icc;
}

MenuHandlerProxy::~MenuHandlerProxy()
{
    
}