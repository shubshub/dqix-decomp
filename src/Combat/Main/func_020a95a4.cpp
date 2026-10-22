#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0208660c;
struct Struct_02061c04_23;
struct Struct_020838c4;
struct Struct_02108760_2;

struct Struct_020a95a4_7 {
    unsigned char unknown_0_[0x23c];
};

struct Struct_020a95a4_8 {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_[0x130];
    unsigned char unknown_13c_[0x98];
    unsigned char unknown_1d4_[0xe04 - 0x1d4];
    unsigned char unknown_e04_[0xc];
    unsigned char unknown_e10_[0xbc];
    unsigned char unknown_ecc_[0x5e];
    unsigned char unknown_f2a_[0xf68 - 0xf2a];
    int unknown_f68_;
    int unknown_f6c_;
    int unknown_f70_;
    int unknown_f74_;
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
    unsigned char unknown_f7d_;
    unsigned char unknown_f7e_[2];
    Struct_020a95a4_7 unknown_f80_[13];
    unsigned char unknown_2c8c_;
    unsigned char unknown_2c8d_[7];
    unsigned int unknown_2c94_;
};

struct Struct_020a95a4 {
    unsigned char unknown_0_[0x1b48];
    int unknown_1b48_;
    int unknown_1b4c_;
};

struct Struct_020a95a4_2 {
    unsigned char unknown_0_[RG(0x840, 0x860)];
    Struct_020a95a4 unknown_840_;
    unsigned char unknown_2390_[RG(0x2774 - 0x2390, 0x27b4 - 0x23b0)];
    Vector3i unknown_2774_;
    int unknown_2780_;
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
    unsigned char unknown_2789_[0x2794 - 0x2789];
    int unknown_2794_;
    unsigned char unknown_2798_[0x27b4 - 0x2798];
    unsigned short unknown_27b4_;
    unsigned short unknown_27b6_;
    unsigned char unknown_27b8_[0x27d0 - 0x27b8];
    unsigned char unknown_27d0_;
};

struct Struct_020a95a4_3 {
    unsigned char unknown_0_[0x4a8];
    unsigned char unknown_4a8_[0x1a];
};

struct Struct_ov004_02170174 {
    unsigned char unknown_0_[6];
};

struct Struct_020a95a4_4 {
    unsigned char unknown_0_[RG(0x63dc, 0x617c)];
    unsigned char unknown_63dc_;
    unsigned char unknown_63dd_[RG(0x74fe - 0x63dd, 0x72be - 0x617d)];
    Struct_ov004_02170174 unknown_74fe_;
    unsigned char unknown_7504_[RG(0x7e74 - 0x7504, 0x7c34 - 0x72c4)];
    int unknown_7e74_;
};

struct Struct_020a95a4_5 {
    unsigned char unknown_0_[0x454];
    unsigned char unknown_454_[0x10];
    unsigned char unknown_464_[0x568 - 0x464];
    short unknown_568_;
    unsigned char unknown_56a_[RG(0x94c - 0x56a, 0x8b4 - 0x56a)];
    int unknown_94c_;
    unsigned char unknown_950_[0x964 - 0x950];
};

struct Struct_020a95a4_6 {
    Struct_020a95a4_7 unknown_0_[13];
    unsigned char unknown_1d0c_;
    unsigned char unknown_1d0d_[4];
    unsigned char unknown_1d11_;
    struct Struct_01ff85b8 { unsigned char unknown_0_[0x12]; } unknown_1d12_[4];
    unsigned char unknown_1d5a_[2];
    unsigned char unknown_1d5c_[0x1d4];
    unsigned short unknown_1f30_[0x3f0];
    unsigned char unknown_2710_[0x3f0];
    unsigned char unknown_2b00_[8];
    unsigned char unknown_2b08_[0x128];
    int unknown_2c30_;
    int unknown_2c34_;
    int unknown_2c38_;
    int unknown_2c3c_;
    int unknown_2c40_;
    unsigned char unknown_2c44_[7];
    unsigned char unknown_2c4b_;
    unsigned short unknown_2c4c_;
    unsigned short unknown_2c4e_;
    unsigned short unknown_2c50_[4];
    unsigned char unknown_2c58_;
    unsigned char unknown_2c59_;
    unsigned char unknown_2c5a_;
    unsigned char unknown_2c5b_;
    unsigned short unknown_2c5c_;
    short unknown_2c5e_;
    Vector3i unknown_2c60_;
    int unknown_2c6c_;
    int unknown_2c70_;
    unsigned char unknown_2c74_;
    unsigned char unknown_2c75_;
    unsigned char unknown_2c76_;
    unsigned char unknown_2c77_;
    Struct_ov004_02170174 unknown_2c78_;
    unsigned char unknown_2c7e_[2];
    int unknown_2c80_;
    int unknown_2c84_;
    unsigned char unknown_2c88_[0x1a];
    unsigned char unknown_2ca2_;
    unsigned char unknown_2ca3_[5];
};

extern "C" void* func_02010828(GameState* arg0);
extern "C" void* func_0202ae18(void);
extern "C" Struct_020a95a4_2* func_02012fe4(void);
extern "C" Struct_020a95a4_3* func_02094d6c(void);
extern "C" void func_020a93e0(char* arg0);
extern "C" void func_02082d6c(void* arg0, void* arg1);
extern "C" int func_020838c4(struct Struct_020838c4* arg0, int arg1);
extern "C" void func_020a093c(struct Struct_0208660c* arg0, int arg1, int arg2, short arg3);
extern "C" int func_020a0a08(struct Struct_02061c04_23* arg0, int arg1, int arg2);
extern "C" void func_0207c258(void* arg0);
extern "C" unsigned short* func_0207c5f8(unsigned char* arg0, unsigned int arg1);
extern "C" unsigned char* func_0207c60c(void* arg0, unsigned int arg1);
extern "C" short func_0207c620(unsigned char* arg0, unsigned int arg1);
extern "C" void func_0207c6a8(unsigned char* arg0, unsigned int arg1, unsigned char arg2);
extern "C" unsigned short* func_020120a0(char* arg0, unsigned int arg1);
extern "C" void func_0209ca70(void* arg0, int arg1);
extern "C" void func_0205e9f4(struct Struct_02108760_2* arg0, int arg1);

