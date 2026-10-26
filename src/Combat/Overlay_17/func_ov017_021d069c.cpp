#include <globaldefs.h>

extern "C" int Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* state);
extern "C" void func_ov017_021d0490(int a);
extern "C" void func_ov017_021c3e18(int a);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021bd2f0(void* table, void* localBuf);

struct Struct_ov017_021d069c {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_0_ : 2;
    unsigned char unknown_7_2_ : 1;
    unsigned char unknown_7_3_ : 2;
    unsigned char unknown_7_5_ : 1;
    unsigned char unknown_7_6_ : 2;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

struct Struct_ov017_021d069c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
};

// USA: func_ov017_021d069c
extern "C" ARM void func_ov017_021d069c(int arg0, struct Struct_ov017_021d069c* arg1, int arg2, unsigned char* arg3, struct Struct_0202c1a4* arg4) {
#if defined(jpn)
 enum {Enum_ov017_021d069c_1844=0x524};
#else
 enum {Enum_ov017_021d069c_1844=0x734};
#endif
    Zone3D_GetInstance();
    unsigned char* table = *(unsigned char**)((char*)a3 + 0x3000 + regionalOffset);
    if (LinkSession_IsHostOrSolo(a4)) {
        func_ov017_021d0490(a0);
        func_ov017_021c3e18(1);
        return;
    }
    if (arg0 != 0) {
        return;
    }
    if (LinkSession_GetOwnSlot(a4) != a1->fieldA) {
        return;
    }

    struct Struct_ov017_021d069c_2 var1;
    unsigned char var2 = arg1->unknown_7_3_;
    var1.unknown_0_ = var2;
    var1.unknown_1_ = arg1->unknown_4_;
    var1.unknown_2_ = arg1->unknown_5_;
    var1.unknown_3_ = arg1->unknown_6_;
    var1.unknown_4_ = arg1->unknown_8_;
    var1.unknown_6_ = arg1->unknown_a_;
    var1.unknown_8_ = arg1->unknown_7_5_;

    var2 = var2 & 0xff;
    if (var2 == 0) {
        var1.unknown_a_ = (unsigned short)*(short*)((char*)arg1 + 0xc);
        var1.unknown_c_ = arg1->unknown_e_;
    } else if (var2 == 1) {
        var1.unknown_a_ = arg1->unknown_c_;
        var1.unknown_c_ = arg1->unknown_e_;
        var1.unknown_e_ = arg1->unknown_10_;
        var1.unknown_10_ = arg1->unknown_12_;
    }

    func_ov017_021bd2f0(var0, &var1);
}
