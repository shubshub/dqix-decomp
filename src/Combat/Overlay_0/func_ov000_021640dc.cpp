#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" int func_ov000_02160fd4(void* work, int mask);
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void func_020a367c(unsigned char* obj, int index);

extern "C" void func_ov017_021c8b78(unsigned short tag);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov000_0215f03c(struct Struct_02000c9c_33* data);
extern "C" void func_ov000_021663a0(struct Struct_ov000_021640dc_4* scene);
extern "C" void func_ov000_02164d74(struct Struct_ov000_021640dc_4* scene);
extern "C" void func_ov000_021674f4(unsigned char* scene, int flag);
extern "C" unsigned char* func_0208a9b4(void);
extern "C" void func_0208b4c0(unsigned char* obj);
extern "C" void func_ov000_02160d80(void* p, int val);
extern "C" void func_ov000_021750e4(void* obj);
extern "C" void func_ov000_021760d4(void* obj);

struct Struct_ov000_021640dc {
    unsigned char field_0x0;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 4;
};

struct Struct_02000c9c_33 {
    char unknown_0_[0x81b0];
    struct Struct_ov000_021640dc formation;
};

struct Struct_ov000_021640dc_2 {
    char unknown_0_[8];
    unsigned short unknown_8_;
    char unknown_a_[2];
    int unknown_c_;
    char unknown_10_[0x2a - 0x10];
    signed char partyId;
    char unknown_2b_;
    int unknown_2c_;
    int unknown_30_;
};

struct Struct_ov000_021640dc_3 {
    char unknown_0_[0x1b];
    signed char partyId;
    char unknown_1c_[4];
    int unknown_20_;
    unsigned short unknown_24_;
};

struct Struct_ov000_021640dc_4 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    struct Struct_02000c9c_33* data;
    struct Struct_ov000_021640dc_2* config;
#if defined(jpn)
    char unknown_220_[0x371c - 0x220];
#else
    char unknown_2a4_[0x3760 - 0x2a4];
#endif
    struct Struct_ov000_021640dc_3 turn;
#if defined(jpn)
    char unknown_3744_[0x56b0 - 0x3744];
#else
    char unknown_3788_[0x54bc - 0x3788];
#endif
    unsigned char unknown_54bc_;
};

static inline void inline_ov000_02163db4(unsigned char* obj, unsigned char index) {
    func_020a367c(obj, index);
}

static inline struct Struct_ov000_021640dc* inline_ov000_021640dc(struct Struct_02000c9c_33* data) {
    return &data->formation;
}

// USA: func_ov000_021640dc
extern "C" ARM void func_ov000_021640dc(struct Struct_ov000_021640dc_4* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    if (res->unknown_42e2_ != 0) {
        func_ov000_02160fa8(scene, 0x2000000);
        return;
    }
    struct Struct_ov000_021640dc_2* config = scene->config;
    int partyId = func_ov017_02195658(res);
    if (func_020a35e0((unsigned char*)config, partyId)) {
        if (config->partyId == partyId) {
            func_ov000_02160fa8(scene, 0x2000000);
            func_ov017_021c8b78(config->unknown_8_);
        }
        inline_ov000_02163db4((unsigned char*)config, partyId);
        return;
    }
    if (!func_ov000_02160fd4(scene, 4)) {
        return;
    }
    if (!func_ov000_02160fd4(scene, 0x200000)) {
        return;
    }
    if (scene->config->partyId != GameState_GetProtagonistIndex(gs)) {
        func_ov000_0215f03c(scene->data);
    }
    func_ov000_021663a0(scene);
    func_ov000_02164d74(scene);
    scene->config->unknown_30_ = 0;
    func_ov000_021674f4((unsigned char*)scene, scene->config->unknown_2c_ == 0);
    func_0208b4c0(func_0208a9b4());
    func_ov000_02160d80(scene, 7);
    func_ov000_02160fa8(scene, 0x10000);
    func_ov000_02160fa8(scene, 0x40000000);
    scene->turn.unknown_24_ = scene->config->unknown_8_;
    scene->unknown_54bc_ = inline_ov000_021640dc(scene->data)->unknown_1_0_;
    scene->turn.unknown_20_ = scene->config->unknown_c_;
    scene->turn.partyId = scene->config->partyId;
    func_ov000_021750e4(&scene->turn);
    func_ov000_021760d4(&scene->turn);
    ClearFlags00(res, 0x10);
}
