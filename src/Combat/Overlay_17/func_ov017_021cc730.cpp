#if defined(jpn)
enum { Enum_ov017_021cc730_2384 = 0x8b8 };
#else
enum { Enum_ov017_021cc730_2384 = 0x950 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov017_021cc730 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short unknown_4_0_:3;
    unsigned short byteVal:8;
    unsigned short unknown_5_3_:4;
    unsigned short unknown_5_7_:1;
    unsigned short field6;
    unsigned int field8;
    unsigned char fieldc;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char pad2[4];
};

// USA: func_ov017_021cc730
extern "C" ARM void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, id);
    if (combatant == 0) return;
    int field150 = func_02053c6c((unsigned char*)combatant);
    if (field150 == 0) return;

    void* p = LinkMessageQueue_GetInstance();
    Struct_ov017_021cc730 buf;
    int idx = *(int*)((char*)field150 + Enum_ov017_021cc730_2384);

    buf.tag = 0xa;
    buf.unknown_4_0_ = (unsigned short)id;
    buf.byteVal = *(unsigned short*)((char*)field150 + idx * 2 + 0x16c);
    buf.unknown_5_3_ = (unsigned short)*(int*)((char*)field150 + Enum_ov017_021cc730_2384);
    buf.field8 = *(unsigned int*)((char*)field150 + idx * 4 + 0x138);
    buf.field6 = *(unsigned short*)((char*)field150 + 0x564);
    buf.fieldc = *(unsigned char*)((char*)field150 + idx + 0x186);
    buf.unknown_5_7_ = (unsigned short)arg1;
    buf.unknown_d_ = arg2;
    buf.unknown_e_ = arg3;

    func_0205e330(p, &buf, 0);
}
