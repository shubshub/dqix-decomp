#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094 { char pad[0x20]; unsigned short id; };
struct Struct_ov000_0215440c { char pad[9]; unsigned char count; };
struct Struct_ov000_021600f8 { char pad[0xe]; short id; };

struct Struct_ov025_021e3c80 {
    char pad[8];
    unsigned short type;
    unsigned char mode;
    float x;
    float y;
    float z;
};

struct Struct_ov025_021ef988_8 {
#if defined(jpn)
    char pad[4];
    char* ctx;
    char pad8[0xc - 0x8];
#else
    char pad[0xc];
    char* ctx;
    char pad10[0x1c - 0x10];
#endif
    unsigned int flags;
};
extern Struct_ov025_021ef988_8 data_ov025_021ef988;

extern "C" void* func_ov000_02160130();
extern "C" char* func_ov000_02160f14(void* work);
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" void func_ov000_021626a0(void* work, int index, int show);
extern "C" void func_ov025_021eb8e8(char* ctx);
extern "C" void func_ov000_0216d600(char* camera, int arg1, int close, int mode, float x, float y, float z, unsigned char arg7);
extern "C" void func_ov000_0216d90c(char* camera, int index);
extern "C" void func_ov025_021eba60(char* obj);
extern "C" void func_ov000_0216da34(char* camera, int arg1, int arg2);
extern "C" struct Random* func_ov000_02160ef8(unsigned char* obj);
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov000_0216dbf0(char* camera, int* ids, int count, short flag);
extern "C" void func_ov000_0216de00(char* camera, int arg1, int arg2);
extern "C" void func_ov000_0216df00(char* camera, int id, int force, float offset, float arg4);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" void func_ov000_0216e250(char* camera, int* ids, int count);
extern "C" void func_ov000_0216d370(char* camera, int flagA, int arg2, int flagC);
extern "C" void func_ov000_0216f2b8(char* camera);

// USA: func_ov025_021e3c80
extern "C" ARM int func_ov025_021e3c80(Struct_ov025_021e3c80* cmd, Struct_ov000_0215440c_2* list) {
    int buf[12];
    int ids[8];
    unsigned char* work = (unsigned char*)func_ov000_02160130();
    char* camera = func_ov000_02160f14(work);
    char* ctx = data_ov025_021ef988.ctx;
    Struct_ov000_02160094* actor = func_ov000_02160094(list, 0);
    Struct_ov000_021600f8* target = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
    if (*(unsigned int*)(ctx + 0x1c4) & 0x40) {
        func_ov000_021626a0(work, 4, 1);
        *(unsigned int*)(ctx + 0x1c4) &= ~0x40;
    }
    camera[0x221] = 1;
    int moved = 0;
    func_ov025_021eb8e8(ctx);
    switch (cmd->type) {
    case 0:
        moved = 1;
        func_ov000_0216d600(camera, 1, 0, 0, 0.0f, 0.0f, 0.0f, 0);
        break;
    case 15:
        moved = 1;
        func_ov000_0216d600(camera, 1, 1, 0, 0.0f, 0.0f, 0.0f, 0);
        break;
    case 1:
        if (actor == 0) return 1;
        func_ov000_0216d90c(camera, actor->id);
        func_ov025_021eba60(ctx);
        break;
    case 2:
        if (actor == 0 || target == 0) return 1;
        func_ov000_0216da34(camera, actor->id, target->id);
        break;
    case 3:
    case 11: {
        struct Random* var8 = func_ov000_02160ef8(work);
        int count = func_ov000_021820bc(var8, (int)list, 0x33, (int)buf);
        func_ov000_0216dbf0(camera, buf, count, cmd->type == 11);
        moved = 1;
        break;
    }
    case 4:
        if (actor == 0 || target == 0) return 1;
        func_ov000_0216de00(camera, actor->id, target->id);
        moved = 1;
        break;
    case 5:
    case 13: {
        if (actor == 0) return 1;
        if (cmd->type == 13) moved = 1;
        float var10 = cmd->z;
        float offset = cmd->y;
        func_ov000_0216df00(camera, actor->id, moved, offset, var10);
        func_ov025_021eba60(ctx);
        moved = 1;
        break;
    }
    case 6:
    case 14: {
        if (target == 0) return 1;
        if (cmd->type == 14) moved = 1;
        float var12 = cmd->z;
        float offset = cmd->y;
        func_ov000_0216df00(camera, target->id, moved, offset, var12);
        func_ov025_021eba60(ctx);
        moved = 1;
        break;
    }
    case 12: {
        if (target == 0) return 1;
        short id = func_ov000_0215ffa0(target);
        void* other = func_ov000_02160130();
        if (other != 0) {
            func_ov000_021626a0(other, 4, 0);
        }
        GameObject* obj = GameState::GetInstance()->GetCombatantByIndex(id);
        if (obj != 0) {
            obj->obj3D_.MakeVisible();
        }
        func_ov000_0216df00(camera, id, 0, 0.0f, 1.8f);
        moved = 1;
        break;
    }
    case 7: {
        int count = ((Struct_ov000_0215440c*)list)->count;
        for (int i = 0; i < count; i++) {
            Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, i);
            if (node != 0) {
                ids[i] = node->id;
            }
        }
        func_ov000_0216e250(camera, ids, count);
        moved = 1;
        break;
    }
    case 8: {
        if (actor == 0) return 1;
        int var20 = actor->id > 3 ? 1 : 0;
        unsigned char var21 = var20 ? 1 : 0;
        func_ov000_0216d600(camera, var21, 0, cmd->mode, cmd->x, cmd->y, cmd->z, 0);
        moved = 1;
        break;
    }
    case 9: {
        if (target == 0) return 1;
        int isParty = 0;
        if (target->id >= 0 && target->id <= 3) isParty = 1;
        unsigned char var23 = isParty ? 0 : 1;
        func_ov000_0216d600(camera, var23, 0, cmd->mode, cmd->x, cmd->y, cmd->z, 0);
        moved = 1;
        break;
    }
    case 10:
        func_ov000_0216d370(camera, 0, 0, 0);
        break;
    }
    if (work != 0 && moved) {
#if defined(jpn)
        enum { regionalOffset0 = 0x71c5 };
#else
        enum { regionalOffset0 = 0x6fd5 };
#endif
        work[regionalOffset0] = 1;
    }
    data_ov025_021ef988.flags |= 8;
    *(int*)(data_ov025_021ef988.ctx + 0x224) = 0;
    func_ov000_0216f2b8(camera);
    return 1;
}
