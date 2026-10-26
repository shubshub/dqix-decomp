#include <globaldefs.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02174738_2 {
    char unknown_0_[0x40];
    char* unknown_40_;
    char unknown_44_[0xa];
    unsigned short unknown_4e_;
};

extern "C" char* func_ov000_0216fe74(struct Struct_ov000_02174738_2* arg0, unsigned int arg1);

struct Struct_ov000_02174738_3 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[0x4c - 0x25];
    int unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

struct Struct_ov000_02174738_4 {
    char unknown_0_[0x20];
    void* unknown_20_;
    char unknown_24_[0x800 - 0x24];
    struct Struct_ov000_02174738_3 unknown_800_[4];
};

struct Struct_ov000_02174738_5 {
    char unknown_0_[0x6c];
    signed char unknown_6c_[4];
    char unknown_70_[0x158 - 0x70];
    struct Struct_ov000_02174738_4 unknown_158_;
};

struct Struct_ov000_02174738_6 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};

struct Struct_ov000_02174738_7 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};

extern "C" int GameState_GetProtagonistIndex(GameState* arg0);
extern "C" void GlyphDestination_Clear(struct Struct_ov000_02174738_6* arg0);
extern "C" void GlyphDestination_SetPixels(void* arg0, int arg1);
extern "C" void GlyphDestination_SetRects(void* arg0, int arg1, unsigned char arg2);
extern "C" void* func_020421b0(int arg0);
extern "C" void func_ov000_02174a38(void* arg0, int arg1);

extern "C" void func_ov000_021710ac(struct Struct_ov000_02174738_3* arg0, int arg1, int arg2);
extern "C" void func_ov000_02171138(void* arg0);
extern "C" void func_ov000_02174b14(struct Struct_ov000_02174738_5* arg0);
extern "C" int func_ov017_021bdbcc();
extern "C" int Font_GetTextWidth(char* arg0, int arg1);
extern "C" void GlyphDestination_DrawText(struct Struct_ov000_02174738_6* arg0, short arg1, int arg2, void* arg3, unsigned char arg4, unsigned char arg5);

extern char data_ov000_0218405b;
extern int data_ov000_02183ff0;

