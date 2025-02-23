#ifndef _UTIL_MACRO_H_
#define _UTIL_MACRO_H

#include <string>
#include <cstring>
#include "Callbacks.h"
#include "FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include <Arduino.h>

/** \brief Macro to get amount of items in array */
#define ITEMCOUNT(array)    (sizeof(array)/ sizeof(array[0]))

#endif /* UTIL_MACRO_H */