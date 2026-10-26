#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };
extern "C" void* func_0207f100(unsigned char* obj, short index);

struct Struct_0207ee90 {
    unsigned short* data;
    unsigned char pad[0xf];
    unsigned char unknown_13_;
};
struct Struct_0207ee90_2 {
    struct Struct_0207ee90* base;
    short count;
    short capacity;
};
extern void* data_02108ed8[2];

// USA: func_0207ee90
extern "C" ARM int func_0207ee90(struct Variant02030b0c* p) {
    struct Struct_0207ee90_2* arr = (struct Struct_0207ee90_2*)data_02108ed8[1];
    struct Struct_0207ee90* e = (struct Struct_0207ee90*)func_0207f100((unsigned char*)arr, (short)(arr->count - 1));
    unsigned short* buf = e->data;
    unsigned char i = 0;
    while (i < e->unknown_13_) {
        buf[i] = (unsigned short)((Script::Parameter*)p)->ToInt();
        p++;
        i++;
    }
    return 1;
}
