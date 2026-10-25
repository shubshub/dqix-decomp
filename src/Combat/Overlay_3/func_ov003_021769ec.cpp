#include <globaldefs.h>
#include "Resource/ItemTable.h"
#if defined(jpn)
enum { Enum_ov003_021769ec_2204 = 0x818 };
enum { Enum_ov003_021769ec_2164 = 0x7f0 };
enum { Enum_ov003_021769ec_4096 = 0xf7c };
#else
enum { Enum_ov003_021769ec_2204 = 0x89c };
enum { Enum_ov003_021769ec_2164 = 0x874 };
enum { Enum_ov003_021769ec_4096 = 0x1000 };
#endif
#include "GameState/GameState.h"

void* GameState_GetParty(GameState* gameState);
struct Obj2081;
void ClearElementFlag0x20_02080c20(Obj2081*, int);
extern "C" void _Z27SetElementFlag0x20_02080c04P7Obj2081i(struct Obj2081* obj, short key);
void SetEntryLowNibbleAndElement02080c68(void*, int, int);
void SetSublistEntriesFlag1_02080b54(void*, int);
struct Node021769ec;
struct Node021769ec* ItemTable_Find(struct ItemTable* c, int key);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryHalfword0xe_0208103c(void* obj, int id, int value);
struct Field150Holder02052df8;
short GetHalfwordEntryFromField150(Field150Holder02052df8* obj, int index);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);
struct Container02080fc4;
void SetEntryFirstField02080fc4(struct Container02080fc4* obj, int id, int value);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" int func_020dcc98(int combatantId);
extern "C" int func_ov003_021753a0(void* obj, int id, void* a, void* b);
extern "C" int func_020813ec(void* obj, short key);

extern int data_ov003_0217fb18[];

struct Struct_ov003_021769ec {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned int unknown_c_0_ : 7;
    unsigned int unknown_c_7_ : 4;
    unsigned int unknown_d_3_ : 21;
    char unknown_10_[0x18 - 0x10];
    short unknown_18_;
};

struct Struct_ov003_021769ec_2 {
    char unknown_0_[0x1c];
    int unknown_1c_[5];
    unsigned int unknown_30_;
    char unknown_34_[0x3a - 0x34];
    short unknown_3a_;
};

struct Menu021769ec {
    char pad0[kRegion874];
    struct ItemTable list;
    char padAfterList[kRegion89c - kRegion874 - sizeof(ItemTable)];
    struct Obj2081* elemObj;
    char pad8a0[kRegion1000 - kRegion89c - 4];
    Party021769ec party;
};

static inline int inline_ov003_021769ec(Struct_ov003_021769ec* arg0) { return arg0->unknown_8_0_ <= 7; }

// USA: func_ov003_021769ec
extern "C" ARM void func_ov003_021769ec(Menu021769ec* self) {
    short group;
    short id0 = 0x1c;
    group = 4;
    short id1 = 0x1d;
    short id2 = 0x1e;
    short id3 = 0x1f;
    short id4 = 0x20;
    short id5 = 0x21;
    short id6 = 0x145;
    short id7 = 0x146;
    struct Obj2081* elemObj = self->elemObj;
    GameState* battle = GameState::GetInstance();
    GameState_GetParty(battle);
    unsigned char count = self->party.memberCount;

    switch (var11) {
    case 2:
        var0 = 5;
        var1 = 0x22;
        var2 = 0x24;
        var3 = 0x26;
        var4 = 0x28;
        var5 = 0x2a;
        var6 = 0x2c;
        var7 = 0x147;
        var8 = 0x149;
        break;
    case 3:
        var0 = 6;
        var1 = 0x2d;
        var2 = 0x30;
        var3 = 0x33;
        var4 = 0x36;
        var5 = 0x39;
        var6 = 0x3c;
        var7 = 0x14b;
        var8 = 0x14e;
        break;
    case 4:
        var0 = 7;
        var1 = 0x3d;
        var2 = 0x41;
        var3 = 0x45;
        var4 = 0x49;
        var5 = 0x4d;
        var6 = 0x51;
        var7 = 0x151;
        var8 = 0x155;
        break;
    }

    func_02080c20(var9, var0);
    func_02080c68(var9, var0, 0);
    func_02080b54(var9, var0);

    Node021769ec* node = ItemTable_Find(&self->list, self->party.key);
    bool valid = false;
    if (node != NULL) {
        valid = IsKindValid(node);
    }
    if (var13) {
        for (unsigned char var14 = 0; var14 < var11; var14++) {
            int var15 = func_020dd4c4((signed char)arg0->unknown_1000_.unknown_1c_[var14], var12);
            int var16 = (signed char)arg0->unknown_1000_.unknown_1c_[var14];
            int var17 = 0;
            GameObject* var18 = var10->GetPartyMemberByIndex(var16);
            if (var18 != NULL) {
                var17 = *(int*)((char*)var18 + 0x134);
            }
            func_02080f8c((struct Struct_02080f8c*)var9, var1, var17);
            func_02080cc0((struct Struct_02080cc0*)var9, var1, func_020dcc98(var16));
            func_02080b40(var9, var1);

            if (var15 != 0) {
                func_02080cc0((struct Struct_02080cc0*)var9, var5, 3);
                func_0208103c(var9, var5, 0xb);
                func_02080b40(var9, var5);
            } else {
                func_02080cc0((struct Struct_02080cc0*)var9, var5, 0xf);
                int var19 = data_ov003_0217fb18[var12->unknown_8_0_];
                if (var19 < 0) {
                    return;
                }
                short var20 = func_02052df8((Struct_02052df8*)var18, var19);
                if (var20 == var12->unknown_18_) {
                    func_0208103c(var9, var5, 0x22);
                    func_02080b40(var9, var5);
                } else {
                    unsigned short var21;
                    unsigned short var22;
                    if (func_ov003_021753a0(arg0, var16, &var21, &var22) != 0) {
                        int var23 = 0xf;
                        if (var21 < var22) {
                            var23 = 5;
                        }
                        if (var21 > var22) {
                            var23 = 9;
                        }
                        func_02080cc0((struct Struct_02080cc0*)var9, var3, var23);
                        func_02080fa8((struct Struct_02080fa8*)var9, var2, var21);
                        func_02080fa8((struct Struct_02080fa8*)var9, var3, var22);
                        func_02080b40(var9, var2);
                        func_02080b40(var9, var3);
                        func_02080b40(var9, var4);
                    } else {
                        float var24;
                        float var25;
                        func_ov003_021753a0(arg0, var16, &var24, &var25);
                        int var26 = 0xf;
                        if (var24 < var25) {
                            var26 = 5;
                        }
                        if (var24 > var25) {
                            var26 = 9;
                        }
                        func_02080cc0((struct Struct_02080cc0*)var9, var8, var26);
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
            var3++;
            var4++;
            var5++;
            var7++;
            var8++;
        }

        if (var12->unknown_c_7_ != 0) {
            func_02080b40(var9, var6);
            func_0208103c(var9, var6, (short)(var12->unknown_c_7_ + 0x2f));
        }
    } else {
        func_02080c04(var9, var0);
    }

    func_020813ec(var9, var0);
}
