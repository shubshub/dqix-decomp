#if defined(jpn)
enum { Enum_ov017_021d2b24_32608 = 0x7c8c, Enum_ov017_021d2b24_1844 = 0x524, Enum_ov017_021d2b24_1816 = 0x508, Enum_ov017_021d2b24_255 = 0xfb };
#else
enum { Enum_ov017_021d2b24_32608 = 0x7f60, Enum_ov017_021d2b24_1844 = 0x734, Enum_ov017_021d2b24_1816 = 0x718, Enum_ov017_021d2b24_255 = 0xff };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021c3e18 {
    int x;
    int y;
    int z;
};
extern "C" void func_ov017_021c3f68(struct Struct_ov017_021c3e18* obj, int x, int y, int z);
extern "C" unsigned short func_ov017_021b8480(void* obj);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
struct Fields020407b4;
extern "C" void func_020407b4(struct Fields020407b4* dst, int a, int b, int c);
struct Vector3i;

struct Struct_ov017_021d2b24 {
    char pad0[4];
    unsigned char id;
    unsigned char flag5;
    char pad6[2];
    int field8;
    int fieldc;
    int field10;
};

struct Struct_ov017_021d2b24_2 {
    char pad0[3];
    unsigned char unknown_3_;
    char pad4[Enum_ov017_021d2b24_255];
    unsigned char unknown_103_;
};

// USA: func_ov017_021d2b24
extern "C" ARM void func_ov017_021d2b24(void* unused0, struct Struct_ov017_021d2b24* evt, int arg2, void* arg3) {
    unsigned char* ctx = (unsigned char*)arg3;
    GameState* battle = GameState::GetInstance();

    if (evt->id == 0xce) {
        func_ov017_021c3f68((struct Struct_ov017_021c3e18*)((char*)battle + Enum_ov017_021d2b24_32608), evt->field8, evt->fieldc, evt->field10);
    }

    GameObject* combatant = battle->GetPartyMemberByIndex(evt->id);
    if (combatant == NULL) {
        return;
    }

    struct Struct_ov017_021d2b24_2* entryPtr = *(struct Struct_ov017_021d2b24_2**)(ctx + 0x3000 + Enum_ov017_021d2b24_1844);
    if (entryPtr->unknown_3_ != 0 && entryPtr->unknown_103_ != 0) {
        return;
    }

    void* var4 = *(void**)(ctx + 0x3000 + Enum_ov017_021d2b24_1816);
    if (*(unsigned char*)((char*)var4 + 0x2) != 0 && func_ov017_021b8480(var4) == 0) {
        return;
    }

    GameObject_ResetTrail((unsigned char*)combatant);
    func_020407b4((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);

    if (evt->flag5 != 0) {
        struct Struct_ov017_021c3e18 tmp;
        func_ov017_021c3f68(&tmp, evt->field8, evt->fieldc, evt->field10);
        *(Vector3i*)((int*)((char*)combatant + 0xd4)) = *(Vector3i const*)((int*)&tmp);
        *(unsigned char*)((char*)combatant + 0xe0) |= 0x20;
    }

    *(unsigned short*)((char*)combatant + 0xac) = 0;

    if (evt->id == 0xce) {
        func_020407b4((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);
    }
}
