#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_020488ec(char* obj);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_02161274
extern "C" ARM void func_ov000_02161274(GameObject* self) {
    if (self == NULL) {
        return;
    }
    void* inner = *(void**)((char*)self + 0x144);
    if (inner == NULL) {
        return;
    }
    short val = *(short*)((char*)inner + 8);
    GameState* bs = GameState::GetInstance();
    int i = 0;
    while (i < 8) {
        GameObject* c = func_0200fea4(bs, i + 0xc0);
        if (c != NULL && c != self) {
            void* var5 = *(void**)((char*)c + 0x144);
            if (var5 != NULL) {
                short var6 = *(short*)((char*)var5 + 8);
                if (var6 == val) {
                    unsigned char* var7 = *(unsigned char**)((char*)c + 0x138);
                    if (var7[0x25] == 0 && *((unsigned char*)c + 0x18d) == 0) {
                        var7[0x25] = 1;
                        *((unsigned char*)c + 0x18d) = 1;
                        func_020488ec((char*)c);
                        return;
                    }
                }
            }
        }
        i++;
    }
}
