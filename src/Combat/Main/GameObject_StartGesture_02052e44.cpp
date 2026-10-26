#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"

void* GlobalFlags_GetInstance(void);
struct FlagWord02046708;
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

extern "C" void func_0205308c(void* obj, int val);
extern "C" void func_ov017_021cc1f8(int a, void* buf, int len, int extra);

unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
int GameState_GetFollowCamera(char* obj);

struct S020a2c70;
int MarkStateIfFlag020a2c70(struct S020a2c70* p);

struct Obj02052e44 {
    char pad0[0x4];
    short field4;
    char pad6[(IS_JPN ? 0x16c : 0x178) - 0x6];
    signed char f178[4];
    signed char f17c;
    signed char f17d;
    signed char f17e;
    char pad17f[0x180 - 0x17f];
    int f180;
    signed char f184;
    signed char f185;
    signed char f186;
    char pad187[0x190 - 0x187];
    int f190;
    int f194;
};

// Main, originally InitFieldsIfInRange02052e44 (USA 0x02052e44, EUR 0x02052e54, JPN 0x02054214)
ARM int GameObject_StartGesture(Obj02052e44* obj, signed char arg1) {
    signed char idx;
    signed char val;
    GameState* battleStruct;

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 2)) {
        return 0;
    }

    {
        int flag17c = (((signed char*)((char*)obj + 0x100))[(IS_JPN ? 0x70 : 0x7c)] > 0);
        if (flag17c) {
            return 0;
        }
    }

    if (arg1 <= 0 || arg1 >= 0x21) {
        return 0;
    }

    obj->f178[0] = arg1;
    obj->f17c = 1;
    obj->f17d = 0;
    obj->f180 = -1;
    obj->f17e = 0;
    obj->f184 = 0;
    obj->f190 = 0;
    obj->f194 = -1;
    obj->f185 = 0;
    obj->f186 = 0;

    idx = ((signed char*)((char*)obj + 0x100))[(IS_JPN ? 0x71 : 0x7d)];
    val = obj->f178[idx];
    func_0205308c(obj, val);

    func_ov017_021cc1f8(obj->field4, &arg1, 1, 0);

    {
        short field4;
        battleStruct = GameState::GetInstance();
        field4 = obj->field4;
        obj = (struct Obj02052e44*)battleStruct;
        unsigned char cur = GameState_GetLeaderIndex((GameState*)obj);
        if (cur == field4) {
            int r = GameState_GetFollowCamera((char*)obj);
            if (r != 0) {
                MarkStateIfFlag020a2c70((struct S020a2c70*)r);
            }
        }
    }

    return 1;
}
