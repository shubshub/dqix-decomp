#include <globaldefs.h>

extern "C" void* __clear(void* arg0, int arg1);

struct Container020e0310;
extern int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" int Font_GetTextWidth(void* p, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern int Text_Append(char* dst, const char* src);

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

    w1 = Font_GetTextWidth((void*)f1, 0);
    int w2 = Font_GetTextWidth((void*)f2, 0);
    if (w1 < w2) w1 = w2;

    sprintf(buf, &data_ov003_02180208, f1);
    Text_Append(dst, buf);

    sprintf(buf, &data_ov003_02180215, f2);
    Text_Append(dst, buf);

    int f3 = KeyTable_Get(c, 0xe);
    sprintf(buf, (const char*)f3);
    Text_Append(dst, buf);

    int var7 = (var1 + 0x1b) & ~7;
    int var8 = var7 >> 3;
    return (short)(var8 + (var8 & 1));
}
