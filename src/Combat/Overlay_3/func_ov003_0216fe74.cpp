#include <globaldefs.h>

struct Struct_0205de24_2;
extern "C" void func_0205de24(struct Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);

extern "C" void* __clear(void* arg0, int arg1);

int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);

struct Struct_0201099c_3;
extern "C" short func_ov003_0216df38(char* arg0, struct Struct_0201099c_3* arg1, int arg2);

struct Struct_0205d5d0;
#if defined(jpn)
extern "C" int sprintf(char* dst, const char* fmt, ...);
int Text_Append(char* dst, const char* src);
const char* KeyTable_Get(struct Container020e0310* c, int key);
extern char data_ov003_0217ea90[];
extern char data_ov003_0217eaac[];
extern char data_ov003_0217eabf[];
extern char data_ov003_0217ea6f[];
int Window_SetPaneText(struct StructA0205d5d0* a, int b, int c, int d);
#else
int Window_SetPaneText(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif

// USA: func_ov003_0216fe74
extern "C" ARM void func_ov003_0216fe74(char* arg0, int arg1, int arg2, int arg3) {
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
#if defined(jpn)
    *(short*)(var0 + 0xa8) = 0;
#else
    *(short*)(var0 + 0xa8) = 0xc;
#endif
    *(short*)(var0 + 0xaa) = 0xe;

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xac) = 0xa;
    *(short*)(var0 + 0xae) = 0x10;

    (*(char**)(arg0 + 0x3c))[0xb5] = 1;

#if defined(jpn)
    char var1[0x200];
    char var2[0x80];
    __clear(var1, 0x200);
    __clear(var2, 0x80);

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
    char var3[0x200];
    __clear(var3, 0x200);

    if (p3 != -1) {
        Text_AppendFrameTag(buf, p3, 8, 5, 5, 5);
    }

    short var4 = func_ov003_0216df38(var3, (struct Struct_0201099c_3*)(arg0 + 0xdc), arg1);

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xa4) = (short)((0x20 - var4) >> 1);
    *(short*)(var0 + 0xa6) = 6;

    var0 = *(char**)(arg0 + 0x3c);
    *(short*)(var0 + 0xa0) = var4;
    *(short*)(var0 + 0xa2) = 9;

    Window_SetPaneText((struct StructA0205d5d0*)*(char**)(self + 0x3c), 0, (int)buf, 1, 0);
#endif
}
