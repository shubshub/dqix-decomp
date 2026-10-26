#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void func_ov000_02162b70(void* self, int index, unsigned char value);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_ov000_02162c90(char* self, int index, int value);

struct Struct_ov000_02162aac {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    signed char f4;
    char pad5;
    short unknown_6_;
    unsigned short f8;
};

extern "C" void func_ov000_02162aac(void* self, int a, struct Struct_ov000_02162aac* s);

struct Struct_ov017_021c68e8 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Struct_ov017_021c68e8_2 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short combatantId;
    short field8;
    unsigned short fielda;
    signed char fieldc;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned char field10;
    unsigned char unknown_11_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char index : 6;
    signed char field12;
};

// USA: func_ov017_021c68e8
extern "C" ARM void func_ov017_021c68e8(int unused0, Struct_ov017_021c68e8_2* evt, GameState* battleStruct, unsigned char* base, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
    void* table = *(void**)(base + 0x3000 + 0x508);
#else
    void* table = *(void**)(base + 0x3000 + 0x718);
#endif
    Struct_ov017_021c68e8* a = (Struct_ov017_021c68e8*)func_ov017_021b8478(table);
    if (!a) return;
    void* b = func_ov017_021b8468(table);
    if (!b) return;
    void* work = func_ov017_021b8470(table);
    if (!work) return;
    if (a->field8 != evt->field4) return;

    if (evt->field12 > -1 && evt->field12 != LinkSession_GetOwnSlot(search)) {
        if (evt->flag1) {
            func_ov000_02162b70(b, (signed char)evt->combatantId, 1);
        }
        return;
    }

    struct Struct_ov000_02162aac s;
    int ok = 1;
    s.f0 = evt->unknown_d_;
    s.f1 = evt->unknown_e_;
    s.f2 = evt->unknown_f_;
    s.f3 = evt->field10;
    s.unknown_6_ = evt->field8;
    s.f4 = evt->fieldc;
    s.f8 = evt->fielda;

    if (s.f1 != 6 && s.f0 != 0xd) {
        if (func_0200ff58(battleStruct, evt->combatantId) != NULL) {
            GameObject* c = func_0200ff1c(battleStruct, evt->combatantId);
            if (c != NULL) {
                int field = func_02053c6c((unsigned char*)c);
                if (field != 0) {
#if defined(jpn)
                    ok = (signed char)*(int*)(field + 0x8b4) == 5;
#else
                    ok = (signed char)*(int*)(field + 0x94c) == 5;
#endif
                }
            }
        }
    }

    if (ok) {
        func_ov000_02162aac(b, evt->combatantId, &s);
    }
    func_ov000_02162c90((char*)b, (signed char)evt->index, evt->unknown_11_0_ ? 1 : 0);
    if (evt->flag1) {
        func_ov000_02162b70(b, (signed char)evt->combatantId, 1);
    }
}
