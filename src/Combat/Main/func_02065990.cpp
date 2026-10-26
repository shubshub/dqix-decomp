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

struct Struct_0203de84 {
    int v[3];
};

struct Struct_02065990_4 {
    int f0;
    int f4;
    int f8;
    int fc;
};

struct Struct_02065990_5 {
    int f0;
    int f4;
    int f8;
};

struct Struct_02065990_6 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned char f4;
    unsigned char unknown_5_;
};

union Struct_02065990_7 {
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
extern "C" void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);
struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" void func_0206b104(void* obj);
extern "C" void MessageSystem_Reset(char*);
struct Struct_02065758;
extern "C" int func_02065758(Struct_02065758*, int);
extern "C" void WindowFrame_Update(void* obj, int step);
struct Struct_0205ce28_2;
extern "C" int func_0205ce28(Struct_0205ce28_2*);
struct Field440Obj0202f6a4;
extern "C" void WindowFrame_Open(Field440Obj0202f6a4*);
struct Struct_02065990;
extern "C" void func_0206b61c(Struct_02065990*);
extern "C" int func_020657c8(void* obj, int step);
extern "C" void func_020658ac(unsigned char*, unsigned int);
extern "C" int func_0209ca2c(void* p);
struct Struct_020456d0;
extern "C" void func_020456d0(Struct_020456d0*);
extern "C" void func_02065920(unsigned char*, unsigned int);
extern "C" void func_020676e0(void* obj, int step);
extern "C" void MessageSystem_Stop(void* obj);
extern "C" void func_ov017_0218d7b0(unsigned char* owner, char* name);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov016_0218b5c0(int a, signed char b);
extern "C" void func_ov017_0218b5f8(signed char a);
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void func_ov017_021a5ab0(void* p);
extern "C" void* func_0203cf4c();
struct Struct_0203dce4_2;
extern "C" void* func_0203dce4(Struct_0203dce4_2*, int);
struct Node020406f8;
extern "C" void func_020406f8(Struct_0203de84*, Node020406f8*);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void func_02065418(int a);
extern "C" int StandardStrings_Get(int a);
extern "C" void func_020652d0(char* obj, int a, int b, int c);
struct Struct_02065990_2;
extern "C" void func_0208bf28(Struct_02065990_2*, int, unsigned char);
extern "C" unsigned char* func_02094d6c();
struct Struct_02065990_3;
extern "C" int func_020965ac(Struct_02065990_3*, unsigned char);
extern "C" void func_020cf0fc(int);
extern "C" void RTC_GetTime(int);
struct Struct0209c830;
extern "C" void func_0209c830(Struct0209c830*, int);
extern "C" void func_0208be94(unsigned char*);
extern "C" void func_0208beb4(unsigned char*);
extern "C" void func_0205e944(void* p, int v);

extern unsigned char g_bgmPlayer;
extern unsigned char g_sePlayer;

