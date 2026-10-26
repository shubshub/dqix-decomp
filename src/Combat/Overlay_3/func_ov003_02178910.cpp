#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Input/Input.h"


#if defined(jpn)
enum { kRegionSelfShift = 0x84, Enum_ov003_02178910_54 = 0x2a };
#else
enum { kRegionSelfShift = 0, Enum_ov003_02178910_54 = 0x36 };
#endif

struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
struct GameState;
extern "C" void* GameState_GetParty(GameState*);

struct Struct_0207fdcc_2;
struct Struct_0207fdf0_2;
struct SePlayer;
struct Struct_02081f20_2;
struct ItemTable;
struct Element020de650 { char pad[8]; unsigned int nibble : 4; };
struct Struct_ov003_02178910;
struct KeyMap020a0b3c { short* keys; signed char* values; short count; };

extern "C" unsigned char* func_02053c6c(unsigned char* combatant);
extern "C" int GameState_GetProtagonistIndex(GameState*);

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_02081ea4(struct Struct_0207fdcc_2* obj, int id, int value);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_0207fdf0(struct Struct_0207fdf0_2* obj, int key);
extern "C" signed char func_020a0b3c(struct KeyMap020a0b3c* map, int key);
extern "C" unsigned int func_ov003_02175898(char* obj, void* s);
extern "C" int func_ov003_021758cc(char* self, int cap);
extern "C" void func_ov003_02175924(char* self);
extern "C" int func_020de194(void* obj);
extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void Scenario_SetFlag(void* a, unsigned char* b, int c, int d);
extern "C" void ItemTable_Construct(void* obj);
extern "C" void func_0207cbe8(char* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

extern "C" void func_ov003_02178548(void* self);
extern "C" void func_ov003_021767ec(void* self);
extern "C" void func_ov003_021769ec(void* self);
extern "C" void func_ov003_02176ed4(void* self);
extern "C" void func_ov003_02176f94(void* self);
extern "C" void func_ov003_021748c4(unsigned char* self);
extern "C" void func_ov003_021785d4(unsigned char* obj);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910* obj, int val);
extern "C" void func_ov023_021ddf5c(void* obj);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern "C" ARM int func_ov003_021764f4(unsigned char* self);
extern "C" int func_ov003_021784bc(void* self, int key, unsigned int kind, int d);
extern "C" void func_ov003_02176468(unsigned char* self);
extern "C" void func_ov003_02177208(char* obj);
extern "C" void func_ov003_0217726c(char* obj);
extern "C" void func_ov003_02177300(char* self);
extern "C" void func_ov003_02177410(void* self);
extern "C" void func_ov003_02177550(void* self);
extern "C" void func_ov003_02177820(char* self);
extern "C" int func_ov003_02178218(void* unused);
extern "C" int func_ov003_021782a0(struct Struct_0207fdcc_2* obj);
extern "C" void func_ov003_02175cb0(char* base, int flag);
extern "C" void func_ov003_0217599c(void* self);
extern "C" int func_020dd4c4(int val, void* elem);
extern "C" int func_ov003_0217839c(int val, void* elem);
extern "C" void* func_ov003_02179cfc(char* base, int combatantId, void* arg2);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_02081f20(void* obj, int scaleCount);
extern "C" void func_0207ccf0(void* ctx, int key, int cap, int arg3, int a5, int a6, int a7);

extern struct SePlayer g_sePlayer;

static inline void inline_ov003_02178910(unsigned char* self, signed char v) {
    *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = v;
    func_ov023_021ddf5c(self + 0x3c);
}

static inline int inline_ov003_02178910_2(struct Element020de650* e) { return e->nibble <= 7; }

