#include "MenuHandler.h"

void MenuHandler::Update(void* parameters)
{
    Serial.println("received data");
}

MenuHandler::MenuHandler(InterCoreHandler* icc)
{
    MenuHandler::icc = icc;
}

MenuHandler::~MenuHandler()
{
    //free list
}