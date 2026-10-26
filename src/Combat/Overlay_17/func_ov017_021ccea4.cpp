#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021ccea4 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char unknown_4_3_ : 4;
    unsigned char unknown_4_7_ : 1;
    unsigned char arr[15];
};

// USA: func_ov017_021ccea4
extern "C" ARM void func_ov017_021ccea4(int a, unsigned char* b, int c) {
    void* p = LinkMessageQueue_GetInstance();
    Struct_ov017_021ccea4 msg;
    msg.tag = 0xf;
    msg.unknown_4_0_ = a;
    int pos = 0;
    int group = 0;
    while (pos < c) {
        int j;
        for (j = 0; j < 15; j++) {
            if (c <= pos + j) break;
            msg.arr[j] = b[group * 15 + j];
        }
        msg.unknown_4_3_ = j;
        func_0205e330(p, &msg, 0);
        pos += msg.unknown_4_3_;
        group++;
    }
}
