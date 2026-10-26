#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d0e00 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char id;
    unsigned char val;
    unsigned char pad1[14];
};

// USA: func_ov017_021d0e00
extern "C" ARM void func_ov017_021d0e00(int id) {
    void* p = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021d0e00 buf;
    buf.tag = 0x18;
    unsigned char* dst = &buf.id;

    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetPartyMemberByIndex(id);
    if (!c) return;
    int field150 = func_02053c6c((unsigned char*)c);
    if (!field150) return;

    dst[0] = (unsigned char)id;
    dst[1] = *(unsigned char*)((char*)field150 + 0x56a);
    func_0205e330(p, &buf, 0);
}
