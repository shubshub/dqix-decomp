#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_02049f3c(unsigned char* obj);
extern "C" void* func_ov000_02160130(void);
extern "C" void func_ov000_02167434(unsigned char* obj, int value);

struct Struct_ov025_021e697c {
    char pad[8];
    unsigned char field8;
};

// USA: func_ov025_021e697c
extern "C" ARM int func_ov025_021e697c(struct Struct_ov025_021e697c* obj, int p1, int arg2, void* p3) {
    int local[8];
    GameState* bs = GameState::GetInstance();
    int count = func_ov000_021820bc(p3, p1, obj->field8, (int)&local[0]);
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = bs->GetCombatantByIndex(local[i]);
        if (c != NULL) {
            func_02049f3c((unsigned char*)c);
            {
                void* work = func_ov000_02160130();
                int val = ((Object3D*)((unsigned char*)c))->GetTexturePaletteOffset();
                func_ov000_02167434((unsigned char*)work, val);
            }
        }
    }
    return 1;
}
