#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
struct Field150Holder02052e2c;
extern "C" short* func_02052e2c(struct Field150Holder02052e2c* obj);

struct Struct_ov017_021c44d8 {
    unsigned char pad0[4];
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char unknown_7_;
    unsigned char field8;
    unsigned char unknown_9_;
    short fielda;
    short fieldc;
    short unknown_e_;
    signed char field10;
};

struct Struct_ov017_021c44d8_2 {
    char pad[0x14];
    unsigned char bit0 : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_;
    short f18;
    short unknown_1a_;
};

// USA: func_ov017_021c44d8
extern "C" ARM void func_ov017_021c44d8(int unused0, struct Struct_ov017_021c44d8* evt, GameState* battleStruct, int arg3, struct SearchStruct0202c1a4* search) {
    if (evt->field10 >= 0) {
        signed char cur = LinkSession_GetOwnSlot(search);
        if (evt->field10 != cur) return;
    }
    unsigned char key = evt->field4;
    signed char cur2 = LinkSession_GetOwnSlot(search);
    if (key == cur2) return;

    GameObject* c = func_0200ff1c(battleStruct, key);
    if (!c) return;

    struct Struct_ov017_021c44d8_2* entry = (struct Struct_ov017_021c44d8_2*)func_02052e2c((struct Field150Holder02052e2c*)c);
    if (!entry) return;

    entry->unknown_15_0_ = evt->field5;
    entry->unknown_14_4_ = evt->field6;
    entry->unknown_14_1_ = evt->unknown_7_;
    entry->bit0 = evt->field8;
    entry->unknown_16_ = evt->fielda;
    entry->f18 = evt->fieldc;
    entry->unknown_1a_ = evt->unknown_e_;
}
