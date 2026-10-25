#include <globaldefs.h>
#include "Resource/MessageUpdate.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#define REGION_FLAG(jpnField, usaField) (arg0->unknown_17ff_.jpnField)
extern "C" void func_020665bc(char*, int, const char*, const char*);
extern const char data_020f07b4[], data_020f07b9[], data_020f07c0[], data_020f07c7[];
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#define REGION_FLAG(jpnField, usaField) (arg0->usaField)
#endif
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_0203de84 {
    int unknown_0_[3];
};

struct Struct_02065990_4 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

struct Struct_02065990_5 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_02065990_6 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};

union Struct_02065990_7 {
    unsigned int unknown_0_;
    struct {
        unsigned int unknown_0_0_ : 7;
        unsigned int unknown_0_7_ : 4;
        unsigned int unknown_1_3_ : 5;
        unsigned int unknown_2_0_ : 5;
        unsigned int unknown_2_5_ : 6;
    } unknown1_0_;
};

struct Container0205a3d0;
void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);
struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" void func_0206b104(void* obj);
void MessageSystem_Reset(char*);
struct Struct02065758;
int UpdateCounterAndFlag02065758(Struct02065758*, int);
void UpdateTimedState0202f380(void* obj, int step);
struct CE28Obj;
int IsField440Empty_0205ce28(CE28Obj*);
struct Field440Obj0202f6a4;
void SetupField440Type1(Field440Obj0202f6a4*);
struct Ctx0206b61c;
void ProcessTextTokens0206b61c(Ctx0206b61c*);
extern "C" int func_020657c8(void* obj, int step);
void UpdateStatusTimer_020658ac(unsigned char*, unsigned int);
int IsAnimationActive0209ca2c(void* p);
struct Battle020456d0;
void StepCounter020456d0(Battle020456d0*);
void ResetOrConsumeCounter02065920(unsigned char*, unsigned int);
extern "C" void func_020676e0(void* obj, int step);
extern "C" void MessageSystem_Stop(void* obj);
void SetName56AndFlag_0218d7b0(unsigned char* owner, char* name);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov016_0218b5c0(int a, signed char b);
extern "C" void func_ov017_0218b5f8(signed char a);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
void CallHelperIfFlag_021a5ab0(void* p);
void* GetGlobalPtr021075f4_0203cf4c();
struct EntryList_203dce4;
void* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
struct Node020406f8;
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void func_02065418(int a);
int StandardStrings_Get(int a);
void InitCombatPairState020652d0(char* obj, int a, int b, int c);
struct Obj0208bf28;
void SetFieldD20208bf28(Obj0208bf28*, int, unsigned char);
unsigned char* GetGlobal02109418_02094d6c();
struct GetTableByteOrFFData;
int GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
void RegisterSlotA020cf0fc(int);
void RegisterSlotB020cf1a8(int);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
void ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94(unsigned char*);
void SetFlag0x2IfByte0xd4Not3_0208beb4(unsigned char*);
extern "C" void func_0205e944(void* p, int v);

extern unsigned char g_bgmPlayer;
extern unsigned char g_sePlayer;

