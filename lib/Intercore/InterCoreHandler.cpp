#include "InterCoreHandler.h"

InterCoreHandler::InterCoreHandler(TASK_CORE coreId, QueueHandle_t* proxyQueue, QueueHandle_t* delegateQueue)
{
    if(NULL == proxyQueue || NULL == delegateQueue)
    {
        return;
    }

    pinMode(16, OUTPUT);
    pinMode(15, OUTPUT);
    InterCoreHandler::proxyQueue = proxyQueue;
    InterCoreHandler::delegateQueue = delegateQueue;
    InterCoreHandler::coreId = coreId;

    delegateTask = new TaskHelper(c_taskConfigs[TASK_INTERCORE_DELEGATE].name,
                                  DelegateHandler, 
                                  c_taskConfigs[TASK_INTERCORE_DELEGATE].stackSize,
                                  this,
                                  coreId, 
                                  c_taskConfigs[TASK_INTERCORE_DELEGATE].priority);
    if(NULL != delegateTask)
    {
        proxyTask = new TaskHelper(c_taskConfigs[TASK_INTERCORE_PROXY].name,
                                   ProxyHandler, 
                                   c_taskConfigs[TASK_INTERCORE_PROXY].stackSize,
                                   this,
                                   coreId, 
                                   c_taskConfigs[TASK_INTERCORE_PROXY].priority);
    }

    //Todo error logging   
}

InterCoreHandler::~InterCoreHandler()
{
    if(NULL == delegateTask && NULL == proxyTask) return;

    delete(delegateTask);
    delegateTask = NULL;

    delete(proxyTask);
    proxyTask = NULL;

    //clear vector
}


void InterCoreHandler::AddObserver(IObserver* oberserver)
{
    if(NULL != oberserver)
    {
        observers.push_back(oberserver);
    }
}

void InterCoreHandler::NotifyObservers(void* parameter)
{
    if(NULL != parameter)
    {
        for(auto observer : observers)
        {
            observer->Update(parameter);
        }
    }
}

void InterCoreHandler::DequeueProxy()
{
    InterCoreData* data = NULL;
    if(pdTRUE == xQueueReceive(*proxyQueue, &data, 100))
    {
        NotifyObservers(data);
    }
}

void InterCoreHandler::DequeueDelegate()
{
    InterCoreData* data = NULL;
    if(pdTRUE == xQueueReceive(*delegateQueue, &data, 100))
    {
        NotifyObservers(data);
    }
}

void InterCoreHandler::ProxyHandler(void* parameters)
{
    while(true)
    {
        InterCoreHandler* handler = static_cast<InterCoreHandler*>(parameters);
        handler->DequeueProxy();
        digitalWrite(15, HIGH);
        vTaskDelay(pdMS_TO_TICKS(100));
        digitalWrite(15, LOW);
    }
}

void InterCoreHandler::DelegateHandler(void* parameters)
{
    while(true)
    {
        InterCoreHandler* handler = static_cast<InterCoreHandler*>(parameters);
        handler->DequeueDelegate();
        digitalWrite(16, HIGH);
        vTaskDelay(pdMS_TO_TICKS(100));
        digitalWrite(16, LOW);
    }
}

bool InterCoreHandler::SendBetweenCores(ICC_TYPE type, InterCoreData* data)
{
    bool success = (NULL != data);

    if(true == success)
    {
        switch(type)
        {
            case ICC_PROXY:
                success = (pdTRUE == xQueueSend(*proxyQueue, data, 100));
                break;
            
            case ICC_DELEGATE:
                success = (pdTRUE == xQueueSend(*delegateQueue, data, 100));
                break;
    
            default:
                success = false;
                break;
        }
    }

    return success;
}