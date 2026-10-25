#include <globaldefs.h>
#include "GameState/GameState.h"


#if defined(jpn)
enum { Enum_02017c58_1052 = 0x43c };
#else
enum { Enum_02017c58_1052 = 0x41c };
#endif

extern "C" void* Scenario_GetInstance(void);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
void CallLoop0206eb20(void* a, void* b, int c, int limit);
extern "C" void func_0206ea8c(void* obj, unsigned char a, short b, int flag);

struct Struct_02017c58 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[0x70 - 4];
};

struct Struct_02017c58_2 {
    int unknown_0_;
    char unknown_4_[0x14 - 4];
    int unknown_14_;
    char unknown_18_[0x44 - 0x14 - 4];
    Struct_02017c58* unknown_44_;
    char unknown_48_[0x54 - 0x44 - 4];
    Struct_02017c58_2* unknown_54_;
};

// USA: func_02017c58
extern "C" ARM void func_02017c58(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    if (var0 == NULL) {
        return;
    }
    char* var1 = (char*)func_0200fd0c(var0);
    if (var1 == NULL) {
        return;
    }
    void* ctx = Scenario_GetInstance();
    if (ctx == NULL) {
        return;
    }

    int var3;
    for (var3 = 0; var3 < 2; var3++) {
        func_0206eb20(var2, (void*)(unsigned char)var3, 0, 0x7f);
        func_0206eb20(var2, (void*)(unsigned char)(unsigned int)var3, 0x80, 0xff);
    }

    int var4;
    int var5;
    Struct_02017c58_2* var6 = *(Struct_02017c58_2**)((char*)arg0 + Enum_02017c58_1052);
    int var7;
    while (var6 != NULL) {
        var4 = var6->unknown_14_;
        var5 = var6->unknown_0_;
        for (var7 = 0; var7 < var4; var7++) {
            Struct_02017c58* var8 = &var6->unknown_44_[var7];
            if (var8 != NULL && (var8->unknown_2_ & 4) != 0) {
                func_0206ea8c(var2, var5, (short)(var8->unknown_0_ + 0x80), 1);
            } else {
                func_0206ea8c(var2, var5, (short)var8->unknown_0_, 1);
            }
        }
        var6 = var6->unknown_54_;
    }
}
