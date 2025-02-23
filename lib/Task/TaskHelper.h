#ifndef _TASK_TASKHELPER_H_
#define _TASK_TASKHELPER_H_

#include <Macro.h>
#include <Arduino.h>
#include "TaskConfiguration.h"


class TaskHelper
{
    private:
        std::string taskName;
        TaskCallback callback;
        uint32_t stackSize;
        void* parameters;
        TaskHandle_t handle;
        TASK_CORE coreId;
        TASK_PRIORITY priority;

    public:
        TaskHelper(std::string name, TaskCallback callback, uint32_t stackSize,
                  void* parameters, TASK_CORE coreId, TASK_PRIORITY priority);
        ~TaskHelper();
};

#endif /* _TASK_TASKHELPER_H_ */