// USA: func_02065990
extern "C" ARM void func_02065990(Struct_02021b84* arg0, int arg1) {
    unsigned char* var0 = (unsigned char*)arg0;
    unsigned short var1;
    struct Struct_02065990_6 var2;
    union Struct_02065990_7 var3;
    struct Struct_0203de84 var4;
    struct Struct_0203de84 var5;
    struct Struct_02065990_4 var6;
    struct Struct_02065990_5 var7;
    struct Struct_0203de84 var8;
    int var9 = arg1;
    if (var9 == 0) var9 = 1;

    if (*(void**)(var0 + REGION_VALUE(0x230, 0x2e0)) != 0 && var0[REGION_VALUE(0x236, 0x2e6)] != 0 && arg0->unknown_9a0_ == 6) {
        if ((*(unsigned short*)0x4000304 & 0x8000) >> 15 == 1) {
            SpriteEntryList_SetFirstObject((Container0205a3d0*)(*(void**)(self + REGION_VALUE(0x230, 0x2e0))), 0, 0x1e);
        }
        SpriteEntryList_AdvanceAnimations((Container0205a330*)(*(void**)(self + REGION_VALUE(0x230, 0x2e0))), step);
    }

    if (arg0->unknown_998_ == 0) return;

    if (REGION_FLAG(flag3, b19d1) != 0) {
        message->b1958 = *(signed char*)(self + REGION_VALUE(0x1786, 0x1958)) - step;
        if (*(signed char*)(self + REGION_VALUE(0x1786, 0x1958)) >= 0) return;
        func_0206b104(self);
        MessageSystem_Reset((char*)self);
        return;
    }

    arg0->func_020656e4(var9);
    if (func_02065758((Struct_02065758*)var0, var9) != 0) return;

    if (arg0->unknown_19b1_ != 0) {
        func_0202f380(var0 + REGION_VALUE(0x1804, 0x19e0), var9);
        if (func_0205ce28((Struct_0205ce28_2*)(var0 + REGION_VALUE(0x1804, 0x19e0))) != 0) {
            func_0202f6a4((Struct_0202f6a4*)(var0 + REGION_VALUE(0x1804, 0x19e0)));
        }
        unsigned char* var10 = *(unsigned char**)(var0 + REGION_VALUE(0x1c44, 0x1e20));
        int var11;
        if (var10 != 0) {
            var11 = *(int*)(var10 + 8) == 2;
        } else {
            var11 = 0;
        }
        if (var11 == 0) return;
    }

    if (REGION_FLAG(unknown_0_0_, unknown_19ce_) != 0) arg0->unknown_44_ = *(int*)(var0 + REGION_VALUE(0x44, 0x78));

    if (arg0->unknown_19b4_ != 0) {
        arg0->unknown_1868_ = arg0->unknown_1868_ + var9;
        if (arg0->unknown_1868_ < arg0->unknown_1864_) return;
        arg0->unknown_1868_ = 0;
        func_0206b61c((Struct_02065990*)var0);
        arg0->unknown_19b4_ = 0;
        arg0->unknown_9a0_ = 5;
        arg0->unknown_19b5_ = 0;
        return;
    }

    if (func_020657c8(var0, var9) != 0) return;
    func_020658ac((unsigned char*)var0, var9);

    if ((message->b195b & 1) != 0) {
        if (IsAnimationActive0209ca2c(&g_bgmPlayer) == 0) {
            message->b195b = message->b195b & ~1;
        }
    } else {
        if (arg0->unknown_8c_ != 0 && (arg0->unknown_8c_)[0xd4] == 2) return;

        if (message->b19c9 != 0) {
            if (IsAnimationActive0209ca2c(&g_bgmPlayer) != 0) return;
            *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
            message->b19c9 = 0;
            return;
        }

        func_020456d0((Struct_020456d0*)var0);
        if (arg0->func_020440cc() != 0) {
            REGION_FLAG(unknown_0_3_, unknown_19d1_) = 1;
            arg0->unknown_1958_ = 5;
            return;
        }

        if (arg0->unknown_9a0_ != 5) {
            func_02065920((unsigned char*)var0, var9);
            if (arg0->unknown_19bc_ != 0) {
                arg0->func_02045740();
            }
            func_020676e0(var0, var9);
            arg0->func_02045688();
            return;
        }
    }

    if (*(short*)(var0 + REGION_VALUE(0x1774, 0x1946)) < 0 && arg0->unknown_19c8_ == 0) {
        *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) = 0;
        arg0->func_02045688();
    }
#if defined(jpn)
    else {
#else
    else if (*(unsigned int*)(var0 + 0x88) < arg0->unknown_78_) {
#endif
        if (*(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) >= 4) {
            *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) = *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) - 4;
            arg0->func_02045688();
            arg0->func_020455f8();
        }
        *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) =
            *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) + GameState::GetInstance()->GetTickCount();
    }

    if (arg0->unknown_19c5_ != 0) var9 = 0x10;
#if defined(jpn)
    int var14 = var9;
    bool var12 = false;
#else
    if ((arg0->unknown_195b_ & 4) != 0 && arg0->unknown_9a0_ != 0) var9 = 0x18;

    int var13 = *(int*)(var0 + 0x80) >> 4;
    *(int*)(var0 + 0x80) += var9 * 16;
    int var14 = (*(int*)(var0 + 0x80) >> 4) - var13;
    if (*(int*)(var0 + 0x80) >= 0xffffff) *(int*)(var0 + 0x80) = 0;

