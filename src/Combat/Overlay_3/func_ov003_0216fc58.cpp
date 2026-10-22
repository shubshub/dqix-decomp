#include <globaldefs.h>

struct Struct_0205de24_2;
struct Struct_0205ba68;
struct Struct_0205bacc;
struct Struct_0205d81c;
struct Struct_0204c610;
struct Struct_0201099c_3;

struct Struct_ov003_0216fc58 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

extern "C" void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);
extern "C" void func_0205cef8(void* arg0);
extern "C" void* __clear(void* arg0, int arg1);
extern "C" int func_02041c08(char* arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" short func_ov003_0216df38(char* arg0, struct Struct_0201099c_3* arg1, int arg2);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" int func_02042058(char* arg0, const char* arg1);
extern "C" const char* func_020e0434(struct Struct_0201099c_3* arg0, int arg1);
extern char data_ov003_0217ea90[];
extern char data_ov003_0217eaac[];
extern char data_ov003_0217eabf[];
extern char data_ov003_0217ea6f[];
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(struct Node0205bacc* s, int val);
struct Elem0216fc58* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
void GetFourShortsAtIndex(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);
void* CreateAndSetFields46_021e2ca8(void* a, void* b, int c, int d);
void* CreateAndSetFields8A_021e2cc8(void* a, void* b, int c, int d);

#if defined(jpn)
// USA: func_ov003_0216fc58
extern "C" ARM void func_ov003_0216fc58(char* arg0, int arg1, int arg2) {
    char* var0 = *(char**)(arg0 + 0x3c);
    if (var0 == 0) {
        return;
    }
    func_0205de24((struct Struct_0205de24_2*)var0, 0, 1);

    (*(char**)(arg0 + 0x3c))[0xb1] = 0;

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xa0) = 0x11;
    *(short*)(var0 + 0xa2) = 9;

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xa4) = 6;
    *(short*)(var0 + 0xa6) = 6;

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xa8) = 0;
    *(short*)(var0 + 0xaa) = 0xe;

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xac) = 0xa;
    *(short*)(var0 + 0xae) = 0x10;

    (*(char**)(arg0 + 0x3c))[0xb5] = 1;

    func_0205cef8(*(char**)(arg0 + 0x3c));

    char var1[0x200];
    char var2[0x80];
    __clear(var1, 0x200);
    __clear(var2, 0x80);
    func_02041c08(var1, arg2, 8, 5, 5, 5);

    if (arg1) {
        sprintf(var2, data_ov003_0217ea90, func_020e0434((struct Struct_0201099c_3*)(arg0 + 0xdc), 6));
    } else {
        sprintf(var2, data_ov003_0217ea90, func_020e0434((struct Struct_0201099c_3*)(arg0 + 0xdc), 5));
    }
    func_02042058(var1, var2);
    sprintf(var2, data_ov003_0217eaac, func_020e0434((struct Struct_0201099c_3*)(arg0 + 0xdc), 7));
    func_02042058(var1, var2);
    sprintf(var2, data_ov003_0217eabf, data_ov003_0217ea6f);
    func_02042058(var1, var2);

    func_0205d304(*(char**)(arg0 + 0x3c), var1, 0, 0, 0, 1, 0);

    window = *(char**)(self + 0x3c);
    *(int*)(window + 0x8) = 1;
    *(int*)(window + 0x58) = 1;
    GridCursor_SetDimensions((struct Struct_0205ba68*)(window + 0x4), 1, 3, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)(window + 0x54), 1, 3, 0);
    GridCursor_SetCount((struct Node0205bacc*)(window + 0x4), 3);
    GridCursor_SetCount((struct Node0205bacc*)(window + 0x54), 3);
}
#else
// USA: func_ov003_0216fc58
extern "C" ARM void func_ov003_0216fc58(char* arg0, int arg1, int arg2) {
    char* var3 = *(char**)(arg0 + 0x3c);
    if (var3 == 0) {
        return;
    }
    func_0205de24((struct Struct_0205de24_2*)var3, 0, 1);

    (*(char**)(arg0 + 0x3c))[0xb1] = 0;

    var3 = *(char**)(arg0 + 0x3c);
    *(short*)(var3 + 0xa0) = 0x11;
    *(short*)(var3 + 0xa2) = 9;

    var3 = *(char**)(arg0 + 0x3c);
    *(short*)(var3 + 0xa4) = 6;
    *(short*)(var3 + 0xa6) = 6;

    var3 = *(char**)(arg0 + 0x3c);
    *(short*)(var3 + 0xa8) = 0xc;
    *(short*)(var3 + 0xaa) = 0xe;

    var3 = *(char**)(arg0 + 0x3c);
    *(short*)(var3 + 0xac) = 0xa;
    *(short*)(var3 + 0xae) = 0x10;

    (*(char**)(arg0 + 0x3c))[0xb5] = 1;

    func_0205cef8(*(char**)(arg0 + 0x3c));

    char var4[0x200];
    __clear(var4, 0x200);
    func_02041c08(var4, arg2, 8, 5, 5, 5);

    short var5 = func_ov003_0216df38(var4, (struct Struct_0201099c_3*)(arg0 + 0xdc), arg1);

    var3 = *(char**)(arg0 + 0x3c);
    *(short*)(var3 + 0xa4) = (short)((0x20 - var5) >> 1);
    *(short*)(var3 + 0xa6) = 6;

    var3 = *(char**)(arg0 + 0x3c);
    *(short*)(var3 + 0xa0) = var5;
    *(short*)(var3 + 0xa2) = 9;

    func_0205d304(*(char**)(arg0 + 0x3c), var4, 0, 0, 0, 1, 0, 0);

    window = *(char**)(self + 0x3c);
    *(int*)(window + 0x8) = 1;
    *(int*)(window + 0x58) = 1;
    GridCursor_SetDimensions((struct Struct_0205ba68*)(window + 0x4), 1, 3, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)(window + 0x54), 1, 3, 0);
    GridCursor_SetCount((struct Node0205bacc*)(window + 0x4), 3);
    GridCursor_SetCount((struct Node0205bacc*)(window + 0x54), 3);

    struct Struct_ov003_0216fc58* var6 = func_0205d81c(*(struct Struct_0205d81c**)(arg0 + 0x3c), 0);
    if (var6 == 0) {
        return;
    }

    short var7 = var6->unknown_ac_ * 8;
    short var8 = var6->unknown_ae_ * 8;
    short var9 = 0x16;
    for (int var10 = 0; var10 < 3; var10++, var9++) {
        short var11, var12, var13, var14;
        func_0204c610((struct Struct_0204c610*)var6, (short)var10, &var11, &var12, &var13, &var14);
        func_ov023_021e2ca8(*(void**)(arg0 + 0xd4), (void*)var9, (short)(var11 + var7), (short)(var12 + var8));
        func_ov023_021e2cc8(*(void**)(arg0 + 0xd4), (void*)var9, var13, var14);
    }
}
#endif
