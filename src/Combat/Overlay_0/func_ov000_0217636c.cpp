#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d6a0;
struct Struct_0205bacc;
struct Struct_0205bcdc;

void ResetEntryList0205d6a0(struct Entry_0205d6a0* list, int mode);
void SetChannelAFlag0205cef8(void* chan);
void SetChannelBFlag0205cf04(void* chan);
void SetupDualPointerTables0205cf28(unsigned char* p, int a, int b, int c);
void GridCursor_SetCount(struct Node0205bacc* node, int val);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* obj, int index);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int v);

struct Struct_ov000_0217636c_2 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    void* unknown_5c_;
};
extern "C" struct Struct_ov000_0217636c_2* func_020421a0();

#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif

struct Struct_ov000_0217636c_3 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov000_0217636c {
    char unknown_0_[4];
    struct Struct_ov000_0217636c_3 unknown_4_;
    char unknown_c_[0x54 - 0xc];
    struct Struct_ov000_0217636c_3 unknown_54_;
    char unknown_5c_[0xa0 - 0x5c];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_0215ab88 {
    char unknown_0_[0x38];
    struct Struct_ov000_0217636c* unknown_38_;
    char unknown_3c_[0x44 - 0x3c];
    int unknown_44_;
    int unknown_48_;
};

extern "C" void func_ov000_02176500(struct Struct_ov000_0215ab88* arg0, void* arg1, int arg2);

// USA: func_ov000_0217636c
extern "C" ARM void func_ov000_0217636c(struct Combatant* obj, int arg) {
    struct Window* window = obj->window;
    if (window != 0) {
        int x = obj->posX;
        int y = obj->posY;
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)window, 1);
        SetChannelAFlag0205cef8(window);
        SetChannelBFlag0205cf04(window);
        SetupDualPointerTables0205cf28((unsigned char*)window, 2, 3, 0);
        GridCursor_SetCount((struct Node0205bacc*)&window->nodeA, 6);
        GridCursor_SetCount((struct Node0205bacc*)&window->nodeB, 6);
        SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)&window->nodeA, 0);
        GridCursor_SetSelectedIndex(&window->nodeB, 0);
        window->nodeA.unk4 = 1;
        window->nodeB.unk4 = 1;
        window->unkA0 = 2;
        window->unkA2 = 1;
        window->tileX = (x >> 3) + 9;
        window->tileY = (y >> 3) + 1;
        window->unkA8 = 0xc;
        window->unkAA = 0xe;
        window->unkAC = 0xa;
        window->unkAE = 0xe;
        window->unkB1 = 0xd;
        void* buf = GetGlobalField0x1c020421a0()->tileBuffer;
#if defined(jpn)
        memset(var3, 0, 0x800);
#else
        memset(var3, 0, 0x960);
#endif
        func_ov000_02176500(arg0, var3, arg1);
#if defined(jpn)
        func_0205d304(arg0->unknown_38_, var3, 0, 1, 0, 1, 0);
#else
        func_0205d304(arg0->unknown_38_, var3, 0, 1, 0, 1, 0, 0);
#endif
    }
}
