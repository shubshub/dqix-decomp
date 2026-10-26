#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);

struct Struct_0205af18;
extern "C" int func_0205af18(int unused, struct Struct_0205af18* obj);
extern "C" void* func_ov023_021fa854(char* obj, unsigned int idx);
extern "C" void func_ov023_021f6e10(void* obj, int idx, unsigned int bit);
extern "C" int MessageSystem_GetInstance();

extern "C" int func_ov023_021fad20(const void* narcBuffer, const char* name, const void** outData, unsigned int* outSize);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

struct ClearTarget0205a234;
extern "C" void func_0205a234(struct ClearTarget0205a234* p);

struct Struct_ov023_021f6d14_2 { unsigned int key; int pad4; void* prev; void* next; };
struct Struct_ov023_021f6d14;
extern "C" void func_ov023_021f6d14(struct Struct_ov023_021f6d14* list, struct Struct_ov023_021f6d14_2* node);

extern const char data_ov023_021fec44[];
extern const char data_ov023_021fec49[];
extern const char data_ov023_021fec4e[];
extern const char data_ov023_021fec53[];

// USA: func_ov023_021fab48
extern "C" ARM void func_ov023_021fab48(void* obj, void* ctx, const void* narcBuffer, int flag4) {
#if defined(jpn)
 enum {regionalOffset0=0x20, regionalOffset1=0x5c, regionalOffset2=0x68, regionalOffset3=0x74, regionalOffset4=0x78, regionalOffset5=0x70, regionalOffset6=0x6e, Enum_ov023_021fab48_728=0x228, Enum_ov023_021fab48_100=0x60, regionalOffset9=0x22c, Enum_ov023_021fab48_740=0x234, Enum_ov023_021fab48_736=0x230, Enum_ov023_021fab48_742=0x236};
#else
 enum {regionalOffset0=0x24, regionalOffset1=0x60, regionalOffset2=0x6c, regionalOffset3=0x78, regionalOffset4=0x7c, regionalOffset5=0x74, regionalOffset6=0x72, Enum_ov023_021fab48_728=0x2d8, Enum_ov023_021fab48_100=0x64, regionalOffset9=0x2dc, Enum_ov023_021fab48_740=0x2e4, Enum_ov023_021fab48_736=0x2e0, Enum_ov023_021fab48_742=0x2e6};
#endif
    if (narcBuffer == 0 || flag4 == 0) return;
    void* base = func_ov011_021845f8(ctx, *(unsigned short*)((char*)obj + 8));
    if (base == 0) return;
    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();

    const void* outData;
    unsigned int outSize;
    if (func_ov023_021fad20(narcBuffer, data_ov023_021fec44, &outData, &outSize) != 0) {
        SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (func_ov023_021fad20(narcBuffer, data_ov023_021fec49, &outData, &outSize) != 0) {
        SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (func_ov023_021fad20(narcBuffer, data_ov023_021fec4e, &outData, &outSize) != 0) {
        SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (func_ov023_021fad20(narcBuffer, data_ov023_021fec53, &outData, &outSize) != 0) {
        void* alloc = ((SafeAllocator*)((char*)base + 4))->Allocate(8);
        if (alloc != 0) {
            func_0205a234((struct ClearTarget0205a234*)alloc);
            *(void**)((char*)obj + regionalOffset1) = alloc;
            SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
        }
    }

    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();
    void* list;
    int var5 = *(int*)((char*)obj + regionalOffset2);
    list = func_ov011_021849c8(ctx);
    *(int*)((char*)obj + regionalOffset3) = 0;
    *(int*)((char*)obj + regionalOffset4) = var5;
    func_ov023_021f6d14((struct Struct_ov023_021f6d14*)list, (struct Struct_ov023_021f6d14_2*)((char*)obj + regionalOffset3));

    for (unsigned int i = 0; i < *(unsigned short*)((char*)obj + regionalOffset6); i++) {
        void* entry = func_ov023_021fa854((char*)obj + regionalOffset0, (unsigned short)i);
        if (entry != 0) {
            int bits = func_0205af18((int)((char*)obj + regionalOffset0), (struct Struct_0205af18*)entry);
            unsigned char byteVal = *(unsigned char*)((char*)obj + regionalOffset5);
            func_ov023_021f6e10(list, byteVal, (unsigned int)bits);
        }
    }

    char* global = (char*)MessageSystem_GetInstance();
    *(void**)(global + Enum_ov023_021fab48_728) = (char*)obj + regionalOffset0;
    *(int*)(global + regionalOffset9) = *(int*)((char*)obj + Enum_ov023_021fab48_100);
    *(short*)(global + Enum_ov023_021fab48_740) = 0;
    *(int*)(global + Enum_ov023_021fab48_736) = *(int*)((char*)obj + regionalOffset1);
    *(unsigned char*)(global + Enum_ov023_021fab48_742) = 1;
}
