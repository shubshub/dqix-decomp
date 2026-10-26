#include <globaldefs.h>
#include "Combat/LootPointEvent.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d38f8 {
    unsigned char mode;
    signed char partySlot;
    unsigned char mask;
    unsigned char pointId;
    Struct_0208ec78 unknown_4_;
};

struct Struct_ov017_021d38f8_2 {
    unsigned char tag;
    unsigned char unknown_1_[3];
    Struct_ov017_021d38f8 payload;
    unsigned char unknown_c_[8];

    Struct_ov017_021d38f8* inline_ov017_021d38f8() { return &payload; }
};

// USA: func_ov017_021d38f8
extern "C" ARM void func_ov017_021d38f8(unsigned char mode, signed char partySlot,
                                   unsigned char mask, unsigned char pointId,
                                   const Struct_0208ec78* arg4) {
    void* dispatcher = LinkMessageQueue_GetInstance();
    Struct_ov017_021d38f8_2 event;
    event.tag = 0xb7;
    Struct_ov017_021d38f8* payload = event.inline_ov017_021d38f8();
    payload->mode = mode;
    payload->partySlot = partySlot;
    payload->mask = mask;
    payload->pointId = pointId;
    payload->unknown_4_ = *arg4;
    func_0205e330(dispatcher, &event, 0);
}
