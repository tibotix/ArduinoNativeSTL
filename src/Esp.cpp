/*
 Esp.cpp - ESP31B-specific APIs
 Copyright (c) 2015 Ivan Grokhotkov. All rights reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Esp.h"
// #include "rom/spi_flash.h"
// #include "esp_sleep.h"
// #include "esp_spi_flash.h"
#include <memory>
// #include <soc/soc.h>
// #include <soc/efuse_reg.h>
// #include <esp_partition.h>
extern "C" {
// #include "esp_ota_ops.h"
// #include "esp_image_format.h"
}
#include "MD5Builder.h"
#include "asserts.h"

/**
 * User-defined Literals
 *  usage:
 *
 *   uint32_t = test = 10_MHz; // --> 10000000
 */

unsigned long long operator"" _kHz(unsigned long long x)
{
    return x * 1000;
}

unsigned long long operator"" _MHz(unsigned long long x)
{
    return x * 1000 * 1000;
}

unsigned long long operator"" _GHz(unsigned long long x)
{
    return x * 1000 * 1000 * 1000;
}

unsigned long long operator"" _kBit(unsigned long long x)
{
    return x * 1024;
}

unsigned long long operator"" _MBit(unsigned long long x)
{
    return x * 1024 * 1024;
}

unsigned long long operator"" _GBit(unsigned long long x)
{
    return x * 1024 * 1024 * 1024;
}

unsigned long long operator"" _kB(unsigned long long x)
{
    return x * 1024;
}

unsigned long long operator"" _MB(unsigned long long x)
{
    return x * 1024 * 1024;
}

unsigned long long operator"" _GB(unsigned long long x)
{
    return x * 1024 * 1024 * 1024;
}


EspClass ESP;

void EspClass::deepSleep(uint32_t time_us)
{
    ASSERT_NOT_REACHED("deepsleep");
}

void EspClass::restart(void)
{
    ASSERT_NOT_REACHED("restart");
}

uint32_t EspClass::getHeapSize(void)
{
    ASSERT_NOT_REACHED("get heap size");
}

uint32_t EspClass::getFreeHeap(void)
{
    ASSERT_NOT_REACHED("get free heap");
}

uint32_t EspClass::getMinFreeHeap(void)
{
    ASSERT_NOT_REACHED("get min free heap");
}

uint32_t EspClass::getMaxAllocHeap(void)
{
    ASSERT_NOT_REACHED("get max alloc heap");
}

uint32_t EspClass::getPsramSize(void)
{
    ASSERT_NOT_REACHED("get Psram size");
}

uint32_t EspClass::getFreePsram(void)
{
    ASSERT_NOT_REACHED("get free Psram");
}

uint32_t EspClass::getMinFreePsram(void)
{
    ASSERT_NOT_REACHED("get min free psram");
}

uint32_t EspClass::getMaxAllocPsram(void)
{
    ASSERT_NOT_REACHED("get max alloc psram");
}

static uint32_t sketchSize(sketchSize_t response) {
    ASSERT_NOT_REACHED("sketch size");
    /**
    esp_image_metadata_t data;
    const esp_partition_t *running = esp_ota_get_running_partition();
    if (!running) return 0;
    const esp_partition_pos_t running_pos  = {
        .offset = running->address,
        .size = running->size,
    };
    data.start_addr = running_pos.offset;
    esp_image_verify(ESP_IMAGE_VERIFY, &running_pos, &data);
    if (response) {
        return running_pos.size - data.image_len;
    } else {
        return data.image_len;
    }
    **/
}
    
uint32_t EspClass::getSketchSize () {
    return sketchSize(SKETCH_SIZE_TOTAL);
}

String EspClass::getSketchMD5()
{
    ASSERT_NOT_REACHED("get sketch md5");
}

uint32_t EspClass::getFreeSketchSpace () {
    ASSERT_NOT_REACHED("get free sketch space");
}

uint8_t EspClass::getChipRevision(void)
{
    ASSERT_NOT_REACHED("get chip revision");
}

const char * EspClass::getChipModel(void)
{
    ASSERT_NOT_REACHED("get chip model");
}

uint8_t EspClass::getChipCores(void)
{
    ASSERT_NOT_REACHED("get chip cores");
}

const char * EspClass::getSdkVersion(void)
{
    ASSERT_NOT_REACHED("get sdk version");
}

uint32_t EspClass::getFlashChipSize(void)
{
    ASSERT_NOT_REACHED("get flash chip size");
}

uint32_t EspClass::getFlashChipSpeed(void)
{
    ASSERT_NOT_REACHED("get flash chip speed");
}

FlashMode_t EspClass::getFlashChipMode(void)
{
    ASSERT_NOT_REACHED("get flash chip mode");
}

uint32_t EspClass::magicFlashChipSize(uint8_t byte)
{
    switch(byte & 0x0F) {
    case 0x0: // 8 MBit (1MB)
        return (1_MB);
    case 0x1: // 16 MBit (2MB)
        return (2_MB);
    case 0x2: // 32 MBit (4MB)
        return (4_MB);
    case 0x3: // 64 MBit (8MB)
        return (8_MB);
    case 0x4: // 128 MBit (16MB)
        return (16_MB);
    default: // fail?
        return 0;
    }
}

uint32_t EspClass::magicFlashChipSpeed(uint8_t byte)
{
    switch(byte & 0x0F) {
    case 0x0: // 40 MHz
        return (40_MHz);
    case 0x1: // 26 MHz
        return (26_MHz);
    case 0x2: // 20 MHz
        return (20_MHz);
    case 0xf: // 80 MHz
        return (80_MHz);
    default: // fail?
        return 0;
    }
}

FlashMode_t EspClass::magicFlashChipMode(uint8_t byte)
{
    FlashMode_t mode = (FlashMode_t) byte;
    if(mode > FM_SLOW_READ) {
        mode = FM_UNKNOWN;
    }
    return mode;
}

bool EspClass::flashEraseSector(uint32_t sector)
{
    ASSERT_NOT_REACHED("flash erease sector");
}

// Warning: These functions do not work with encrypted flash
bool EspClass::flashWrite(uint32_t offset, uint32_t *data, size_t size)
{
    ASSERT_NOT_REACHED("flash write");
}

bool EspClass::flashRead(uint32_t offset, uint32_t *data, size_t size)
{
    ASSERT_NOT_REACHED("flash read");
}

/**
bool EspClass::partitionEraseRange(const esp_partition_t *partition, uint32_t offset, size_t size) 
{
    ASSERT_NOT_REACHED("partition erase range");
}

bool EspClass::partitionWrite(const esp_partition_t *partition, uint32_t offset, uint32_t *data, size_t size) 
{
    ASSERT_NOT_REACHED("partition write");
}

bool EspClass::partitionRead(const esp_partition_t *partition, uint32_t offset, uint32_t *data, size_t size) 
{
    ASSERT_NOT_REACHED("partition Read");
}
**/

uint64_t EspClass::getEfuseMac(void)
{
    ASSERT_NOT_REACHED("get efuse mac");
}
