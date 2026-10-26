#if defined(jpn)
enum { Enum_ov017_021c847c_2380 = 0x8b4 };
#else
enum { Enum_ov017_021c847c_2380 = 0x94c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
struct CheckField0AndGlobalHalfStruct0202c508;
extern "C" int LinkSession_IsHostOrSolo(struct CheckField0AndGlobalHalfStruct0202c508* obj);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Party021c847c {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Struct_ov017_021c847c_2 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char arr[8];
    unsigned char pad1[8];
};

// USA: func_ov017_021c847c
extern "C" ARM void func_ov017_021c847c(void) {
    GameState* battleStruct = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c847c_2 msg;
    msg.tag = 0x76;
    char* base = (char*)msg.arr;
    int i;
    for (i = 0; i < 4; i++) {
        base[i] = -1;
        *(base + i + 4) = -1;
    }

    if (LinkSession_IsHostOrSolo((struct CheckField0AndGlobalHalfStruct0202c508*)search)) {
        int j;
        for (j = 0; j < 4; j++) {
            GameObject* c = func_0200ff58(battleStruct, j);
            if (c != NULL) {
                int field = func_02053c6c((unsigned char*)c);
                if (field != 0) {
                    base[j] = (unsigned char)*(int*)(field + Enum_ov017_021c847c_2380);
                }
            }
        }
    }

    struct Party021c847c* party = (struct Party021c847c*)GameState_GetParty(battleStruct);
    int k;
    for (k = 0; k < party->count; k++) {
        unsigned char id = party->ids[k];
        GameObject* c2 = func_0200ff1c(battleStruct, id);
        if (c2 != NULL) {
            int field2 = func_02053c6c((unsigned char*)c2);
            if (field2 != 0) {
                unsigned int v = *(unsigned int*)(field2 + 0x78);
                *(base + id + 4) = (unsigned char)((v << 1) >> 31);
            }
        }
    }

    func_0205e330(data, &msg, 0);
}
