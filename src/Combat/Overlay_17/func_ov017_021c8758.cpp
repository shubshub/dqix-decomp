#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

void* LinkMessageQueue_GetInstance(void);
void* GetField6b0_021b8470(void* obj);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int flag);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c8758 {
    Vector3i unknown_0_;
    short unknown_c_;
    unsigned short unknown_e_;
};

struct Struct_ov017_021c8758_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    struct Struct_ov017_021c8758 unknown_4_;
};

// USA: func_ov017_021c8758
extern "C" ARM void func_ov017_021c8758(unsigned short arg0) {
#if defined(jpn)
 enum { Enum_ov017_021c8758_1816=0x508 };
#else
 enum { Enum_ov017_021c8758_1816=0x718 };
#endif
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GetGameResources();
    void* data = LinkMessageQueue_GetInstance();
    void* field = GetField6b0_021b8470(*(void**)(base + 0x3000 + regionalOffset));
    if (field == NULL) {
        return;
    }

    short var4[8];
    struct Struct_ov017_021c8758_2 var5;
    struct Struct_ov017_021c8758_2 var6;

    int var7 = func_ov000_0215e9fc(var3, var4, 8, 0x10);
    for (int var8 = 0; var8 < var7; var8++) {
        GameObject* var9 = var0->GetCombatantByIndex(var4[var8]);
        unsigned char* var10;
        if (var9 == NULL || (var10 = *(unsigned char**)((unsigned char*)var9 + 0x13c)) == NULL) {
            continue;
        }
        memset(&var5, 0, sizeof(var5));
        var5.unknown_0_ = 0x78;
        struct Struct_ov017_021c8758* var11 = &var5.unknown_4_;
        var11->unknown_e_ = arg0;
        var11->unknown_c_ = var4[var8];
        var11->unknown_0_ = *(Vector3i*)(var10 + 0x10);
        func_0205e330(var2, &var5, 0);
    }

    var7 = func_ov000_0215eb1c(var3, var4, 8, 0x10);
    for (int var12 = 0; var12 < var7; var12++) {
        GameObject* var13 = var0->GetCombatantByIndex(var4[var12]);
        unsigned char* var14;
        if (var13 == NULL || (var14 = *(unsigned char**)((unsigned char*)var13 + 0x13c)) == NULL) {
            continue;
        }
        memset(&var6, 0, sizeof(var6));
        var6.unknown_0_ = 0x78;
        struct Struct_ov017_021c8758* var15 = &var6.unknown_4_;
        var15->unknown_e_ = arg0;
        var15->unknown_c_ = var4[var12];
        var15->unknown_0_ = *(Vector3i*)(var14 + 0x10);
        func_0205e330(var2, &var6, 0);
    }
}
