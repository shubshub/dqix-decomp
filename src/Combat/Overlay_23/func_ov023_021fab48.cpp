#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* arg0, int arg1);
extern "C" void* func_ov011_021849c8(void*);

struct Struct_0205af18;
extern "C" int func_0205af18(int arg0, struct Struct_0205af18* arg1);
extern "C" void* func_ov023_021fa854(char* arg0, unsigned int arg1);
extern "C" void func_ov023_021f6e10(void* arg0, int arg1, unsigned int arg2);
extern "C" int func_020421a0();

int FindFileOrRecord_021fad20(const void* narcBuffer, const char* name, const void** outData, unsigned int* outSize);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

struct Struct_02043368;
extern "C" void func_0205a234(struct Struct_02043368* arg0);

struct Struct_ov023_021f6d14_2 { unsigned int unknown_0_; int unknown_4_; void* unknown_8_; void* unknown_c_; };
struct Struct_ov023_021f6d14;
extern "C" void func_ov023_021f6d14(struct Struct_ov023_021f6d14* arg0, struct Struct_ov023_021f6d14_2* arg1);

extern const char data_ov023_021fec44[];
extern const char data_ov023_021fec49[];
extern const char data_ov023_021fec4e[];
extern const char data_ov023_021fec53[];

// USA: func_ov023_021fab48
extern "C" ARM void func_ov023_021fab48(void* arg0, void* arg1, const void* arg2, int arg3) {
#if defined(jpn)
 enum {Enum_ov023_021fab48_36=0x20, Enum_ov023_021fab48_96=0x5c, Enum_ov023_021fab48_108=0x68, Enum_ov023_021fab48_120=0x74, Enum_ov023_021fab48_124=0x78, Enum_ov023_021fab48_116=0x70, Enum_ov023_021fab48_114=0x6e, Enum_ov023_021fab48_728=0x228, Enum_ov023_021fab48_100=0x60, Enum_ov023_021fab48_732=0x22c, Enum_ov023_021fab48_740=0x234, Enum_ov023_021fab48_736=0x230, Enum_ov023_021fab48_742=0x236};
#else
 enum {Enum_ov023_021fab48_36=0x24, Enum_ov023_021fab48_96=0x60, Enum_ov023_021fab48_108=0x6c, Enum_ov023_021fab48_120=0x78, Enum_ov023_021fab48_124=0x7c, Enum_ov023_021fab48_116=0x74, Enum_ov023_021fab48_114=0x72, Enum_ov023_021fab48_728=0x2d8, Enum_ov023_021fab48_100=0x64, Enum_ov023_021fab48_732=0x2dc, Enum_ov023_021fab48_740=0x2e4, Enum_ov023_021fab48_736=0x2e0, Enum_ov023_021fab48_742=0x2e6};
#endif
    if (arg2 == 0 || arg3 == 0) return;
    void* var0 = func_ov011_021845f8(arg1, *(unsigned short*)((char*)arg0 + 8));
    if (var0 == 0) return;
    ((SafeAllocator*)((char*)var0 + 4))->GetSizeWithLargestBlockRemoved();

    const void* outData;
    unsigned int outSize;
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec44, &outData, &outSize) != 0) {
        SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec49, &outData, &outSize) != 0) {
        SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec4e, &outData, &outSize) != 0) {
        SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
    }
    if (FindFileOrRecord_021fad20(narcBuffer, data_ov023_021fec53, &outData, &outSize) != 0) {
        void* alloc = ((SafeAllocator*)((char*)base + 4))->Allocate(8);
        if (alloc != 0) {
            ClearField0And40205a234((struct ClearTarget0205a234*)alloc);
            *(void**)((char*)obj + regionalOffset1) = alloc;
            SpriteContext_LoadFile((char*)obj + regionalOffset0, (void*)outData, (int)outSize, (char*)base + 4);
        }
    }

    ((SafeAllocator*)((char*)var0 + 4))->GetSizeWithLargestBlockRemoved();
    void* var4;
    int var5 = *(int*)((char*)arg0 + Enum_ov023_021fab48_108);
    var4 = func_ov011_021849c8(arg1);
    *(int*)((char*)arg0 + Enum_ov023_021fab48_120) = 0;
    *(int*)((char*)arg0 + Enum_ov023_021fab48_124) = var5;
    func_ov023_021f6d14((struct Struct_ov023_021f6d14*)var4, (struct Struct_ov023_021f6d14_2*)((char*)arg0 + Enum_ov023_021fab48_120));

    for (unsigned int var6 = 0; var6 < *(unsigned short*)((char*)arg0 + Enum_ov023_021fab48_114); var6++) {
        void* var7 = func_ov023_021fa854((char*)arg0 + Enum_ov023_021fab48_36, (unsigned short)var6);
        if (var7 != 0) {
            int var8 = func_0205af18((int)((char*)arg0 + Enum_ov023_021fab48_36), (struct Struct_0205af18*)var7);
            unsigned char var9 = *(unsigned char*)((char*)arg0 + Enum_ov023_021fab48_116);
            func_ov023_021f6e10(var4, var9, (unsigned int)var8);
        }
    }

    char* var10 = (char*)func_020421a0();
    *(void**)(var10 + Enum_ov023_021fab48_728) = (char*)arg0 + Enum_ov023_021fab48_36;
    *(int*)(var10 + Enum_ov023_021fab48_732) = *(int*)((char*)arg0 + Enum_ov023_021fab48_100);
    *(short*)(var10 + Enum_ov023_021fab48_740) = 0;
    *(int*)(var10 + Enum_ov023_021fab48_736) = *(int*)((char*)arg0 + Enum_ov023_021fab48_96);
    *(unsigned char*)(var10 + Enum_ov023_021fab48_742) = 1;
}