#endif

    while (var14 != 0) {
        if (arg0->unknown_6c_ <= arg0->unknown_78_) return;
        var1 = ((unsigned short*)arg0->unknown_4c_)[arg0->unknown_78_];
#if defined(jpn)
        if (func_02069430(var0, var1) != 0) {
            int var15 = func_02069444(var0, var1);
#else
        if (func_02044494(var0, &var1) != 0) {
            int var15 = func_02044420(var0, &var1);
#endif
            if (var15 != 0) {
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + var15 + 1;
                continue;
            }
            if (var1 == 0xff01) {
                if ((arg0->unknown_195b_ & 4) != 0) {
                    arg0->unknown_195b_ = arg0->unknown_195b_ | 8;
                }
                arg0->unknown_9a0_ = 0;
                arg0->func_02045688();
                return;
            } else if (var1 == 0xff02) {
                arg0->unknown_9a0_ = 0;
                arg0->func_02045688();
                return;
            } else if (tok == 0xff03) {
                message->mode = 0;
                message->ProcessPendingFlag02045688();
                MessageSystem_Reset((char*)self);
                MessageSystem_Stop(self);
                return;
            } else if (var1 == 0xff0b) {
                arg0->unknown_9a0_ = 4;
                arg0->func_02045688();
                (var0 + 0x1000)[REGION_VALUE(0x78d, 0x95f)] = (var0 + 0x1000)[REGION_VALUE(0x78c, 0x95e)];
                *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) = 0;
                if (*(short*)(var0 + REGION_VALUE(0x1800, 0x19da)) >= 0) {
                    (var0 + 0x1000)[REGION_VALUE(0x78d, 0x95f)] = (unsigned char)*(short*)(var0 + REGION_VALUE(0x1800, 0x19da));
                    *(short*)(var0 + REGION_VALUE(0x1800, 0x19da)) = -1;
                }
                return;
            } else if (var1 == 0xff0c) {
                arg0->unknown_1961_ = arg0->unknown_1960_;
                arg0->unknown_9a0_ = 1;
                arg0->func_02045688();
                return;
            } else if (var1 == 0xff0d) {
                arg0->unknown_9a0_ = 1;
                arg0->func_02045688();
                return;
            } else if (var1 == 0xff0a) {
                arg0->unknown_9a0_ = 3;
                arg0->func_02045688();
                return;
            } else if (var1 == REGION_VALUE(0xff1d, 0xff1b)) {
                var2.unknown_0_ = 0;
                var2.unknown_1_ = 0;
                var2.unknown_2_ = 0;
                var2.unknown_4_ = 0;
                var2.unknown_5_ = 0;
                var2.unknown_0_ = arg0->unknown_19c6_ == 0;
                var2.unknown_1_ = arg0->unknown_19c7_ == 0;
                var2.unknown_2_ = *(unsigned short*)(var0 + REGION_VALUE(0x174e, 0x187e));
                var2.unknown_4_ = 1;
                func_ov017_0218d7b0(((unsigned char*)GetGameResources()), (char*)&var2);
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (tok == REGION_VALUE(0xff1e, 0xff1c)) {
                int slot = *(signed char*)(self + REGION_VALUE(0x1785, 0x1957));
                if (slot >= 0 && slot < *(signed char*)(self + REGION_VALUE(0x1784, 0x1956))) {
                    int val;
                    int kind = *(signed char*)(message->b1952 + slot);
                    val = *(signed char*)(self + REGION_VALUE(0x177c, 0x194e) + slot);
                    if (kind > 0) {
                        SePlayer_Play((SePlayer*)&g_sePlayer, 0x65, 0);
                        if (kind == 2) {
                            val = -1;
                            func_ov016_0218b5c0(1, val);
                            func_ov017_0218b5f8(val);
                        }
                    }
                    if (var17 >= 0xa && var17 <= 0x32) {
                        int var19 = var17 / 0xa - 1;
                        int var20 = var19 >= 0 && var19 <= 3;
                        if (var20) {
                            func_ov016_0218b5c0(1, var19);
                            func_ov017_0218b5f8(var19);
                        }
                        var17 = var17 - (var19 + 1) * 0xa;
                    }
                    int var21 = var17 >= 0 && var17 <= 3;
                    if (var21) {
                        func_ov016_0218b5c0(1, var17);
                        func_ov017_0218b5f8(var17);
                        unsigned char* var22 = ((unsigned char*)GetGameResources());
                        if (func_02046b60((Struct_02038598_5*)(*(void**)(var22 + REGION_VALUE(0x34ec, 0x36fc))), 0xc) != 0) {
                            func_ov017_021a5ab0(*(void**)(var22 + REGION_VALUE(0x350c, 0x371c)));
                        }
                    }
                }
                arg0->unknown_1957_ = *(signed char*)(var0 + REGION_VALUE(0x1785, 0x1957)) + 1;
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (var1 == REGION_VALUE(0xff1c, 0xff1a)) {
                if (REGION_FLAG(unknown_0_2_, unknown_19d0_) != 0) return;
                arg0->func_02045688();
                ((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] =
                    ((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] - 1;
                if (((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] > 0) return;
                ((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] = 0;
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                arg0->unknown_19ac_ = *(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac)) + 1;
                arg0->unknown_19ac_ = *(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac)) & 3;
                *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) = 0;
                return;
            } else if (var1 == REGION_VALUE(0xff1f, 0xff1d)) {
                arg0->unknown_9a0_ = 2;
                arg0->func_02045688();
                return;
            } else if (var1 == REGION_VALUE(0xff20, 0xff1e)) {
                arg0->func_02045688();
                ((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] =
                    ((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] - 1;
                if (((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] > 0) {
                    if (g_keyManager.TestKeysPressed(0xfe3) == 0 &&
                        g_touchInput.pressed_ == 0) {
                        return;
                    }
                }
                ((int*)(var0 + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac))] = 0;
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                arg0->unknown_19ac_ = *(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac)) + 1;
                arg0->unknown_19ac_ = *(signed char*)(var0 + REGION_VALUE(0x17dc, 0x19ac)) & 3;
                *(signed char*)(var0 + REGION_VALUE(0x7e2, 0x912)) = 0;
                return;
            } else if (var1 == REGION_VALUE(0xff21, 0xff1f)) {
                arg0->unknown_19ca_ = 0;
                arg0->unknown_9a0_ = 2;
                arg0->func_02045688();
                return;
            } else if (var1 == REGION_VALUE(0xff28, 0xff26)) {
                arg0->unknown_19b1_ = 1;
                arg0->unknown_19cd_ = 1;
            } else if (var1 == REGION_VALUE(0xff29, 0xff27)) {
                arg0->unknown_19b1_ = 0;
                arg0->unknown_19cd_ = 1;
            } else if (var1 == REGION_VALUE(0xff2a, 0xff28)) {
                arg0->unknown_19b8_ = 1;
            } else if (var1 == REGION_VALUE(0xff2b, 0xff29)) {
                arg0->unknown_19b8_ = 0;
            } else if (var1 == REGION_VALUE(0xff2c, 0xff2a)) {
                arg0->unknown_1844_ = *(int*)(var0 + REGION_VALUE(0x1710, 0x1840));
                arg0->unknown_19b6_ = 1;
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                arg0->func_02045688();
                return;
            } else if (var1 == REGION_VALUE(0xff2e, 0xff2c)) {
                arg0->unknown_1844_ = arg0->unknown_183c_;
                arg0->unknown_19b6_ = 1;
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                arg0->func_02045688();
                return;
            } else if (var1 == REGION_VALUE(0xff2f, 0xff2d)) {
                unsigned char* var23 = (unsigned char*)GameState::GetInstance()->GetUnknownGameObject();
                void* var24 = func_0203dce4((Struct_0203dce4_2*)func_0203cf4c(), arg0->unknown_1838_);
                if (var23 != 0 && var24 != 0) {
                    var4 = *(struct Struct_0203de84*)(var23 + 0x44);
                    func_020406f8(&var8, (Struct_0203de84_2*)var24);
                    var5 = var8;
                    arg0->unknown_1844_ = fix32ReduceAngle0To2Pi(fix32_Atan2(var4.unknown_0_[0] - var5.unknown_0_[0], var4.unknown_0_[2] - var5.unknown_0_[2]));
                    arg0->unknown_19b6_ = 1;
                    arg0->func_02045688();
                }
                *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (tok == REGION_VALUE(0xff30, 0xff2e)) {
                message->ProcessPendingFlag02045688();
                (self + 0x1000)[REGION_VALUE(0x787, 0x959)] = 0x3c;
                (self + 0x1000)[REGION_VALUE(0x7e7, 0x9b7)] = 1;
                (self + 0x1000)[REGION_VALUE(0x78a, 0x95c)] = 0;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                SePlayer_Play((SePlayer*)&g_sePlayer, 6, 0);
                return;
            } else if (tok == REGION_VALUE(0xff31, 0xff2f)) {
                message->ProcessPendingFlag02045688();
                (self + 0x1000)[REGION_VALUE(0x787, 0x959)] = 0x3c;
                (self + 0x1000)[REGION_VALUE(0x7e7, 0x9b7)] = 1;
                (self + 0x1000)[REGION_VALUE(0x78a, 0x95c)] = 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                SePlayer_Play((SePlayer*)&g_sePlayer, 0x1c, 0);
                return;
            } else if (var1 == 0xff04 || var1 == 0xff05 || var1 == 0xff06 || var1 == 0xff07) {
                func_02065418(arg0->unknown_19cc_);
                int var25 = 0;
                if (*(int*)(var0 + REGION_VALUE(0x218, 0x2c8)) == 1 || var1 == 0xff05) var25 = 1;
                *(int*)(var0 + REGION_VALUE(0x218, 0x2c8)) = 0;
#if defined(jpn)
                func_020665bc((char*)(var0 + REGION_VALUE(0x50, 0x90)), var25, data_020f07b4, data_020f07b9);
#else
                int a = StandardStrings_Get(0x1b);
                int b = StandardStrings_Get(0x1c);
                InitCombatPairState020652d0((char*)(self + REGION_VALUE(0x50, 0x90)), first, a, b);
#endif
                message->w94c[2] = first;
                (self + 0x1000)[REGION_VALUE(0x7ea, 0x9ba)] = 1;
                *(int*)(self + REGION_VALUE(0x85c, 0x98c)) = 0;
                message->mode = 6;
                message->ProcessPendingFlag02045688();
                SePlayer_Play((SePlayer*)&g_sePlayer, 5, 0);
                int alive = 1;
                unsigned char* bs = (unsigned char*)GameState::GetInstance();
                unsigned char* w = (unsigned char*)((GameState*)bs)->GetResources();
                if ((bs + 0x5000)[REGION_VALUE(0xa68, 0xcc8)] == 2) alive = 0;
                if (w != 0 && alive != 0) (w + 0x4000)[REGION_VALUE(0x134, 0x354)] = 0xa;
                return;
            } else if (var1 == 0xff08) {
                volatile unsigned int* var31 = (volatile unsigned int*)0x4000000;
                unsigned int var32 = (*var31 & 0x1f00) >> 8;
                unsigned int var33 = *var31 & ~0x1f00;
                *var31 = var33 | ((var32 | 0x10) << 8);
                func_02065418(arg0->unknown_19cc_);
#if defined(jpn)
                func_020665bc((char*)(var0 + REGION_VALUE(0x50, 0x90)), 0, data_020f07c0, data_020f07c7);
#else
                int a = StandardStrings_Get(0x1d);
                int b = StandardStrings_Get(0x1e);
                InitCombatPairState020652d0((char*)(self + REGION_VALUE(0x50, 0x90)), 0, a, b);
#endif
                message->w94c[2] = 0;
                (self + 0x1000)[REGION_VALUE(0x7ea, 0x9ba)] = 1;
                *(int*)(self + REGION_VALUE(0x85c, 0x98c)) = 1;
                message->mode = 6;
                message->ProcessPendingFlag02045688();
                SePlayer_Play((SePlayer*)&g_sePlayer, 5, 0);
                unsigned char* w = (unsigned char*)GameState::GetInstance()->GetResources();
                if (w != 0) (w + 0x4000)[REGION_VALUE(0x134, 0x354)] = 0xa;
                return;
            } else if (var1 == 0xff0f) {
                unsigned char* var37 = arg0->unknown_8c_;
#if defined(jpn)
                {
#else
                if (var37 != 0) {
#endif
                    *(unsigned short*)(ent + 0xda) = *(unsigned short*)(ent + 0xda) | 0x40;
                    SetFieldD20208bf28((Obj0208bf28*)(message->child), *(short*)(self + REGION_VALUE(0x1776, 0x1948)), 0);
                    *&message->b195b |= 1;
                    unsigned char* g = GetGlobal02109418_02094d6c();
                    int idx = GetTableByteOrFF_020965ac((GetTableByteOrFFData*)g, (unsigned char)*(short*)(self + REGION_VALUE(0x1776, 0x1948)));
                    RegisterSlotA020cf0fc((int)&sa);
                    RegisterSlotB020cf1a8((int)&sb);
                    packed.b.a = sa.f0;
                    packed.b.b = sa.f4;
                    packed.b.c = sa.f8;
                    packed.b.d = sb.f0;
                    packed.b.e = sb.f4;
                    *(unsigned int*)(g + idx * 4 + 0x178) = packed.w;
                    SetValueAndActivate0209c830((Struct0209c830*)&g_bgmPlayer, 0x32);
                }
            } else if (tok > REGION_VALUE(0xff39, 0xff34) && tok < REGION_VALUE(0xff4e, 0xff49)) {
                message->ProcessPendingFlag02045688();
                SetValueAndActivate0209c830((Struct0209c830*)&g_bgmPlayer, tok - REGION_VALUE(0xff08, 0xff03));
                message->b19c9 = 1;
                return;
            } else if (tok >= REGION_VALUE(0xff4f, 0xff4a) && tok <= REGION_VALUE(0xff51, 0xff4c)) {
                int arg = -1;
                if (tok == REGION_VALUE(0xff50, 0xff4b)) arg = 0xe;
                if (arg >= 0) {
                    SePlayer_Play((SePlayer*)&g_sePlayer, 0xe, 0);
                }
            } else if (tok == 0xff10) {
                unsigned char* ent = message->child;
                if (ent != 0) *(short*)(ent + 0xd2) = *(short*)(self + REGION_VALUE(0x1776, 0x1948));
            } else if (tok == 0xff11) {
                unsigned char* ent = message->child;
                if (ent != 0) {
                    *(unsigned short*)(ent + 0xda) = *(unsigned short*)(ent + 0xda) | 0x200;
                    ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94((unsigned char*)(message->child));
                    *&message->b195b |= 1;
                    SetValueAndActivate0209c830((Struct0209c830*)&g_bgmPlayer, 0x33);
                }
            } else if (tok == 0xff13) {
                unsigned char* ent = message->child;
                if (ent != 0) {
                    *(unsigned short*)(ent + 0xda) = *(unsigned short*)(ent + 0xda) | 0x300;
                    ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94((unsigned char*)(message->child));
                    *&message->b195b |= 1;
                    SetValueAndActivate0209c830((Struct0209c830*)&g_bgmPlayer, 0x44);
                }
            } else if (var1 == 0xff12) {
                if (arg0->unknown_8c_ != 0) {
                    func_0208beb4((unsigned char*)(arg0->unknown_8c_));
                }
#if defined(jpn)
            } else if (var1 == 0xff37) {
                var12 = true;
            } else if (var1 == 0xff38) {
                var12 = false;
#endif
            } else if (tok >= REGION_VALUE(0xff52, 0xff4d) && tok <= REGION_VALUE(0xff55, 0xff50)) {
                int v = *(signed char*)(self + REGION_VALUE(0x1778, 0x194a) + (tok - REGION_VALUE(0xff52, 0xff4d)));
                func_0205e944(&g_sePlayer, ((v * 0x21dd) >> 10) & 0x7f);
            } else if (tok == 0xff0e) {
                message->b19c0 = 1;
                message->b195d = 0x1e;
#if defined(jpn)
            } else if ((unsigned short)(var1 + 0xe6) <= 1) {
                var14++;
#endif
            }
        }
        arg0->unknown_9a0_ = 5;
        *(int*)(var0 + REGION_VALUE(0x44, 0x78)) = *(int*)(var0 + REGION_VALUE(0x44, 0x78)) + 1;
#if defined(jpn)
        if (!var12) var14--;
#else
        var14--;
#endif
    }
}
