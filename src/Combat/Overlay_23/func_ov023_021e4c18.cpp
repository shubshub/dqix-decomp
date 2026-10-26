#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int func_ov023_021e29d0(char* obj);
extern "C" void func_ov023_021e2ce8(int combatantId, void* p1);
struct BackgroundGraphics;
extern "C" void* Background_GetScreen(struct BackgroundGraphics* list, unsigned int index);
extern "C" void func_020dc7e8(int a, int b);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
extern "C" void func_ov005_021551d4(void* p);
extern "C" void func_ov005_021551fc(char* base, int byteVal, int cond);
typedef void (*Type_ov023_021e4c18)(char*, int, int);

struct Struct_ov023_021e4c18 {
    void* f0;
    char pad1[0xc8 - 0x4];
    void* fc8;
    char pad2[0xd4 - 0xcc];
    char unknown_d4_[1];
#if defined(jpn)
    char pad3[0x130 - 0xd5];
#else
    char pad3[0x134 - 0xd5];
#endif

    int unknown_134_;
    char pad4[0x4e5 - 0x138];
    signed char unknown_4e5_;
    char pad5[0x4e8 - 0x4e6];
    int f4e8;
    int unknown_4ec_[4];
    int unknown_4fc_;
#if defined(jpn)
    char pad6[0x56c - 0x4fc];
#else
    char pad6[0x634 - 0x500];
#endif

    unsigned short unknown_634_;
};

// USA: func_ov023_021e4c18
extern "C" ARM void func_ov023_021e4c18(struct Struct_ov023_021e4c18* obj) {
#if defined(jpn)
 enum {regionalOffset0=0xe80, regionalOffset1=0x3d44};
#else
 enum {regionalOffset0=0xe84, regionalOffset1=0x3dcc};
#endif
    unsigned short flags = obj->unknown_634_;
    if (flags & 0x40) return;
    if (!(flags & 0x80)) return;

    GameState* battleStruct = GameState::GetInstance();

    int index = -1;
    int i;
    for (i = 0; i < 4; i++) {
        if (obj->unknown_4fc_ == obj->unknown_4ec_[i]) {
            index = i;
            break;
        }
    }

    int five = 0;
    if (g_touchInput.pressed_ != 0) {
        if (func_ov023_021e29d0((char*)obj + 0xd4) == 0x21) five = 1;
    }
    if (!five) {
        if (g_keyManager.TestKeysPressed(0x800) != 0) five = 1;
    }
    if (!five) return;

    GameObject* combatant;
    for (;;) {
        index = index + five;
        if (index < 0) index = obj->f4e8 - 1;
        if (index > obj->f4e8 - 1) index = 0;
        combatant = battleStruct->GetGameObjectByIndex(obj->unknown_4ec_[index]);
        if (combatant != 0) break;
    }

    if (obj->unknown_4fc_ == obj->unknown_4ec_[index]) return;

    obj->unknown_634_ |= 0x400;

    if (obj->f0 != 0) {
        int rawId = obj->unknown_4ec_[index];
        signed char var7 = (signed char)rawId;
        struct BackgroundGraphics* list = (struct BackgroundGraphics*)((char*)obj->f0 + regionalOffset0);
        if (list != 0) {
            if (Background_GetScreen(list, 1) != 0) {
                func_020dc7e8(5, var7);
            }
        }
    }

#if defined(jpn)

#else
    func_ov023_021e2ce8(obj->unknown_4ec_[index], obj->fc8);
#endif

    combatant = battleStruct->GetGameObjectByIndex(obj->unknown_4ec_[index]);
    unsigned short var9 = combatant->obj3D_.unknown_0_;
    if ((var9 & 0x1000) || (var9 & 0x800) || (var9 & 0x200)) {
        if (obj->unknown_134_ > 0) return;

        obj->unknown_4fc_ = obj->unknown_4ec_[index];
        obj->unknown_634_ = obj->unknown_634_ | 0x54;

        SePlayer_Play(&g_sePlayer, 1, 0);

        if (obj->unknown_4e5_ != 3) return;
        if (obj->f0 == 0) return;

        func_ov005_021551d4(obj->f0);
        *(int*)((char*)obj->f0 + regionalOffset1) |= 0x200;
        ((Type_ov023_021e4c18)(void*)&func_ov005_021551fc)((char*)obj->f0, obj->unknown_4fc_, 1);
    }
}
