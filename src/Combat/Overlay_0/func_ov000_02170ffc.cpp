#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02170ffc_2 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int field94c;
};

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" struct Struct_ov000_02170ffc_2* func_02053c6c(unsigned char* obj);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
};
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" void __clear(void* buf, int count);

struct Struct_ov000_02170ffc {
    char pad0[4];
    struct Container020e0310* container;
    char pad8[0x24 - 0x8];
    unsigned char flags;
    char unknown_25_[0x4c - 0x25];
    int combatantId;
    struct Obj0203c108 label;
#if defined(jpn)
    char unknown_66_[0xc7 - 0x66];
#else
    char unknown1_66_[0x87 - 0x66];
#endif
    unsigned char visible;
};

extern "C" int func_ov000_021719f8(int* obj);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170ffc* obj);
#else
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170ffc* obj, char* buf);
#endif

// USA: func_ov000_02170ffc
extern "C" ARM void func_ov000_02170ffc(struct Struct_ov000_02170ffc* obj) {
#if !defined(jpn)
    char buf[0x80];
#endif
    if (obj->flags & 2) {
        return;
    }
    if (obj->visible == 0) {
        return;
    }
    if (func_ov000_021719f8((int*)obj)) {
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
    short key = 0x753e;
    GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->combatantId);
    if (member == NULL) {
        return;
    }
    struct Struct_ov000_02170ffc_2* ext = func_02053c6c((unsigned char*)member);
    key += (signed char)ext->field94c;
    CachedTextLabel_SetText(&obj->label, (char*)KeyTable_Get(obj->container, key));
}
