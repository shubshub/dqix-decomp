#include <globaldefs.h>

extern "C" unsigned char* func_ov031_022201d8(unsigned char*, unsigned int*, unsigned int*);
extern "C" int func_ov031_022210c4(unsigned char*, const unsigned char*, unsigned int, const unsigned char*, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);

// USA: func_ov031_022204ec
extern "C" THUMB unsigned int func_ov031_022204ec(unsigned char* packet, unsigned int arg1, unsigned char* destination, const unsigned char* key) {
    unsigned int type;
    unsigned int length;
    unsigned char* payload = func_ov031_022201d8(packet, &type, &length);
    if (!payload) return 0;
    if (type != arg1) return 0;
    if (key) {
        func_ov031_022210c4(destination, payload, length, key, 16);
        length -= 8;
    } else {
        memcpy(destination, payload, length);
    }
    return length;
}
