#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void LinkSession_GetInstance(void);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);

struct Struct_ov017_021c8654 {
    unsigned char tag;
    unsigned char pad[3];
    int arr[4];
};

// USA: func_ov017_021c8654
extern "C" ARM void func_ov017_021c8654(void) {
    GameState* bs = GameState::GetInstance();
    LinkSession_GetInstance();
    void* ctx = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021c8654 buf;
    buf.tag = 0x77;
    int* arr = buf.arr;
    for (int i = 0; i < 4; i++) {
        arr[i] = -1;
    }

    unsigned char* list = (unsigned char*)GameState_GetParty(bs);
    for (int i = 0; i < list[0xf7c]; i++) {
        unsigned char* row = list + i;
        unsigned char id = row[0xf78];
        GameObject* c = func_0200ff58(bs, id);
        if (c == NULL) {
            arr[id] = *(int*)(list + 0xf6c);
        }
    }

    func_0205e330(ctx, &buf, 0);
}