// USA: func_02065990
extern "C" ARM void func_02065990(MessageSystem* message, int amount) {
    unsigned char* self = (unsigned char*)message;
    unsigned short tok;
    struct Struct_02065990_6 nm;
    union Struct_02065990_7 packed;
    struct Struct_0203de84 var4;
    struct Struct_0203de84 dst;
    struct Struct_02065990_4 sa;
    struct Struct_02065990_5 sb;
    struct Struct_0203de84 src;
    int step = amount;
    if (step == 0) step = 1;

    if (*(void**)(self + REGION_VALUE(0x230, 0x2e0)) != 0 && self[REGION_VALUE(0x236, 0x2e6)] != 0 && message->mode == 6) {
        if ((*(unsigned short*)0x4000304 & 0x8000) >> 15 == 1) {
            SpriteEntryList_SetFirstObject((Container0205a3d0*)(*(void**)(self + REGION_VALUE(0x230, 0x2e0))), 0, 0x1e);
        }
        SpriteEntryList_AdvanceAnimations((Container0205a330*)(*(void**)(self + REGION_VALUE(0x230, 0x2e0))), step);
    }

    if (message->active == 0) return;

    if (REGION_FLAG(unknown_0_3_, unknown_19d1_) != 0) {
        message->unknown_1958_ = *(signed char*)(self + REGION_VALUE(0x1786, 0x1958)) - step;
        if (*(signed char*)(self + REGION_VALUE(0x1786, 0x1958)) >= 0) return;
        func_0206b104(self);
        MessageSystem_Reset((char*)self);
        return;
    }

    message->func_020656e4(step);
    if (func_02065758((Struct_02065758*)self, step) != 0) return;

    if (message->unknown_19b1_ != 0) {
        WindowFrame_Update(self + REGION_VALUE(0x1804, 0x19e0), step);
        if (func_0205ce28((Struct_0205ce28_2*)(self + REGION_VALUE(0x1804, 0x19e0))) != 0) {
            WindowFrame_Open((Field440Obj0202f6a4*)(self + REGION_VALUE(0x1804, 0x19e0)));
        }
        unsigned char* w = *(unsigned char**)(self + REGION_VALUE(0x1c44, 0x1e20));
        int var11;
        if (w != 0) {
            var11 = *(int*)(w + 8) == 2;
        } else {
            var11 = 0;
        }
        if (var11 == 0) return;
    }

    if (REGION_FLAG(unknown_0_0_, unknown_19ce_) != 0) message->unknown_44_ = *(int*)(self + REGION_VALUE(0x44, 0x78));

    if (message->unknown_19b4_ != 0) {
        message->unknown_1868_ = message->unknown_1868_ + step;
        if (message->unknown_1868_ < message->unknown_1864_) return;
        message->unknown_1868_ = 0;
        func_0206b61c((Struct_02065990*)self);
        message->unknown_19b4_ = 0;
        message->mode = 5;
        message->unknown_19b5_ = 0;
        return;
    }

    if (func_020657c8(self, step) != 0) return;
    func_020658ac((unsigned char*)self, step);

    if ((message->unknown_195b_ & 1) != 0) {
        if (func_0209ca2c(&g_bgmPlayer) == 0) {
            message->unknown_195b_ = message->unknown_195b_ & ~1;
        }
    } else {
        if (message->child != 0 && (message->child)[0xd4] == 2) return;

        if (message->unknown_19c9_ != 0) {
            if (func_0209ca2c(&g_bgmPlayer) != 0) return;
            *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
            message->unknown_19c9_ = 0;
            return;
        }

        func_020456d0((Struct_020456d0*)self);
        if (message->func_020440cc() != 0) {
            REGION_FLAG(unknown_0_3_, unknown_19d1_) = 1;
            message->unknown_1958_ = 5;
            return;
        }

        if (message->mode != 5) {
            func_02065920((unsigned char*)self, step);
            if (message->unknown_19bc_ != 0) {
                message->func_02045740();
            }
            func_020676e0(self, step);
            message->func_02045688();
            return;
        }
    }

    if (*(short*)(self + REGION_VALUE(0x1774, 0x1946)) < 0 && message->unknown_19c8_ == 0) {
        *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
        message->func_02045688();
    }
#if defined(jpn)
    else {
#else
    else if (*(unsigned int*)(self + 0x88) < message->unknown_78_) {
#endif
        if (*(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) >= 4) {
            *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) - 4;
            message->func_02045688();
            message->func_020455f8();
        }
        *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) =
            *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) + GameState::GetInstance()->GetTickCount();
    }

    if (message->unknown_19c5_ != 0) step = 0x10;
#if defined(jpn)
    int n = step;
    bool var12 = false;
#else
    if ((message->unknown_195b_ & 4) != 0 && message->mode != 0) step = 0x18;

    int old = *(int*)(self + 0x80) >> 4;
    *(int*)(self + 0x80) += step * 16;
    int n = (*(int*)(self + 0x80) >> 4) - old;
    if (*(int*)(self + 0x80) >= 0xffffff) *(int*)(self + 0x80) = 0;

