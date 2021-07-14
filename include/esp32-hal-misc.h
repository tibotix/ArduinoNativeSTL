#ifndef ESP_HAL_LOG_H
#define ESP_HAL_LOG_H

#include "asserts.h"

/**
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_attr.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "esp_partition.h"
#include "esp_log.h"
#include "esp_timer.h"
**/
#ifdef CONFIG_APP_ROLLBACK_ENABLE
#include "esp_ota_ops.h"
#endif //CONFIG_APP_ROLLBACK_ENABLE
#ifdef CONFIG_BT_ENABLED
#include "esp_bt.h"
#endif //CONFIG_BT_ENABLED
#include <sys/time.h>
/*
#include "soc/rtc.h"
#include "soc/rtc_cntl_reg.h"
#include "soc/apb_ctrl_reg.h"
#include "rom/rtc.h"
#include "esp_task_wdt.h"
**/
#include "esp32-hal.h"


#define ESP_TEMPERATURE 99


float temperatureRead();
void enableCore0WDT();
void disableCore0WDT();
unsigned long micros();
unsigned long millis();
void delay(uint32_t ms);
void delayMicroseconds(uint32_t us);
void initArduino();
const char * pathToFileName(const char * path);


bool verifyOta() __attribute__((weak));
bool verifyOta() { return true; }

void yield() {};








#endif
