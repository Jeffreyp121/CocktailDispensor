#ifndef _SYSTEM_TASKCONFIGURATION_H_
#define _SYSTEM_TASKCONFIGURATION_H_

#include "Macro.h"

#define TASKCONFIGURATION_MIN_TASK_SIZE ((uint16_t)2048)
#define TASKCONFIGURATION_MAX_TASK_SIZE ((uint16_t)520000)

/** \brief list of available tasks */
typedef enum
{
    TASK_MONITOR,
    TASK_WIFI_CONTROLLER,
    TASK_INTERCORE_PROXY,
    TASK_INTERCORE_DELEGATE,
    NR_OF_HANDLERS
}TASK_HANDLERS;

/** \brief list of available cores */
typedef enum
{
    TASK_CORE_SLAVE = 0,
    TASK_CORE_MAIN,
    NR_OF_CORES,
}TASK_CORE;

typedef enum
{
   TASK_PRIO_HIGH     = configMAX_PRIORITIES - 5,
   TASK_PRIO_MEDIUM   = configMAX_PRIORITIES - ( 2 * 5),
   TASK_PRIO_LOW      = configMAX_PRIORITIES - ( 3 * 5),
}TASK_PRIORITY;

/** \brief Struct of */
typedef struct 
{
    std::string name;
    uint32_t stackSize;
    TASK_PRIORITY priority;
}TaskConfiguration;

extern const TaskConfiguration c_taskConfigs[NR_OF_HANDLERS];

#define MONITOR_STACKSIZE               ((uint32_t)TASKCONFIGURATION_MIN_TASK_SIZE)
#define WIFI_CONTROLOR_STACKSIZE        ((uint32_t)TASKCONFIGURATION_MIN_TASK_SIZE)
#define INTERCORE_STACKSIZE             ((uint32_t)TASKCONFIGURATION_MIN_TASK_SIZE)

#endif /* _SYSTEM_TASKCONFIGURATION_H_ */
