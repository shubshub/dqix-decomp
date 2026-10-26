#if defined(jpn)
enum { Enum_ov025_021dc220_3704 = 0xdf4 };
#else
enum { Enum_ov025_021dc220_3704 = 0xe78 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" int func_ov000_021627fc(void* obj);
struct Struct_ov000_0215440c;
extern "C" void* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" void func_02049ae4(unsigned char* obj);
extern "C" int func_02048c10(unsigned char* obj);
extern "C" void func_0204a030(unsigned char*, int);
extern "C" void GameObject_FaceGameObject(void* a, int b, int c);

extern char data_ov025_021ef404[];
extern "C" unsigned char _ZZ21inline_ov025_021dcf14vE1s;

struct Struct_ov025_021dc220 {
    char pad0[Enum_ov025_021dc220_3704];
    unsigned char unknown_e78_;
    char pad1[0x33];
    int unknown_eac_;
};

struct Struct_ov025_021dc220_2 {
    char pad0[0x20];
    unsigned short id;
    char pad1[0xc];
    struct Struct_ov025_021dc220_2* next;
};

struct Struct_ov025_021dc220_3 {
    char pad0[0x10];
    struct Struct_ov025_021dc220_2* head;
};

// USA: func_ov025_021dc220
extern "C" ARM void func_ov025_021dc220(void* obj) {
    struct Struct_ov025_021dc220* self = (struct Struct_ov025_021dc220*)obj;
    GameState* battle = GameState::GetInstance();
    void* slot = func_ov000_02160f20(obj);
    short idx = -1;

    if (func_ov000_021627fc(obj)) {
        *(int*)(data_ov025_021ef404 + 4) = 1;
        self->unknown_eac_ = 6;
        {
            void* var4 = func_ov000_021600f8((struct Struct_ov000_0215440c*)slot, 0);
            if (var4 != NULL) {
                idx = *(short*)((char*)var4 + 0xe);
            }
        }
    } else {
        self->unknown_eac_ = 3;
    }

    if (slot != NULL) {
        struct Struct_ov025_021dc220_3* list = (struct Struct_ov025_021dc220_3*)slot;
        struct Struct_ov025_021dc220_2* node = list->head;
        int var7 = 1;
        while (node != NULL) {
            GameObject* combatant = battle->GetCombatantByIndex(node->id);
            if (combatant != NULL) {
                func_02049ae4((unsigned char*)combatant);
                if (idx >= 0) {
                    int var9 = var7;
                    if (func_02048c10((unsigned char*)combatant) || self->unknown_e78_ == 0) {
                        var9 = 0;
                    }
                    if (var9) {
                        if (_ZZ21inline_ov025_021dcf14vE1s != 0) {
                            func_0204a030((unsigned char*)combatant, idx);
                        } else {
                            GameObject_FaceGameObject(combatant, idx, 1);
                        }
                    }
                }
            }
            node = node->next;
        }
    }
}
