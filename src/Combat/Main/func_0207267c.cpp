#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Struct_0207267c { short a; int b; };
struct Struct_02072a28;
extern "C" void func_02072a28(Struct_02072a28* list, Struct_0207267c* src);
extern "C" int STD_GetStringLength(const char* text);
struct Struct_02108db0_2 {
    unsigned char unknown_0_;
    unsigned char padding;
    unsigned short unknown_2_;
    char* destination;
    short* unknown_8_;
    SafeAllocator* allocator;
    Struct_02072a28* list;
};
extern Struct_02108db0_2 data_02108db0;
extern char data_020f0cf0[];

// USA: func_0207267c
extern "C" ARM int func_0207267c(Script::Parameter* params) {
    Struct_0207267c entry;
    entry.b = 0;
    entry.a = (params++)->ToInt();
    int var1 = 1;
    if (data_02108db0.unknown_8_ != NULL && data_02108db0.unknown_2_ != 0) {
        var1 = 0;
        for (unsigned short i = 0; i < data_02108db0.unknown_2_; i++) {
            if (entry.a == data_02108db0.unknown_8_[i]) var1 = 1;
        }
    }
    if (!var1) return 1;
    for (unsigned char i = 0; i < data_02108db0.unknown_0_; i++) {
        (params++)->ToString();
    }
    int length;
    const char* text = params->ToString();
    if (data_02108db0.destination != NULL) {
        if (text != NULL) strcpy(data_02108db0.destination, text);
        return 1;
    }
    length = 0;
    if (text != NULL) length = STD_GetStringLength(text);
    entry.b = (int)data_02108db0.allocator->Allocate(length + 1);
    if (entry.b == 0) return 0;
    ((char*)entry.b)[length] = 0;
    if (entry.b != 0) sprintf((char*)entry.b, data_020f0cf0, text);
    func_02072a28(data_02108db0.list, &entry);
    return 1;
}
