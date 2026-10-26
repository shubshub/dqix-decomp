#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd0d8 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char count : 3;
    unsigned char pad4 : 2;
    unsigned char pad5;
    short unknown_6_[7];
};

// USA: func_ov017_021cd0d8
extern "C" ARM void func_ov017_021cd0d8(int a0, unsigned short* a1, int a2) {
    void* p = LinkMessageQueue_GetInstance();
    int var1;
    int j;

    struct Struct_ov017_021cd0d8 evt;
    evt.tag = 0x10;
    evt.unknown_4_0_ = (unsigned char)a0;

    var1 = 0;
    j = 0;
    while (var1 < a2) {
        int i = 0;
        for (; i < 7; i++) {
            if (a2 <= var1 + i) {
                break;
            }
            evt.unknown_6_[i] = a1[j * 7 + i];
        }
        evt.count = i;
        func_0205e330(p, &evt, 0);
        var1 += evt.count;
        j++;
    }
}
