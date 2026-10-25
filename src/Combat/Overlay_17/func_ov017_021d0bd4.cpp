#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(char* name, void* buf, int flag);
extern "C" void func_ov017_0219558c(unsigned char* obj, int value);

struct Struct_0202c1a4;
extern "C" signed char func_0202c1a4(struct Struct_0202c1a4* arg0);
extern "C" void func_ov017_021954c4(void* arg0, int arg1);
extern "C" void func_ov017_0219541c(void* arg0, int arg1, char* arg2);
extern "C" void func_ov017_021afae8(unsigned char* arg0, int arg1);
extern "C" void func_ov017_021afafc(unsigned char* arg0, int arg1);
extern "C" void func_ov017_021afb10(void* arg0);
extern "C" void func_ov017_021afb1c(void* arg0);
extern "C" void func_ov017_021afb28(void* arg0);
extern "C" void func_ov017_021afb34(void* arg0, int arg1);
extern "C" void func_ov017_021afb84(void* arg0, int arg1);

struct Struct_ov017_021d0bd4_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[12];
};

struct Struct_ov017_021d0bd4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[14];
};

// USA: func_ov017_021d0bd4
extern "C" ARM void func_ov017_021d0bd4(int arg0, Struct_ov017_021d0bd4_2* arg1, int arg2, unsigned char* arg3, struct Struct_0202c1a4* arg4) {
#if defined(jpn)
 enum {Enum_ov017_021d0bd4_2864=0x910, Enum_ov017_021d0bd4_860=0x13c, Enum_ov017_021d0bd4_48=0xc};
#else
 enum {Enum_ov017_021d0bd4_2864=0xb30, Enum_ov017_021d0bd4_860=0x35c, Enum_ov017_021d0bd4_48=0x30};
#endif
    unsigned char* var0 = *(unsigned char**)(arg3 + 0x3000 + Enum_ov017_021d0bd4_2864);
    switch (arg1->unknown_4_) {
    case 0: {
        func_ov017_021954c4(arg3, arg1->unknown_6_);
        Struct_ov017_021d0bd4 var1;
        var1.unknown_0_ = arg1->unknown_6_;
        var1.unknown_1_ = 1;
        strcpy(var1.unknown_2_, arg1->unknown_8_);
        func_ov017_0219541c(arg3, arg1->unknown_6_, (char*)&var1);
        unsigned char* var2 = arg3 + Enum_ov017_021d0bd4_860 + 0x4000 + arg1->unknown_6_ * Enum_ov017_021d0bd4_48;
        if (var2 == 0) break;
#if defined(jpn)
        strcpy((char*)var2, arg1->unknown_8_);
#else
        char nameBuf[regionalOffset2];
        __clear(nameBuf, regionalOffset2);
        Font_DecodeText(evt->name, nameBuf, 1);
        strcpy((char*)entry, nameBuf);
#endif

        break;
    }
    case 1:
        if (func_0202c1a4(arg4) == 0) {
            func_ov017_021afae8(var0, (unsigned char)arg0);
        }
        break;
    case 2:
        if (func_0202c1a4(arg4) == 0) {
            func_ov017_021afafc(var0, (unsigned char)arg0);
        }
        break;
    case 3:
        if (var0[9] == 2) {
            func_ov017_021afb10(var0);
        }
        break;
    case 4:
        func_ov017_021afb1c(var0);
        break;
    case 5:
        func_ov017_021afb28(var0);
        break;
    case 6:
        func_ov017_021afb34(var0, (unsigned char)arg0);
        break;
    case 7:
        func_ov017_021afb84(var0, 2);
        break;
    case 8:
        func_ov017_021afb84(var0, 1);
        break;
    case 9:
        func_ov017_0219558c(arg3, arg0);
        break;
    }
}
