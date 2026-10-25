#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

extern "C" int func_020dc920(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov017_0218b628(signed char arg0);
extern int data_020fdcb0[][8];

struct Struct_ov002_02159774 {
#if defined(jpn)
    unsigned char unknown_0_[0x10];
#else
    unsigned char unknown1_0_[0x34];
#endif
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    unsigned char unknown_38_[4];
};

// USA: func_ov002_02159774
extern "C" ARM int func_ov002_02159774(char *arg0, int arg1, int arg2, int arg3, unsigned char arg4) {
#if defined(jpn)
    enum { Enum_ov002_02159774_7206 = 0x1aee, Enum_ov002_02159774_9340 = 0x22ac, Enum_ov002_02159774_7096 = 0x1a80, Enum_ov002_02159774_6832 = 0x1a08 };
#else
    enum { Enum_ov002_02159774_7206 = 0x1c26, Enum_ov002_02159774_9340 = 0x247c, Enum_ov002_02159774_7096 = 0x1bb8, Enum_ov002_02159774_6832 = 0x1ab0 };
#endif
    GameObject *var0;
    float var1, var2, var3;
    int var4;
    var0 = func_0200ff1c(GameState::GetInstance(), arg1);
    if (var0 == 0) return 3;
    if (arg2) {
        int var5 = 0;
        if (*(short *) (arg0 + Enum_ov002_02159774_7206) == 0xd1) var5 = 1;
        if (func_020dc920(arg1 & 0xff, arg3, arg4, var5) == 0) return 3;
    }
    int *e = data_020fdcb0[c->obj3D_.actorIndex_];
    cur    = (float) e[0];
    max    = (float) e[2];
    if ((*(int *) (self + regionalOffset1) & 1) || *(int *) (self + regionalOffset2) == 4) {
        if (TestFlagBit55dIfActive_0218b628(id)) {
            cur = (float) (int) c->combatFields_.savedState_130_->hp;
            max = (float) (int) c->baseStats_->primaryStats.maxHP;
        } else {
            Stat02159774 *s = &((Stat02159774 *) (self + regionalOffset3))[c->obj3D_.actorIndex_];
            cur             = (float) (unsigned int) s->cur;
            max             = (float) (unsigned int) s->max;
        }
    }
    var3 = 0.0f;
    if (var1 > 0.0f && var2 > 0.0f) var3 = var1 / var2;
    var4 = 0xf;
    if (var3 <= 0.0f)
        var4 = 9;
    else if (var3 <= 0.08f)
        var4 = 0xb;
    else if (var3 <= 0.25f)
        var4 = 0xd;
    return var4;
}
