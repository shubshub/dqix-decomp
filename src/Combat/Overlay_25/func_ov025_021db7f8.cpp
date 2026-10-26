#if defined(jpn)
enum {regionalOffset0=0x218, regionalOffset1=0x21c, regionalOffset2=0xe0c, regionalOffset3=0xe14, regionalOffset4=0x71ec, regionalOffset5=0x17ee};
#else
enum {regionalOffset0=0x29c, regionalOffset1=0x2a0, regionalOffset2=0xe90, regionalOffset3=0xe98, regionalOffset4=0x6ffc, regionalOffset5=0x19be};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov000_0215e9fc(void* party, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* party, short* buf, int max, int start);
extern "C" void func_0204a00c(unsigned char* obj, int value);
extern "C" void func_ov000_02182498(void* obj, int flag);
extern "C" void func_ov017_02195530(unsigned char* obj);
extern "C" unsigned char* MessageSystem_GetInstance();

struct Struct_ov025_021db7f8 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Struct_ov025_021db7f8_2 {
    char pad0[regionalOffset0];
    void* party;
    char unknown_2a0_[regionalOffset2 - regionalOffset1];
    unsigned char unknown_e90_;
    char unknown_e91_[3];
    int unknown_e94_;
    char unknown_e98_[regionalOffset4 - regionalOffset3];
    char unknown_6ffc_[4];
};

// USA: func_ov025_021db7f8
extern "C" ARM void func_ov025_021db7f8(Struct_ov025_021db7f8_2* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(obj->party, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(obj->party, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; i++, p++) {
        GameObject* c = bs->GetCombatantByIndex(*p);
        if (c) {
            Struct_ov025_021db7f8* s = (Struct_ov025_021db7f8*)((char*)c + 0xc1);
            if (s->hi == 1 || s->hi == 6) {
                s->hi = 0;
            }
            func_0204a00c((unsigned char*)c, 0);
        }
    }
    func_ov000_02182498(obj->unknown_6ffc_, 1);
    func_ov017_02195530((unsigned char*)GetGameResources());
    MessageSystem_GetInstance()[regionalOffset5] = 0;
    obj->unknown_e90_ = 0;
    obj->unknown_e94_ = 0;
}
