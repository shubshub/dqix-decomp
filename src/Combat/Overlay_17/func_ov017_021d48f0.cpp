#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0205e57c_6;
extern "C" int func_0205e830(struct Struct_0205e57c_6* obj, int index);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);

struct Struct_ov017_021d48f0 { unsigned char idx; };
extern "C" Struct_ov017_021d48f0* func_0205e41c(void* obj, int* outPtr);

typedef void (*Type_01ff91ac_3)(int, Struct_ov017_021d48f0*, GameState*, GameResources*, void*);
extern Type_01ff91ac_3 data_ov017_021d7f98[];

// USA: func_ov017_021d48f0
extern "C" ARM void func_ov017_021d48f0(void) {
    GameState* bs = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    void* data = LinkMessageQueue_GetInstance();
    void* extra = LinkSession_GetInstance();
    int var4;
    Struct_ov017_021d48f0* node;
    while ((node = func_0205e41c(data, &var4)) != NULL) {
        unsigned char idx = node->idx;
        if (idx < 0xbc) {
            if (func_0205e830((struct Struct_0205e57c_6*)data, idx)) {
                data_ov017_021d7f98[idx](var4, node, bs, ov, extra);
            }
        }
    }
}
