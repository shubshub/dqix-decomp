#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION_OFFSET_0 0x1a8
#define REGION_OFFSET_1 0x218
#define REGION_OFFSET_2 0xff0
#define REGION_OFFSET_3 0xff4
#define REGION_OFFSET_4 0xff1
#else
#define REGION_OFFSET_0 0x1bc
#define REGION_OFFSET_1 0x29c
#define REGION_OFFSET_2 0xe00
#define REGION_OFFSET_3 0xe04
#define REGION_OFFSET_4 0xe01
#endif


extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" int NNS_GfdAllocFrmPlttVram(int a, int b, int c);

struct Struct_ov000_0216733c { unsigned int v[2]; };
struct Struct_ov000_0216733c_2 {
    char pad[0x58];
    struct Struct_ov000_0216733c p1;
    struct Struct_ov000_0216733c p2;
};

// USA: func_ov000_0216733c
extern "C" ARM void func_ov000_0216733c(char* arg0) {
    (int)GetGameResources();
    struct Struct_ov000_0216733c_2* foo = (struct Struct_ov000_0216733c_2*)(arg0 + REGION_OFFSET_0);
    foo->p2 = foo->p1;
    VramState_Restore(arg0 + REGION_OFFSET_0);

    unsigned char byteVal = *(unsigned char*)(*(char**)(arg0 + REGION_OFFSET_1) + 0x8000 + 0x1b0);
    int val = byteVal;
    int mult;
    if (val > 5) {
        mult = 0x100;
        *(unsigned char*)(arg0 + 0x5000 + REGION_OFFSET_2) = 8;
    } else {
        *(unsigned char*)(arg0 + 0x5000 + REGION_OFFSET_2) = 5;
        mult = 0x190;
    }

    int i;
    for (i = 0; i < *(unsigned char*)(arg0 + 0x5000 + REGION_OFFSET_2); i++) {
        *(int*)(arg0 + i * 4 + 0x5000 + REGION_OFFSET_3) = NNS_GfdAllocFrmPlttVram(mult, 0, 0);
    }

    VramState_Save(arg0 + REGION_OFFSET_0);
    *(unsigned char*)(arg0 + 0x5000 + REGION_OFFSET_4) = 0;
}
