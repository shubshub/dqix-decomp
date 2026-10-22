#if defined(jpn)
enum { Enum_ov017_0218d644_17560 = 0x41e8 };
#else
enum { Enum_ov017_0218d644_17560 = 0x4498 };
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "std_library_functions.h"

void StoreThreeWords_0218cbcc(int* p, int a, int b, int c);
struct Obj020dbfa4;
void ProcessPendingNode020dbfa4(struct Obj020dbfa4* o, int arg1);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern int g_sePlayer;
extern char data_ov017_021d739f;

struct Struct_ov017_0218d644 {
    char unknown_0_[0x10];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_:1, unknown_11_1_:1, unknown_11_2_:1, unknown_11_3_:1, unknown_11_4_:1, unknown_11_5_:1, unknown_11_6_:1, unknown_11_7_:1;
    short unknown_12_;
    short unknown_14_, unknown_16_, unknown_18_, unknown_1a_;
    short unknown_1c_;
    int unknown_20_, unknown_24_, unknown_28_;
    int unknown_2c_[3];
    int unknown_38_, unknown_3c_, unknown_40_;
    int unknown_44_, unknown_48_, unknown_4c_;
};

// USA: func_ov017_0218d644
extern "C" ARM void func_ov017_0218d644(GameResources* arg0, void* arg1, int arg2) {
    struct Struct_020dbfa4* var0 = *(struct Struct_020dbfa4**)((char*)arg0 + Enum_ov017_0218d644_17560);

    struct Struct_ov017_0218d644 var1;
    var1.unknown_0_[0] = 0;
    var1.unknown_10_ = 1;
    var1.unknown_11_0_ = 0;
    var1.unknown_11_1_ = 0;
    var1.unknown_11_2_ = 1;
    var1.unknown_11_3_ = 0;
    var1.unknown_11_4_ = 0;
    var1.unknown_11_5_ = 0;
    var1.unknown_11_6_ = 0;
    var1.unknown_11_7_ = 0;
    var1.unknown_14_ = -1;
    var1.unknown_16_ = -1;
    var1.unknown_18_ = -1;
    var1.unknown_1a_ = -1;
    var1.unknown_1c_ = -0x1000;
    var1.unknown_20_ = 0;
    var1.unknown_24_ = 0;
    var1.unknown_28_ = 0;
    var1.unknown_2c_[0] = 0;
    var1.unknown_2c_[1] = 0;
    var1.unknown_2c_[2] = 0;
    var1.unknown_38_ = 0;
    var1.unknown_3c_ = 0;
    var1.unknown_40_ = 0;
    var1.unknown_44_ = 0x1000;
    var1.unknown_48_ = 0x1000;
    var1.unknown_4c_ = 0x1000;
    var1.unknown_11_2_ = 0;
    var1.unknown_12_ = (short)arg2;
    strcpy(var1.unknown_0_, &data_ov017_021d739f);

    var1.unknown_44_ = 0x10a;
    var1.unknown_48_ = 0x10a;
    var1.unknown_4c_ = 0x10a;

    int* src = (int*)a;
    StoreThreeWords_0218cbcc(buf.words2c, src[0], src[1], src[2]);
    ProcessPendingNode020dbfa4(p, (int)&buf);
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x5f, 0);
}
