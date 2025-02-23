#ifndef _BOOTLOADER_BOOTLOADER_H_
#define _BOOTLOADER_BOOTLOADER_H_

#include <ArduinoOTA.h>
#include "Macro.h"
#include "TaskHelper.h"

class Bootloader
{
    private:
        TaskHelper* task;
        
        static void UpdateTask(void* parameter);
        

    public:
        void UpdateFirmware();
        Bootloader();
        ~Bootloader();
};

#endif /* _BOOTLOADER_BOOTLOADER_H_ */
