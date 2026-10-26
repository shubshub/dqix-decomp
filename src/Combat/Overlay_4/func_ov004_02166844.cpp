#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov004_02166844_0 = 1, Enum_ov004_02166844_1 = 0, Enum_ov004_02166844_2402 = 0x790, Enum_ov004_02166844_6144 = 0x1400, Enum_ov004_02166844_356 = 0x394, Enum_ov004_02166844_392 = 0x3b8 };
#else
enum { Enum_ov004_02166844_0 = 0, Enum_ov004_02166844_1 = 1, Enum_ov004_02166844_2402 = 0x962, Enum_ov004_02166844_6144 = 0x1800, Enum_ov004_02166844_356 = 0x164, Enum_ov004_02166844_392 = 0x188 };
#endif

#include "Memory/SafeAllocator.h"
#include "Resource/QuestScript.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "std_library_functions.h"


struct Struct_0208b9a0 {
    unsigned int unknown_0_;
    unsigned short h4, h6;
    unsigned int w8;
    unsigned short hc, he;
};
extern "C" void func_0208d82c(struct Struct_0208b9a0* header);
extern "C" int* func_02094d6c(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_020e2d24(int* obj, int a, int b);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_02095b30(int* g, int v);
extern "C" void* func_ov011_021845f8(void* obj, int key);
extern "C" void* func_ov004_02165e70(void* obj, int type);

extern void* data_ov004_0217101c[2];
extern int data_ov004_0217059c;

struct Struct_ov004_02166844 {
    int field0, field4, field8;
    Struct_0208b9a0 stream;
    SafeAllocator allocators[2];
    int taskId;
    short field48, unknown_4a_, field4c, unknown_4e_;
    unsigned char unknown_50_0_ : 6;
    unsigned char unknown_50_6_ : 1;
    unsigned char unknown_50_7_ : 1;
    unsigned char unknown_51_[0x66];
    int unknown_b8_;
};

// USA: func_ov004_02166844
extern "C" ARM int func_ov004_02166844(void* a1) {
    char* node;
    data_ov004_0217101c[Enum_ov004_02166844_0] = 0;
    int* g = func_02094d6c();
    char* c = (char*)Scenario_GetInstance();
    node = (char*)func_ov011_021845f8(a1, 0);
    if (node == 0) {
        return 0;
    }

    data_ov004_0217101c[Enum_ov004_02166844_0] = ((SafeAllocator*)(node + 4))->Allocate(sizeof(Struct_ov004_02166844));
    void* p = ((SafeAllocator*)(node + 4))->Allocate(2);
    if (p != 0) {
        *(short*)p = 0x7de0;
        CleanInvalidateCacheRange(p, 2);
        LoadToMainBGStandardPalette(p, 0x12, 2);
        CleanCacheRange(p, 2);
    }

    Struct_ov004_02166844* state = (Struct_ov004_02166844*)data_ov004_0217101c[Enum_ov004_02166844_0];
    if (state == 0) {
        return 0;
    }
    state->field0 = 0;
    state->field4 = 0;
    state->field8 = 0;
    func_0208d82c(&state->stream);
    state->allocators[0].ResetAllocatorPointer();
    state->taskId = -1;
    state->field48 = 0;
    state->unknown_4a_ = 0;
    state->field4c = 0;
    state->unknown_4e_ = 0;
    state->unknown_50_0_ = 0;
    state->unknown_50_6_ = 0;
    state->unknown_50_7_ = 1;
    memset(state->unknown_51_, 0, sizeof(state->unknown_51_));
    state->unknown_b8_ = 0;

    int n = data_ov004_0217059c;
    void* q = ((SafeAllocator*)(node + 4))->Allocate(n);
    ((Struct_ov004_02166844*)data_ov004_0217101c[Enum_ov004_02166844_0])->allocators[0].CreateTypeA(q, n);
    n = data_ov004_0217059c;
    q = ((SafeAllocator*)(node + 4))->Allocate(n);
    ((Struct_ov004_02166844*)data_ov004_0217101c[Enum_ov004_02166844_0])->allocators[1].CreateTypeA(q, n);

    char* n2 = (char*)func_ov004_02165e70(a1, 7);
    if (n2 != 0) {
        unsigned short* flags = (unsigned short*)(n2 + 0x34);
        flags[0x6d] |= 0x10;
    }
    n2[0x110] = 0;

    memcpy(((Struct_ov004_02166844*)data_ov004_0217101c[Enum_ov004_02166844_0])->unknown_51_, c + 0x2cc, 0x66);
    ((Struct_ov004_02166844*)data_ov004_0217101c[Enum_ov004_02166844_0])->unknown_b8_ = *(int*)((char*)g + 0xa0);
    func_020956b8((Struct_020956b8*)g, (SafeAllocator*)(node + 4));
    func_02095b30(g, 1);

    data_ov004_0217101c[Enum_ov004_02166844_1] = 0;
    data_ov004_0217101c[Enum_ov004_02166844_1] = ((SafeAllocator*)(node + 4))->Allocate(0x20);
    for (unsigned char i = 0; i < 8; i++) {
        ((void**)data_ov004_0217101c[Enum_ov004_02166844_1])[i] = 0;
        ((void**)data_ov004_0217101c[Enum_ov004_02166844_1])[i] = ((SafeAllocator*)(node + 4))->Allocate(0x80);
    }

    char* f = (char*)MessageSystem_GetInstance();
    *(unsigned char*)(f + 0x1000 + Enum_ov004_02166844_2402) = 1;
    func_020e2d24((int*)(f + Enum_ov004_02166844_356 + Enum_ov004_02166844_6144), 9, 1);
    func_020e2d24((int*)(f + Enum_ov004_02166844_392 + Enum_ov004_02166844_6144), 0x19, 1);
    return 0;
}
