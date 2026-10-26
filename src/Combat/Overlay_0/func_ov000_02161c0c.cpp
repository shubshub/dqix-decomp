#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02161c0c_3;
struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct Struct_02048850;
struct Struct_02048850_2;
struct Struct_02010604;

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gameState, int combatantId);
void FindOrAssignSlot02167c28(unsigned char* obj, int id);
unsigned char* SearchWithLow15Comparator02070fd0(struct Container02070e60* table, int key);
struct Param02048850* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* table, int key);
void ResetNameState02048614(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
void SetupFieldsFromParam02048850(struct Obj02048850* obj, struct Param02048850* param);
void CopyObjectFields02048588(unsigned char* dst, unsigned char* src);
void GameObject_ForceMotionState(struct Bytes02033b88* obj, int v);
void CopyBlob_02161dfc(unsigned char* dst, unsigned char* src);
void BuildName020488ec(char* obj);
void SyncNameFlag_02161274(GameObject* obj);
void AllocateSlotAndConfigureField02166784(struct Struct5e00* obj1, unsigned char* obj2, unsigned char* obj3);
void ClearCombatantSlot_0200fd48(GameState* gameState, int id);

struct Struct_ov000_02161c0c {
    char unknown_0_[2];
    short unknown_2_;
};

struct Struct_ov000_02161c0c_2 {
    char unknown_0_[0x11];
    signed char unknown_11_[8];
    unsigned char unknown_19_;
};

#if defined(jpn)
enum { Enum_ov000_02161c0c_672 = 0x21c, Enum_ov000_02161c0c_3768 = 0xe34, Enum_ov000_02161c0c_3784 = 0xe44, Enum_ov000_02161c0c_668 = 0x218 };
#else
enum { Enum_ov000_02161c0c_672 = 0x2a0, Enum_ov000_02161c0c_3768 = 0xeb8, Enum_ov000_02161c0c_3784 = 0xec8, Enum_ov000_02161c0c_668 = 0x29c };
#endif

// USA: func_ov000_02161c0c
extern "C" ARM void func_ov000_02161c0c(unsigned char* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    unsigned char* var1 = (unsigned char*)func_0200fea4(var0, arg1);
    unsigned char* var2 = *(unsigned char**)(arg0 + Enum_ov000_02161c0c_672);
    struct Struct_02070b6c_3* var3 = (struct Struct_02070b6c_3*)(var2 + 0x684);
    struct Struct_0206f01c_2* var4 = (struct Struct_0206f01c_2*)(var2 + 0x678);
    struct Struct_ov000_02161c0c* var5 = 0;
    unsigned short var6 = *(unsigned short*)(var1 + 0x186);
    for (int var7 = 0; var7 < 4; var7++) {
        struct Struct_ov000_02161c0c* var8 = *(struct Struct_ov000_02161c0c**)(arg0 + var7 * 4 + Enum_ov000_02161c0c_3768);
        if (var8 == 0) continue;
        if (var6 == var8->unknown_2_) {
            var5 = var8;
            break;
        }
    }
    if (var5 == 0) return;

    func_ov000_02167c28(arg0, arg1);
    unsigned short var9 = *(unsigned short*)(var1 + 0x186);
    unsigned char var10 = var1[0x18c];
    unsigned char var11 = var1[0x18d];
    int var12 = *(int*)(var1 + 0x13c);
    unsigned char* var13 = func_02070fd0(var3, var9);
    struct Struct_02048850_2* var14 = func_0206f4f0(var4, (short)var9);
    unsigned char* var15 = *(unsigned char**)(arg0 + Enum_ov000_02161c0c_672) + 0x158 + (arg1 - 0xc0) * 0xa4;

    ResetNameState02048614(c);
    *(short*)(c + 4) = id;
    func_02049c88(c, param);
    *(unsigned char**)(c + 0x148) = entry;
    SetupFieldsFromParam02048850((struct Obj02048850*)c, info);
    CopyObjectFields02048588((unsigned char*)found, c);
    ((Object3D*)c)->SetField06(*(unsigned short*)(obj + kField06));
    c[0x17c] = slot;
    GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
    *(unsigned char**)(c + 0x138) = blob;
    CopyBlob_02161dfc(blob, entry + 0x6c);
    (*(unsigned char**)(c + 0x138))[0x25] = mode;
    BuildName020488ec((char*)c);
    c[0xc2] |= 0x20;
    c[0x18d] = mode;
    if (mode == 2) {
        SyncNameFlag_02161274((GameObject*)c);
    }
    func_ov000_02166784((struct Struct_ov000_02161c0c_3*)arg0, (unsigned char*)var5, var1);

    int var16 = var10;
    arg0 = *(unsigned char**)(arg0 + Enum_ov000_02161c0c_668) + 0x81b0;
    for (arg1 = 0; arg1 < ((struct Struct_ov000_02161c0c_2*)(arg0 + var16 * 0x18))->unknown_19_; arg1++) {
        func_0200fd48(var0, (short)(((struct Struct_ov000_02161c0c_2*)(arg0 + var16 * 0x18))->unknown_11_[arg1] + 0xc0));
    }
    memset(arg0 + 0x11 + var10 * 0x18, 0, 8);
    (arg0 + var10 * 0x18)[0x19] = 0;
}
