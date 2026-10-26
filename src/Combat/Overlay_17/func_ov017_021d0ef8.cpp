#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d0ef8 {
    unsigned char f0;
    unsigned char f1;
    unsigned char len : 7;
    unsigned char unknown_2_7_ : 1;
    unsigned char data[12];
};

struct Struct_ov017_021d0ef8_2 {
    unsigned char tag;
    unsigned char pad[3];
    Struct_ov017_021d0ef8 buf;
};

// USA: func_ov017_021d0ef8
extern "C" ARM void func_ov017_021d0ef8(int a1, unsigned char* a2, int a3, int a4, int* outLen) {
    void* data = LinkMessageQueue_GetInstance();

    Struct_ov017_021d0ef8_2 msg;
    Struct_ov017_021d0ef8* buf = &msg.buf;
    buf->f0 = (unsigned char)a1;
    msg.tag = 0xab;
    int len = a3 - a4;

    *outLen = len;
    if (len > 12) {
        *outLen = 12;
    } else {
        buf->unknown_2_7_ = 1;
    }
    buf->len = (unsigned char)*outLen;
    buf->f1 = (unsigned char)a4;
    memcpy(buf->data, a2 + a4, *outLen);

    func_0205e330(data, &msg, 0);
}
