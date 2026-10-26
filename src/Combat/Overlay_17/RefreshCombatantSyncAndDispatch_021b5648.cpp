#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Field18 = 0x14, Field23ec = 0x240c };
#else
enum { Field18 = 0x18, Field23ec = 0x23ec };
#endif

extern "C" void* LinkSession_GetInstance(void);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
struct U16Field0x6_020375f8;
extern "C" unsigned short NodeGraph_FindClosestNode(void* a, void* b);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021a2128(void* a, int b, int c, int d, void* e, int f, int g, int h);

struct Buf3_021b5648 { unsigned int a, b, c; };
extern struct Buf3_021b5648 data_ov017_021d6bcc;

// USA: func_ov017_021b5648  (semantic: RefreshCombatantSyncAndDispatch_021b5648)
extern "C" ARM void func_ov017_021b5648(char* self) {
    GameState* bs = GameState::GetInstance();
    void* ctx = LinkSession_GetInstance();

    int i;
    for (i = 0; i < 4; i++) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, i);
        if (c == 0) continue;
        void* p8 = *(void**)(self + 0x8);
        if (*(unsigned short*)p8 != ((Object3D*)((struct U16Field0x6_020375f8*)c))->GetField06()) continue;

        unsigned short v = NodeGraph_FindClosestNode((char*)p8 + Field18, (char*)c + 0x44);
        *(unsigned short*)((char*)c + 0xb8) = v;
        ((unsigned char*)c)[0xc2] |= 0x40;
    }

    if (LinkSession_IsHostOrSolo(ctx) != 0 && *(unsigned short*)(self + 0x12) != 0) {
        GameState* bs2 = GameState::GetInstance();
        void* obj5 = GetGameResources();
        bs2->GetGrottoStruct();
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)Zone3D_GetInstance() + Field23ec);
        unsigned char env = grotto->GetActiveGrottoEnviron() & 0xff;

        struct Buf3_021b5648 local = data_ov017_021d6bcc;
        switch (env) {
            case 1: local.c = 0xfffecccd; break;
            case 2: local.c = 0xffff019a; break;
            case 3: local.c = -0x13800; break;
            case 4: local.c = 0xfffecccd; break;
            case 5: local.c = 0xfffebb34; break;
            default: local.c = 0xfffecccd; break;
        }

        unsigned char flags = 0;
        if (((unsigned char*)self)[0x11] == 1) flags |= 2;
        else if (((unsigned char*)self)[0x11] == 2) flags |= 4;

        func_ov017_021a2128(obj5, *(unsigned short*)(*(void**)(self + 0x8)),
                             *(unsigned short*)(self + 0x12), -1, &local, 0, 0, flags);
    }

    *(unsigned short*)((char*)(*(void**)(self + 0x8)) + 2) |= 0x8;
    self[1] = 1;
}
