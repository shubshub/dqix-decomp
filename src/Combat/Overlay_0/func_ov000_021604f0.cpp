#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#if defined(jpn)
#define REGION_OFFSET_0 0xe44
#define REGION_OFFSET_1 0x58
#define REGION_OFFSET_2 0x371c
#define REGION_OFFSET_3 0x57bc
#define REGION_OFFSET_4 0x57c0
#define REGION_OFFSET_5 0x57e4
#define REGION_OFFSET_6 0x57e8
#define REGION_OFFSET_7 0x7901
#define REGION_ALLOCATOR_COUNT 4
#else
#define REGION_OFFSET_0 0xec8
#define REGION_OFFSET_1 0x6c
#define REGION_OFFSET_2 0x3760
#define REGION_OFFSET_3 0x55cc
#define REGION_OFFSET_4 0x55d0
#define REGION_OFFSET_5 0x55f4
#define REGION_OFFSET_6 0x55f8
#define REGION_OFFSET_7 0x7711
#define REGION_ALLOCATOR_COUNT 5
#endif

#include "Memory/SafeAllocator.h"

extern "C" void func_0205eb80(void* arg0);
extern "C" void func_02013750(void* arg0, int arg1);
extern "C" void func_ov000_02172720(void* arg0);

extern "C" void func_02079f9c(char* arg0);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* arg0, int arg1);
extern "C" void func_ov023_021eb26c(void* arg0);

extern char g_sePlayer[];
extern int data_ov000_02182fe0[];

struct Struct_ov000_021604f0 {
    char unknown_0_[8];
    SafeAllocator unknown_8_[REGION_ALLOCATOR_COUNT];
    char unknown_6c_[REGION_OFFSET_0 - REGION_OFFSET_1];
    char unknown_ec8_[REGION_OFFSET_2 - REGION_OFFSET_0];
    char unknown_3760_[REGION_OFFSET_3 - REGION_OFFSET_2];
    void* unknown_55cc_;
    char unknown_55d0_[REGION_OFFSET_5 - REGION_OFFSET_4];
    int unknown_55f4_;
    char unknown_55f8_[REGION_OFFSET_7 - REGION_OFFSET_6];
    unsigned char unknown_7711_;
};

// USA: func_ov000_021604f0
extern "C" ARM void func_ov000_021604f0(struct CombatWork_021604f0* work) {
    if (work->displayActive) {
        ForwardField0xc0_0205eb80(g_sePlayer);
        work->displayActive = 0;
    }
    func_02013750(arg0->unknown_ec8_, 1);
    if (!(arg0->unknown_55f4_ & 0x800)) {
        func_ov000_02172720(arg0->unknown_3760_);
    }
    func_02079f9c((char*)func_020797dc());
    void* var0 = func_02057924();
    for (int* var1 = data_ov000_02182fe0; *var1 >= 0; var1++) {
        func_02057f00(var0, *var1);
    }
    if (arg0->unknown_55cc_ != NULL) {
        func_ov023_021eb26c(arg0->unknown_55cc_);
    }
    for (int var2 = 0; var2 < REGION_ALLOCATOR_COUNT; var2++) {
        if (arg0->unknown_8_[var2].GetSignedAllocator() != NULL) {
            arg0->unknown_8_[var2].Destroy();
        }
    }
}
