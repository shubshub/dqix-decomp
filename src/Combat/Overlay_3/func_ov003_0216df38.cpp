#include <globaldefs.h>

extern "C" void* __clear(void* buf, int len);

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

extern "C" int Font_GetTextWidth(void* p, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int Text_Append(char* dst, const char* src);

extern const char data_ov003_02180208;
extern const char data_ov003_02180215;

// USA: func_ov003_0216df38
extern "C" ARM short func_ov003_0216df38(char* dst, struct Container020e0310* c, int flag) {
    char buf[0x80];
    __clear(buf, 0x80);

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

    int rounded = (w1 + 0x1b) & ~7;
    int half = rounded >> 3;
    return (short)(half + (half & 1));
}
