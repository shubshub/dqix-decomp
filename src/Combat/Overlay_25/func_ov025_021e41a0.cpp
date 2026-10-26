#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_ov025_021e41a0_4 {
    unsigned char padding0[8];
    const char* name;
    unsigned char type;
    signed char slot;
    unsigned short id;
    unsigned char flags;
    unsigned char unknown_11_;
    short x;
    short y;
    short z;
    short unknown_18_;
    unsigned char mode;
};
struct Struct_02078398_2 {
    char name[0x10];
    unsigned char type;
    unsigned char unknown_11_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flags : 5;
    short field12;
    short combatant;
    short unknown_16_;
    short field18;
    short unknown_1a_;
    short field1c;
    short unknown_1e_;
    Vector3i field20;
    Vector3i position;
    Vector3i rotation;
    Vector3i scale;
};
struct Struct_ov000_0215440c_2;
struct Struct_ov025_021e41a0_2 { unsigned char padding0[0x20]; unsigned short id; };
struct Struct_ov025_021e41a0_3 { unsigned char padding0[0xe]; short id; };
struct Struct_ov000_0215440c { unsigned char padding0[9]; unsigned char count; };
#if defined(jpn)
struct Struct_ov025_021e41a0 { unsigned char padding0[0x70f2]; unsigned short id; };
#else
struct Struct_ov025_021e41a0 { unsigned char padding0[0x6f02]; unsigned short id; };
#endif
#if defined(jpn)
struct Struct_ov025_021ef988_10 { unsigned char padding0[4]; char* slots; };
#else
struct Struct_ov025_021ef988_10 { unsigned char padding0[0xc]; char* slots; };
#endif
extern Struct_ov025_021ef988_10 data_ov025_021ef988;
extern "C" void* func_02057924();
extern "C" Struct_ov025_021e41a0_2* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov025_021e41a0_3* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" void func_02078484(Struct_02078398_2*);
extern "C" Struct_ov025_021e41a0* func_ov000_02160130();
extern "C" void* func_02057fb4(void*, int, void*);
extern "C" void** func_ov025_021e8cf0(char*, int);

static inline void inline_ov025_021e41a0(Vector3i* offset, int arg1) {
    offset->x *= arg1;
    offset->z *= arg1;
}

// USA: func_ov025_021e41a0
extern "C" ARM int func_ov025_021e41a0(Struct_ov025_021e41a0_4* command, Struct_ov000_0215440c* list) {
    GameState* game = GameState::GetInstance();
    void* manager = func_02057924();
    Struct_ov025_021e41a0_2* source = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
    if (!source) return 0;
    int var3 = source->id;
    GameObject* object = game->GetGameObjectByIndex(var3);
    int frame = object->obj3D_.normalizedAnimationTime_;
    if (command->unknown_18_ > 0 && frame < command->unknown_18_) return 0;
    Struct_02078398_2 effect;
    func_02078484(&effect);
    effect.flag2 = 0;
    int var7 = 1;
    if (command->flags & 1) {
        Vector3i position = {};
        for (int i = 0; i < list->count; i++) {
            Struct_ov025_021e41a0_3* target = func_ov000_021600f8(list, i);
            if (target) {
                GameObject* var11 = game->GetGameObjectByIndex(target->id);
                if (var11) {
                    Vector3i targetPosition = var11->obj3D_.position_;
                    Vector3fix_Add(&position, &targetPosition, &position);
                    effect.scale = var11->obj3D_.GetScale();
                }
            }
        }
        if (list->count) {
            int scale = 4096.0f * (1.0f / (unsigned int)list->count);
            Vector3fixMultiplyScalar(&position, scale, &position);
        }
        Struct_ov025_021e41a0_3* target = func_ov000_021600f8(list, 0);
        Vector3i offset = {command->x, command->y, command->z};
        int party = 0;
        int id = target->id;
        if (id >= 0 && id <= 3) party = 1;
        if (!party) inline_ov025_021e41a0(&offset, -1);
        Vector3fix_Add(&position, &offset, &position);
        effect.position = position;
        int var18 = 0;
        int var19 = target->id;
        if (var19 >= 0 && var19 <= 3) var18 = 1;
        effect.rotation.y = var18 ? 0x3244 : 0;
        var7 = 0;
    }
    if (var7) effect.combatant = var3;
    if (command->name) strcpy(effect.name, command->name);
    effect.type = command->type;
    effect.unknown_11_0_ = command->mode;
    if (effect.unknown_11_0_) {
        effect.combatant = -1;
        effect.scale.x = 0x800;
        effect.scale.y = 0x800;
        effect.scale.z = 0x800;
    }
    Struct_ov025_021e41a0* work = func_ov000_02160130();
    work->id = command->id;
    void* instance = func_02057fb4(manager, command->id, &effect);
    void** slot = func_ov025_021e8cf0(data_ov025_021ef988.slots, command->slot);
    if (slot) *slot = instance;
    return 1;
}
