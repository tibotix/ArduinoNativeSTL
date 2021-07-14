// #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "HardwareSerial.h"
#include "asserts.h"

#ifndef RX1
#define RX1 9
#endif

#ifndef TX1
#define TX1 10
#endif

#ifndef RX2
#define RX2 16
#endif

#ifndef TX2
#define TX2 17
#endif

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
HardwareSerial Serial(0);
HardwareSerial Serial1(1);
HardwareSerial Serial2(2);
#endif

HardwareSerial::HardwareSerial(int uart_nr) {}

void HardwareSerial::begin(unsigned long baud, uint32_t config, int8_t rxPin, int8_t txPin, bool invert, unsigned long timeout_ms)
{
}

void HardwareSerial::updateBaudRate(unsigned long baud)
{
}

void HardwareSerial::end()
{
    ASSERT_NOT_REACHED("end");
}

size_t HardwareSerial::setRxBufferSize(size_t new_size) {
    ASSERT_NOT_REACHED("setRxBufferSize");
}

void HardwareSerial::setDebugOutput(bool en)
{
}

int HardwareSerial::available(void)
{
    ASSERT_NOT_REACHED("available");
}
int HardwareSerial::availableForWrite(void)
{
    ASSERT_NOT_REACHED("availableForWrite");
}

int HardwareSerial::peek(void)
{
    if (available()) {
        ASSERT_NOT_REACHED("peek");
    }
    return -1;
}

int HardwareSerial::read(void)
{
    if(available()) {
        ASSERT_NOT_REACHED("read");
    }
    return -1;
}

// read characters into buffer
// terminates if size characters have been read, or no further are pending
// returns the number of characters placed in the buffer
// the buffer is NOT null terminated.
size_t HardwareSerial::read(uint8_t *buffer, size_t size)
{
    size_t avail = available();
    if (size < avail) {
        avail = size;
    }
    size_t count = 0;
    while(count < avail) {
        ASSERT_NOT_REACHED("read");
        // *buffer++ = uartRead(_uart);
        count++;
    }
    return count;
}

void HardwareSerial::flush(void)
{
    ASSERT_NOT_REACHED("flush");
}

void HardwareSerial::flush(bool txOnly)
{
    flush();
}

size_t HardwareSerial::write(uint8_t c)
{
    ASSERT_NOT_REACHED("write");
    return 1;
}

size_t HardwareSerial::write(const uint8_t *buffer, size_t size)
{
    ASSERT_NOT_REACHED("write");
    return size;
}

uint32_t  HardwareSerial::baudRate()
{
	return 115200; // TODO: maybe macro
}
HardwareSerial::operator bool() const
{
    return true;
}

void HardwareSerial::setRxInvert(bool invert)
{
}
