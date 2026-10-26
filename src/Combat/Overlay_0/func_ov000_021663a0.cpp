#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_ov000_0216733c(struct Struct_ov000_021663a0_2* scene);
extern "C" void func_ov000_02166540(struct Struct_ov000_021663a0_2* scene, int id, int kind, int group);
extern "C" void IntArray_Shuffle(int* ids, int count);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_02048bd0(unsigned char* obj);

struct Struct_ov000_021663a0_3 {
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char rest : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov000_021663a0_4 {
    unsigned char field_0x0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    unsigned char hi : 2;
    char unknown_2_[2];
    struct Struct_ov000_021663a0_3 groups[3];
};

struct Struct_ov000_021663a0_5 {
    char unknown_0_[0x81b0];
    struct Struct_ov000_021663a0_4 formation;
    char unknown_81fc_[0x8de0 - 0x81b0 - sizeof(struct Struct_ov000_021663a0_4)];
    int slots[8];
};

struct Struct_ov000_021663a0 {
    char unknown_0_[0x2c];
    int unknown_2c_;
};

struct Struct_ov000_021663a0_2 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    struct Struct_ov000_021663a0_5* data;
    struct Struct_ov000_021663a0* config;
};

// USA: func_ov000_021663a0
extern "C" ARM void func_ov000_021663a0(struct Struct_ov000_021663a0_2* scene) {
    GameState* gs = GameState::GetInstance();
    GetGameResources();
    struct Struct_ov000_021663a0_4* formation = &scene->data->formation;
    int count = 0;
    func_ov000_0216733c(scene);
    unsigned char saved[8];
    int ids[8];
    if (scene->config->unknown_2c_ != 0) {
        unsigned char* p = saved;
        for (int i = 0; i < 8; i++) {
            *p = scene->data->slots[i];
            p++;
        }
    }
    for (int g = 0; g < formation->groupCount; g++) {
        struct Struct_ov000_021663a0_3* group = &formation->groups[g];
        for (int j = 0; j < group->count; j++) {
            int id = group->ids[j] + 0xc0;
            func_ov000_02166540(scene, id, group->kind, g);
            ids[count++] = id;
        }
    }
    if (scene->config->unknown_2c_ != 0) {
        unsigned char* p = saved;
        for (int i = 0; i < 8; i++) {
            scene->data->slots[i] = *p;
            p++;
        }
    }
    IntArray_Shuffle(ids, count);
    for (int i = 0; i < count; i++) {
        GameObject* c = func_0200fea4(gs, ids[i]);
        if (c != 0 && scene->config->unknown_2c_ == 0 && !func_02048bd0((unsigned char*)c)) {
            c->obj3D_.SetInheritedAlpha(0);
            ((unsigned char*)c)[0x183] = 0x10 / count * i + 5;
        }
    }
}
