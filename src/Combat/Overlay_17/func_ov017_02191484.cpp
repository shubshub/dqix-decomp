#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" void func_ov017_02190264(void* h, int i);
extern "C" void func_0200fd48(GameState* battleStruct, int id);
extern "C" void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov017_02191484
extern "C" ARM void func_ov017_02191484(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x980};
#else
 enum {regionalOffset0=0xba0};
#endif
    GameState* bs = GameState::GetInstance();
    int h = ((int)GetGameResources());
    for (int i = 0; i < 4; i++) {
        GameObject* c = func_0200ff1c(bs, i);
        if (c) {
            if (func_02061bd8((struct Struct_0205faf4_11*)c)) {
                func_ov017_02190264((void*)h, i);
            }
        }
    }
    func_0200fd48(bs, 0xce);
    unsigned char* p = (unsigned char*)GameState_GetParty(bs);
    p[0xf7d] = 0;
    unsigned char* p2 = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    p2[0xb] = 0;
}