#if defined(jpn)
// JPN: func_ov000_02174738
extern "C" ARM void func_ov000_02174738(struct Struct_ov000_02174738_5* arg0, int arg1) {
    int var0;
    if (arg1 >= 0) {
        if (arg1 <= 3) {
            var0 = 1;
            goto checkvalid;
        }
    }
    var0 = 0;
checkvalid:
    if (!var0) {
        return;
    }

    for (int var1 = 0; var1 < 4; var1++) {
        signed char* var2 = (signed char*)((int)arg0 + 0x6c);
        signed char* var3 = var2;
        struct Struct_ov000_02174738_3* var4 = &arg0->unknown_158_.unknown_800_[var3[var1]];
        if (arg1 == var4->unknown_4c_) {
            func_ov000_02171138(var4);
            func_ov000_02174b14(arg0);
            return;
        }
    }

    GameState* var5 = GameState::GetInstance();
    for (int var6 = 0; var6 < 4; var6++) {
        struct Struct_ov000_02174738_3* var7 = &arg0->unknown_158_.unknown_800_[arg0->unknown_6c_[var6]];
        if (arg0->unknown_6c_[var6] != arg1) {
            continue;
        }
        if (var7->unknown_4c_ >= 0) {
            continue;
        }
        func_ov000_021710ac(var7, arg1, arg1 == GameState_GetProtagonistIndex(var5));
        func_ov000_02174a38(var7, arg1 == GameState_GetProtagonistIndex(var5));
        func_ov000_02171138(var7);
        data_ov000_02183ff0 = data_ov000_02183ff0 + 1;
        func_ov000_02174b14(arg0);
        if (data_ov000_02183ff0 > 4) {
            data_ov000_02183ff0 = 4;
        }
        return;
    }
}
#else
// USA: func_ov000_02174738
extern "C" ARM void func_ov000_02174738(struct Struct_ov000_02174738_5* arg0, int arg1) {
    int var8;
    if (arg1 >= 0) {
        if (arg1 <= 3) {
            var8 = 1;
            goto checkvalid;
        }
    }
    var8 = 0;
checkvalid:
    if (!var8) {
        return;
    }

    for (int var9 = 0; var9 < 4; var9++) {
        signed char* var10 = (signed char*)((int)arg0 + 0x6c);
        signed char* var11 = var10;
        struct Struct_ov000_02174738_3* var12 = &arg0->unknown_158_.unknown_800_[var11[var9]];
        if (arg1 == var12->unknown_4c_) {
            func_ov000_02171138(var12);
            func_ov000_02174b14(arg0);
            return;
        }
    }

    void* var13 = arg0->unknown_158_.unknown_20_;
    char* var14;
    char* var15;
    GameObject* var16 = GameState::GetInstance()->GetPartyMemberByIndex(arg1);
    if (var16 != NULL) {
        char* var17 = func_ov000_0216fe74((struct Struct_ov000_02174738_2*)((char*)arg0 + 0x11c),
                                                (unsigned short)(arg1 + 0x20));
        if (var17 != NULL) {
          var14 = *(char**)(var17 + 8);
          if (var14 != NULL) {
            int var18 = *(int*)(*(char**)((char*)var16 + 0x150) + 0x950);
            unsigned char var19 = (unsigned char)(var18 * 4 + 0x28);
            GetGameResources();
            if (func_ov017_021bdbcc() != 0) {
                var19 = 0x28;
            }
            memcpy(var13, func_020421b0(var19), 0x80);

            unsigned short var20 = *(unsigned short*)(var14 + 4) & 0x3ff;
            unsigned int var21 = var20 << 7;
            CleanInvalidateCacheRange(var13, 0x80);
            LoadToSubObjVRAM(var13, var21, 0x80);
            CleanCacheRange(var13, 0x80);
          }
        }
        {
            char* var22 = func_ov000_0216fe74((struct Struct_ov000_02174738_2*)((char*)arg0 + 0x11c),
                                                     (unsigned short)(arg1 + 0x24));
            if (var22 != NULL) {
              var15 = *(char**)(var22 + 8);
              if (var15 != NULL) {
                memset(var13, 0, 0x80);
                struct Struct_ov000_02174738_6 var23;
                struct Struct_ov000_02174738_7 var24;
                var24.unknown_0_ = 0;
                var24.unknown_4_ = 0;
                var24.unknown_6_ = 0;
                var24.unknown_8_ = 0x10;
                var24.unknown_a_ = 0x10;
                GlyphDestination_Clear(&var23);
                GlyphDestination_SetPixels(&var23, (int)var13);
                GlyphDestination_SetRects(&var23, (int)&var24, 1);
                char* var25 = *(char**)((char*)var16 + 0x150);
                int var26 = *(int*)(var25 + 0x950);
                char* var27 = var25 + var26 * 2 + 0x100;
                unsigned short var28 = *(unsigned short*)(var27 + 0x6c);
                char var29[8];
                sprintf(var29, &data_ov000_0218405b, var28);
                short var30 = (short)(0x10 - Font_GetTextWidth(var29, 0));
                GlyphDestination_DrawText(&var23, var30, 0, var29, 0xf, 0);

                unsigned short var31 = *(unsigned short*)(var15 + 4) & 0x3ff;
                unsigned int var32 = var31 << 7;
                CleanInvalidateCacheRange(var13, 0x80);
                LoadToSubObjVRAM(var13, var32, 0x80);
                CleanCacheRange(var13, 0x80);
              }
            }
        }
    }

    GameState* var33 = GameState::GetInstance();
    for (int var34 = 0; var34 < 4; var34++) {
        struct Struct_ov000_02174738_3* var35 = &arg0->unknown_158_.unknown_800_[arg0->unknown_6c_[var34]];
        if (arg0->unknown_6c_[var34] != arg1) {
            continue;
        }
        if (var35->unknown_4c_ >= 0) {
            continue;
        }
        func_ov000_021710ac(var35, arg1, arg1 == GameState_GetProtagonistIndex(var33));
        func_ov000_02174a38(var35, arg1 == GameState_GetProtagonistIndex(var33));
        func_ov000_02171138(var35);
        data_ov000_02183ff0 = data_ov000_02183ff0 + 1;
        func_ov000_02174b14(arg0);
        if (data_ov000_02183ff0 > 4) {
            data_ov000_02183ff0 = 4;
        }
        return;
    }
}
#endif
