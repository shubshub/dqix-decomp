#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"

extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord02046708;
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

extern "C" void func_0205308c(void* obj, int val);
extern "C" void func_ov017_021cc1f8(int a, void* buf, int len, int extra);

extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
extern "C" int GameState_GetFollowCamera(char* obj);

struct S020a2c70;
extern "C" int func_020a2c70(struct S020a2c70* p);

struct Struct_02052f44 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Obj02052f44 {
    char pad0[0x4];
    short field4;
    char pad6[0xc1 - 0x6];
    struct Struct_02052f44 unknown_c1_;
    char unknown_c2_[(IS_JPN ? 0x16c : 0x178) - 0xc2];
    signed char unknown_178_[1];
    char unknown_179_[0x17c - 0x179];
    signed char unknown_17c_;
    signed char unknown_17d_;
    signed char unknown_17e_;
    char unknown_17f_[0x180 - 0x17f];
    int unknown_180_;
    signed char unknown_184_;
    signed char unknown_185_;
    signed char unknown_186_;
    char unknown_187_[0x190 - 0x187];
    int unknown_190_;
    int unknown_194_;
};

// Main, originally FilterBytesAndInit02052f44 (USA 0x02052f44, EUR 0x02052f54, JPN 0x02054314)
extern "C" ARM int GameObject_StartGestureSequence(struct Obj02052f44* obj, signed char* src, int len) {
    int count;
    int i;
    signed char idx;
    signed char val;
    GameState* battleStruct;

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 2)) {
        return 0;
    }

    if (len > 4) {
        return 0;
    }

    {
        int var5 = (((signed char*)((char*)obj + 0x100))[(IS_JPN ? 0x70 : 0x7c)] > 0);
        if (var5) {
            return 0;
        }
    }

    count = 0;
    for (i = 0; i < len; i++) {
        signed char c = src[i];
        if (c > 0 && c < 0x21) {
            obj->unknown_178_[count] = c;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    obj->unknown_17c_ = count;
    obj->unknown_17d_ = 0;
    obj->unknown_180_ = -1;
    obj->unknown_17e_ = 0;
    obj->unknown_184_ = 0;
    obj->unknown_190_ = 0;
    obj->unknown_194_ = -1;
    obj->unknown_185_ = 0;
    obj->unknown_186_ = 0;

    idx = ((signed char*)((char*)obj + 0x100))[(IS_JPN ? 0x71 : 0x7d)];
    val = obj->unknown_178_[idx];
    func_0205308c(obj, val);

    func_ov017_021cc1f8(obj->field4, src, len, 0);

    obj->unknown_c1_.mode |= 2;

    {
        short field4;
        battleStruct = GameState::GetInstance();
        field4 = obj->field4;
        obj = (struct Obj02052f44*)battleStruct;
        unsigned char cur = GameState_GetLeaderIndex((GameState*)obj);
        if (cur == field4) {
            int r = GameState_GetFollowCamera((char*)obj);
            if (r != 0) {
                func_020a2c70((struct S020a2c70*)r);
            }
        }
    }

    return 1;
}
