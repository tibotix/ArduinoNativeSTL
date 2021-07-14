#ifndef __ESP8266_MD5_BUILDER__
#define __ESP8266_MD5_BUILDER__

#include "WString.h"
#include "Stream.h"
// #include "rom/md5_hash.h"

class MD5Builder
{
private:
    // struct MD5Context _ctx;
    uint8_t _buf[16];
public:
    void begin(void);
    void add(uint8_t * data, uint16_t len);
    void add(const char * data)
    {
        add((uint8_t*)data, strlen(data));
    }
    void add(char * data)
    {
        add((const char*)data);
    }
    void add(String data)
    {
        add(data.c_str());
    }
    void addHexString(const char * data);
    void addHexString(char * data)
    {
        addHexString((const char*)data);
    }
    void addHexString(String data)
    {
        addHexString(data.c_str());
    }
    bool addStream(Stream & stream, const size_t maxLen);
    void calculate(void);
    void getBytes(uint8_t * output);
    void getChars(char * output);
    String toString(void);
};


#endif
