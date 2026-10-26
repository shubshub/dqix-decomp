#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(char* name, void* buf, int flag);
extern "C" void func_ov017_0219558c(unsigned char* obj, int value);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021954c4(void* obj, int arg1);
extern "C" void func_ov017_0219541c(void* obj, int idx, char* arg2);
extern "C" void func_ov017_021afae8(unsigned char* obj, int value);
extern "C" void func_ov017_021afafc(unsigned char* obj, int value);
extern "C" void func_ov017_021afb10(void* obj);
extern "C" void func_ov017_021afb1c(void* obj);
extern "C" void func_ov017_021afb28(void* obj);
extern "C" void func_ov017_021afb34(void* obj, int value);
extern "C" void func_ov017_021afb84(void* obj, int v);

struct Struct_ov017_021d0bd4_2 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short mode;
    unsigned short slot;
    char name[12];
};

struct Struct_ov017_021d0bd4 {
    unsigned char slot;
    unsigned char flag;
    char name[14];
};

// USA: func_ov017_021d0bd4
extern "C" ARM void func_ov017_021d0bd4(int value, Struct_ov017_021d0bd4_2* evt, int unused, unsigned char* obj, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0x910, regionalOffset1=0x13c, regionalOffset2=0xc};
#else
 enum {regionalOffset0=0xb30, regionalOffset1=0x35c, regionalOffset2=0x30};
#endif
    unsigned char* status = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    switch (evt->mode) {
    case 0: {
        func_ov017_021954c4(obj, evt->slot);
        Struct_ov017_021d0bd4 var1;
        var1.slot = evt->slot;
        var1.flag = 1;
        strcpy(var1.name, evt->name);
        func_ov017_0219541c(obj, evt->slot, (char*)&var1);
        unsigned char* entry = obj + regionalOffset1 + 0x4000 + evt->slot * regionalOffset2;
        if (entry == 0) break;
#if defined(jpn)
        strcpy((char*)entry, evt->name);
#else
        char nameBuf[regionalOffset2];
        __clear(nameBuf, regionalOffset2);
        Font_DecodeText(evt->name, nameBuf, 1);
        strcpy((char*)entry, nameBuf);
#endif

        break;
    }
    case 1:
        if (LinkSession_GetOwnSlot(search) == 0) {
            func_ov017_021afae8(status, (unsigned char)value);
        }
        break;
    case 2:
        if (LinkSession_GetOwnSlot(search) == 0) {
            func_ov017_021afafc(status, (unsigned char)value);
        }
        break;
    case 3:
        if (status[9] == 2) {
            func_ov017_021afb10(status);
        }
        break;
    case 4:
        func_ov017_021afb1c(status);
        break;
    case 5:
        func_ov017_021afb28(status);
        break;
    case 6:
        func_ov017_021afb34(status, (unsigned char)value);
        break;
    case 7:
        func_ov017_021afb84(status, 2);
        break;
    case 8:
        func_ov017_021afb84(status, 1);
        break;
    case 9:
        func_ov017_0219558c(obj, value);
        break;
    }
}
