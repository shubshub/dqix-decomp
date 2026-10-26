#include <globaldefs.h>
#include "Resource/ItemTable.h"
#if defined(jpn)
enum { kRegion89c = 0x818 };
enum { kRegion874 = 0x7f0 };
enum { Enum_ov003_021769ec_4096 = 0xf7c };
#else
enum { kRegion89c = 0x89c };
enum { kRegion874 = 0x874 };
enum { Enum_ov003_021769ec_4096 = 0x1000 };
#endif
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* gameState);
struct Struct_0207fdcc_2;
extern "C" void func_02080c20(Struct_0207fdcc_2*, int);
extern "C" void func_02080c04(struct Struct_0207fdcc_2* obj, short key);
extern "C" void func_02080c68(void*, int, int);
extern "C" void func_02080b54(void*, int);
struct Node021769ec;
extern "C" struct Node021769ec* ItemTable_Find(struct ItemTable* c, int key);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
extern "C" int func_02080b40(void* obj, int id);
extern "C" void func_0208103c(void* obj, int id, int value);
struct Struct_02052df8;
extern "C" short func_02052df8(Struct_02052df8* obj, int index);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
struct Struct_02080fc4;
extern "C" void func_02080fc4(struct Struct_02080fc4* obj, int id, int value);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" int func_020dcc98(int combatantId);
extern "C" int func_ov003_021753a0(void* obj, int id, void* a, void* b);
extern "C" int func_020813ec(void* obj, short key);

extern int data_ov003_0217fb18[];

struct Node021769ec {
    char pad0[8];
    unsigned int kind : 4;
    unsigned int pad8 : 28;
    unsigned int lo : 7;
    unsigned int unknown_c_7_ : 4;
    unsigned int hi : 21;
    char pad10[0x18 - 0x10];
    short count;
};

struct Struct_ov003_021769ec_2 {
    char pad0[0x1c];
    int ids[5];
    unsigned int memberCount;
    char unknown_34_[0x3a - 0x34];
    short key;
};

struct Struct_ov003_021769ec_3 {
    char pad0[kRegion874];
    struct ItemTable list;
    char padAfterList[kRegion89c - kRegion874 - sizeof(ItemTable)];
    struct Struct_0207fdcc_2* unknown_89c_;
    char unknown_8a0_[Enum_ov003_021769ec_4096 - kRegion89c - 4];
    Struct_ov003_021769ec_2 party;
};

static inline int inline_ov003_021769ec(Node021769ec* n) { return n->kind <= 7; }

// USA: func_ov003_021769ec
extern "C" ARM void func_ov003_021769ec(Struct_ov003_021769ec_3* self) {
    short group;
    short var1 = 0x1c;
    group = 4;
    short var2 = 0x1d;
    short id2 = 0x1e;
    short var4 = 0x1f;
    short var5 = 0x20;
    short var6 = 0x21;
    short var7 = 0x145;
    short var8 = 0x146;
    struct Struct_0207fdcc_2* var9 = self->unknown_89c_;
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);
    unsigned char count = self->party.memberCount;

    switch (count) {
    case 2:
        group = 5;
        var1 = 0x22;
        var2 = 0x24;
        id2 = 0x26;
        var4 = 0x28;
        var5 = 0x2a;
        var6 = 0x2c;
        var7 = 0x147;
        var8 = 0x149;
        break;
    case 3:
        group = 6;
        var1 = 0x2d;
        var2 = 0x30;
        id2 = 0x33;
        var4 = 0x36;
        var5 = 0x39;
        var6 = 0x3c;
        var7 = 0x14b;
        var8 = 0x14e;
        break;
    case 4:
        group = 7;
        var1 = 0x3d;
        var2 = 0x41;
        id2 = 0x45;
        var4 = 0x49;
        var5 = 0x4d;
        var6 = 0x51;
        var7 = 0x151;
        var8 = 0x155;
        break;
    }

    func_02080c20(var9, group);
    func_02080c68(var9, group, 0);
    func_02080b54(var9, group);

    Node021769ec* node = ItemTable_Find(&self->list, self->party.key);
    bool var13 = false;
    if (node != NULL) {
        var13 = inline_ov003_021769ec(node);
    }
    if (var13) {
        for (unsigned char i = 0; i < count; i++) {
            int var15 = func_020dd4c4((signed char)self->party.ids[i], node);
            int id = (signed char)self->party.ids[i];
            int value = 0;
            GameObject* member = battle->GetPartyMemberByIndex(id);
            if (member != NULL) {
                value = *(int*)((char*)member + 0x134);
            }
            func_02080f8c((struct Container02080f8c*)var9, var1, value);
            func_02080cc0((struct Struct_02080cc0*)var9, var1, func_020dcc98(id));
            func_02080b40(var9, var1);

            if (var15 != 0) {
                func_02080cc0((struct Struct_02080cc0*)var9, var5, 3);
                func_0208103c(var9, var5, 0xb);
                func_02080b40(var9, var5);
            } else {
                func_02080cc0((struct Struct_02080cc0*)var9, var5, 0xf);
                int index = data_ov003_0217fb18[node->kind];
                if (index < 0) {
                    return;
                }
                short var20 = func_02052df8((Struct_02052df8*)member, index);
                if (var20 == node->count) {
                    func_0208103c(var9, var5, 0x22);
                    func_02080b40(var9, var5);
                } else {
                    unsigned short cur;
                    unsigned short max;
                    if (func_ov003_021753a0(self, id, &cur, &max) != 0) {
                        int nibble = 0xf;
                        if (cur < max) {
                            nibble = 5;
                        }
                        if (cur > max) {
                            nibble = 9;
                        }
                        func_02080cc0((struct Struct_02080cc0*)var9, id2, nibble);
                        func_02080fa8((struct Struct_02080fa8*)var9, var2, cur);
                        func_02080fa8((struct Struct_02080fa8*)var9, id2, max);
                        func_02080b40(var9, var2);
                        func_02080b40(var9, id2);
                        func_02080b40(var9, var4);
                    } else {
                        float var24;
                        float var25;
                        func_ov003_021753a0(self, id, &var24, &var25);
                        int nibble = 0xf;
                        if (var24 < var25) {
                            nibble = 5;
                        }
                        if (var24 > var25) {
                            nibble = 9;
                        }
                        func_02080cc0((struct Struct_02080cc0*)var9, var8, nibble);
                        func_02080fc4((struct Struct_02080fc4*)var9, var7, *(int*)&var24);
                        func_02080fc4((struct Struct_02080fc4*)var9, var8, *(int*)&var25);
                        func_02080b40(var9, var7);
                        func_02080b40(var9, var8);
                        func_02080b40(var9, var4);
                    }
                }
            }
            var1++;
            var2++;
            id2++;
            var4++;
            var5++;
            var7++;
            var8++;
        }

        if (node->unknown_c_7_ != 0) {
            func_02080b40(var9, var6);
            func_0208103c(var9, var6, (short)(node->unknown_c_7_ + 0x2f));
        }
    } else {
        func_02080c04(var9, group);
    }

    func_020813ec(var9, group);
}
