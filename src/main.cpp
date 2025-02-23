#include <Arduino.h>
#include <Cocktail.h>
#include <Soda.h>
#include <Liquor.h>
#include <TaskHelper.h>
#include <InterCoreHandler.h>
#include <Bootloader.h>
#include <WiFi.h>
#include <MenuHandler.h>
#include <MenuHandlerProxy.h>

InterCoreHandler* slaveHandler = NULL;
InterCoreHandler* masterHandler = NULL;
Bootloader* bootloader = NULL;
IObserver* menuHandler;
IObserver* proxy;

static const char* ssid = "";
static const char* password = "";

QueueHandle_t masterQueue = xQueueCreate(10, sizeof(InterCoreData));
QueueHandle_t slaveQueue = xQueueCreate(10, sizeof(InterCoreData));

void setup() 
{
  IPAddress local_IP(192, 168, 178, 184);
  // Set your Gateway IP address
  IPAddress gateway(192, 168, 178, 1);
  
  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8);   //optional
  IPAddress secondaryDNS(8, 8, 4, 4); //optional

  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) 
  {
    Serial.println("STA Failed to configure");
  }
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  bootloader = new Bootloader();
  slaveHandler = new InterCoreHandler(TASK_CORE_SLAVE, &masterQueue, &slaveQueue);
  masterHandler = new InterCoreHandler(TASK_CORE_MAIN, &slaveQueue, &masterQueue);
  menuHandler = new MenuHandler(masterHandler);
  proxy = new MenuHandlerProxy(slaveHandler);
  masterHandler->AddObserver(menuHandler);
  slaveHandler->AddObserver(proxy);
}

void loop() 
{
  bootloader->UpdateFirmware();
  proxy->Update(NULL);
  vTaskDelay(pdMS_TO_TICKS(1000));
}


