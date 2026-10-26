#include <globaldefs.h>

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

struct Struct_020a8a34 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char pad6;
    unsigned char unknown_7_;
};

// USA: func_020a8a34
extern "C" ARM void func_020a8a34(struct Struct_020a8a34* obj, int mode, int shift, unsigned char val) {
    if (mode == 0) {
        obj->unknown_5_ &= ~(1 << shift);
        obj->unknown_7_ = val;
    } else if (mode == 1) {
        obj->unknown_5_ |= (1 << shift);
        obj->unknown_7_ = val;
    } else if (mode == 2) {
        signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance());
        func_ov017_021d1874(obj->byte0, obj->unknown_1_, obj->unknown_2_, obj->unknown_4_, (unsigned char)cur, 1, 0);
    }
}