// USA: func_ov003_02178910
extern "C" ARM void func_ov003_02178910(unsigned char* self) {
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    void* battleSum = GameState_GetParty((GameState*)battle);
    struct Struct_0207fdcc_2* var2 = *(struct Struct_0207fdcc_2**)(self + (0x89c - kRegionSelfShift));
    int state = *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift));

    if (state == 0) {
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 1) {
        *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 3;
        if (*(short*)(self + (0x1000 + 6 - kRegionSelfShift)) < 0) {
            short id = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
            *(short*)(self + (0x1000 + 6 - kRegionSelfShift)) = id;
        }
        *(short*)((char*)var2 + Enum_ov003_02178910_54) = *(short*)(self + (0x1000 + 6 - kRegionSelfShift));
        func_02080c68(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        func_02081ea4(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        func_ov003_02178548(self);
        func_ov003_021767ec(self);
        func_ov003_021769ec(self);
        func_ov003_02176ed4(self);
        func_ov003_02176f94(self);
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        func_ov003_021748c4(self);
        if (*(unsigned char*)(self + (0x1000 + 0x4d - kRegionSelfShift)) != 0) {
            signed char var5 = -1;
            inline_ov003_02178910(self, var5);
            *(unsigned char*)(self + (0x1000 + 0x4d - kRegionSelfShift)) = 0;
        }
        return;
    }

    if (state == 2) {
        short key = *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 6 - kRegionSelfShift);
        func_ov003_021785d4(self);
        signed char var7 = -1;
        *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = var7;
        func_ov023_021dcae0((struct Struct_ov003_02178910*)(self + 0x3c), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        int r = func_ov003_021765b4(self);
        if (r != 0 && key == *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift))) {
            *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) = 1;
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(self + (0x874 - kRegionSelfShift)), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            *(void**)(self + 8) = elem;
            if (elem == 0) return;
            int kind = elem->nibble;
            int ok = func_ov003_021784bc(battleSum, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), kind, *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)));
            if (ok == 0) {
                func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1b;
                *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(short*)(self + (0x1000 + 0 - kRegionSelfShift)) = -1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            int var12 = func_ov003_021758cc((char*)self, *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)));
            if (var12 != 0) {
                struct Element020de650* var13 = *(struct Element020de650**)(self + 8);
                unsigned short mult = *(unsigned short*)(self + (0x800 + 0x6c - kRegionSelfShift));
                int var15 = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
                int val = func_020de194(var13);
                int var17 = mult * val;
                void* battleSum2 = GameState_GetParty((GameState*)(BattleStruct*)GameState::GetInstance());
                int var19 = var13->nibble;
                int var20 = func_ov003_021784bc(battleSum2, *(short*)((char*)var13 + 0x18), var19, var15);
                int result;
                if (var20 == 1) {
                    result = 1;
                } else {
                    unsigned int q = _u32_div_f((unsigned int)var17, 100);
                    unsigned int var23 = *(unsigned int*)((char*)battleSum2 + 0xf6c);
                    result = (var23 < (q << 1)) ? 1 : 0;
                }
                if (result != 0) {
                    func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 2;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 5;
                    return;
                }
                func_02080c68(var2, 3, 1);
                func_02080c68(var2, 4, 1);
                func_02080c68(var2, 5, 1);
                func_02080c68(var2, 6, 1);
                func_02080c68(var2, 7, 1);
                func_02080c68(var2, 8, 1);
                func_02080c68(var2, 0x19, 1);
                func_02080c68(var2, 0x1a, 1);
                func_02080c68(var2, 0x1b, 1);
                func_02080c68(var2, 0x1c, 1);
                *(short*)(self + (0xf00 + 0xfc - kRegionSelfShift)) = *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift));
                (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
                return;
            }
            func_0207fdcc(var2, 3);
            func_0207fdcc(var2, 4);
            func_0207fdcc(var2, 5);
            func_0207fdcc(var2, 6);
            func_0207fdcc(var2, 7);
            func_0207fdcc(var2, 8);
            func_0207fdcc(var2, 0x19);
            func_0207fdcc(var2, 0x1a);
            func_0207fdcc(var2, 0x1b);
            func_0207fdcc(var2, 0x1c);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 7;
            *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 1;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
            return;
        }
        int var24 = func_ov003_021766e8(self);
        if (var24 == 0) return;
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0xa;
        *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 1;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
        func_0207fdcc(var2, 3);
        func_0207fdcc(var2, 4);
        func_0207fdcc(var2, 5);
        func_0207fdcc(var2, 6);
        func_0207fdcc(var2, 7);
        func_0207fdcc(var2, 8);
        func_0207fdcc(var2, 0x19);
        func_0207fdcc(var2, 0x1a);
        func_0207fdcc(var2, 0x1b);
        func_0207fdcc(var2, 0x1c);
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
        return;
    }

    if (state == 3) {
        func_ov003_02177208((char*)self);
        func_ov003_0217726c((char*)self);
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift)) = 0;
        return;
    }

    if (state == 4) {
        unsigned char counter = *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift));
        int delta = 0;
        if (counter < 5) {
            *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift)) = counter + 1;
        } else {
            delta = func_ov003_02178218(self);
            if (delta != 0) {
                *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift)) = 0;
            }
        }

        struct BattleStruct* b2 = (BattleStruct*)GameState::GetInstance();
        int scaleCount = ((GameState*)b2)->GetTickCount();
        int ratio = func_02081f20(self + (0x8c + 0x800 - kRegionSelfShift), scaleCount);
        if ((unsigned short)(ratio + 0xffff) <= 1) {
            void* var30 = *(void**)(self + (0x88c - kRegionSelfShift));
            int v = (var30 != 0) ? *(unsigned short*)var30 : 0;
            if (v == 0x40) delta = 1;
            else if (v == 0x80) delta = -1;
            else if (v == 0x20) delta = 0x83;
            else if (v == 0x10) delta = ~0x82;
        }

        if (delta != 0) {
            int var32 = *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) + delta;
            int var33 = func_ov003_02175898((char*)self, *(void**)(self + 8));
            unsigned int var34 = (var33 == 0) ? 1 : var33;
            int q = _u32_div_f(*(unsigned int*)((char*)battleSum + 0xf6c), var34);
            struct Element020de650* elem = *(struct Element020de650**)(self + 8);
            int kind = 0xa;
            if (elem != 0) kind = elem->nibble;
            int var38 = func_ov003_021784bc(battleSum, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), kind, *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)));
            if (q < var38) var38 = q;
            if (var38 < var32) var32 = var38;
            if (var32 <= 1) var32 = 1;
            *(unsigned char*)(self + (0x1000 + 0x4b - kRegionSelfShift)) = (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) < var32) ? 1 : 0;
            *(unsigned char*)(self + (0x1000 + 0x4c - kRegionSelfShift)) = (var32 < *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift))) ? 1 : 0;
            *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) = var32;
            func_ov003_02177208((char*)self);
            func_ov003_0217726c((char*)self);
        }

        int var39 = func_ov003_021782a0((struct Struct_0207fdcc_2*)self);
        int var40 = g_keyManager.TestKeysPressed(0x401);
        if (var40 != 0 || var39 == 1) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1f;
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) == 1) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 2;
            }
            (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
            func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
            return;
        }

        int var41 = g_keyManager.TestKeysPressed(2);
        if (var41 != 0 || var39 == -1) {
            func_0207fdcc(var2, 9);
            func_0207fdcc(var2, 0xa);
            func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        }
        return;
    }

    if (state == 5) {
        func_ov003_02176468(self);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 6) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;

            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x1000;
            func_ov003_02175924((char*)self);
            func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
            struct Element020de650* elem = *(struct Element020de650**)(self + 8);
            if (inline_ov003_02178910_2(elem)) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 3;
                (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
                if (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)) != 1) return;

                int val = GameState_GetProtagonistIndex((GameState*)battle);
                *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = val;
                int check = func_020dd4c4(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                if (check == 0) return;

                func_ov003_02175cb0((char*)self, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }

            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x15;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0xb;
            short var46 = *(short*)(self + (0x1000 + 0x34 - kRegionSelfShift));
        short key = *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift));
        if (var46 == 0x20 && key == 0x55f0) {
                void* base = Scenario_GetInstance();
                Scenario_SetFlag(base, (unsigned char*)base + 0x8c, 0x1139, 1);
            }
            return;
        }

        func_0207fdcc(var2, 9);
        func_0207fdcc(var2, 0xa);
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2f;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        return;
    }

    if (state == 7) {
        func_ov003_02176468(self);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 8) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;

            if (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)) == 1) {
                int val = GameState_GetProtagonistIndex((GameState*)battle);
                *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = val;
                void* elem2 = func_ov003_02179cfc((char*)self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                int var52 = (*(unsigned int*)((char*)elem2 + 8) << 0xd) >> 0x1f;
                if (var52 != 0) {
                    func_ov003_02175cb0((char*)self, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1e;
                    *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 9;
                } else {
                    int var53 = func_ov003_0217839c(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                    if (var53 != 0) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2e;
                        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0x32;
                        return;
                    }
                    func_ov003_0217599c(self);
                    func_ov003_02175cb0((char*)self, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
                    *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                }
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }

            MessageSystem_Reset((char*)MessageSystem_GetInstance());
            (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
            return;
        }

        func_ov003_02175cb0((char*)self, 0);
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        if (*(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) & 0x1000) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x23;
        }
        return;
    }

    if (state == 9) {
        int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
        switch (field) {
        case 2:
            *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0xb;
            break;
        case 3:
            *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0xc;
            break;
        case 4:
            *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0xd;
            break;
        }

        short var55 = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        *(short*)(self + (0x1000 + 8 - kRegionSelfShift)) = var55;
        *(short*)((char*)var2 + Enum_ov003_02178910_54) = *(short*)(self + (0x1000 + 8 - kRegionSelfShift));
        short id2 = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        short diff = *(short*)(self + (0x1000 + 8 - kRegionSelfShift)) - id2;
        int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
        *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
        *(unsigned char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) = *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift));
        func_ov003_02177300((char*)self);
        func_ov003_02177410(self);
        func_ov003_02177550(self);
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        inline_ov003_02178910(self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)));
        *(unsigned char*)(self + (0x1000 + 0x4d - kRegionSelfShift)) = 1;
        return;
    }

    if (state == 0xa) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 8 - kRegionSelfShift);
        short var59 = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        short diff = *(short*)(self + (0x1000 + 8 - kRegionSelfShift)) - var59;
        int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
        *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;

        if (*(short*)(self + (0x1000 + 0 - kRegionSelfShift)) == *(short*)(*(void**)(self + (0xff8 - kRegionSelfShift))) &&
            *(signed char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) == *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift))) {
        } else {
            *(unsigned char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) = *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift));
            func_ov003_02177410(self);
            func_ov003_02177550(self);
            inline_ov003_02178910(self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)));
        }

        int ok = func_ov003_021765b4(self);
        if (ok != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
            int check = func_020dd4c4(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            if (check != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x19;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 9;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            void* elem2 = func_ov003_02179cfc((char*)self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            int var65 = (*(unsigned int*)((char*)elem2 + 8) << 0xd) >> 0x1f;
            if (var65 != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1e;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 9;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            int var66 = func_ov003_0217839c(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            if (var66 != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2e;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0x32;
                return;
            }
            func_ov003_0217599c(self);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 0x1d;
            unsigned char var67 = 7;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = var67;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x1000;
            *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = var67 - 8;
            func_ov023_021ddf5c(self + 0x3c);
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) != 0) return;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x1000;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            return;
        }

        int var68 = func_ov003_021766e8(self);
        if (var68 == 0) return;
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        func_ov003_02175cb0((char*)self, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        if (*(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) & 0x1000) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x23;
        }
        return;
    }

    if (state == 0xb) {
        int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
        switch (field) {
        case 1: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x11; break;
        case 2: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x12; break;
        case 3: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x13; break;
        case 4: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x14; break;
        default: break;
        }

        short id = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) = id;
        *(short*)((char*)var2 + Enum_ov003_02178910_54) = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift));
        func_02081ea4(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        func_02080c68(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        func_ov003_02177820((char*)self);
        short id2 = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        short diff = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) - id2;
        int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
        *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
        *(unsigned char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) = *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift));
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 0xc) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 0xa - kRegionSelfShift);
        int ok = func_ov003_021765b4(self);
        if (ok != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            short id = func_02080468(var2, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
            short diff = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) - id;
            int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
            *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
            func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);

            struct BattleStruct* battle2 = (BattleStruct*)GameState::GetInstance();
            struct CombatantStruct* combatant = (CombatantStruct*)((GameState*)battle2)->GetPartyMemberByIndex(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)));
            if (combatant != 0) {
                unsigned char* field150 = func_02053c6c((unsigned char*)combatant);
                if (field150 == 0) return;

                short j, count;
                for (count = 0, j = 0; j < 8; j++) {
                    if (*(short*)(field150 + 0x400 + j * 2 + 0x54) <= 0) break;
                    count++;
                }

                if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) <= (8 - count)) {
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x17;
                    *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                    int* var83 = *(int**)((char*)combatant + 0x130);
                    if (*var83 & 1) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2d;
                    }
                } else {
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x21;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                    *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                    void* ptr2a04 = GameState_GetParty((GameState*)battle2);
                    int var85 = func_020a0b3c((struct KeyMap020a0b3c*)ptr2a04, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
                    if (var85 == 0x63) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x22;
                    } else {
                        int found = 0;
                        short k;
                        for (k = 0; k < 8; k++) {
                            if (*(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)) == *(short*)(field150 + 0x400 + k * 2 + 0x54)) {
                                found = 1;
                                break;
                            }
                        }
                        if (found == 0) {
                            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x16;
                        }
                    }
                }

                unsigned char localCtx[0x38];
                ((SafeAllocator*)localCtx)->ResetAllocatorPointer();
                ItemTable_Construct(localCtx + 0x14);
                func_0207cbe8((char*)localCtx);
                func_0207cbe8((char*)localCtx);
                *(void**)(localCtx + 0x2c) = self + (0x874 - kRegionSelfShift);
                func_0207ccf0(localCtx, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)),
                    *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), 1, 1, 0);
                *(unsigned char*)(self + (0x1000 + 0x4f - kRegionSelfShift)) = 0;
                return;
            }

            func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x18;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            void* ptr2a04b = GameState_GetParty((GameState*)battle2);
            int var90 = func_020a0b3c((struct KeyMap020a0b3c*)ptr2a04b, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) > (0x63 - var90)) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x37;
            }
            func_ov003_02175cb0((char*)self, 1);
            return;
        }

        int var91 = func_ov003_021766e8(self);
        if (var91 == 0) return;
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        func_0208203c((struct Struct_02081f20_2*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x18;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        void* ptr2a04c = GameState_GetParty((GameState*)battle);
        int var93 = func_020a0b3c((struct KeyMap020a0b3c*)ptr2a04c, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) > (0x63 - var93)) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x37;
        }
        func_ov003_02175cb0((char*)self, 1);
        return;
    }

    if (state == 0x32) {
        func_ov003_02176468(self);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 0x33) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;

            int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
            if (field == 1) {
                func_ov003_0217599c(self);
                func_ov003_02175cb0((char*)self, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
                *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }

            func_ov003_0217599c(self);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 0x1d;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 7;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x1000;
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) != 0) return;

            *(unsigned char*)(self + (0x1000 + 0x4f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x1000;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            return;
        }

        int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
        if (field == 1) {
            func_ov003_02175cb0((char*)self, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            return;
        }
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        func_ov003_02175cb0((char*)self, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        if (*(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) & 0x1000) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x23;
        }
        return;
    }
}
