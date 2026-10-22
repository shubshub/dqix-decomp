#include <globaldefs.h>
#include "Resource/MessageUpdate.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#define REGION_FLAG(jpnField, usaField) (message->flags17ff.jpnField)
extern "C" void func_020665bc(char*, int, const char*, const char*);
extern const char data_020f07b4[], data_020f07b9[], data_020f07c0[], data_020f07c7[];
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#define REGION_FLAG(jpnField, usaField) (message->usaField)
#endif
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Vec3_020406f8 {
    int v[3];
};

struct SlotA020cf0fc {
    int f0;
    int f4;
    int f8;
    int fc;
};

struct SlotB020cf1a8 {
    int f0;
    int f4;
    int f8;
};

struct Name56_0218d7b0 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned char f4;
    unsigned char f5;
};

union Packed0209c830 {
    unsigned int w;
    struct {
        unsigned int a : 7;
        unsigned int b : 4;
        unsigned int c : 5;
        unsigned int d : 5;
        unsigned int e : 6;
    } b;
};

struct Container0205a3d0;
void SetEntryByte14ByKey0205a42c(Container0205a3d0*, int, int);
struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);
extern "C" void func_0206b104(void* obj);
void ReinitController02043204(char*);
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
extern "C" void func_02043124(void* obj);
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
int CallFunc020e0434With02153694_020e51cc(int a);
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

extern unsigned char data_02109bf4;
extern unsigned char g_sePlayer;

// USA: func_02065990
extern "C" ARM void func_02065990(MessageSystem* message, int amount) {
    unsigned char* self = (unsigned char*)message;
    unsigned short tok;
    struct Name56_0218d7b0 nm;
    union Packed0209c830 packed;
    struct Vec3_020406f8 here;
    struct Vec3_020406f8 dst;
    struct SlotA020cf0fc sa;
    struct SlotB020cf1a8 sb;
    struct Vec3_020406f8 src;
    int step = amount;
    if (step == 0) step = 1;

    if (*(void**)(self + REGION_VALUE(0x230, 0x2e0)) != 0 && self[REGION_VALUE(0x236, 0x2e6)] != 0 && message->mode == 6) {
        if ((*(unsigned short*)0x4000304 & 0x8000) >> 15 == 1) {
            SetEntryByte14ByKey0205a42c((Container0205a3d0*)(*(void**)(self + REGION_VALUE(0x230, 0x2e0))), 0, 0x1e);
        }
        IterateEntries0205a330((Container0205a330*)(*(void**)(self + REGION_VALUE(0x230, 0x2e0))), step);
    }

    if (message->active == 0) return;

    if (REGION_FLAG(flag3, b19d1) != 0) {
        message->b1958 = *(signed char*)(self + REGION_VALUE(0x1786, 0x1958)) - step;
        if (*(signed char*)(self + REGION_VALUE(0x1786, 0x1958)) >= 0) return;
        func_0206b104(self);
        ReinitController02043204((char*)self);
        return;
    }

    message->CheckAndClearFlag020656e4(step);
    if (UpdateCounterAndFlag02065758((Struct02065758*)self, step) != 0) return;

    if (message->b19b1 != 0) {
        UpdateTimedState0202f380(self + REGION_VALUE(0x1804, 0x19e0), step);
        if (IsField440Empty_0205ce28((CE28Obj*)(self + REGION_VALUE(0x1804, 0x19e0))) != 0) {
            SetupField440Type1((Field440Obj0202f6a4*)(self + REGION_VALUE(0x1804, 0x19e0)));
        }
        unsigned char* w = *(unsigned char**)(self + REGION_VALUE(0x1c44, 0x1e20));
        int ready;
        if (w != 0) {
            ready = *(int*)(w + 8) == 2;
        } else {
            ready = 0;
        }
        if (ready == 0) return;
    }

    if (REGION_FLAG(streamMode, b19ce) != 0) message->stream44 = *(int*)(self + REGION_VALUE(0x44, 0x78));

    if (message->b19b4 != 0) {
        message->w1868 = message->w1868 + step;
        if (message->w1868 < message->w1864) return;
        message->w1868 = 0;
        ProcessTextTokens0206b61c((Ctx0206b61c*)self);
        message->b19b4 = 0;
        message->mode = 5;
        message->b19b5 = 0;
        return;
    }

    if (func_020657c8(self, step) != 0) return;
    UpdateStatusTimer_020658ac((unsigned char*)self, step);

    if ((message->b195b & 1) != 0) {
        if (IsAnimationActive0209ca2c(&data_02109bf4) == 0) {
            message->b195b = message->b195b & ~1;
        }
    } else {
        if (message->child != 0 && (message->child)[0xd4] == 2) return;

        if (message->b19c9 != 0) {
            if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) return;
            *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
            message->b19c9 = 0;
            return;
        }

        StepCounter020456d0((Battle020456d0*)self);
        if (message->func_020440cc() != 0) {
            REGION_FLAG(flag3, b19d1) = 1;
            message->b1958 = 5;
            return;
        }

        if (message->mode != 5) {
            ResetOrConsumeCounter02065920((unsigned char*)self, step);
            if (message->b19bc != 0) {
                message->HandleRepeatInput02045740();
            }
            func_020676e0(self, step);
            message->ProcessPendingFlag02045688();
            return;
        }
    }

    if (*(short*)(self + REGION_VALUE(0x1774, 0x1946)) < 0 && message->b19c8 == 0) {
        *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
        message->ProcessPendingFlag02045688();
    }
