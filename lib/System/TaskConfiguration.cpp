#include "TaskConfiguration.h"

const TaskConfiguration c_taskConfigs[NR_OF_HANDLERS]
{
    {
        .name = "Monitor",
        .stackSize = MONITOR_STACKSIZE,
        .priority = TASK_PRIO_HIGH,
    },
    {
        .name = "Wifi controllor",
        .stackSize = WIFI_CONTROLOR_STACKSIZE,
        .priority = TASK_PRIO_MEDIUM,
    },
    {
        .name = "InterCore proxy handler",
        .stackSize = INTERCORE_STACKSIZE,
        .priority = TASK_PRIO_MEDIUM,
    },
    {
        .name = "InterCore delegate handler",
        .stackSize = INTERCORE_STACKSIZE,
        .priority = TASK_PRIO_MEDIUM
    },
};
