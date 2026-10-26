#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
struct Field150Holder02052e2c;
extern "C" short* func_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c4418 {
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

struct Struct_ov017_021c4418_2 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char unknown_7_;
    unsigned char field8;
    unsigned char unknown_9_;
    short fieldA;
    short fieldC;
    short unknown_e_;
    signed char field10;
};

// USA: func_ov017_021c4418
extern "C" ARM void func_ov017_021c4418(int combatantId, signed char arg1) {
    GameState* battleStruct = GameState::GetInstance();
    void* p = LinkMessageQueue_GetInstance();
    GameObject* c = func_0200ff1c(battleStruct, combatantId);
    if (!c) return;
    struct Struct_ov017_021c4418* entry = (struct Struct_ov017_021c4418*)func_02052e2c((struct Field150Holder02052e2c*)c);
    if (!entry) return;

    struct Struct_ov017_021c4418_2 evt;
    evt.tag = 1;
    evt.field4 = combatantId;
    evt.field5 = entry->unknown_15_0_;
    evt.field6 = entry->unknown_14_4_;
    evt.unknown_7_ = entry->unknown_14_1_;
    evt.field8 = entry->bit0;
    evt.fieldA = entry->unknown_16_;
    evt.fieldC = entry->f18;
    evt.unknown_e_ = entry->unknown_1a_;
    evt.field10 = arg1;
    func_0205e330(p, &evt, 0);
}
