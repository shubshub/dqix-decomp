#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020a9d78_32376 = 0x7c38 };
#else
enum { Enum_020a9d78_32376 = 0x7e78 };
#endif
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void* Zone3D_GetInstance();
struct Struct_0201bc7c;
extern "C" void func_0201bc7c(struct Struct_0201bc7c* obj, unsigned short val);
struct Struct_0201bc88;
extern "C" void func_0201bc88(struct Struct_0201bc88* obj, unsigned short val);

struct Data02109bf4 {
    unsigned char pad[0xc8];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
};
extern struct Data02109bf4 g_bgmPlayer;

struct Struct_020a9d78_3 {
    unsigned short zoneId;
    short unknown2;
    Vector3i position;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char flag;
    signed char unknown_15_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
};

struct PendingLocation {
    unsigned short zoneId;
    unsigned char unknown2[5];
    unsigned char unknown_7_;
    unsigned char unknown8[8];
    Vector3i position;
    short unknown_1c_;
};

struct Struct_020a9d78 {
    short x;
    short y;
    short z;
    signed char key;
};

struct Struct_020a9d78_2 {
    unsigned char unknown0[Enum_020a9d78_32376];
    Struct_020a9d78 pending;
};

// USA: func_020a9d78
extern "C" ARM int func_020a9d78(void* arg0) {
    Struct_020a9d78_3* saved = static_cast<Struct_020a9d78_3*>(arg0);
    GameState* battleStruct = GameState::GetInstance();
    PendingLocation* destination = static_cast<PendingLocation*>(GameState_GetZoneTransition(battleStruct));

    destination->zoneId = saved->zoneId;
    destination->position = saved->position;

    destination->unknown_1c_ = saved->unknown2;
    destination->unknown_7_ = 1;

    void* g = Zone3D_GetInstance();
    func_0201bc7c((struct Struct_0201bc7c*)g, saved->unknown_12_);
    func_0201bc88((struct Struct_0201bc88*)g, saved->unknown_10_);

    g_bgmPlayer.b3 = (saved->flag != 0);

    Struct_020a9d78* pending = &reinterpret_cast<Struct_020a9d78_2*>(battleStruct)->pending;
    pending->x = saved->unknown_16_;
    pending->y = saved->unknown_18_;
    pending->z = saved->unknown_1a_;
    pending->key = saved->unknown_15_;
    return 1;
}