#endif

    while (n != 0) {
        if (message->unknown_6c_ <= message->unknown_78_) return;
        tok = ((unsigned short*)message->unknown_4c_)[message->unknown_78_];
#if defined(jpn)
        if (func_02069430(self, tok) != 0) {
            int var15 = func_02069444(self, tok);
#else
        if (func_02044494(self, &tok) != 0) {
            int var15 = func_02044420(self, &tok);
#endif
            if (var15 != 0) {
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + var15 + 1;
                continue;
            }
            if (tok == 0xff01) {
                if ((message->unknown_195b_ & 4) != 0) {
                    message->unknown_195b_ = message->unknown_195b_ | 8;
                }
                message->mode = 0;
                message->func_02045688();
                return;
            } else if (tok == 0xff02) {
                message->mode = 0;
                message->func_02045688();
                return;
            } else if (tok == 0xff03) {
                message->mode = 0;
                message->func_02045688();
                MessageSystem_Reset((char*)self);
                MessageSystem_Stop(self);
                return;
            } else if (tok == 0xff0b) {
                message->mode = 4;
                message->func_02045688();
                (self + 0x1000)[REGION_VALUE(0x78d, 0x95f)] = (self + 0x1000)[REGION_VALUE(0x78c, 0x95e)];
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                if (*(short*)(self + REGION_VALUE(0x1800, 0x19da)) >= 0) {
                    (self + 0x1000)[REGION_VALUE(0x78d, 0x95f)] = (unsigned char)*(short*)(self + REGION_VALUE(0x1800, 0x19da));
                    *(short*)(self + REGION_VALUE(0x1800, 0x19da)) = -1;
                }
                return;
            } else if (tok == 0xff0c) {
                message->unknown_1961_ = message->unknown_1960_;
                message->mode = 1;
                message->func_02045688();
                return;
            } else if (tok == 0xff0d) {
                message->mode = 1;
                message->func_02045688();
                return;
            } else if (tok == 0xff0a) {
                message->mode = 3;
                message->func_02045688();
                return;
            } else if (tok == REGION_VALUE(0xff1d, 0xff1b)) {
                nm.f0 = 0;
                nm.f1 = 0;
                nm.f2 = 0;
                nm.f4 = 0;
                nm.unknown_5_ = 0;
                nm.f0 = message->unknown_19c6_ == 0;
                nm.f1 = message->unknown_19c7_ == 0;
                nm.f2 = *(unsigned short*)(self + REGION_VALUE(0x174e, 0x187e));
                nm.f4 = 1;
                func_ov017_0218d7b0(((unsigned char*)GetGameResources()), (char*)&nm);
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (tok == REGION_VALUE(0xff1e, 0xff1c)) {
                int slot = *(signed char*)(self + REGION_VALUE(0x1785, 0x1957));
                if (slot >= 0 && slot < *(signed char*)(self + REGION_VALUE(0x1784, 0x1956))) {
                    int val;
                    int kind = *(signed char*)(message->unknown_1952_ + slot);
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
                        int var19 = val / 0xa - 1;
                        int var20 = var19 >= 0 && var19 <= 3;
                        if (var20) {
                            func_ov016_0218b5c0(1, var19);
                            func_ov017_0218b5f8(var19);
                        }
                        val = val - (var19 + 1) * 0xa;
                    }
                    int var21 = val >= 0 && val <= 3;
                    if (var21) {
                        func_ov016_0218b5c0(1, val);
                        func_ov017_0218b5f8(val);
                        unsigned char* who = ((unsigned char*)GetGameResources());
                        if (func_02046b60((ListHead02046b60*)(*(void**)(who + REGION_VALUE(0x34ec, 0x36fc))), 0xc) != 0) {
                            func_ov017_021a5ab0(*(void**)(who + REGION_VALUE(0x350c, 0x371c)));
                        }
                    }
                }
                message->unknown_1957_ = *(signed char*)(self + REGION_VALUE(0x1785, 0x1957)) + 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (tok == REGION_VALUE(0xff1c, 0xff1a)) {
                if (REGION_FLAG(flag2, unknown_19d0_) != 0) return;
                message->func_02045688();
                ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] =
                    ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] - 1;
                if (((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] > 0) return;
                ((int*)(self + REGION_VALUE(0x173c, 0x186c)))[*(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac))] = 0;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->unknown_19ac_ = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) + 1;
                message->unknown_19ac_ = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) & 3;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                return;
            } else if (tok == REGION_VALUE(0xff1f, 0xff1d)) {
                message->mode = 2;
                message->func_02045688();
                return;
            } else if (tok == REGION_VALUE(0xff20, 0xff1e)) {
                message->func_02045688();
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
                message->unknown_19ac_ = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) + 1;
                message->unknown_19ac_ = *(signed char*)(self + REGION_VALUE(0x17dc, 0x19ac)) & 3;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                return;
            } else if (tok == REGION_VALUE(0xff21, 0xff1f)) {
                message->b19ca = 0;
                message->mode = 2;
                message->func_02045688();
                return;
            } else if (tok == REGION_VALUE(0xff28, 0xff26)) {
                message->unknown_19b1_ = 1;
                message->unknown_19cd_ = 1;
            } else if (tok == REGION_VALUE(0xff29, 0xff27)) {
                message->unknown_19b1_ = 0;
                message->unknown_19cd_ = 1;
            } else if (tok == REGION_VALUE(0xff2a, 0xff28)) {
                message->unknown_19b8_ = 1;
            } else if (tok == REGION_VALUE(0xff2b, 0xff29)) {
                message->unknown_19b8_ = 0;
            } else if (tok == REGION_VALUE(0xff2c, 0xff2a)) {
                message->unknown_1844_ = *(int*)(self + REGION_VALUE(0x1710, 0x1840));
                message->unknown_19b6_ = 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->func_02045688();
                return;
            } else if (tok == REGION_VALUE(0xff2e, 0xff2c)) {
                message->unknown_1844_ = message->unknown_183c_;
                message->unknown_19b6_ = 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                message->func_02045688();
                return;
            } else if (tok == REGION_VALUE(0xff2f, 0xff2d)) {
                unsigned char* who = (unsigned char*)GameState::GetInstance()->GetLeader();
                void* node = func_0203dce4((Struct_0203dce4_2*)func_0203cf4c(), message->selectedEntry);
                if (who != 0 && node != 0) {
                    var4 = *(struct Struct_0203de84*)(who + 0x44);
                    func_020406f8(&src, (Node020406f8*)node);
                    dst = src;
                    message->unknown_1844_ = fix32ReduceAngle0To2Pi(fix32_Atan2(var4.v[0] - dst.v[0], var4.v[2] - dst.v[2]));
                    message->unknown_19b6_ = 1;
                    message->func_02045688();
                }
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                return;
            } else if (tok == REGION_VALUE(0xff30, 0xff2e)) {
                message->func_02045688();
                (self + 0x1000)[REGION_VALUE(0x787, 0x959)] = 0x3c;
                (self + 0x1000)[REGION_VALUE(0x7e7, 0x9b7)] = 1;
                (self + 0x1000)[REGION_VALUE(0x78a, 0x95c)] = 0;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                SePlayer_Play((SePlayer*)&g_sePlayer, 6, 0);
                return;
            } else if (tok == REGION_VALUE(0xff31, 0xff2f)) {
                message->func_02045688();
                (self + 0x1000)[REGION_VALUE(0x787, 0x959)] = 0x3c;
                (self + 0x1000)[REGION_VALUE(0x7e7, 0x9b7)] = 1;
                (self + 0x1000)[REGION_VALUE(0x78a, 0x95c)] = 1;
                *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
                *(signed char*)(self + REGION_VALUE(0x7e2, 0x912)) = 0;
                SePlayer_Play((SePlayer*)&g_sePlayer, 0x1c, 0);
                return;
            } else if (tok == 0xff04 || tok == 0xff05 || tok == 0xff06 || tok == 0xff07) {
                func_02065418(message->unknown_19cc_);
                int first = 0;
                if (*(int*)(self + REGION_VALUE(0x218, 0x2c8)) == 1 || tok == 0xff05) first = 1;
                *(int*)(self + REGION_VALUE(0x218, 0x2c8)) = 0;
#if defined(jpn)
                func_020665bc((char*)(self + REGION_VALUE(0x50, 0x90)), first, data_020f07b4, data_020f07b9);
#else
                int a = StandardStrings_Get(0x1b);
                int b = StandardStrings_Get(0x1c);
                func_020652d0((char*)(self + REGION_VALUE(0x50, 0x90)), first, a, b);
#endif
                message->unknown_94c_[2] = first;
                (self + 0x1000)[REGION_VALUE(0x7ea, 0x9ba)] = 1;
                *(int*)(self + REGION_VALUE(0x85c, 0x98c)) = 0;
                message->mode = 6;
                message->func_02045688();
                SePlayer_Play((SePlayer*)&g_sePlayer, 5, 0);
                int var28 = 1;
                unsigned char* bs = (unsigned char*)GameState::GetInstance();
                unsigned char* w = (unsigned char*)((GameState*)bs)->GetResources();
                if ((bs + 0x5000)[REGION_VALUE(0xa68, 0xcc8)] == 2) var28 = 0;
                if (w != 0 && var28 != 0) (w + 0x4000)[REGION_VALUE(0x134, 0x354)] = 0xa;
                return;
            } else if (tok == 0xff08) {
                volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
                unsigned int bits = (*reg & 0x1f00) >> 8;
                unsigned int keep = *reg & ~0x1f00;
                *reg = keep | ((bits | 0x10) << 8);
                func_02065418(message->unknown_19cc_);
#if defined(jpn)
                func_020665bc((char*)(self + REGION_VALUE(0x50, 0x90)), 0, data_020f07c0, data_020f07c7);
#else
                int a = StandardStrings_Get(0x1d);
                int b = StandardStrings_Get(0x1e);
                func_020652d0((char*)(self + REGION_VALUE(0x50, 0x90)), 0, a, b);
#endif
                message->unknown_94c_[2] = 0;
                (self + 0x1000)[REGION_VALUE(0x7ea, 0x9ba)] = 1;
                *(int*)(self + REGION_VALUE(0x85c, 0x98c)) = 1;
                message->mode = 6;
                message->func_02045688();
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
                    func_0208bf28((Struct_02065990_2*)(message->child), *(short*)(self + REGION_VALUE(0x1776, 0x1948)), 0);
                    *&message->unknown_195b_ |= 1;
                    unsigned char* g = func_02094d6c();
                    int idx = func_020965ac((Struct_02065990_3*)g, (unsigned char)*(short*)(self + REGION_VALUE(0x1776, 0x1948)));
                    func_020cf0fc((int)&sa);
                    RTC_GetTime((int)&sb);
                    packed.b.a = sa.f0;
                    packed.b.b = sa.f4;
                    packed.b.c = sa.f8;
                    packed.b.d = sb.f0;
                    packed.b.e = sb.f4;
                    *(unsigned int*)(g + idx * 4 + 0x178) = packed.w;
                    func_0209c830((Struct0209c830*)&g_bgmPlayer, 0x32);
                }
            } else if (tok > REGION_VALUE(0xff39, 0xff34) && tok < REGION_VALUE(0xff4e, 0xff49)) {
                message->func_02045688();
                func_0209c830((Struct0209c830*)&g_bgmPlayer, tok - REGION_VALUE(0xff08, 0xff03));
                message->unknown_19c9_ = 1;
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
                    func_0208be94((unsigned char*)(message->child));
                    *&message->unknown_195b_ |= 1;
                    func_0209c830((Struct0209c830*)&g_bgmPlayer, 0x33);
                }
            } else if (tok == 0xff13) {
                unsigned char* ent = message->child;
                if (ent != 0) {
                    *(unsigned short*)(ent + 0xda) = *(unsigned short*)(ent + 0xda) | 0x300;
                    func_0208be94((unsigned char*)(message->child));
                    *&message->unknown_195b_ |= 1;
                    func_0209c830((Struct0209c830*)&g_bgmPlayer, 0x44);
                }
            } else if (tok == 0xff12) {
                if (message->child != 0) {
                    func_0208beb4((unsigned char*)(message->child));
                }
#if defined(jpn)
            } else if (tok == 0xff37) {
                var12 = true;
            } else if (tok == 0xff38) {
                var12 = false;
#endif
            } else if (tok >= REGION_VALUE(0xff52, 0xff4d) && tok <= REGION_VALUE(0xff55, 0xff50)) {
                int v = *(signed char*)(self + REGION_VALUE(0x1778, 0x194a) + (tok - REGION_VALUE(0xff52, 0xff4d)));
                func_0205e944(&g_sePlayer, ((v * 0x21dd) >> 10) & 0x7f);
            } else if (tok == 0xff0e) {
                message->unknown_19c0_ = 1;
                message->unknown_195d_ = 0x1e;
#if defined(jpn)
            } else if ((unsigned short)(tok + 0xe6) <= 1) {
                n++;
#endif
            }
        }
        message->mode = 5;
        *(int*)(self + REGION_VALUE(0x44, 0x78)) = *(int*)(self + REGION_VALUE(0x44, 0x78)) + 1;
#if defined(jpn)
        if (!var12) n--;
#else
        n--;
#endif
    }
}
