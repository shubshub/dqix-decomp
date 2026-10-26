#include <globaldefs.h>

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_ov017_021d1874(unsigned char a, unsigned char b, unsigned char c, int d, int e, int f, int g);

struct Obj020a8a34 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3_pad;
    unsigned char byte4;
    unsigned char mask_0x5;
    unsigned char pad6;
    unsigned char val7;
};

// USA: func_020a8a34  (semantic: SetFlagOrEnqueueEntry_020a8a34)
extern "C" ARM void func_020a8a34(struct Obj020a8a34* obj, int mode, int shift, unsigned char val) {
    if (mode == 0) {
        obj->mask_0x5 &= ~(1 << shift);
        obj->val7 = val;
    } else if (mode == 1) {
        obj->mask_0x5 |= (1 << shift);
        obj->val7 = val;
    } else if (mode == 2) {
        signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)LinkSession_GetInstance());
        func_ov017_021d1874(obj->byte0, obj->byte1, obj->byte2, obj->byte4, (unsigned char)cur, 1, 0);
    }
}
