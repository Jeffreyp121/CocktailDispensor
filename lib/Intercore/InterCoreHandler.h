#ifndef _SYSTEM_INTERCOREHANDLER_H_
#define _SYSTEM_INTERCOREHANDLER_H_

#include <Macro.h>
#include <Subject.h>
#include <TaskHelper.h>
#include "TaskConfiguration.h"
#include "InterCoreData.h"
#include <vector>

typedef enum
{
    ICC_PROXY,
    ICC_DELEGATE,
    NR_OF_ICC_TYPES
}ICC_TYPE;

class InterCoreHandler : ISubject
{
    private:
        TASK_CORE coreId;
        QueueHandle_t* proxyQueue;
        QueueHandle_t* delegateQueue;
        std::vector<IObserver*> observers;
        TaskHelper* proxyTask;
        TaskHelper* delegateTask;

        void DequeueProxy();
        void DequeueDelegate();

        static void ProxyHandler(void* parameters);
        static void DelegateHandler(void* parameters);

    public:
        InterCoreHandler(TASK_CORE coreId, QueueHandle_t* proxyQueue, QueueHandle_t* delegateQueue);
        ~InterCoreHandler();
        void AddObserver(IObserver* oberserver);
        void NotifyObservers(void* parameters);
        bool SendBetweenCores(ICC_TYPE type, InterCoreData* data);
};

#endif /* _SYSTEM_INTERCOREHANDLER_H_ */