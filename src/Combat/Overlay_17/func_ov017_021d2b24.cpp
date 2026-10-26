#if defined(jpn)
enum { Enum_ov017_021d2b24_32608 = 0x7c8c, Enum_ov017_021d2b24_1844 = 0x524, Enum_ov017_021d2b24_1816 = 0x508, Enum_ov017_021d2b24_255 = 0xfb };
#else
enum { Enum_ov017_021d2b24_32608 = 0x7f60, Enum_ov017_021d2b24_1844 = 0x734, Enum_ov017_021d2b24_1816 = 0x718, Enum_ov017_021d2b24_255 = 0xff };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021c3e18 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};
void SetVec3_021c3f68(struct Vec3_021c3f68* obj, int x, int y, int z);
unsigned short GetField6b4_021b8480(void* obj);
void GameObject_ResetTrail(unsigned char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c);
struct Vector3i;

struct Struct_ov017_021d2b24 {
    char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    char unknown_6_[2];
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};

struct Struct_ov017_021d2b24_2 {
    char unknown_0_[3];
    unsigned char unknown_3_;
    char unknown_4_[Enum_ov017_021d2b24_255];
    unsigned char unknown_103_;
};

// USA: func_ov017_021d2b24
extern "C" ARM void func_ov017_021d2b24(void* arg0, struct Struct_ov017_021d2b24* arg1, int arg2, void* arg3) {
    unsigned char* var0 = (unsigned char*)arg3;
    GameState* var1 = GameState::GetInstance();

    if (arg1->unknown_4_ == 0xce) {
        func_ov017_021c3f68((struct Struct_ov017_021c3e18*)((char*)var1 + Enum_ov017_021d2b24_32608), arg1->unknown_8_, arg1->unknown_c_, arg1->unknown_10_);
    }

    GameObject* var2 = var1->GetPartyMemberByIndex(arg1->unknown_4_);
    if (var2 == NULL) {
        return;
    }

    struct Struct_ov017_021d2b24_2* var3 = *(struct Struct_ov017_021d2b24_2**)(var0 + 0x3000 + Enum_ov017_021d2b24_1844);
    if (var3->unknown_3_ != 0 && var3->unknown_103_ != 0) {
        return;
    }

    void* var4 = *(void**)(var0 + 0x3000 + Enum_ov017_021d2b24_1816);
    if (*(unsigned char*)((char*)var4 + 0x2) != 0 && func_ov017_021b8480(var4) == 0) {
        return;
    }

    GameObject_ResetTrail((unsigned char*)combatant);
    SetFields0x44((struct Fields020407b4*)combatant, evt->field8, evt->fieldc, evt->field10);

    if (arg1->unknown_5_ != 0) {
        struct Struct_ov017_021c3e18 var5;
        func_ov017_021c3f68(&var5, arg1->unknown_8_, arg1->unknown_c_, arg1->unknown_10_);
        *(Vector3i*)((int*)((char*)var2 + 0xd4)) = *(Vector3i const*)((int*)&var5);
        *(unsigned char*)((char*)var2 + 0xe0) |= 0x20;
    }

    *(unsigned short*)((char*)var2 + 0xac) = 0;

    if (arg1->unknown_4_ == 0xce) {
        func_020407b4((struct Struct_02040774_2*)var2, arg1->unknown_8_, arg1->unknown_c_, arg1->unknown_10_);
    }
}