extern unsigned char data_02109bf4[];
extern unsigned char g_sePlayer[];

// USA: func_020a95a4
#if defined(jpn)
extern "C" ARM int func_020a95a4(Struct_020a95a4_6* arg0, Struct_020a95a4_5* arg1) {
#else
extern "C" ARM int func_020a95a4(Struct_020a95a4_6* arg0, Struct_020a95a4_5* arg1, unsigned char* arg2) {
#endif
    GameState* var0 = GameState::GetInstance();
    Struct_020a95a4_8* var1 = static_cast<Struct_020a95a4_8*>(func_02010828(var0));
    func_0202ae18();
    Struct_020a95a4_2* var2 = func_02012fe4();
    GetGameResources();
    Struct_020a95a4_3* var3 = func_02094d6c();
#if !defined(jpn)
    func_020a93e0((char*)arg0);
#endif

    for (int var4 = 0; var4 < arg0->unknown_1d11_; var4++) {
        unsigned char var5 = arg0->unknown_1d0d_[var4];
        Struct_020a95a4_7* var6 = &arg0->unknown_0_[arg0->unknown_1d0c_ + var4];
        Struct_020a95a4_5* var7 = NULL;
        int var8;
        for (var8 = 0; var8 < 4; var8++) {
            if (var5 == arg1[var8].unknown_568_) {
                var7 = &arg1[var8];
                break;
            }
        }
        if (var7 == NULL) {
            for (var8 = 0; var8 < 4; var8++) {
                if (arg1[var8].unknown_568_ < 0) {
                    var7 = &arg1[var8];
                }
            }
        }
        if (var7 != NULL) {
            func_02082d6c(var7, var6);
            var7->unknown_568_ = var5;
            memcpy(var7->unknown_454_, &arg0->unknown_1d12_[var4], 0x10);
            func_020838c4((struct Struct_020838c4*)var7, 0x5612);
            if (var5 == 0) {
                var7->unknown_94c_ = 5;
            }
        }
    }

    var1->unknown_2c8c_ = arg0->unknown_1d0c_;
    memcpy(var1->unknown_f80_, arg0->unknown_0_, arg0->unknown_1d0c_ * sizeof(Struct_020a95a4_7));
    memcpy(var1->unknown_f78_, arg0->unknown_1d0d_, 4);
    var1->unknown_f7c_ = arg0->unknown_1d11_;
    memcpy(var1->unknown_0_, arg0->unknown_1d5c_, sizeof(arg0->unknown_1d5c_));
    func_020a093c((struct Struct_0208660c*)var1->unknown_0_, (int)var1->unknown_c_, (int)var1->unknown_13c_, 0x98);
    func_020a0a08((struct Struct_02061c04_23*)var1->unknown_0_, 0x5612, 0x63);

    int var9 = 0;
    func_0207c258(var1->unknown_1d4_);
    for (int var10 = 0; var10 < 8; var10++) {
        unsigned short* var11 = func_0207c5f8(var1->unknown_1d4_, var10);
        unsigned char* var12 = func_0207c60c(var1->unknown_1d4_, var10);
        short var13 = func_0207c620(var1->unknown_1d4_, var10);
        memcpy(var11, &arg0->unknown_1f30_[var9], var13 * 2);
        memcpy(var12, &arg0->unknown_2710_[var9], var13);
        var9 += var13;
        func_0207c6a8(var1->unknown_1d4_, var10, arg0->unknown_2b00_[var10]);
    }

    memcpy(battle->tactics, save->tactics, sizeof(save->tactics));
    SetFields020a093c((struct Fields020a093c*)battle->tactics, (int)battle->tacticsKeys, (int)battle->tacticsValues, 0x5e);
    battle->valueF6c = save->valueF6c;
    battle->valueF68 = save->valueF68;
    battle->valueF70 = save->valueF70;
    battle->valueF74 = save->valueF74;
    memcpy(battle->extraIds, save->extraIds, sizeof(save->extraIds));
    GameStateLoadView* view = (GameStateLoadView*)gs;
    battle->areaId = save->areaId;
    view->value7e74 = save->areaId;
    memcpy(GetField0x74deForValidIndex_020120a0((char*)gs, 0), save->words, sizeof(save->words));
    SetModeClamped0209ca70(data_02109bf4, save->globalByte);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)g_sePlayer, save->globalByte2);
    battle->byteF7d = save->byteF7d;
    view->byte63dc = save->byte63dc;
    field->savedDir = save->dir;
    field->savedAngle = save->angle;
    field->savedPos = save->pos;
    field->savedValue = save->value;
    field->savedExtra = save->extra;
    field->savedFlag = save->flag;
    field->savedCountA = save->countA;
    field->savedCountB = save->countB;
    field->savedCountC = save->countC;
    view->name74fe = save->name;
    FieldSubState* sub = &field->sub;
    sub->savedPosA = save->posA;
    sub->savedPosB = save->posB;
    memcpy(global->block4a8, save->block4a8, sizeof(save->block4a8));
#if !defined(jpn)
    *arg2 = arg0->unknown_2ca2_;
#endif
    return 1;
}
