#include <globaldefs.h>

extern "C" void* __clear(void* arg0, int arg1);

struct Container020e0310;
extern int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" int func_020420e8(void* arg0, int arg1);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" int func_02042058(char* arg0, const char* arg1);

extern const char data_ov003_02180208;
extern const char data_ov003_02180215;

// USA: func_ov003_0216df38
extern "C" ARM short func_ov003_0216df38(char* arg0, struct Struct_0201099c_3* arg1, int arg2) {
    char var0[0x80];
    __clear(var0, 0x80);

    int w1;
    int key1 = 5;
    int f1, f2;
    if (flag) key1 = 6;
    f1 = KeyTable_Get(c, key1);
    f2 = KeyTable_Get(c, 7);

    var1 = func_020420e8((void*)var3, 0);
    int var5 = func_020420e8((void*)var4, 0);
    if (var1 < var5) var1 = var5;

    sprintf(var0, &data_ov003_02180208, var3);
    func_02042058(arg0, var0);

    sprintf(var0, &data_ov003_02180215, var4);
    func_02042058(arg0, var0);

    int f3 = KeyTable_Get(c, 0xe);
    sprintf(buf, (const char*)f3);
    AppendString02042058(dst, buf);

    int var7 = (var1 + 0x1b) & ~7;
    int var8 = var7 >> 3;
    return (short)(var8 + (var8 & 1));
}
