#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c9954 {
    Object3D unknown_0_;
    char unknown_ac_[0x17d - 0xac];
    unsigned char unknown_17d_0_ : 7;
    unsigned char unknown_17d_7_ : 1;
};

struct Struct_ov017_021c9954_2 {
    char unknown_0_[3];
    unsigned char unknown_3_;
};

struct Struct_ov017_021c9954_3 {
    char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021c9954_4 {
    char unknown_0_[4];
    unsigned short unknown_4_;
};

struct Struct_ov017_021c9954_5 {
    char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov017_021c9954_6 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

struct Struct_ov017_021c9954_7 {
#if defined(jpn)
    char unknown_0_[0x3508];
#else
    char unknown1_0_[0x3718];
#endif
    Struct_ov017_021c9954_2* unknown_3718_;
#if defined(jpn)
    char unknown_350c_[0x3978 - 0x350c];
#else
    char unknown_371c_[0x3b98 - 0x371c];
#endif
    Struct_ov017_021c9954_5* unknown_3b98_;
#if defined(jpn)
    char unknown_397c_[0x41fe - 0x397c];
#else
    char unknown_3b9c_[0x44ae - 0x3b9c];
#endif
    Struct_ov017_021c9954_6 unknown_44ae_;
};

extern "C" void func_ov017_021b86f8(Party021c9954* party, int id, int flag, int keep);
extern "C" void FieldMonsterState_Init(void* obj);
extern "C" Leader021c9954* func_ov017_021b8478(Party021c9954* party);
extern "C" Leader021c9954* func_ov017_021b8468(Party021c9954* party);
void NoOp02163778(void* current);
extern "C" void func_020dc548(signed char id, signed char* out, signed char* count);
extern "C" void func_ov017_021917f0(int id, int flag);
Combatant021c9954* FindCombatantByField16a_021a278c(void* unused, int val);
void SetFieldForMatchingCombatant_021c98f4(int id, int value);
void TrySetMode02076ccc(void* obj, int mode);
Slot021c9954* GetPtrPlusOffsetC_021a7c8c(void* obj);
void SetByteAtOffset1_021a7c1c(unsigned char* obj);

// USA: func_ov017_021c9954
extern "C" ARM void func_ov017_021c9954(int arg0, int arg1, int arg2, int arg3) {
    GameState::GetInstance();
    Struct_ov017_021c9954_7* var0 = (Struct_ov017_021c9954_7*)GetGameResources();
    Struct_ov017_021c9954* var1;
    Struct_ov017_021c9954_2* var2 = var0->unknown_3718_;
    func_ov017_021b86f8(var2, arg0, 1, arg2);

    combatant = FindCombatantByField16a_021a278c(battle, id);
    if (combatant != 0 && keep == 0) {
        FieldMonsterState_Init(combatant);
        combatant->obj3D.MakeHidden();
    }
    func_ov017_021c98f4(arg0, 0);

    if (arg1 != 0) {
        Struct_ov017_021c9954_3* var3 = func_ov017_021b8478(var2);
        Struct_ov017_021c9954_3* var4 = func_ov017_021b8468(var2);
        if (var4 != 0 && var3 != 0 && var3->unknown_8_ == arg0) {
            func_ov000_02163778(var4);
        }
    }

    Struct_ov017_021c9954_6* var5 = &var0->unknown_44ae_;
    if (var0->unknown_44ae_.unknown_0_ == arg0) {
        var5->unknown_0_ = 0;
        var5->unknown_2_ = 0;
    }

    if (var1 != 0 && arg2 != 0) {
        func_02076ccc(var1, 1);
        var1->unknown_17d_7_ = 0;
    }

    Struct_ov017_021c9954_5* var6 = var0->unknown_3b98_;
    if (var6->unknown_2_ != 0) {
        Struct_ov017_021c9954_4* var7 = func_ov017_021a7c8c(var6);
        if (var7->unknown_4_ == arg0) {
            func_ov017_021a7c1c((unsigned char*)var6);
        }
    }

    if (arg3 > -1 && var2->unknown_3_ == 0) {
        signed char var8;
        signed char var9[7];
        func_020dc548(arg3, var9, &var8);
        for (int var10 = 0; var10 < var8; var10++) {
            func_ov017_021917f0(var9[var10], 0);
        }
    }
}
