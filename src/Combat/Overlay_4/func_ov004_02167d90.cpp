#include <globaldefs.h>

struct Struct_ov004_02167d90 {
    unsigned char f4;
    short unknown_2_;
    short f8;
    short fa;
    int fc;
};

extern "C" void func_ov004_0216794c(short* a, short* b, short* c, unsigned char* d, int* e);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02167d90
extern "C" ARM int func_ov004_02167d90(void* obj) {
    struct Struct_ov004_02167d90 buf;
    func_ov004_0216794c(&buf.fa, &buf.f8, &buf.unknown_2_, &buf.f4, &buf.fc);
    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) {
        func_ov011_021848a0(obj, 0xc8);
        return 0;
    }
    if (buf.fa == 0) {
        func_ov011_021848a0(obj, 0xa);
        goto ret0;
    }
    if (buf.fc < 0) {
        func_ov011_021848a0(obj, 0x64);
    } else {
        func_ov011_021848a0(obj, 0x1e);
    }
ret0:
    return 0;
}
