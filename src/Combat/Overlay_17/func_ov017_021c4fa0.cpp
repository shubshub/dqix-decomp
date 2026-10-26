#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/ZoneResourceTree.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* memset(void* dst, int c, unsigned int n);
void* LinkMessageQueue_GetInstance(void);

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 4;
    unsigned short unknown_2_4_ : 12;
    unsigned short unknown_4_;
};
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct Struct_ov017_0218e674;
extern "C" int func_ov017_021bd3a4(Struct_ov017_0218e674* arg0);
extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);
extern "C" void* func_ov017_021b8470(void* arg0);
extern "C" int func_ov017_021b8b94(void* arg0);

struct Struct_ov017_021c4fa0_6 {
    char unknown_0_[8];
    unsigned short unknown_8_;
    char unknown_a_[8];
    unsigned char unknown_12_;
    char unknown_13_[5];
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    unsigned short unknown_1c_;
    char unknown_1e_[0x32];
    unsigned short unknown_50_;
    short unknown_52_;
#if defined(jpn)
    char unknown_54_[0xae];
#else
    char unknown1_54_[0xb2];
#endif
    unsigned char unknown_106_;
};

struct Struct_ov017_021c4fa0 {
    char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov017_021c4fa0_2 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov017_021c4fa0_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

struct Struct_ov017_021c4fa0_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    short unknown_4_;
    float unknown_8_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
};

struct Struct_ov017_021c4fa0_5 {
    unsigned char unknown_0_;
    struct Struct_ov017_021c4fa0_4 unknown_4_;
};

// USA: func_ov017_021c4fa0
extern "C" ARM void func_ov017_021c4fa0(int arg0, int arg1) {
    GameState* var0;
    unsigned short* var1;
    void* var2;
    char* var3;
    GameResources* var4;
    Struct_ov017_021c4fa0_4* var5;
    Struct_ov017_021c4fa0_2* var6;
    Struct_ov017_021c4fa0_6* var7;
    void* var8;
    Struct_ov017_021c4fa0* var9;
    int var10;
    Struct_020fdd44* var11;
    Struct_ov017_021c4fa0_3* var12;
    Struct_ov017_021c4fa0_5 var13;

    gs = GameState::GetInstance();
    search = LinkSession_GetInstance();
    cur = Zone3D_GetInstance();
    res = GetGameResources();
    unit = (Unit_021c4fa0*)res->unknown_ptr_array_371c[6];
    ZoneRecords_GetInstance();
    data = LinkMessageQueue_GetInstance();

    var13.unknown_0_ = 0x8f;
    var5 = &var13.unknown_4_;
    memset(var5, 0, sizeof(*var5));
    var5->unknown_1_ = 0;
    var5->unknown_0_ = arg0;
    var5->unknown_8_ = -1.0f;

    var9 = (Struct_ov017_021c4fa0*)var4->unknown_ptr_3718;
    var3 = (char*)func_ov017_021b8470(var9);
    var6 = (Struct_ov017_021c4fa0_2*)func_ov017_021b8478(var9);

    if (LinkSession_IsHostOrSolo(search)) {
        ok = 1;
        if (unit->field1a != id || (unit->flags50 & 0x800)) {
            if (unit->field1c != id) {
                ok = 0;
            }
        }
        if (func_ov017_021bd3a4((Struct_ov017_0218e674*)var7) && var7->unknown_12_ != 0 && var7->unknown_106_ == 0 && var10) {
            var5->unknown_1_ = 1;
            if (var7->unknown_18_ == 0) {
                var5->unknown_2_ = var7->unknown_8_;
                var5->unknown_4_ = var7->unknown_52_;
            } else {
                var5->unknown_2_ = var7->unknown_18_;
                var5->unknown_4_ = var7->unknown_52_;
            }
        } else if (var9->unknown_2_ != 0 && !(var3 != NULL && var3[0x8e14] != 0) && var6 != NULL &&
                   !func_020a35e0((unsigned char*)var6, arg0 & 0xff) && !func_ov017_021b8b94(var9) && var6->unknown_c_ >= 0) {
            var5->unknown_1_ = 2;
            var5->unknown_2_ = var6->unknown_c_;
            var5->unknown_4_ = *var1;
        }

        p->time = gs->GetDayTimer();
        entry = ZoneRecords_Find(ZoneRecords_GetInstance(), id);
        if (entry != NULL) {
            p->fieldC = entry->value;
            p->fieldE = entry->value2;
        } else {
#if defined(jpn)
            var12 = (Struct_ov017_021c4fa0_3*)((char*)var4 + 0x4204);
#else
            var12 = (Struct_ov017_021c4fa0_3*)((char*)var4 + 0x44b4);
#endif
            if (var12->unknown_0_ == arg1) {
                var5->unknown_c_ = var12->unknown_2_;
            } else {
                var5->unknown_c_ = 0;
            }
            var5->unknown_e_ = 0;
        }
    }
    func_0205e330(var2, &var13, 0);
}
