#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd0d8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char unknown_4_3_ : 3;
    unsigned char unknown_4_6_ : 2;
    unsigned char unknown_5_;
    short unknown_6_[7];
};

// USA: func_ov017_021cd0d8  (semantic: SendShortArrayInChunks_021cd0d8)
extern "C" ARM void func_ov017_021cd0d8(int a0, unsigned short* a1, int a2) {
    void* p = LinkMessageQueue_GetInstance();
    int consumed;
    int j;

    struct Struct_ov017_021cd0d8 var3;
    var3.unknown_0_ = 0x10;
    var3.unknown_4_0_ = (unsigned char)arg0;

    var1 = 0;
    var2 = 0;
    while (var1 < arg2) {
        int var4 = 0;
        for (; var4 < 7; var4++) {
            if (arg2 <= var1 + var4) {
                break;
            }
            var3.unknown_6_[var4] = arg1[var2 * 7 + var4];
        }
        var3.unknown_4_3_ = var4;
        func_0205e330(var0, &var3, 0);
        var1 += var3.unknown_4_3_;
        var2++;
    }
}
