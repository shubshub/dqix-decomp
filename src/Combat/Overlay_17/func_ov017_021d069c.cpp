#include <globaldefs.h>

extern "C" int Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* state);
extern "C" void func_ov017_021d0490(int a);
extern "C" void func_ov017_021c3e18(int a);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021bd2f0(void* table, void* localBuf);

struct Struct_ov017_021d069c {
    unsigned char pad0[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char fieldA : 2;
    unsigned char unknown_7_2_ : 1;
    unsigned char fieldB : 2;
    unsigned char fieldC : 1;
    unsigned char unknown_7_6_ : 2;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};

struct Struct_ov017_021d069c_2 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned char f8;
    unsigned char unknown_9_;
    unsigned short fa;
    unsigned short fc;
    unsigned short fe;
    unsigned short f10;
};

// USA: func_ov017_021d069c
extern "C" ARM void func_ov017_021d069c(int a0, struct Struct_ov017_021d069c* a1, int arg2, unsigned char* a3, struct SearchStruct0202c1a4* a4) {
#if defined(jpn)
 enum {regionalOffset=0x524};
#else
 enum {regionalOffset=0x734};
#endif
    Zone3D_GetInstance();
    unsigned char* table = *(unsigned char**)((char*)a3 + 0x3000 + regionalOffset);
    if (LinkSession_IsHostOrSolo(a4)) {
        func_ov017_021d0490(a0);
        func_ov017_021c3e18(1);
        return;
    }
    if (a0 != 0) {
        return;
    }
    if (LinkSession_GetOwnSlot(a4) != a1->fieldA) {
        return;
    }

    struct Struct_ov017_021d069c_2 buf;
    unsigned char var2 = a1->fieldB;
    buf.f0 = var2;
    buf.f1 = a1->unknown_4_;
    buf.f2 = a1->unknown_5_;
    buf.f3 = a1->unknown_6_;
    buf.f4 = a1->unknown_8_;
    buf.unknown_6_ = a1->unknown_a_;
    buf.f8 = a1->fieldC;

    var2 = var2 & 0xff;
    if (var2 == 0) {
        buf.fa = (unsigned short)*(short*)((char*)a1 + 0xc);
        buf.fc = a1->unknown_e_;
    } else if (var2 == 1) {
        buf.fa = a1->unknown_c_;
        buf.fc = a1->unknown_e_;
        buf.fe = a1->unknown_10_;
        buf.f10 = a1->unknown_12_;
    }

    func_ov017_021bd2f0(table, &buf);
}
