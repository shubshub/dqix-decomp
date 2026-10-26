#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct_020a7f88;
extern "C" void func_020a810c(Struct_020a7f88* obj);
extern "C" void func_020a8128(unsigned char* obj);

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Struct02030b7c { int field0; void* field4; };

struct Struct_0201d530 { int type; union { int i; float f; } value; };

extern "C" int STD_GetStringLength(const char* s);

struct Struct_020a825c { unsigned int v[4]; };
struct Struct_020a7f88_2 {
    unsigned char b0, b1, b2, b3;
    unsigned int w4;
    Struct_020a825c block;
    unsigned short unknown_18_, unknown_1a_, unknown_1c_, unknown_1e_;
    unsigned int unknown_20_, unknown_24_, unknown_28_;
};
struct Struct_020a825c_2 { Struct_020a7f88_2* base; unsigned short cap; unsigned short count; };
extern "C" void func_020a825c(Struct_020a825c_2* list, Struct_020a7f88_2* src);

struct Struct_02109fe0_2 { SafeAllocator* allocator; Struct_020a825c_2* list; };
extern Struct_02109fe0_2 data_02109fe0;
extern const char data_020f1b94;

// USA: func_020a7f88
extern "C" ARM int func_020a7f88(unsigned char* src) {
    Struct_020a7f88_2 elem;
    func_020a810c((Struct_020a7f88*)&elem.block);
    func_020a8128((unsigned char*)&elem);
    func_020a8128((unsigned char*)&elem);

    elem.b0 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)src))->ToInt();
    elem.b2 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)(src + 0x8)))->ToInt();
    char* name = (char*)(void*)((Script::Parameter*)((Struct02030b7c*)(src + 0x10)))->ToString();
    elem.unknown_18_ = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(src + 0x18)))->ToInt();

    char* blk = (char*)&elem.block;
    *(short*)(blk + 0) = (short)((Script::Parameter*)((Variant02030b0c*)(src + 0x20)))->ToInt();
    *(short*)(blk + 2) = (short)(int)(((Script::Parameter*)((Struct_0201d530*)(src + 0x28)))->ToFloat() * 4096.0f);
    *(int*)(blk + 4) = (int)(((Script::Parameter*)((Struct_0201d530*)(src + 0x30)))->ToFloat() * 4096.0f);
    *(int*)(blk + 8) = (int)(((Script::Parameter*)((Struct_0201d530*)(src + 0x38)))->ToFloat() * 4096.0f);
    *(int*)(blk + 0xc) = (int)(((Script::Parameter*)((Struct_0201d530*)(src + 0x40)))->ToFloat() * 4096.0f);

    elem.unknown_1a_ = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(src + 0x48)))->ToInt();
    elem.unknown_1c_ = (unsigned short)((Script::Parameter*)((Variant02030b0c*)(src + 0x50)))->ToInt();

    elem.unknown_20_ = (unsigned int)(int)(((Script::Parameter*)((Struct_0201d530*)(src + 0x58)))->ToFloat() * 4096.0f);
    elem.unknown_24_ = (unsigned int)(int)(((Script::Parameter*)((Struct_0201d530*)(src + 0x60)))->ToFloat() * 4096.0f);

    int len = STD_GetStringLength(name);
    elem.w4 = (unsigned int)data_02109fe0.allocator->Allocate(len + 1);
    sprintf((char*)elem.w4, &data_020f1b94, name);
    ((char*)elem.w4)[len] = 0;

    func_020a825c(data_02109fe0.list, &elem);
    return 1;
}
