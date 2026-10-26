#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021c812c(int a, int b);
extern "C" void func_02049390(unsigned char* obj, unsigned char value);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_02160fa8(void* work, int mask);

struct Struct_ov017_021c82bc {
    unsigned char pad0[4];
    unsigned char unknown_4_0_ : 4;
    unsigned char flag4 : 1;
    unsigned char unknown_4_5_ : 3;
    unsigned char arr1[4];
    unsigned char arr2[8];
};

// USA: func_ov017_021c82bc
extern "C" ARM void func_ov017_021c82bc(int p0, struct Struct_ov017_021c82bc* evt, int arg2, int table, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset=0x508};
#else
 enum {regionalOffset=0x718};
#endif
    signed char cur = LinkSession_GetOwnSlot(search);
    if (evt->unknown_4_0_ != cur) return;
    if (evt->flag4) {
        func_ov017_021c812c((unsigned char)p0, 0);
        return;
    }

    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        GameObject* c = bs->GetCombatantByIndex(i);
        if (c != NULL && evt->arr1[i] != 0xff) {
            func_02049390((unsigned char*)c, evt->arr1[i]);
        }
    }
    int j;
    for (j = 0; j < 8; j++) {
        GameObject* c = bs->GetCombatantByIndex(j + 0xc0);
        if (c != NULL && evt->arr2[j] != 0xff) {
            func_02049390((unsigned char*)c, evt->arr2[j]);
        }
    }

    void* var6 = *(void**)((char*)table + 0x3000 + regionalOffset);
    void* work = func_ov017_021b8468(var6);
    if (!work) return;
    func_ov000_02160fa8(work, 0x200000);
}
