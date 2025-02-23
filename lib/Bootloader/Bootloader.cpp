#include "Bootloader.h"
#include "Arduino.h"

Bootloader::Bootloader()
{   
    ArduinoOTA.begin();
}

Bootloader::~Bootloader()
{
    if(NULL != task)
    {
        delete(task);
    }
    task = NULL;
}

void Bootloader::UpdateTask(void* parameter)
{
    Bootloader* handler = static_cast<Bootloader*>(parameter);
    //handler->UpdateFirmware(NULL);
}

void Bootloader::UpdateFirmware()
{
    ArduinoOTA.handle();
}

