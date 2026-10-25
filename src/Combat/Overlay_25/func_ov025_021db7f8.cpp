#if defined(jpn)
enum {Enum_ov025_021db7f8_668=0x218, Enum_ov025_021db7f8_672=0x21c, Enum_ov025_021db7f8_3728=0xe0c, Enum_ov025_021db7f8_3736=0xe14, Enum_ov025_021db7f8_28668=0x71ec, Enum_ov025_021db7f8_6590=0x17ee};
#else
enum {Enum_ov025_021db7f8_668=0x29c, Enum_ov025_021db7f8_672=0x2a0, Enum_ov025_021db7f8_3728=0xe90, Enum_ov025_021db7f8_3736=0xe98, Enum_ov025_021db7f8_28668=0x6ffc, Enum_ov025_021db7f8_6590=0x19be};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov000_0215e9fc(void* party, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* party, short* buf, int max, int start);
void SetSubstructWord0x68_0204a00c(unsigned char* obj, int value);
void SetOrInitField_02182498(void* obj, int flag);
void SetFlag320_02195530(unsigned char* obj);
unsigned char* MessageSystem_GetInstance();

struct Struct_ov025_021db7f8 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov025_021db7f8_2 {
    char unknown_0_[Enum_ov025_021db7f8_668];
    void* unknown_29c_;
    char unknown_2a0_[Enum_ov025_021db7f8_3728 - Enum_ov025_021db7f8_672];
    unsigned char unknown_e90_;
    char unknown_e91_[3];
    int unknown_e94_;
    char unknown_e98_[Enum_ov025_021db7f8_28668 - Enum_ov025_021db7f8_3736];
    char unknown_6ffc_[4];
};

// USA: func_ov025_021db7f8
extern "C" ARM void func_ov025_021db7f8(Struct_ov025_021db7f8_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    short var1[16];
    int var2 = 0;
    var2 = var2 + func_ov000_0215e9fc(arg0->unknown_29c_, var1, 0x10, var2);
    var2 = var2 + func_ov000_0215ec1c(arg0->unknown_29c_, var1 + var2, 0x10 - var2, 0);
    short* var3 = var1;
    for (int var4 = 0; var4 < var2; var4++, var3++) {
        GameObject* var5 = var0->GetCombatantByIndex(*var3);
        if (var5) {
            Struct_ov025_021db7f8* var6 = (Struct_ov025_021db7f8*)((char*)var5 + 0xc1);
            if (var6->unknown_0_4_ == 1 || var6->unknown_0_4_ == 6) {
                var6->unknown_0_4_ = 0;
            }
            func_0204a00c((unsigned char*)var5, 0);
        }
    }
    SetOrInitField_02182498(obj->field6ffc, 1);
    SetFlag320_02195530((unsigned char*)GetGameResources());
    MessageSystem_GetInstance()[regionalOffset5] = 0;
    obj->fieldE90 = 0;
    obj->fieldE94 = 0;
}
