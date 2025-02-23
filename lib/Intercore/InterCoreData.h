#ifndef _INTERCORE_INTERCOREDATA_H
#define _INTERCORE_INTERCOREDATA_H

#include "Macro.h"

typedef enum
{
    COMMUNICATOR_MENUHANDLER,
}INTERCORE_COMUNICATOR;

class InterCoreData
{
    private:
        INTERCORE_COMUNICATOR communicator;
        void* data;
        uint16_t size;
    public:
        InterCoreData(void* data, uint16_t size, INTERCORE_COMUNICATOR communicator);
        ~InterCoreData();
};

#endif
