#include <globaldefs.h>

struct Struct_020974b0_2 {
    struct Struct_020974b0_2* next;
    unsigned char pad4[0xf];
    unsigned char bit0 : 1;
    unsigned char marked : 1;
    unsigned char unknown_13_2_ : 6;
};

// USA: func_02097844
extern "C" ARM void func_02097844(struct Struct_020974b0_2** arg0, int arg1) {
    int var0;
    int var1;
    struct Struct_020974b0_2* last;
    int var3;
    struct Struct_020974b0_2* var4;
    struct Struct_020974b0_2* var5;
    struct Struct_020974b0_2* var6;
    struct Struct_020974b0_2* cursor;

    if (arg1 <= 0) {
        return;
    }
    var4 = *arg0;
    var0 = 0;
    var1 = 0;
    var3 = 0;
    var5 = NULL;
    var6 = NULL;
    cursor = var4;
    while (cursor != NULL) {
        var0++;
        if (cursor->marked) {
            var1++;
        }
        last = cursor;
        cursor = cursor->next;
        if (var0 == arg1 || cursor == NULL) {
            if (var1 > 0) {
                var3++;
                if (var5 != NULL) {
                    var5->next = var4;
                } else {
                    *arg0 = var4;
                }
                var5 = last;
            }
            var0 = 0;
            var1 = 0;
            var4 = cursor;
            if (var6 == NULL) {
                var6 = last;
            }
        }
    }
    if (var3 == 0) {
        if (var6 != NULL) {
            var6->next = NULL;
        }
    } else {
        if (var5 != NULL) {
            var5->next = NULL;
        }
    }
}
