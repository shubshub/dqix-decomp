#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void __clear(void* arg0, int arg1);
extern "C" int func_02001aec(void* arg0, void* arg1, int arg2);

struct Struct_0204a848;
struct Struct_0204acdc;
struct Struct_0204aa64;

typedef void (*Type_0204b174)(const void*, int, unsigned int);

extern "C" int func_0204a848(Struct_0204a848* arg0, Type_0204b174 arg1, unsigned char* arg2, void* arg3);
extern "C" int func_0204acdc(Struct_0204acdc* arg0, void* arg1, unsigned char* arg2, SafeAllocator* arg3);
extern "C" int func_0204aa64(Struct_0204aa64* arg0, Type_0204b174 arg1, unsigned char* arg2, void* arg3);

extern char data_020f0238;
extern char data_020f023d;
extern char data_020f0242;
extern int data_020f01f8[][4];
extern Type_0204b174 data_020f01b0[];
extern int data_020f0218[][4];

struct Struct_0204b174 {
    unsigned char unknown_0_[0x10];
    Struct_0204acdc* unknown_10_;
    unsigned char unknown_14_[8];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
};

// Main, originally func_0204b174 (USA 0x0204b174, EUR 0x0204b184, JPN 0x0204bf94)
extern "C" ARM int Background_LoadFile(struct Self0204b174* self, char* str, Cb0204b174 cb) {
    char buf[5];

    if (arg1 == 0) {
        return 1;
    }

    __clear(var0, 5);
    memcpy(var0, arg1, 5);

    if (func_02001aec(var0, &data_020f0238, 4) == 0) {
        Type_0204b174 var1 = (Type_0204b174)data_020f01f8[arg0->unknown_1c_0_][arg0->unknown_1c_4_];
        return func_0204a848((Struct_0204a848*)arg0, var1, (unsigned char*)arg1, (void*)arg2);
    }

    if (func_02001aec(var0, &data_020f023d, 4) == 0) {
        Type_0204b174 var2 = data_020f01b0[arg0->unknown_1c_0_];
        return func_0204aa64((Struct_0204aa64*)((char*)arg0 + 0xc), var2, (unsigned char*)arg1, (void*)arg2);
    }

    if (func_02001aec(var0, &data_020f0242, 4) == 0) {
        if (arg0->unknown_10_ != 0) {
            if (arg0->unknown_1e_ <= arg0->unknown_1d_) {
                return 1;
            }
            int var3 = func_0204acdc((Struct_0204acdc*)((char*)arg0->unknown_10_ + arg0->unknown_1d_ * 0x10),
                                           (void*)(Type_0204b174)data_020f0218[arg0->unknown_1c_0_][arg0->unknown_1c_4_],
                                           (unsigned char*)arg1, (SafeAllocator*)arg2);
            if (var3 != 0) {
                return 1;
            }
            arg0->unknown_1d_ = arg0->unknown_1d_ + 1;
            return 0;
        }
    }

    return 1;
}