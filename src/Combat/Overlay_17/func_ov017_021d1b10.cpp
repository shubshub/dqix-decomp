#if defined(jpn)
enum { Enum_ov017_021d1b10_1804 = 0x4fc, Enum_ov017_021d1b10_1844 = 0x524, Enum_ov017_021d1b10_10100 = 0x27b4 };
#else
enum { Enum_ov017_021d1b10_1804 = 0x70c, Enum_ov017_021d1b10_1844 = 0x734, Enum_ov017_021d1b10_10100 = 0x2774 };
#endif

#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020a72ac(void* base, int val);

union Struct_ov017_021d1b10_2 {
    signed short raw;
    struct { signed short unknown_0_0_ : 14; signed short sub : 2; } bits;
};

struct Struct_ov017_021d1b10_3 {
    unsigned char pad0[4];
    signed short field4;
    union Struct_ov017_021d1b10_2 field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned short fieldc;
    signed short unknown_e_;
    unsigned char field10;
};

struct Struct_ov017_021d1b10_4 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2;
    unsigned char unknown_3_;
    unsigned char pad4[0xe];
    short field12;
    short field14;
    unsigned short unknown_16_;
    unsigned short field18;
    unsigned short unknown_1a_;
    short field1c;
    unsigned char unknown_1e_;
};

struct LiveState_021d1b10 {
    unsigned char pad0[Enum_ov017_021d1b10_10100];
    Vector3i vec;
    int unknown_2780_;
    short unknown_2784_;
    short unknown_2786_;
    unsigned char unknown_2788_;
};

// USA: func_ov017_021d1b10
extern "C" ARM void func_ov017_021d1b10(int unused0, Struct_ov017_021d1b10_3* b, int arg2, unsigned char* ov, struct SearchStruct0202c1a4* search) {
    if (LinkSession_GetOwnSlot(search) == 0) return;

    LiveState_021d1b10* live = (LiveState_021d1b10*)Zone3D_GetInstance();
    Struct_ov017_021d1b10_4* var1 = *(Struct_ov017_021d1b10_4**)(ov + 0x3000 + Enum_ov017_021d1b10_1804);
    unsigned char* obj2 = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021d1b10_1844);

    if (var1->unknown_3_ != 0 && var1->field1 != 1) {
        var1->field12 = b->field4;
        var1->field14 = b->field6.raw;
        var1->unknown_16_ = b->field8;
        var1->field18 = b->fielda;
        var1->unknown_1a_ = b->fieldc;
        var1->field1c = b->unknown_e_;
        var1->unknown_1e_ = b->field10;
    } else {
        live->unknown_2786_ = b->field4;
        short var3 = b->field6.bits.unknown_0_0_;
        if (var3 != -1) live->unknown_2784_ = var3;
        live->unknown_2788_ = (unsigned char)b->field6.bits.sub;
        Vector3i var4 = { (short)b->field8 << 7, (short)b->fielda << 7, (short)b->fieldc << 7 };
        live->vec = var4;
        live->unknown_2780_ = b->unknown_e_;
        if (obj2[3] == 0) {
            func_020a72ac(live, b->field10);
        }
    }
}
