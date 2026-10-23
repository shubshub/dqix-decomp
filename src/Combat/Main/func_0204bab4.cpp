#include <globaldefs.h>

extern "C" void Background_CopyScreenRect(void*, void*, int, int, int, int, int, int, int, int);

struct Struct_0204bab4 {
    char unknown_0_[0x14];
    void* unknown_14_;
};

struct Struct_0204bab4_2 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[8];
    void* unknown_c_;
};

// USA: func_0204bab4
extern "C" ARM void func_0204bab4(struct Struct_0204bab4* arg0, struct Struct_0204bab4_2* arg1, int arg2, int arg3,
                        int arg4, short arg5, int arg6, int arg7, unsigned short arg8) {
    int var0;
    short var1;
    short var2, var3;

    if (arg2 <= 0 || arg3 <= 0) return;
    if (arg1->unknown_c_ == NULL) return;

    var2 = arg1->unknown_0_;
    var3 = arg1->unknown_2_;
    var1 = arg5;
    if (var2 < arg2) arg2 = var2;
    if (var3 < arg3) arg3 = var3;

    for (unsigned short j = 0; j < countY; j++) {
        curX = x0;
        for (unsigned short i = 0; i < countX; i++) {
            if (obj->field14 != NULL) {
                Background_CopyScreenRect(obj, obj->field14, (int)pt, 0, 0, curX, curY, width, height, a9);
            }
            var0 = (short)(var0 + arg2);
        }
        var1 = (short)(var1 + arg3);
    }
}
