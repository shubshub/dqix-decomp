#include <globaldefs.h>

struct Struct0205de24;
struct GridCursor;
struct Struct_0205d81c;
struct ShortArrays0204c610;
struct Container020e0310;

struct Struct_ov003_0216fc58 {
    char unk_0[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_0205cef8(void* obj);
extern "C" void* __clear(void* dst, int count);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" short func_ov003_0216df38(char* dst, struct Container020e0310* c, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern char data_ov003_0217ea90[];
extern char data_ov003_0217eaac[];
extern char data_ov003_0217eabf[];
extern char data_ov003_0217ea6f[];
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
extern "C" struct Struct_ov003_0216fc58* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_0204c610(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);
extern "C" void* func_ov023_021e2ca8(void* a, void* b, int c, int d);
extern "C" void* func_ov023_021e2cc8(void* a, void* b, int c, int d);

#if defined(jpn)
// USA: func_ov003_0216fc58
extern "C" ARM void func_ov003_0216fc58(char* self, int flag, int tag) {
    char* window = *(char**)(self + 0x3c);
    if (window == 0) {
        return;
    }
    func_0205de24((struct Struct0205de24*)window, 0, 1);

    (*(char**)(self + 0x3c))[0xb1] = 0;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa0) = 0x11;
    *(short*)(window + 0xa2) = 9;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa4) = 6;
    *(short*)(window + 0xa6) = 6;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa8) = 0;
    *(short*)(window + 0xaa) = 0xe;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xac) = 0xa;
    *(short*)(window + 0xae) = 0x10;

    (*(char**)(self + 0x3c))[0xb5] = 1;

    func_0205cef8(*(char**)(self + 0x3c));

    char buf[0x200];
    char line[0x80];
    __clear(buf, 0x200);
    __clear(line, 0x80);
    Text_AppendFrameTag(buf, tag, 8, 5, 5, 5);

    if (flag) {
        sprintf(line, data_ov003_0217ea90, KeyTable_Get((struct Container020e0310*)(self + 0xdc), 6));
    } else {
        sprintf(line, data_ov003_0217ea90, KeyTable_Get((struct Container020e0310*)(self + 0xdc), 5));
    }
    Text_Append(buf, line);
    sprintf(line, data_ov003_0217eaac, KeyTable_Get((struct Container020e0310*)(self + 0xdc), 7));
    Text_Append(buf, line);
    sprintf(line, data_ov003_0217eabf, data_ov003_0217ea6f);
    Text_Append(buf, line);

    Window_OpenPane(*(char**)(self + 0x3c), buf, 0, 0, 0, 1, 0);

    window = *(char**)(self + 0x3c);
    *(int*)(window + 0x8) = 1;
    *(int*)(window + 0x58) = 1;
    GridCursor_SetDimensions((struct GridCursor*)(window + 0x4), 1, 3, 0);
    GridCursor_SetDimensions((struct GridCursor*)(window + 0x54), 1, 3, 0);
    GridCursor_SetCount((struct GridCursor*)(window + 0x4), 3);
    GridCursor_SetCount((struct GridCursor*)(window + 0x54), 3);
}
#else
// USA: func_ov003_0216fc58
extern "C" ARM void func_ov003_0216fc58(char* self, int flag, int tag) {
    char* window = *(char**)(self + 0x3c);
    if (window == 0) {
        return;
    }
    func_0205de24((struct Struct0205de24*)window, 0, 1);

    (*(char**)(self + 0x3c))[0xb1] = 0;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa0) = 0x11;
    *(short*)(window + 0xa2) = 9;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa4) = 6;
    *(short*)(window + 0xa6) = 6;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa8) = 0xc;
    *(short*)(window + 0xaa) = 0xe;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xac) = 0xa;
    *(short*)(window + 0xae) = 0x10;

    (*(char**)(self + 0x3c))[0xb5] = 1;

    func_0205cef8(*(char**)(self + 0x3c));

    char buf[0x200];
    __clear(buf, 0x200);
    Text_AppendFrameTag(buf, tag, 8, 5, 5, 5);

    short w = func_ov003_0216df38(buf, (struct Container020e0310*)(self + 0xdc), flag);

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa4) = (short)((0x20 - w) >> 1);
    *(short*)(window + 0xa6) = 6;

    window = *(char**)(self + 0x3c);
    *(short*)(window + 0xa0) = w;
    *(short*)(window + 0xa2) = 9;

    Window_OpenPane(*(char**)(self + 0x3c), buf, 0, 0, 0, 1, 0, 0);

    window = *(char**)(self + 0x3c);
    *(int*)(window + 0x8) = 1;
    *(int*)(window + 0x58) = 1;
    GridCursor_SetDimensions((struct GridCursor*)(window + 0x4), 1, 3, 0);
    GridCursor_SetDimensions((struct GridCursor*)(window + 0x54), 1, 3, 0);
    GridCursor_SetCount((struct GridCursor*)(window + 0x4), 3);
    GridCursor_SetCount((struct GridCursor*)(window + 0x54), 3);

    struct Struct_ov003_0216fc58* elem = func_0205d81c(*(struct Struct_0205d81c**)(self + 0x3c), 0);
    if (elem == 0) {
        return;
    }

    short var7 = elem->unknown_ac_ * 8;
    short var8 = elem->unknown_ae_ * 8;
    short id = 0x16;
    for (int i = 0; i < 3; i++, id++) {
        short var11, var12, x1, var14;
        func_0204c610((struct ShortArrays0204c610*)elem, (short)i, &var11, &var12, &x1, &var14);
        func_ov023_021e2ca8(*(void**)(self + 0xd4), (void*)id, (short)(var11 + var7), (short)(var12 + var8));
        func_ov023_021e2cc8(*(void**)(self + 0xd4), (void*)id, x1, var14);
    }
}
#endif
