#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" int func_0204936c(unsigned char* obj);
extern "C" void func_ov025_021dc220(void* obj);

struct Struct_ov025_021dc168 {
    char pad0[0x20];
    unsigned short id;
    char unknown_22_[0xe];
    struct Struct_ov025_021dc168* next;
};

struct Struct_ov025_021dc168_2 {
    char pad0[0x10];
    struct Struct_ov025_021dc168* head;
};

struct Struct_ov025_021dc168_3 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    int unknown_29c_;
    char unknown_2a0_[0xeac - 0x2a0];
    int unknown_eac_;
};

// USA: func_ov025_021dc168
extern "C" ARM void func_ov025_021dc168(struct Struct_ov025_021dc168_3* obj) {
    GameState* bs = GameState::GetInstance();
    int var1 = obj->unknown_29c_;
    bs->GetCamera();
    GetGameResources();

    short buf[12];
    int n = 0;
    n = n + func_ov000_0215e9fc(var1, buf, 12, n);
    n = n + func_ov000_0215ec1c(var1, buf + n, 12 - n, 0);

    if (obj->unknown_eac_ == 2) {
        struct Struct_ov025_021dc168_2* list = (struct Struct_ov025_021dc168_2*)func_ov000_02160f20(obj);
        struct Struct_ov025_021dc168* node = list->head;
        int var6 = 1;
        while (node != NULL) {
            GameObject* combatant = bs->GetCombatantByIndex(node->id);
            if (combatant != NULL && func_0204936c((unsigned char*)combatant)) {
                var6 = 0;
                break;
            }
            node = node->next;
        }
        if (var6) {
            func_ov025_021dc220(obj);
        }
    }
}
