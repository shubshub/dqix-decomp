#if defined(jpn)
enum { Enum_ov017_021d1a18_10100 = 0x27b4, Enum_ov017_021d1a18_10112 = 0x27c0 };
#else
enum { Enum_ov017_021d1a18_10100 = 0x2774, Enum_ov017_021d1a18_10112 = 0x2780 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};

extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void* Zone3D_GetInstance(void* unused);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d1a18 { int x, y, z; };

struct Struct_ov017_021d1a18_2 {
    short unknown_0_0_ : 14;
    short unknown_1_6_ : 2;
};

struct Struct_ov017_021d1a18_3 {
    short flag;
    struct Struct_ov017_021d1a18_2 bits;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    unsigned short w;
    unsigned char d;
};

struct Struct_ov017_021d1a18_4 {
    unsigned char tag;
    unsigned char pad0[3];
    Struct_ov017_021d1a18_3 sub;
};

// USA: func_ov017_021d1a18
extern "C" ARM void func_ov017_021d1a18(int a, short b, short c, unsigned char d) {
    if (!LinkSession_IsActive(LinkSession_GetInstance())) return;
    if (LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance()) != 0) return;

    ((int)GetGameResources());
    GameState* bs = GameState::GetInstance();
    void* base = Zone3D_GetInstance(GameState_GetZoneTransition(bs));
    void* p = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021d1a18_4 buf;
    buf.tag = 0xb2;
    buf.sub.flag = (a == 0) ? 1 : a;
    buf.sub.bits.unknown_0_0_ = b;
    buf.sub.bits.unknown_1_6_ = c;

    struct Struct_ov017_021d1a18 vec = *(struct Struct_ov017_021d1a18*)((char*)base + Enum_ov017_021d1a18_10100);
    buf.sub.unknown_4_ = (short)(vec.x >> 7);
    buf.sub.unknown_6_ = (short)(vec.y >> 7);
    buf.sub.unknown_8_ = (short)(vec.z >> 7);

    buf.sub.w = *(int*)((char*)base + Enum_ov017_021d1a18_10112);
    buf.sub.d = d;
    func_0205e330(p, &buf, 0);
}