#if defined(jpn)
    else {
#else
    else if (*(unsigned int*)(self + 0x88) < message->tokenIndex) {
#endif
        if (*(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) >= 4) {
            *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) - 4;
            message->ProcessPendingFlag02045688();
            message->HandleStateChange020455f8();
        }
        *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) =
            *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) + GameState::GetInstance()->GetTickCount();
    }

    if (message->b19c5 != 0) step = 0x10;
#if defined(jpn)
    int n = step;
    bool skipCount = false;
#else
    if ((message->b195b & 4) != 0 && message->mode != 0) step = 0x18;

    int old = *(int*)(self + 0x80) >> 4;
    *(int*)(self + 0x80) += step * 16;
    int n = (*(int*)(self + 0x80) >> 4) - old;
    if (*(int*)(self + 0x80) >= 0xffffff) *(int*)(self + 0x80) = 0;

#endif

    while (n != 0) {
        if (message->tokenCount <= message->tokenIndex) return;
        tok = ((unsigned short*)message->firstLineBuffer)[message->tokenIndex];
#if defined(jpn)
        if (func_02069430(self, tok) != 0) {
            int adv = func_02069444(self, tok);
#else
        if (IsHighByteFF02044494(self, &tok) != 0) {
            int adv = Dispatch02044420(self, &tok);
#endif
            if (adv != 0) {
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + adv + 1;
                continue;
            }
            if (tok == 0xff01) {
                if ((message->b195b & 4) != 0) {
                    message->b195b = message->b195b | 8;
                }
                message->mode = 0;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == 0xff02) {
                message->mode = 0;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == 0xff03) {
                message->mode = 0;
                message->ProcessPendingFlag02045688();
                ReinitController02043204((char*)self);
                func_02043124(self);
                return;
            } else if (tok == 0xff0b) {
                message->mode = 4;
                message->ProcessPendingFlag02045688();
                (self + 0x1000)[REGION_VALUE(0x78d, 0x95f)] = (self + 0x1000)[REGION_VALUE(0x78c, 0x95e)];
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                if (*(short*)(self + REGION_VALUE(0x1800, 0x19da)) >= 0) {
                    (self + 0x1000)[REGION_VALUE(0x78d, 0x95f)] = (unsigned char)*(short*)(self + REGION_VALUE(0x1800, 0x19da));
                    *(short*)(self + REGION_VALUE(0x1800, 0x19da)) = -1;
                }
                return;
            } else if (tok == 0xff0c) {
                message->inputDelay = message->b1960;
                message->mode = 1;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == 0xff0d) {
                message->mode = 1;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == 0xff0a) {
                message->mode = 3;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == REGION_VALUE(0xff1d, 0xff1b)) {
                nm.f0 = 0;
                nm.f1 = 0;
                nm.f2 = 0;
                nm.f4 = 0;
                nm.f5 = 0;
                nm.f0 = message->b19c6 == 0;
                nm.f1 = message->b19c7 == 0;
                nm.f2 = *(unsigned short*)(self + REGION_VALUE(0x174e, 0x187e));
                nm.f4 = 1;
                SetName56AndFlag_0218d7b0(((unsigned char*)GetGameResources()), (char*)&nm);
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
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
                    if (val >= 0xa && val <= 0x32) {
                        int tens = val / 0xa - 1;
                        int okt = tens >= 0 && tens <= 3;
                        if (okt) {
                            func_ov016_0218b5c0(1, tens);
                            func_ov017_0218b5f8(tens);
                        }
                        val = val - (tens + 1) * 0xa;
                    }
                    int okv = val >= 0 && val <= 3;
                    if (okv) {
                        func_ov016_0218b5c0(1, val);
                        func_ov017_0218b5f8(val);
                        unsigned char* who = ((unsigned char*)GetGameResources());
                        if (ListContainsId((ListHead02046b60*)(*(void**)(who + REGION_VALUE(0x34ec, 0x36fc))), 0xc) != 0) {
                            CallHelperIfFlag_021a5ab0(*(void**)(who + REGION_VALUE(0x350c, 0x371c)));
                        }
                    }
                }
                message->b1957 = *(signed char*)(self + REGION_VALUE(0x1785, 0x1957)) + 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (tok == REGION_VALUE(0xff1c, 0xff1a)) {
                if (REGION_FLAG(flag2, b19d0) != 0) return;
                message->ProcessPendingFlag02045688();
                ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] =
                    ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] - 1;
                if (((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] > 0) return;
                ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] = 0;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->b19ac = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) + 1;
                message->b19ac = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) & 3;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                return;
            } else if (tok == REGION_VALUE(0xff1f, 0xff1d)) {
                message->mode = 2;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == REGION_VALUE(0xff20, 0xff1e)) {
                message->ProcessPendingFlag02045688();
                ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] =
                    ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] - 1;
                if (((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] > 0) {
                    if (g_keyManager.TestKeysPressed(0xfe3) == 0 &&
                        g_touchInput.pressed_ == 0) {
                        return;
                    }
                }
                ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] = 0;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->b19ac = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) + 1;
                message->b19ac = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) & 3;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                return;
            } else if (tok == REGION_VALUE(0xff21, 0xff1f)) {
                message->b19ca = 0;
                message->mode = 2;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == REGION_VALUE(0xff28, 0xff26)) {
                message->b19b1 = 1;
                message->b19cd = 1;
            } else if (tok == REGION_VALUE(0xff29, 0xff27)) {
                message->b19b1 = 0;
                message->b19cd = 1;
            } else if (tok == REGION_VALUE(0xff2a, 0xff28)) {
                message->b19b8 = 1;
            } else if (tok == REGION_VALUE(0xff2b, 0xff29)) {
                message->b19b8 = 0;
            } else if (tok == REGION_VALUE(0xff2c, 0xff2a)) {
                message->pendingValue = *(int*)(self + REGION_VALUE(0x1710, 0x1840));
                message->pendingValueActive = 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == REGION_VALUE(0xff2e, 0xff2c)) {
                message->pendingValue = message->selectedValue;
                message->pendingValueActive = 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->ProcessPendingFlag02045688();
                return;
            } else if (tok == REGION_VALUE(0xff2f, 0xff2d)) {
                unsigned char* who = (unsigned char*)GameState::GetInstance()->GetUnknownGameObject();
                void* node = GetEntryUnlessFlag0x8000_0203dce4((EntryList_203dce4*)GetGlobalPtr021075f4_0203cf4c(), message->selectedEntry);
                if (who != 0 && node != 0) {
                    here = *(struct Vec3_020406f8*)(who + 0x44);
                    SelectVec3FromSources020406f8(&src, (Node020406f8*)node);
                    dst = src;
                    message->pendingValue = fix32ReduceAngle0To2Pi(fix32_Atan2(here.v[0] - dst.v[0], here.v[2] - dst.v[2]));
                    message->pendingValueActive = 1;
                    message->ProcessPendingFlag02045688();
                }
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
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
            } else if (tok == 0xff04 || tok == 0xff05 || tok == 0xff06 || tok == 0xff07) {
                func_02065418(message->b19cc);
                int first = 0;
                if (*(int*)(self + REGION_VALUE(0x218, 0x2c8)) == 1 || tok == 0xff05) first = 1;
                *(int*)(self + REGION_VALUE(0x218, 0x2c8)) = 0;
#if defined(jpn)
                func_020665bc((char*)(self + REGION_VALUE(0x50, 0x90)), first, data_020f07b4, data_020f07b9);
#else
                int a = CallFunc020e0434With02153694_020e51cc(0x1b);
                int b = CallFunc020e0434With02153694_020e51cc(0x1c);
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
            } else if (tok == 0xff08) {
                volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
                unsigned int bits = (*reg & 0x1f00) >> 8;
                unsigned int keep = *reg & ~0x1f00;
                *reg = keep | ((bits | 0x10) << 8);
                func_02065418(message->b19cc);
#if defined(jpn)
                func_020665bc((char*)(self + REGION_VALUE(0x50, 0x90)), 0, data_020f07c0, data_020f07c7);
#else
                int a = CallFunc020e0434With02153694_020e51cc(0x1d);
                int b = CallFunc020e0434With02153694_020e51cc(0x1e);
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
            } else if (tok == 0xff0f) {
                unsigned char* ent = message->child;
#if defined(jpn)
                {
#else
                if (ent != 0) {
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
                    SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x32);
                }
            } else if (tok > REGION_VALUE(0xff39, 0xff34) && tok < REGION_VALUE(0xff4e, 0xff49)) {
                message->ProcessPendingFlag02045688();
                SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, tok - REGION_VALUE(0xff08, 0xff03));
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
                    SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x33);
                }
            } else if (tok == 0xff13) {
                unsigned char* ent = message->child;
                if (ent != 0) {
                    *(unsigned short*)(ent + 0xda) = *(unsigned short*)(ent + 0xda) | 0x300;
                    ClearField0xd0AndSetFlag0x1IfByte0xd4Not2_0208be94((unsigned char*)(message->child));
                    *&message->b195b |= 1;
                    SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x44);
                }
            } else if (tok == 0xff12) {
                if (message->child != 0) {
                    SetFlag0x2IfByte0xd4Not3_0208beb4((unsigned char*)(message->child));
                }
#if defined(jpn)
            } else if (tok == 0xff37) {
                skipCount = true;
            } else if (tok == 0xff38) {
                skipCount = false;
#endif
            } else if (tok >= REGION_VALUE(0xff52, 0xff4d) && tok <= REGION_VALUE(0xff55, 0xff50)) {
                int v = *(signed char*)(self + REGION_VALUE(0x1778, 0x194a) + (tok - REGION_VALUE(0xff52, 0xff4d)));
                func_0205e944(&g_sePlayer, ((v * 0x21dd) >> 10) & 0x7f);
            } else if (tok == 0xff0e) {
                message->b19c0 = 1;
                message->b195d = 0x1e;
#if defined(jpn)
            } else if ((unsigned short)(tok + 0xe6) <= 1) {
                n++;
#endif
            }
        }
        message->mode = 5;
        *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
#if defined(jpn)
        if (!skipCount) n--;
#else
        n--;
#endif
    }
}
