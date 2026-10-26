#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_021537b8(char* self, short id, void* rec);

extern "C" int func_ov000_021543f4(GameObject* combatant);
extern "C" void* func_02079e2c(char* p, int key);

// USA: func_ov000_0215f110
extern "C" ARM void func_ov000_0215f110(char* self) {
    char* var0 = self;
    ActionDataTables* data = func_020797dc();
    int i = 0;
    while (i < *(int*)(var0 + 0x8000 + 0xe7c)) {
        char* rec = (char*)(*(int**)(var0 + 0x8000 + 0xe78)) + i * 0x28;
        short id = *(short*)((char*)(*(void**)(rec + 0x10)) + 0x20);
        GameState* bs = GameState::GetInstance();
        GameObject* c = bs->GetCombatantByIndex(id);
        if (c == NULL) {
            return;
        }
        if (!func_ov000_021543f4(c)) {
            short key = *(short*)rec;
            void* res = func_02079e2c((char*)data, key);
            if (res != NULL) {
                unsigned int v = *(unsigned int*)((char*)res + 8);
                if (((v << 3) >> 31) != 0) {
                    short var10 = *(short*)((char*)(*(void**)(rec + 0x10)) + 0x20);
                    func_ov000_021537b8(var0, var10, rec);
                }
            }
        }
        i++;
    }
}
