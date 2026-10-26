#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

union Struct_ov017_021c9168 {
    struct { unsigned char unknown_0_0_ : 4; unsigned char unknown_0_4_ : 4; } lo;
    struct { char unknown_0_0_ : 4; char unknown_0_4_ : 4; } hi;
};

struct Struct_ov017_021c9168_2 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned char pad2[1];
    union Struct_ov017_021c9168 payload;
    unsigned short field8;
    unsigned short fieldA;
    unsigned int fieldC;
    unsigned int field10;
};

// USA: func_ov017_021c9168
extern "C" ARM void func_ov017_021c9168(int p0, int p1, int p2, int p3,
        int p4, int p5, int p6, int p7, int p8, int p9, int p10) {
    void* d = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c9168_2 evt;
    evt.tag = 0x84;
    evt.field4 = (unsigned short)p0;
    evt.payload.lo.unknown_0_0_ = (unsigned char)p1;
    evt.payload.hi.unknown_0_4_ = (char)p10;
    evt.fieldC = p4;
    evt.field10 = p6;
    evt.fieldA = (unsigned short)p8;
    evt.field8 = (unsigned short)p3;

    func_0205e330(d, &evt, 0);
}
