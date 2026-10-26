#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02170ffc_2 {
#if defined(jpn)
    char unknown_0_[0x8b4];
#else
    char unknown1_0_[0x94c];
#endif
    int unknown_94c_;
};

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
struct CombatantExt02170ffc* GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Struct_0203c108_3 {
    char unknown_0_[0x14];
    short unknown_14_;
};
void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" void __clear(void* arg0, int arg1);

struct Struct_ov000_02170ffc {
    char unknown_0_[4];
    struct Struct_0201099c_3* unknown_4_;
    char unknown_8_[0x24 - 0x8];
    unsigned char unknown_24_;
    char unknown_25_[0x4c - 0x25];
    int unknown_4c_;
    struct Struct_0203c108_3 unknown_50_;
#if defined(jpn)
    char unknown_66_[0xc7 - 0x66];
#else
    char unknown1_66_[0x87 - 0x66];
#endif
    unsigned char unknown_87_;
};

extern "C" int func_ov000_021719f8(int* arg0);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170ffc* arg0);
#else
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170ffc* arg0, char* arg1);
#endif

// USA: func_ov000_02170ffc
extern "C" ARM void func_ov000_02170ffc(struct Struct_ov000_02170ffc* arg0) {
#if !defined(jpn)
    char var0[0x80];
#endif
    if (arg0->unknown_24_ & 2) {
        return;
    }
    if (arg0->unknown_87_ == 0) {
        return;
    }
    if (func_ov000_021719f8((int*)arg0)) {
#if defined(jpn)
        int key = func_ov000_02171a74(obj);
        struct Container020e0310* container = obj->container;
        if (container != NULL && key >= 0) {
            CachedTextLabel_SetText(&obj->label, (char*)KeyTable_Get(container, key));
            return;
        }
#else
        __clear(buf, sizeof(buf));
        if (func_ov000_02171a74(obj, buf) >= 0) {
            CachedTextLabel_SetText(&obj->label, buf);
            return;
        }
#endif
    }
    short var3 = 0x753e;
    GameObject* var4 = GameState::GetInstance()->GetPartyMemberByIndex(arg0->unknown_4c_);
    if (var4 == NULL) {
        return;
    }
    struct CombatantExt02170ffc* ext = GetFieldAt0x150_02053c6c((unsigned char*)member);
    key += (signed char)ext->field94c;
    CachedTextLabel_SetText(&obj->label, (char*)KeyTable_Get(obj->container, key));
}
