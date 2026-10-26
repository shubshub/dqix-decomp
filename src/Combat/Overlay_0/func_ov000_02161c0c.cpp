#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02161c0c_3;
struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct Struct_02048850;
struct Struct_02048850_2;
struct Bytes02033b88;

extern "C" GameObject* func_0200fea4(GameState* gameState, int combatantId);
extern "C" void func_ov000_02167c28(unsigned char* obj, int id);
extern "C" unsigned char* func_02070fd0(struct Struct_02070b6c_3* table, int key);
extern "C" struct Struct_02048850_2* func_0206f4f0(struct Struct_0206f01c_2* table, int key);
extern "C" void func_02048614(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
extern "C" void func_02048850(struct Struct_02048850* obj, struct Struct_02048850_2* param);
extern "C" void func_02048588(unsigned char* dst, unsigned char* src);
extern "C" void GameObject_ForceMotionState(struct Bytes02033b88* obj, int v);
extern "C" void func_ov000_02161dfc(unsigned char* dst, unsigned char* src);
extern "C" void func_020488ec(char* obj);
extern "C" void func_ov000_02161274(GameObject* obj);
extern "C" void func_ov000_02166784(struct Struct_ov000_02161c0c_3* arg0, unsigned char* obj2, unsigned char* arg2);
extern "C" void func_0200fd48(GameState* gameState, int id);

struct Struct_ov000_02161c0c {
    char pad0[2];
    short key;
};

struct Struct_ov000_02161c0c_2 {
    char pad0[0x11];
    signed char ids[8];
    unsigned char count;
};

#if defined(jpn)
enum { Enum_ov000_02161c0c_672 = 0x21c, Enum_ov000_02161c0c_3768 = 0xe34, Enum_ov000_02161c0c_3784 = 0xe44, Enum_ov000_02161c0c_668 = 0x218 };
#else
enum { Enum_ov000_02161c0c_672 = 0x2a0, Enum_ov000_02161c0c_3768 = 0xeb8, Enum_ov000_02161c0c_3784 = 0xec8, Enum_ov000_02161c0c_668 = 0x29c };
#endif

// USA: func_ov000_02161c0c
extern "C" ARM void func_ov000_02161c0c(unsigned char* obj, int id) {
    GameState* gs = GameState::GetInstance();
    unsigned char* c = (unsigned char*)func_0200fea4(gs, id);
    unsigned char* data = *(unsigned char**)(obj + Enum_ov000_02161c0c_672);
    struct Struct_02070b6c_3* entries = (struct Struct_02070b6c_3*)(data + 0x684);
    struct Struct_0206f01c_2* var4 = (struct Struct_0206f01c_2*)(data + 0x678);
    struct Struct_ov000_02161c0c* found = 0;
    unsigned short key = *(unsigned short*)(c + 0x186);
    for (int i = 0; i < 4; i++) {
        struct Struct_ov000_02161c0c* node = *(struct Struct_ov000_02161c0c**)(obj + i * 4 + Enum_ov000_02161c0c_3768);
        if (node == 0) continue;
        if (key == node->key) {
            found = node;
            break;
        }
    }
    if (found == 0) return;

    func_ov000_02167c28(obj, id);
    unsigned short kind = *(unsigned short*)(c + 0x186);
    unsigned char slot = c[0x18c];
    unsigned char mode = c[0x18d];
    int param = *(int*)(c + 0x13c);
    unsigned char* entry = func_02070fd0(entries, kind);
    struct Struct_02048850_2* info = func_0206f4f0(var4, (short)kind);
    unsigned char* var15 = *(unsigned char**)(obj + Enum_ov000_02161c0c_672) + 0x158 + (id - 0xc0) * 0xa4;

    func_02048614(c);
    *(short*)(c + 4) = id;
    func_02049c88(c, param);
    *(unsigned char**)(c + 0x148) = entry;
    func_02048850((struct Struct_02048850*)c, info);
    func_02048588((unsigned char*)found, c);
    ((Object3D*)c)->SetField06(*(unsigned short*)(obj + Enum_ov000_02161c0c_3784));
    c[0x17c] = slot;
    GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
    *(unsigned char**)(c + 0x138) = var15;
    func_ov000_02161dfc(var15, entry + 0x6c);
    (*(unsigned char**)(c + 0x138))[0x25] = mode;
    func_020488ec((char*)c);
    c[0xc2] |= 0x20;
    c[0x18d] = mode;
    if (mode == 2) {
        func_ov000_02161274((GameObject*)c);
    }
    func_ov000_02166784((struct Struct_ov000_02161c0c_3*)obj, (unsigned char*)found, c);

    int group = slot;
    obj = *(unsigned char**)(obj + Enum_ov000_02161c0c_668) + 0x81b0;
    for (id = 0; id < ((struct Struct_ov000_02161c0c_2*)(obj + group * 0x18))->count; id++) {
        func_0200fd48(gs, (short)(((struct Struct_ov000_02161c0c_2*)(obj + group * 0x18))->ids[id] + 0xc0));
    }
    memset(obj + 0x11 + slot * 0x18, 0, 8);
    (obj + slot * 0x18)[0x19] = 0;
}
