#if defined(jpn)
enum { Enum_ov017_0218d644_17560 = 0x41e8 };
#else
enum { Enum_ov017_0218d644_17560 = 0x4498 };
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "std_library_functions.h"

extern "C" void func_ov017_0218cbcc(int* p, int a, int b, int c);
struct Struct_020dbfa4;
extern "C" void func_020dbfa4(struct Struct_020dbfa4* o, int arg1);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern int g_sePlayer;
extern char data_ov017_021d739f;

struct Struct_ov017_0218d644 {
    char name[0x10];
    unsigned char unknown_10_;
    unsigned char b0:1, b1:1, b2:1, b3:1, unknown_11_4_:1, unknown_11_5_:1, unknown_11_6_:1, unknown_11_7_:1;
    short field12;
    short f14, unknown_16_, f18, unknown_1a_;
    short f1c;
    int f20, f24, f28;
    int unknown_2c_[3];
    int unknown_38_, f3c, f40;
    int unknown_44_, unknown_48_, unknown_4c_;
};

// Overlay 17, originally func_ov017_0218d644 (USA/EUR 0x0218d644, JPN 0x0218e224)
extern "C" ARM void GameResources_PlaySpecialItemEffect(GameResources* ov, void* a, int b) {
    struct Struct_020dbfa4* p = *(struct Struct_020dbfa4**)((char*)ov + Enum_ov017_0218d644_17560);

    struct Struct_ov017_0218d644 buf;
    buf.name[0] = 0;
    buf.unknown_10_ = 1;
    buf.b0 = 0;
    buf.b1 = 0;
    buf.b2 = 1;
    buf.b3 = 0;
    buf.unknown_11_4_ = 0;
    buf.unknown_11_5_ = 0;
    buf.unknown_11_6_ = 0;
    buf.unknown_11_7_ = 0;
    buf.f14 = -1;
    buf.unknown_16_ = -1;
    buf.f18 = -1;
    buf.unknown_1a_ = -1;
    buf.f1c = -0x1000;
    buf.f20 = 0;
    buf.f24 = 0;
    buf.f28 = 0;
    buf.unknown_2c_[0] = 0;
    buf.unknown_2c_[1] = 0;
    buf.unknown_2c_[2] = 0;
    buf.unknown_38_ = 0;
    buf.f3c = 0;
    buf.f40 = 0;
    buf.unknown_44_ = 0x1000;
    buf.unknown_48_ = 0x1000;
    buf.unknown_4c_ = 0x1000;
    buf.b2 = 0;
    buf.field12 = (short)b;
    strcpy(buf.name, &data_ov017_021d739f);

    buf.unknown_44_ = 0x10a;
    buf.unknown_48_ = 0x10a;
    buf.unknown_4c_ = 0x10a;

    int* src = (int*)a;
    func_ov017_0218cbcc(buf.unknown_2c_, src[0], src[1], src[2]);
    func_020dbfa4(p, (int)&buf);
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x5f, 0);
}
