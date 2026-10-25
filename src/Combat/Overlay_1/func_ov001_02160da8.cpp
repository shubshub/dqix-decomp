#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"

struct Struct_ov001_0215b72c { char unknown_0_[8]; };
struct Struct_ov001_02160da8 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
    unsigned char unknown_1_;
    short unknown_2_;
    unsigned char unknown_4_;
    char unknown_5_[3];
    union { char unknown_0_[36]; int unknown1_0_; } unknown_8_;
    int unknown_2c_;
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    char unknown_32_[2];
    Struct_ov001_02160da8* unknown_34_;
};
struct Struct_ov001_02160da8_2 {
    #if defined(jpn)
    char unknown_0_[0xcc]; Struct_ov001_02160da8* unknown_d0_;
#else
    char unknown1_0_[0xd0]; Struct_ov001_02160da8* unknown_d0_;
#endif
    char unknown_d4_[0xf8 - 0xd4]; unsigned int unknown_f8_0_ : 27; unsigned int unknown_fb_3_ : 5;
    char unknown_fc_[0x116 - 0xfc]; signed char unknown_116_;
};
struct Obj02061bd8;
extern "C" int func_ov017_021d60f4(ScriptArgument*);
extern "C" const char* func_ov017_021d612c(ScriptArgument*);
int GameState_GetLeaderIndex(GameState*);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int GetNibbleAt56b_ov001_021612ac(void*);
int CheckField0x56bLowNibble(Obj02061bd8*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_02165728[];
extern const char data_ov001_02165745[];
extern const char data_ov001_02165775[];
extern const char data_ov001_021657b2[];

// USA: func_ov001_02160da8
extern "C" ARM int func_ov001_02160da8(Struct_ov001_0215b72c* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov001_02160da8* var1;
    Struct_ov001_02160da8_2* var2 = (Struct_ov001_02160da8_2*)GetGameResources()->unknown_ptr_array_371c[6];
    SafeAllocator* var3 = data_ov001_021658b8[0];
    unsigned int var4 = var2->unknown_fb_3_ + 160;
    if (var4 > 191) return 0;
    var1 = (Struct_ov001_02160da8*)var3->Allocate(sizeof(Struct_ov001_02160da8));
    var1->unknown_0_0_ = 0;
    var1->unknown_0_4_ = 0;
    var1->unknown_1_ = 0;
    var1->unknown_2_ = 0;
    var1->unknown_4_ = 0;
    memset(var1->unknown_8_.unknown_0_, 0, sizeof(var1->unknown_8_.unknown_0_));
    var1->unknown_2c_ = -1;
    var1->unknown_34_ = 0;
    var1->unknown_30_ = 0;
    var1->unknown_31_ = 0;
    var1->unknown_0_0_ = (unsigned char)func_ov017_021d60f4(arg0);
    switch (var1->unknown_0_0_) {
    case 0:
    case 1:
    case 9:
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        if (command->kind == 1) command->objectId = GameState_GetLeaderIndex(game);
        else if (command->kind == 9) {
            command->objectId = state->selectedObject;
            if (!GetCombatantWithFlag0x100_0200ff1c(game, command->objectId)) command->objectId = GameState_GetLeaderIndex(game);
        }
        if (var1->unknown_2_ == 0) var1->unknown_0_4_ = 1;
        else var1->unknown_0_4_ = 2;
        break;
    case 11:
    case 12:
    case 13:
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        command->group = 2;
        GameState_GetLeaderIndex(game);
        if (command->kind == 11) command->objectId = 3;
        else if (command->kind == 12) command->objectId = 2;
        else if (command->kind == 13) command->objectId = 1;
        if (!game->GetGameObjectByIndex(command->objectId)) {
            command->kind = 15;
            return 0;
        }
        break;
    case 10: {
        if (arg1 < 2) return 0;
        var1->unknown_1_ = func_ov017_021d60f4(arg0 + 1);
        int var5 = 0;
        GameObject* var6 = func_0200ff58(var0, 0xce);
        if (var6) {
            var1->unknown_2_ = 0xce;
            var5 = func_ov001_021612ac(var6);
        } else {
            int var7;
            for (var7 = 0; var7 < 4; ++var7) {
                GameObject* var8 = func_0200ff58(var0, var7);
                if (var8 && func_02061bd8((Struct_0205faf4_11*)var8)) {
                    var1->unknown_2_ = var7;
                    var5 = func_ov001_021612ac(var8);
                    break;
                }
            }
            if (var7 == 4) return 0;
        }
        var1->unknown_0_4_ = (unsigned char)(var5 + 2);
        break;
    }
    case 2:
    case 6:
    case 7: {
        if (arg1 < 3) return 0;
        const char* var9 = func_ov017_021d612c(arg0 + 1);
        if (var1->unknown_0_0_ == 6) {
            if (!strstr(var9, data_ov001_02165728)) return 0;
            const char* var10 = strrchr(var9, '/');
            if (var10) var9 = var10 + 1;
            strcpy(var1->unknown_8_.unknown_0_, var9);
        } else sprintf(var1->unknown_8_.unknown_0_, data_ov001_02165745, var9);
        var1->unknown_1_ = func_ov017_021d60f4(arg0 + 2);
        var1->unknown_2_ = var2->unknown_fb_3_ + 160;
        ++var2->unknown_fb_3_;
        if (arg1 > 3) var1->unknown_30_ = func_ov017_021d60f4(arg0 + 3);
        break;
    }
    case 8:
        if (arg1 < 2) return 0;
        sprintf(var1->unknown_8_.unknown_0_, data_ov001_02165775);
        var1->unknown_1_ = func_ov017_021d60f4(arg0 + 1);
        var1->unknown_2_ = var2->unknown_fb_3_ + 160;
        ++var2->unknown_fb_3_;
        if (arg1 > 2) var1->unknown_30_ = func_ov017_021d60f4(arg0 + 2);
        break;
    case 3:
        if (arg1 < 3) return 0;
        sprintf(var1->unknown_8_.unknown_0_, data_ov001_021657b2, func_ov017_021d612c(arg0 + 1));
        var1->unknown_1_ = func_ov017_021d60f4(arg0 + 2);
        if (arg1 > 3) var1->unknown_30_ = func_ov017_021d60f4(arg0 + 3);
        break;
    case 4:
    case 5:
        if (arg1 < 3) return 0;
        var1->unknown_8_.unknown1_0_ = func_ov017_021d60f4(arg0 + 1);
        var1->unknown_1_ = func_ov017_021d60f4(arg0 + 2);
        if (var1->unknown_0_0_ == 4) {
            var1->unknown_2_ = var2->unknown_fb_3_ + 160;
            ++var2->unknown_fb_3_;
        }
        break;
    default:
        return 0;
    }
    if (!var2->unknown_d0_) var2->unknown_d0_ = var1;
    else {
        Struct_ov001_02160da8* var11 = var2->unknown_d0_;
        while (var11->unknown_34_) var11 = var11->unknown_34_;
        var11->unknown_34_ = var1;
    }
    return 1;
}
