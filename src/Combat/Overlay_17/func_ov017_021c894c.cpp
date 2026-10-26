#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int flag);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c894c {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_[8];
    unsigned short value;
    unsigned char pad[2];
};

struct Struct_ov017_021c894c_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021c894c body;
};

// USA: func_ov017_021c894c
extern "C" ARM void func_ov017_021c894c(unsigned short value) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* data = LinkMessageQueue_GetInstance();
    void* field = func_ov017_021b8470(res->unknown_ptr_3718);
    if (field == NULL) {
        return;
    }

    struct Struct_ov017_021c894c_2 msg;
    short ids[8];
    memset(&msg, 0, sizeof(msg));
    struct Struct_ov017_021c894c* body = &msg.body;
    msg.tag = 0x79;
    body->value = value;
    int i;
    for (i = 0; i < 4; i++) {
        body->unknown_0_[i] = 0xff;
    }
    int j;
    for (j = 0; j < 8; j++) {
        body->unknown_4_[j] = 0xff;
    }

    int count = func_ov000_0215e9fc(field, ids, 8, 0x10);
    int k;
    for (k = 0; k < count; k++) {
        GameObject* c = battleStruct->GetCombatantByIndex(ids[k]);
        if (c != NULL) {
            body->unknown_0_[ids[k]] = func_020493a4((unsigned char*)c);
        }
    }

    count = func_ov000_0215eb1c(field, ids, 8, 0x10);
    int m;
    for (m = 0; m < count; m++) {
        GameObject* c = battleStruct->GetCombatantByIndex(ids[m]);
        if (c != NULL) {
            int idx = ids[m] - 0xc0;
            body->unknown_4_[idx] = func_020493a4((unsigned char*)c);
        }
    }

    func_0205e330(data, &msg, 0);
}
