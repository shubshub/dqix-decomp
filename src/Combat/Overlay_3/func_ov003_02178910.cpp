#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Input/Input.h"


#if defined(jpn)
enum { kRegionSelfShift = 0x84, kRegionElementCursor = 0x2a };
#else
enum { Enum_ov003_02178910_0 = 0, Enum_ov003_02178910_54 = 0x36 };
#endif

struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
};
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};
struct GameState;
void* GameState_GetParty(GameState*);

struct Obj2081;
struct Cont0207fdf0;
struct SePlayer;
struct Obj0208203c;
struct ItemTable;
struct Element020de650 { char pad[8]; unsigned int nibble : 4; };
struct Obj021dcae0;
struct KeyMap020a0b3c { short* keys; signed char* values; short count; };

unsigned char* GetFieldAt0x150_02053c6c(unsigned char* combatant);
int GameState_GetProtagonistIndex(GameState*);

short FindMappedMemberId02080468(void* obj, int id);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void SetElementFlag0x40_02081ea4(struct Obj2081* obj, int id, int value);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void ResetWithSub0208203c(struct Obj0208203c* obj);
struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
void CallFunc0204c804OnMatchingKey_0207fdcc(struct Obj2081* obj, int key);
void CallFunc0204c804OnNonMatchingKey(struct Cont0207fdf0* obj, int key);
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
unsigned int ComputeRatio_02175898(char* obj, void* s);
int CheckRatioWithinCap_021758cc(char* self, int cap);
void TrySpendResource_02175924(char* self);
int EvalOrDispatch020de194(void* obj);
int MessageSystem_GetInstance();
void MessageSystem_Reset(char* obj);
extern "C" void Scenario_SetFlag(void* a, unsigned char* b, int c, int d);
void ItemTable_Construct(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

extern "C" void func_ov003_02178548(void* self);
extern "C" void func_ov003_021767ec(void* self);
extern "C" void func_ov003_021769ec(void* self);
extern "C" void func_ov003_02176ed4(void* self);
extern "C" void func_ov003_02176f94(void* self);
extern "C" void func_ov003_021748c4(unsigned char* self);
extern "C" void func_ov003_021785d4(unsigned char* obj);
extern "C" void func_ov023_021dcae0(struct Obj021dcae0* obj, int val);
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
extern "C" int func_ov003_021782a0(struct Obj2081* obj);
extern "C" void func_ov003_02175cb0(char* base, int flag);
extern "C" void func_ov003_0217599c(void* self);
extern "C" int func_020dd4c4(int val, void* elem);
extern "C" int func_ov003_0217839c(int val, void* elem);
extern "C" void* func_ov003_02179cfc(char* base, int combatantId, void* fallback);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_02081f20(void* obj, int scaleCount);
extern "C" void func_0207ccf0(void* ctx, int key, int cap, int elemId, int a5, int a6, int a7);

extern struct SePlayer g_sePlayer;

static inline void inline_ov003_02178910(unsigned char* arg0, signed char arg1) {
    *(signed char*)(arg0 + (0x7b6 - Enum_ov003_02178910_0)) = arg1;
    func_ov023_021ddf5c(arg0 + 0x3c);
}

static inline int inline_ov003_02178910_2(struct Struct_0201099c_9* arg0) { return arg0->unknown_8_0_ <= 7; }

// USA: func_ov003_02178910
extern "C" ARM void func_ov003_02178910(unsigned char* self) {
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    void* battleSum = GameState_GetParty((GameState*)battle);
    struct Obj2081* elemObj = *(struct Obj2081**)(self + (0x89c - kRegionSelfShift));
    int state = *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift));

    if (var3 == 0) {
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        return;
    }

    if (var3 == 1) {
        *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 3;
        if (*(short*)(arg0 + (0x1000 + 6 - Enum_ov003_02178910_0)) < 0) {
            short var4 = func_02080468(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)));
            *(short*)(arg0 + (0x1000 + 6 - Enum_ov003_02178910_0)) = var4;
        }
        *(short*)((char*)var2 + Enum_ov003_02178910_54) = *(short*)(arg0 + (0x1000 + 6 - Enum_ov003_02178910_0));
        func_02080c68(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)), 0);
        func_02081ea4(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)), 0);
        func_ov003_02178548(arg0);
        func_ov003_021767ec(arg0);
        func_ov003_021769ec(arg0);
        func_ov003_02176ed4(arg0);
        func_ov003_02176f94(arg0);
        func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
        *(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0)) = 0;
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        func_ov003_021748c4(arg0);
        if (*(unsigned char*)(arg0 + (0x1000 + 0x4d - Enum_ov003_02178910_0)) != 0) {
            signed char var5 = -1;
            inline_ov003_02178910(arg0, var5);
            *(unsigned char*)(arg0 + (0x1000 + 0x4d - Enum_ov003_02178910_0)) = 0;
        }
        return;
    }

    if (state == 2) {
        short key = *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 6 - kRegionSelfShift);
        func_ov003_021785d4(self);
        signed char negOne = -1;
        *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = negOne;
        func_ov023_021dcae0((struct Obj021dcae0*)(self + 0x3c), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        int r = func_ov003_021765b4(self);
        if (r != 0 && key == *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift))) {
            *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) = 1;
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(self + (0x874 - kRegionSelfShift)), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            *(void**)(self + 8) = elem;
            if (elem == 0) return;
            int kind = elem->nibble;
            int ok = func_ov003_021784bc(battleSum, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), kind, *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)));
            if (ok == 0) {
                CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1b;
                *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(short*)(self + (0x1000 + 0 - kRegionSelfShift)) = -1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            int capOk = CheckRatioWithinCap_021758cc((char*)self, *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)));
            if (capOk != 0) {
                struct Element020de650* elem2a = *(struct Element020de650**)(self + 8);
                unsigned short mult = *(unsigned short*)(self + (0x800 + 0x6c - kRegionSelfShift));
                int field30 = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
                int val = EvalOrDispatch020de194(elem2a);
                int product = mult * val;
                void* battleSum2 = GameState_GetParty((GameState*)(BattleStruct*)GameState::GetInstance());
                int kind2 = elem2a->nibble;
                int ok2 = func_ov003_021784bc(battleSum2, *(short*)((char*)elem2a + 0x18), kind2, field30);
                int result;
                if (ok2 == 1) {
                    result = 1;
                } else {
                    unsigned int var22 = _u32_div_f((unsigned int)var17, 100);
                    unsigned int var23 = *(unsigned int*)((char*)var18 + 0xf6c);
                    var21 = (var23 < (var22 << 1)) ? 1 : 0;
                }
                if (var21 != 0) {
                    func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
                    *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 2;
                    *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 5;
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
                *(short*)(arg0 + (0xf00 + 0xfc - Enum_ov003_02178910_0)) = *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0));
                (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
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
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 7;
            *(unsigned char*)(arg0 + (0x1000 + 0x3e - Enum_ov003_02178910_0)) = 1;
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 0;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x2000;
            return;
        }
        int var24 = func_ov003_021766e8(arg0);
        if (var24 == 0) return;
        func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
        *(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0)) = 0;
        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0xa;
        *(unsigned char*)(arg0 + (0x1000 + 0x3e - Enum_ov003_02178910_0)) = 1;
        *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 0;
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
        *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x2000;
        return;
    }

    if (var3 == 3) {
        func_ov003_02177208((char*)arg0);
        func_ov003_0217726c((char*)arg0);
        func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        *(unsigned char*)(arg0 + (0x1000 + 0x4a - Enum_ov003_02178910_0)) = 0;
        return;
    }

    if (var3 == 4) {
        unsigned char var25 = *(unsigned char*)(arg0 + (0x1000 + 0x4a - Enum_ov003_02178910_0));
        int var26 = 0;
        if (var25 < 5) {
            *(unsigned char*)(arg0 + (0x1000 + 0x4a - Enum_ov003_02178910_0)) = var25 + 1;
        } else {
            var26 = func_ov003_02178218(arg0);
            if (var26 != 0) {
                *(unsigned char*)(arg0 + (0x1000 + 0x4a - Enum_ov003_02178910_0)) = 0;
            }
        }

        struct Struct_0203d028_2* var27 = (Struct_0203d028_2*)GameState::GetInstance();
        int var28 = ((GameState*)var27)->GetTickCount();
        int var29 = func_02081f20(arg0 + (0x8c + 0x800 - Enum_ov003_02178910_0), var28);
        if ((unsigned short)(var29 + 0xffff) <= 1) {
            void* var30 = *(void**)(arg0 + (0x88c - Enum_ov003_02178910_0));
            int var31 = (var30 != 0) ? *(unsigned short*)var30 : 0;
            if (var31 == 0x40) var26 = 1;
            else if (var31 == 0x80) var26 = -1;
            else if (var31 == 0x20) var26 = 0x83;
            else if (var31 == 0x10) var26 = ~0x82;
        }

        if (var26 != 0) {
            int var32 = *(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0)) + var26;
            int var33 = func_ov003_02175898((char*)arg0, *(void**)(arg0 + 8));
            unsigned int var34 = (var33 == 0) ? 1 : var33;
            int var35 = _u32_div_f(*(unsigned int*)((char*)var1 + 0xf6c), var34);
            struct Struct_0201099c_9* var36 = *(struct Struct_0201099c_9**)(arg0 + 8);
            int var37 = 0xa;
            if (var36 != 0) var37 = var36->unknown_8_0_;
            int var38 = func_ov003_021784bc(var1, *(short*)(arg0 + (0x1000 + 0x3a - Enum_ov003_02178910_0)), var37, *(int*)(arg0 + (0x1000 + 0x30 - Enum_ov003_02178910_0)));
            if (var35 < var38) var38 = var35;
            if (var38 < var32) var32 = var38;
            if (var32 <= 1) var32 = 1;
            *(unsigned char*)(arg0 + (0x1000 + 0x4b - Enum_ov003_02178910_0)) = (*(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0)) < var32) ? 1 : 0;
            *(unsigned char*)(arg0 + (0x1000 + 0x4c - Enum_ov003_02178910_0)) = (var32 < *(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0))) ? 1 : 0;
            *(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0)) = var32;
            func_ov003_02177208((char*)arg0);
            func_ov003_0217726c((char*)arg0);
        }

        int hitZone = func_ov003_021782a0((struct Obj2081*)self);
        int flagTest = g_keyManager.TestKeysPressed(0x401);
        if (flagTest != 0 || hitZone == 1) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1f;
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) == 1) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 2;
            }
            (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
            func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
            return;
        }

        int var41 = g_keyManager.TestKeysPressed(2);
        if (var41 != 0 || var39 == -1) {
            func_0207fdcc(var2, 9);
            func_0207fdcc(var2, 0xa);
            func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
        }
        return;
    }

    if (var3 == 5) {
        func_ov003_02176468(arg0);
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        return;
    }

    if (var3 == 6) {
        int var42 = func_ov003_021764f4(arg0);
        if (var42 != -1) {
            if (var42 != 1) return;

            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) &= ~0x1000;
            func_ov003_02175924((char*)arg0);
            func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
            struct Struct_0201099c_9* var43 = *(struct Struct_0201099c_9**)(arg0 + 8);
            if (inline_ov003_02178910_2(var43)) {
                *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 3;
                (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
                if (*(int*)(arg0 + (0x1000 + 0x30 - Enum_ov003_02178910_0)) != 1) return;

                int val = GameState_GetProtagonistIndex((GameState*)battle);
                *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = val;
                int check = func_020dd4c4(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                if (check == 0) return;

                func_ov003_02175cb0((char*)arg0, 0);
                *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 9;
                *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
                *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
                return;
            }

            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x15;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0xb;
            short st34 = *(short*)(self + (0x1000 + 0x34 - kRegionSelfShift));
        short key = *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift));
        if (st34 == 0x20 && key == 0x55f0) {
                void* base = Scenario_GetInstance();
                Scenario_SetFlag(base, (unsigned char*)base + 0x8c, 0x1139, 1);
            }
            return;
        }

        func_0207fdcc(var2, 9);
        func_0207fdcc(var2, 0xa);
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x2f;
        *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
        *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
        return;
    }

    if (var3 == 7) {
        func_ov003_02176468(arg0);
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        return;
    }

    if (var3 == 8) {
        int var49 = func_ov003_021764f4(arg0);
        if (var49 != -1) {
            if (var49 != 1) return;

            if (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)) == 1) {
                int val = GameState_GetProtagonistIndex((GameState*)battle);
                *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = val;
                void* elem2 = func_ov003_02179cfc((char*)self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                int bit18 = (*(unsigned int*)((char*)elem2 + 8) << 0xd) >> 0x1f;
                if (bit18 != 0) {
                    func_ov003_02175cb0((char*)self, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1e;
                    *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 9;
                } else {
                    int var53 = func_ov003_0217839c(*(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)), *(void**)(arg0 + 8));
                    if (var53 != 0) {
                        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x2e;
                        *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 0x32;
                        return;
                    }
                    func_ov003_0217599c(arg0);
                    func_ov003_02175cb0((char*)arg0, 0);
                    *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 8;
                    *(short*)(arg0 + (0x1000 + 0x38 - Enum_ov003_02178910_0)) = 4;
                }
                *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
                *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
                return;
            }

            MessageSystem_Reset((char*)MessageSystem_GetInstance());
            (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
            return;
        }

        func_ov003_02175cb0((char*)arg0, 0);
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 9;
        *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
        *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
        if (*(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) & 0x1000) {
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x23;
        }
        return;
    }

    if (var3 == 9) {
        int var54 = *(int*)(arg0 + (0x1000 + 0x30 - Enum_ov003_02178910_0));
        switch (var54) {
        case 2:
            *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0xb;
            break;
        case 3:
            *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0xc;
            break;
        case 4:
            *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0xd;
            break;
        }

        short var55 = func_02080468(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)));
        *(short*)(arg0 + (0x1000 + 8 - Enum_ov003_02178910_0)) = var55;
        *(short*)((char*)var2 + Enum_ov003_02178910_54) = *(short*)(arg0 + (0x1000 + 8 - Enum_ov003_02178910_0));
        short var56 = func_02080468(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)));
        short var57 = *(short*)(arg0 + (0x1000 + 8 - Enum_ov003_02178910_0)) - var56;
        int var58 = ((int*)(arg0 + (0x1000 + 0x1c - Enum_ov003_02178910_0)))[var57];
        *(unsigned char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)) = var58;
        *(unsigned char*)(arg0 + (0x1000 + 0x44 - Enum_ov003_02178910_0)) = *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0));
        func_ov003_02177300((char*)arg0);
        func_ov003_02177410(arg0);
        func_ov003_02177550(arg0);
        func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
        *(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0)) = 0;
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        inline_ov003_02178910(arg0, *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)));
        *(unsigned char*)(arg0 + (0x1000 + 0x4d - Enum_ov003_02178910_0)) = 1;
        return;
    }

    if (var3 == 0xa) {
        *(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0)) = arg0 + (0x1000 + 8 - Enum_ov003_02178910_0);
        short var59 = func_02080468(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)));
        short var60 = *(short*)(arg0 + (0x1000 + 8 - Enum_ov003_02178910_0)) - var59;
        int var61 = ((int*)(arg0 + (0x1000 + 0x1c - Enum_ov003_02178910_0)))[var60];
        *(unsigned char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)) = var61;

        if (*(short*)(arg0 + (0x1000 + 0 - Enum_ov003_02178910_0)) == *(short*)(*(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0))) &&
            *(signed char*)(arg0 + (0x1000 + 0x44 - Enum_ov003_02178910_0)) == *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0))) {
        } else {
            *(unsigned char*)(arg0 + (0x1000 + 0x44 - Enum_ov003_02178910_0)) = *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0));
            func_ov003_02177410(arg0);
            func_ov003_02177550(arg0);
            inline_ov003_02178910(arg0, *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)));
        }

        int ok = func_ov003_021765b4(self);
        if (ok != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            int check = func_020dd4c4(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            if (check != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x19;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 9;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            void* var64 = func_ov003_02179cfc((char*)arg0, *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)), *(void**)(arg0 + 8));
            int var65 = (*(unsigned int*)((char*)var64 + 8) << 0xd) >> 0x1f;
            if (var65 != 0) {
                *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x1e;
                *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 9;
                *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
                return;
            }
            int var66 = func_ov003_0217839c(*(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)), *(void**)(arg0 + 8));
            if (var66 != 0) {
                *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x2e;
                *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 0x32;
                return;
            }
            func_ov003_0217599c(arg0);
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 8;
            *(short*)(arg0 + (0x1000 + 0x38 - Enum_ov003_02178910_0)) = 0x1d;
            unsigned char var67 = 7;
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = var67;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x1000;
            *(signed char*)(arg0 + (0x7b6 - Enum_ov003_02178910_0)) = var67 - 8;
            func_ov023_021ddf5c(arg0 + 0x3c);
            if (*(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0)) != 0) return;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) &= ~0x1000;
            *(short*)(arg0 + (0x1000 + 0x38 - Enum_ov003_02178910_0)) = 4;
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
            return;
        }

        int var68 = func_ov003_021766e8(arg0);
        if (var68 == 0) return;
        func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
        *(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0)) = 0;
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        func_ov003_02175cb0((char*)arg0, 0);
        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 9;
        *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
        *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
        if (*(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) & 0x1000) {
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x23;
        }
        return;
    }

    if (var3 == 0xb) {
        int var69 = *(int*)(arg0 + (0x1000 + 0x30 - Enum_ov003_02178910_0));
        switch (var69) {
        case 1: *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0x11; break;
        case 2: *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0x12; break;
        case 3: *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0x13; break;
        case 4: *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)) = 0x14; break;
        default: break;
        }

        short var70 = func_02080468(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)));
        *(short*)(arg0 + (0x1000 + 0xa - Enum_ov003_02178910_0)) = var70;
        *(short*)((char*)var2 + Enum_ov003_02178910_54) = *(short*)(arg0 + (0x1000 + 0xa - Enum_ov003_02178910_0));
        func_02081ea4(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)), 0);
        func_02080c68(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)), 0);
        func_ov003_02177820((char*)arg0);
        short var71 = func_02080468(var2, *(short*)(arg0 + (0xf00 + 0xfe - Enum_ov003_02178910_0)));
        short var72 = *(short*)(arg0 + (0x1000 + 0xa - Enum_ov003_02178910_0)) - var71;
        int var73 = ((int*)(arg0 + (0x1000 + 0x1c - Enum_ov003_02178910_0)))[var72];
        *(unsigned char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)) = var73;
        *(unsigned char*)(arg0 + (0x1000 + 0x44 - Enum_ov003_02178910_0)) = *(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0));
        func_0208203c((struct Struct_02081f20_2*)(arg0 + (0x88c - Enum_ov003_02178910_0)));
        *(void**)(arg0 + (0xff8 - Enum_ov003_02178910_0)) = 0;
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        return;
    }

    if (state == 0xc) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 0xa - kRegionSelfShift);
        int ok = func_ov003_021765b4(self);
        if (ok != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            short id = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
            short diff = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) - id;
            int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
            *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);

            struct Struct_0203d028_2* var78 = (Struct_0203d028_2*)GameState::GetInstance();
            struct Struct_0203d028_3* var79 = (Struct_0203d028_3*)((GameState*)var78)->GetPartyMemberByIndex(*(signed char*)(arg0 + (0x1000 + 0x43 - Enum_ov003_02178910_0)));
            if (var79 != 0) {
                unsigned char* var80 = func_02053c6c((unsigned char*)var79);
                if (var80 == 0) return;

                short var81, var82;
                for (var82 = 0, var81 = 0; var81 < 8; var81++) {
                    if (*(short*)(var80 + 0x400 + var81 * 2 + 0x54) <= 0) break;
                    var82++;
                }

                if (*(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0)) <= (8 - var82)) {
                    *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x17;
                    *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
                    *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
                    int* var83 = *(int**)((char*)var79 + 0x130);
                    if (*var83 & 1) {
                        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x2d;
                    }
                } else {
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x21;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                    *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                    void* ptr2a04 = GameState_GetParty((GameState*)battle2);
                    int lookupVal = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr2a04, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
                    if (lookupVal == 0x63) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x22;
                    } else {
                        int var86 = 0;
                        short var87;
                        for (var87 = 0; var87 < 8; var87++) {
                            if (*(short*)(arg0 + (0x1000 + 0x3a - Enum_ov003_02178910_0)) == *(short*)(var80 + 0x400 + var87 * 2 + 0x54)) {
                                var86 = 1;
                                break;
                            }
                        }
                        if (var86 == 0) {
                            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x16;
                        }
                    }
                }

                unsigned char localCtx[0x38];
                ((SafeAllocator*)localCtx)->ResetAllocatorPointer();
                ItemTable_Construct(localCtx + 0x14);
                InitStruct0207cbe8((char*)localCtx);
                InitStruct0207cbe8((char*)localCtx);
                *(void**)(localCtx + 0x2c) = self + (0x874 - kRegionSelfShift);
                func_0207ccf0(localCtx, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)),
                    *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), 1, 1, 0);
                *(unsigned char*)(self + (0x1000 + 0x4f - kRegionSelfShift)) = 0;
                return;
            }

            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x18;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            void* ptr2a04b = GameState_GetParty((GameState*)battle2);
            int lookupVal2 = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr2a04b, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) > (0x63 - lookupVal2)) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x37;
            }
            func_ov003_02175cb0((char*)arg0, 1);
            return;
        }

        int ok3 = func_ov003_021766e8(self);
        if (ok3 == 0) return;
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x18;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        void* ptr2a04c = GameState_GetParty((GameState*)battle);
        int lookupVal3 = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr2a04c, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) > (0x63 - lookupVal3)) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x37;
        }
        func_ov003_02175cb0((char*)arg0, 1);
        return;
    }

    if (var3 == 0x32) {
        func_ov003_02176468(arg0);
        (*(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)))++;
        return;
    }

    if (var3 == 0x33) {
        int var94 = func_ov003_021764f4(arg0);
        if (var94 != -1) {
            if (var94 != 1) return;

            int var95 = *(int*)(arg0 + (0x1000 + 0x30 - Enum_ov003_02178910_0));
            if (var95 == 1) {
                func_ov003_0217599c(arg0);
                func_ov003_02175cb0((char*)arg0, 0);
                *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 8;
                *(short*)(arg0 + (0x1000 + 0x38 - Enum_ov003_02178910_0)) = 4;
                *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
                *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
                return;
            }

            func_ov003_0217599c(arg0);
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 8;
            *(short*)(arg0 + (0x1000 + 0x38 - Enum_ov003_02178910_0)) = 0x1d;
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 7;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x1000;
            if (*(unsigned char*)(arg0 + (0x1000 + 0x3c - Enum_ov003_02178910_0)) != 0) return;

            *(unsigned char*)(arg0 + (0x1000 + 0x4f - Enum_ov003_02178910_0)) = 0;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) &= ~0x1000;
            *(short*)(arg0 + (0x1000 + 0x38 - Enum_ov003_02178910_0)) = 4;
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
            return;
        }

        int var96 = *(int*)(arg0 + (0x1000 + 0x30 - Enum_ov003_02178910_0));
        if (var96 == 1) {
            func_ov003_02175cb0((char*)arg0, 0);
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 9;
            *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
            *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
            return;
        }
        func_0207fdf0((struct Struct_0207fdf0_2*)var2, 0);
        func_ov003_02175cb0((char*)arg0, 0);
        *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 9;
        *(unsigned char*)(arg0 + (0x1000 + 0x3f - Enum_ov003_02178910_0)) = 1;
        *(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) |= 0x20;
        if (*(unsigned short*)(arg0 + (0x1000 + 0x46 - Enum_ov003_02178910_0)) & 0x1000) {
            *(short*)(arg0 + (0x1000 + 0x36 - Enum_ov003_02178910_0)) = 0x23;
        }
        return;
    }
}
