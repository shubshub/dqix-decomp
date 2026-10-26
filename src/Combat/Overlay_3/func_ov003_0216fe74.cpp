#include <globaldefs.h>

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

extern "C" void* __clear(void* dst, int count);

extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);

struct Container020e0310;
extern "C" short func_ov003_0216df38(char* dst, struct Container020e0310* c, int flag);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" const char* KeyTable_Get(struct Container020e0310* c, int key);
extern char data_ov003_0217ea90[];
extern char data_ov003_0217eaac[];
extern char data_ov003_0217eabf[];
extern char data_ov003_0217ea6f[];
extern "C" int Window_SetPaneText(struct StructA0205d5d0* a, int b, int c, int d);
#else
extern "C" int Window_SetPaneText(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

// USA: func_ov003_0216fe74
extern "C" ARM void func_ov003_0216fe74(char* self, int p1, int p2, int p3) {
    char* field3c = *(char**)(self + 0x3c);
    if (field3c == 0) {
        return;
    }
    func_0205de24((struct Struct0205de24*)field3c, 0, 1);

    (*(char**)(self + 0x3c))[0xb1] = 0;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa0) = 0x11;
    *(short*)(field3c + 0xa2) = 9;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa4) = 6;
    *(short*)(field3c + 0xa6) = 6;

    field3c = *(char**)(self + 0x3c);
#if defined(jpn)
    *(short*)(field3c + 0xa8) = 0;
#else
    *(short*)(field3c + 0xa8) = 0xc;
#endif
    *(short*)(field3c + 0xaa) = 0xe;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xac) = 0xa;
    *(short*)(field3c + 0xae) = 0x10;

    (*(char**)(self + 0x3c))[0xb5] = 1;

#if defined(jpn)
    char buf[0x200];
    char line[0x80];
    __clear(buf, 0x200);
    __clear(line, 0x80);

    if (p3 != -1) {
        Text_AppendFrameTag(buf, p3, 8, 5, 5, 5);
    }

    if (p1) {
        sprintf(line, data_ov003_0217ea90, KeyTable_Get((struct Container020e0310*)(self + 0xdc), 6));
    } else {
        sprintf(line, data_ov003_0217ea90, KeyTable_Get((struct Container020e0310*)(self + 0xdc), 5));
    }
    Text_Append(buf, line);
    sprintf(line, data_ov003_0217eaac, KeyTable_Get((struct Container020e0310*)(self + 0xdc), 7));
    Text_Append(buf, line);
    sprintf(line, data_ov003_0217eabf, data_ov003_0217ea6f);
    Text_Append(buf, line);

    Window_SetPaneText((struct StructA0205d5d0*)*(char**)(self + 0x3c), 0, (int)buf, 1);
#else
    char buf[0x200];
    __clear(buf, 0x200);

    if (p3 != -1) {
        Text_AppendFrameTag(buf, p3, 8, 5, 5, 5);
    }

    short w = func_ov003_0216df38(buf, (struct Container020e0310*)(self + 0xdc), p1);

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa4) = (short)((0x20 - w) >> 1);
    *(short*)(field3c + 0xa6) = 6;

    field3c = *(char**)(self + 0x3c);
    *(short*)(field3c + 0xa0) = w;
    *(short*)(field3c + 0xa2) = 9;

    Window_SetPaneText((struct StructA0205d5d0*)*(char**)(self + 0x3c), 0, (int)buf, 1, 0);
#endif
}
